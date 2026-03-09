#!/usr/bin/python3

import glob
import random
import sys

evos = {"wingull":
        {
            "level": 25,
            "next": "pelipper",
            "ability": "Keen Eye"
        }
        }

def get_pool(tclass, level, name, count=False):
    lvl = int(level)
    if lvl >= 50:
        lvl = 50
    elif lvl >= 35:
        lvl = 35
    elif lvl >= 20:
        lvl = 20
    else:
        lvl = 10

    if not count:
        count = 6

    mon_list = glob.glob(f"trainer_sets/{tclass}/{lvl}-*")

    random.seed(f"{tclass} {name}")
    try:
        # choose 6 mons
        chosen_mons = random.sample(mon_list, count)
    except ValueError:
        print(tclass, "not enough mons", file=sys.stderr)
        return
    i = 1
    for mon in chosen_mons:
        i += 1
        with open(mon) as f:
            content = f.read().strip()

        mon = mon.split('-', 1)[-1]

        # if we have multiple sets just use the first
        content = content.split("\n\n")[0]
        evolve = False
        if mon in evos and evos[mon]['level'] <= int(level):
            evolve = evos[mon]['next']

        for l in content.split("\n"):
            if l.startswith(mon.title()) and evolve:
                print(l.replace(mon.title(), evolve.title()))
            elif evolve and l.startswith("Ability:"):
                print("Ability:", evos[mon]['ability'])
            elif l.startswith("Level: "):
                print("Level:", level)
            else:
                print(l)
        if i <= len(chosen_mons):
            print()

with open("trainers.party.src") as f:
    lines = f.readlines()

for l in lines:
    if l.strip().startswith("{{"):
        args = l.replace("{{", "").replace("}}", "").split()
        count = False
        if len(args) > 3:
            count = args[3]
        get_pool(args[0], args[1], args[2], int(count))
    else:
        print(l.strip())
