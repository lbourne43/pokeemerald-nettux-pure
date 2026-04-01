#!/usr/bin/env python3
"""
Generate an HTML page documenting trainers and encounter sections from docs.trainers.

Features:
- Preserves the order trainers/encounters appear in the source file
- Includes any "*Encounters:" sections (e.g., "Encounters:", "Water Encounters:")
- Trainer teams rendered as a table with each Pokémon in its own column
- Adds "Tera Type" row if at least one Pokémon in the team has it
- Shows a Pokémon PNG under each Pokémon name (official artwork)
  - Uses NATIONAL DEX NUMBER by resolving via PokéAPI in client-side JS
  - If Pokémon header is "Species @ Item", lookup uses only "Species"
"""

from __future__ import annotations

from pathlib import Path
import re
import html

# ----------------------------
# Config
# ----------------------------

SRC_PATH = Path("docs.trainers")
OUT_PATH = Path("trainers_and_encounters.html")

# Trainer header lines look like: === TRAINER_FOO_BAR ===
TRAINER_HEADER_RE = re.compile(r"^===\s*(TRAINER_[A-Z0-9_]+)\s*===$")

# Capture ANY encounter section label that ends with "Encounters", case-insensitive:
# e.g. "Encounters:", "Water Encounters:", "Cave Encounters:"
ENCOUNTERS_RE = re.compile(r"\b(.*Encounters):\s*(.*)", re.IGNORECASE)

PLACEHOLDER_GIF = (
    "data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///ywAAAAAAQABAAACAUwAOw=="
)

CSS = """
:root{--bg:#0b0d10;--card:#131821;--text:#e6edf3;--muted:#9aa4b2;--accent:#4da3ff;--border:#243042}
*{box-sizing:border-box}
body{margin:0;font-family:system-ui,-apple-system,Segoe UI,Roboto,Ubuntu,Cantarell,Noto Sans,sans-serif;background:var(--bg);color:var(--text);line-height:1.45}
header{padding:24px 16px;border-bottom:1px solid var(--border);position:sticky;top:0;background:linear-gradient(to bottom, rgba(11,13,16,.98), rgba(11,13,16,.85));backdrop-filter: blur(8px)}
header h1{margin:0;font-size:20px}
header p{margin:6px 0 0;color:var(--muted);font-size:13px}
main{max-width:1200px;margin:0 auto;padding:18px 16px 40px}
.card{background:var(--card);border:1px solid var(--border);border-radius:14px;padding:14px 14px 12px;margin:14px 0;box-shadow:0 10px 30px rgba(0,0,0,.25)}
.card h2{margin:0 0 8px;font-size:16px}
.small{color:var(--muted);font-size:12px}
.badge{display:inline-block;padding:2px 8px;border:1px solid var(--border);border-radius:999px;color:var(--muted);font-size:12px;margin-left:8px}
dl{display:grid;grid-template-columns:140px 1fr;gap:6px 10px;margin:10px 0 0}
dt{color:var(--muted);font-size:12px}
dd{margin:0;font-size:13px}
table{width:100%;border-collapse:collapse;margin-top:12px}
th,td{border:1px solid var(--border);padding:8px;vertical-align:top;font-size:13px}
th{background:#101521}
td ul{margin:0;padding-left:18px}
.enc-list{display:flex;flex-wrap:wrap;gap:8px;margin-top:10px}
.pill{border:1px solid var(--border);border-radius:999px;padding:4px 10px;font-size:13px;background:rgba(255,255,255,.02)}
.pokemon-name{text-align:center;font-weight:600}
.pokemon-img{display:block;margin:6px auto 0;width:96px;height:96px;image-rendering:pixelated}
.pokemon-img.loading{filter:grayscale(100%);opacity:.55}
code{color:#b7d7ff}
"""


# ----------------------------
# Helpers
# ----------------------------

def esc(x: object) -> str:
    return html.escape(str(x), quote=True)


def clean_encounters_list(s: str) -> list[str]:
    s = s.strip().replace("*/", "").replace("/*", "").strip()
    return [x.strip() for x in s.split(",") if x.strip()]


def species_from_header(name: str) -> str:
    """
    If the Pokémon "name" line contains held item syntax like:
      'Eevee @ Leftovers'
    return just:
      'Eevee'
    """
    return name.split("@", 1)[0].strip()


def is_pokemon_name_line(st: str) -> bool:
    """
    In the trainer block format, a Pokémon line is typically a plain line
    without ':' and not a comment/move/header.
    """
    if not st:
        return False
    if st.startswith("===") or st.startswith("/*") or st.startswith("-"):
        return False
    if ":" in st:
        return False
    return True


# ----------------------------
# Parse source file into ordered elements
# ----------------------------

def parse_docs_trainers(lines: list[str]) -> list[dict]:
    """
    Returns a list of dict elements in file order:
    - {"type": "encounters", "label": "...Encounters", "items": [...], "line": N}
    - {"type": "trainer", "meta": {...}, "team": [...], "line": N}
    """
    elements: list[dict] = []
    i = 0

    while i < len(lines):
        line = lines[i]

        # Any encounters line (including Water Encounters, etc.)
        m_enc = ENCOUNTERS_RE.search(line)
        if m_enc:
            label = m_enc.group(1).strip()
            items = clean_encounters_list(m_enc.group(2))
            elements.append(
                {"type": "encounters", "label": label, "items": items, "line": i + 1}
            )
            i += 1
            continue

        # Trainer header
        m_tr = TRAINER_HEADER_RE.match(line.strip())
        if m_tr:
            tid = m_tr.group(1)

            # Block ends at next trainer header OR next encounters line
            j = i + 1
            while j < len(lines):
                if TRAINER_HEADER_RE.match(lines[j].strip()):
                    break
                if ENCOUNTERS_RE.search(lines[j]):
                    break
                j += 1

            block = lines[i:j]
            meta = {"ID": tid}
            team: list[dict] = []
            current = None

            k = 1
            while k < len(block):
                st = block[k].strip()
                if not st:
                    k += 1
                    continue

                # Location comment line
                if st.startswith("/*") and "Location:" in st:
                    loc = st.replace("/*", "").replace("*/", "").strip()
                    lm = re.search(r"Location:\s*(.*)", loc)
                    if lm:
                        meta["Location"] = lm.group(1).strip()
                    k += 1
                    continue

                # Pokémon name line
                if is_pokemon_name_line(st):
                    current = {
                        "name": st,
                        "species": species_from_header(st),
                        "moves": [],
                        "fields": {},
                    }
                    team.append(current)
                    k += 1
                    continue

                # Move line
                if st.startswith("-") and current is not None:
                    current["moves"].append(st.lstrip("-").strip())
                    k += 1
                    continue

                # Key: Value line
                if ":" in st:
                    key, val = st.split(":", 1)
                    key = key.strip()
                    val = val.strip()
                    if current is None:
                        meta[key] = val
                    else:
                        current["fields"][key] = val
                    k += 1
                    continue

                k += 1

            elements.append(
                {"type": "trainer", "meta": meta, "team": team, "line": i + 1}
            )
            i = j
            continue

        i += 1

    return elements


# ----------------------------
# HTML generation
# ----------------------------

CLIENT_JS = r"""
<script>
(function(){
  const PLACEHOLDER = "data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///ywAAAAAAQABAAACAUwAOw==";
  const cache = new Map();

  function speciesPart(name){
    return (name || "").split("@")[0].trim();
  }

  function normalizeName(name){
    name = speciesPart(name);
    return name
      .toLowerCase()
      .trim()
      .replace(/♀/g, "-f")
      .replace(/♂/g, "-m")
      .replace(/\./g, "")
      .replace(/'/g, "")
      .replace(/\s+/g, "-");
  }

  async function getDexNumber(name){
    const key = normalizeName(name);
    if (cache.has(key)) return cache.get(key);

    // /pokemon/<name> -> species URL
    const p = await fetch(`https://pokeapi.co/api/v2/pokemon/${encodeURIComponent(key)}`);
    if (!p.ok) throw new Error("pokemon lookup failed: " + key);
    const pdata = await p.json();

    // species -> national dex entry_number
    const s = await fetch(pdata.species.url);
    if (!s.ok) throw new Error("species lookup failed");
    const sdata = await s.json();

    const nd = (sdata.pokedex_numbers || []).find(x => x.pokedex && x.pokedex.name === "national");
    if (!nd) throw new Error("no national dex number");
    cache.set(key, nd.entry_number);
    return nd.entry_number;
  }

  async function resolveAll(){
    const imgs = Array.from(document.querySelectorAll("img.pokemon-img[data-pokemon]"));
    await Promise.all(imgs.map(async (img) => {
      const raw = img.getAttribute("data-pokemon") || "";
      const name = speciesPart(raw);
      try{
        const dex = await getDexNumber(name);
        img.src = `https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/other/official-artwork/${dex}.png`;
        img.classList.remove("loading");
      }catch(e){
        img.src = PLACEHOLDER;
        img.classList.remove("loading");
        img.title = "Sprite not found (could not resolve Pokédex number)";
      }
    }));
  }

  if (document.readyState === "loading") {
    document.addEventListener("DOMContentLoaded", resolveAll);
  } else {
    resolveAll();
  }
})();
</script>
"""


def build_html(elements: list[dict], src_name: str) -> str:
    parts: list[str] = []

    parts.append(
        "<!doctype html><html lang='en'><head><meta charset='utf-8'/>"
        "<meta name='viewport' content='width=device-width, initial-scale=1'/>"
        "<title>Trainers & Encounters</title>"
        f"<style>{CSS}</style></head><body>"
    )

    parts.append(
        "<header><h1>Trainers & Encounters</h1>"
        f"<p>Generated from <code>{esc(src_name)}</code>. Shown in the order they appear in the file.</p>"
        "</header><main>"
    )

    for el in elements:
        if el["type"] == "encounters":
            parts.append("<section class='card'>")
            parts.append(f"<h2>{esc(el['label'])}</h2>")
            parts.append(f"<div class='small'>Source line {el['line']}</div>")
            parts.append("<div class='enc-list'>")
            for mon in el["items"]:
                parts.append(f"<span class='pill'>{esc(mon)}</span>")
            parts.append("</div></section>")
            continue

        # trainer
        meta = el["meta"]
        team = el["team"]

        title = meta.get("Name", meta.get("ID", "Trainer"))
        cls = meta.get("Class", "")
        loc = meta.get("Location", "")

        parts.append("<section class='card'>")
        h2 = esc(title)
        if cls:
            h2 += f" <span class='badge'>{esc(cls)}</span>"
        parts.append(f"<h2>{h2}</h2>")

        sub = f"ID: <code>{esc(meta.get('ID',''))}</code>"
        if loc:
            sub += f" • Location: {esc(loc)}"
        parts.append(f"<div class='small'>{sub}</div>")

        if team:
            row_order = ["Level", "Item", "Ability", "Tera Type", "Nature", "EVs", "IVs", "Moves"]

            # Only include rows that appear for at least one Pokémon (Moves included if any moves exist).
            present = set()
            for p in team:
                for r in row_order[:-1]:
                    if p["fields"].get(r):
                        present.add(r)
                if p["moves"]:
                    present.add("Moves")

            parts.append("<table>")
            parts.append("<thead><tr><th>Team</th>")
            for p in team:
                parts.append("<th>")
                parts.append(f"<div class='pokemon-name'>{esc(p['name'])}</div>")
                # Use species (before "@") for lookup
                parts.append(
                    f"<img class='pokemon-img loading' src='{PLACEHOLDER_GIF}' "
                    f"data-pokemon='{esc(p.get('species', p['name']))}' alt='{esc(p['name'])}'>"
                )
                parts.append("</th>")
            parts.append("</tr></thead><tbody>")

            for r in row_order:
                if r not in present:
                    continue
                parts.append(f"<tr><td><strong>{esc(r)}</strong></td>")
                for p in team:
                    if r == "Moves":
                        if p["moves"]:
                            items = "".join(f"<li>{esc(m)}</li>" for m in p["moves"])
                            parts.append(f"<td><ul>{items}</ul></td>")
                        else:
                            parts.append("<td></td>")
                    else:
                        val = p["fields"].get(r, "")
                        parts.append(f"<td>{esc(val)}</td>" if val else "<td></td>")
                parts.append("</tr>")

            parts.append("</tbody></table>")

        parts.append("</section>")

    parts.append(CLIENT_JS)
    parts.append("</main></body></html>")
    return "\n".join(parts)


# ----------------------------
# Main
# ----------------------------

def main() -> None:
    if not SRC_PATH.exists():
        raise SystemExit(f"Source file not found: {SRC_PATH}")

    lines = SRC_PATH.read_text(errors="replace").splitlines()
    elements = parse_docs_trainers(lines)

    html_text = build_html(elements, SRC_PATH.name)
    OUT_PATH.write_text(html_text, encoding="utf-8")

    print(f"Wrote: {OUT_PATH.resolve()}")


if __name__ == "__main__":
    main()

