#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "caps.h"
#include "pokemon.h"


u32 GetCurrentLevelCap(void)
{
    static const u32 sLevelCapFlagMap[][2] =
    {
        {FLAG_NETTUX_DEFEATED_RED_1, 10},          // 8  RED
        {FLAG_NETTUX_FINISH_GAUNTLET_1, 10},       // 9 BLUE
        {FLAG_NETTUX_FINISH_AQUA_FOREST, 15},      // 13 GRUNT
        {FLAG_NETTUX_FINISH_GAUNTLET_2, 15},       // 14 MAY
        {FLAG_NETTUX_FINISH_LEAF_1, 20},           // 18 LEAF
        {FLAG_NETTUX_FINISH_GAUNTLET_3, 20},       // 20 WALLY
        {FLAG_BADGE01_GET, 20},                    // 20 ROXANNE
        {FLAG_NETTUX_FINISH_GAUNTLET_4, 25},       // 25 KOGA
        {FLAG_NETTUX_FINISH_AQUA_TUNNEL, 25},      // 24 GRUNT
        {FLAG_NETTUX_FINISH_GAUNTLET_5, 25},       // 25 MAY
        {FLAG_NETTUX_FINISH_GAUNTLET_6, 30},       // 30 LORELEI
        {FLAG_BADGE02_GET, 30},                    // 30 BRAWLY
        {FLAG_NETTUX_FINISH_GAUNTLET_7, 36},       // 36 MISTY
        {FLAG_NETTUX_FINISH_AQUA_MUSEUM, 36},      // 35 GRUNTS
        {FLAG_NETTUX_FINISH_GAUNTLET_8, 40},       // 40 MAY
        {FLAG_NETTUX_FINISH_GAUNTLET_9, 44},       // 44 GIOVANNI
                                                   // 44 WALLY
        {FLAG_BADGE03_GET, 44},                    // 44 WATTSON
                                                   // 44 BROCK
        {FLAG_NETTUX_FINISH_WINSTRATES, 46},       // 40+2 WINSTRATES
        {FLAG_NETTUX_FINISH_GAUNTLET_11, 46},      // 46 BLAINE
        {FLAG_NETTUX_FINISH_AQUA1, 46},            // 47 ARCHIE
                                                   // 48 TABITHA
        {FLAG_NETTUX_FINISH_MAXIE1, 50},           // 50 MAXIE
        {FLAG_NETTUX_FINISH_GAUNTLET_12, 55},      // 55 AGATHA
                                                   // 53 RED
        {FLAG_BADGE04_GET, 55},                    // 55 FLANNERY
                                                   // 55 LT SURGE
        {FLAG_NETTUX_FINISH_WALLY_2, 60},          // 60 WALLY
        {FLAG_BADGE05_GET, 60},                    // 60 NORMAN
        {FLAG_NETTUX_FINISH_GAUNTLET_14, 66},      // 66 BRENDAN
                                                   // 63 GRUNTS
        {FLAG_NETTUX_FINISH_SHELLY_1, 66},         // 65 SHELLY
                                                   // 66 LEAF
        {FLAG_NETTUX_FINISH_GAUNTLET_15, 66},      // 66 ERIKA
        {FLAG_BADGE06_GET, 70},                    // 70 WINONA
        {FLAG_NETTUX_FINISH_GAUNTLET_16, 70},      // 70 LANCE
        {FLAG_NETTUX_FINISH_GAUNTLET_17, 70},      // 70 BLUE
        {FLAG_NETTUX_FINISH_GAUNTLET_18, 76},      // 76 SABRINA
                                                   // 74 GRUNTS
        {FLAG_NETTUX_FINISH_ARCHIE2, 76},          // 76 ARCHIE
                                                   // 82 TABITHA
        {FLAG_NETTUX_FINISH_MAXIE2, 83},           // 83 MAXIE
                                                   // 81 GRUNTS
        {FLAG_NETTUX_FINISH_MATT, 83},             // 82 MATT
        {FLAG_NETTUX_FINISH_GAUNTLET_19, 83},      // 83 BRUNO
        {FLAG_BADGE07_GET, 86},                    // 86 TATE&LIZA
                                                   // 86 GRUNTS
        {FLAG_NETTUX_FINISH_MAXIE3, 88},           // 87 MAXIE&TABITHA
                                                   // 88 SHELLY
        {FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 88}, // 88 ARCHIE
                                                   // 92 GABBY&TY
        {FLAG_NETTUX_FINISH_RED_AND_LEAF, 93},     // 93 RED&LEAF
        {FLAG_BADGE08_GET, 96},                    // 96 JUAN
                                                   // 96 OAK
                                                   // 96 WALLY
        {FLAG_IS_CHAMPION, 100},                   // 100 LEAGUE
    };

    u32 i;

    //if (FlagGet(FLAG_NETTUX_NO_CAP))
    //    return MAX_LEVEL;

    if (B_LEVEL_CAP_TYPE == LEVEL_CAP_FLAG_LIST)
    {
        for (i = 0; i < ARRAY_COUNT(sLevelCapFlagMap); i++)
        {
            if (!FlagGet(sLevelCapFlagMap[i][0]))
                return sLevelCapFlagMap[i][1];
        }
    }
    else if (B_LEVEL_CAP_TYPE == LEVEL_CAP_VARIABLE)
    {
        return VarGet(B_LEVEL_CAP_VARIABLE);
    }

    return MAX_LEVEL;
}

u32 GetSoftLevelCapExpValue(u32 level, u32 expValue)
{
    static const u32 sExpScalingDown[5] = { 4, 8, 16, 32, 64 };
    static const u32 sExpScalingUp[5]   = { 16, 8, 4, 2, 1 };

    u32 levelDifference;
    u32 currentLevelCap = GetCurrentLevelCap();

    if (B_EXP_CAP_TYPE == EXP_CAP_NONE)
        return expValue;

    if (level < currentLevelCap)
    {
        if (B_LEVEL_CAP_EXP_UP)
        {
            levelDifference = currentLevelCap - level;
            if (levelDifference > ARRAY_COUNT(sExpScalingUp) - 1)
                return expValue + (expValue / sExpScalingUp[ARRAY_COUNT(sExpScalingUp) - 1]);
            else
                return expValue + (expValue / sExpScalingUp[levelDifference]);
        }
        else
        {
            return expValue;
        }
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_HARD)
    {
        return 0;
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_SOFT)
    {
        levelDifference = level - currentLevelCap;
        if (levelDifference > ARRAY_COUNT(sExpScalingDown) - 1)
            return expValue / sExpScalingDown[ARRAY_COUNT(sExpScalingDown) - 1];
        else
            return expValue / sExpScalingDown[levelDifference];
    }
    else
    {
       return expValue;
    }
}

u32 GetCurrentEVCap(void)
{
    static const u16 sEvCapFlagMap[][2] = {
        // Define EV caps for each milestone
        {FLAG_BADGE01_GET, MAX_TOTAL_EVS *  1 / 17},
        {FLAG_BADGE02_GET, MAX_TOTAL_EVS *  3 / 17},
        {FLAG_BADGE03_GET, MAX_TOTAL_EVS *  5 / 17},
        {FLAG_BADGE04_GET, MAX_TOTAL_EVS *  7 / 17},
        {FLAG_BADGE05_GET, MAX_TOTAL_EVS *  9 / 17},
        {FLAG_BADGE06_GET, MAX_TOTAL_EVS * 11 / 17},
        {FLAG_BADGE07_GET, MAX_TOTAL_EVS * 13 / 17},
        {FLAG_BADGE08_GET, MAX_TOTAL_EVS * 15 / 17},
        {FLAG_IS_CHAMPION, MAX_TOTAL_EVS},
    };

    if (B_EV_CAP_TYPE == EV_CAP_FLAG_LIST)
    {
        for (u32 evCap = 0; evCap < ARRAY_COUNT(sEvCapFlagMap); evCap++)
        {
            if (!FlagGet(sEvCapFlagMap[evCap][0]))
                return sEvCapFlagMap[evCap][1];
        }
    }
    else if (B_EV_CAP_TYPE == EV_CAP_VARIABLE)
    {
        return VarGet(B_EV_CAP_VARIABLE);
    }
    else if (B_EV_CAP_TYPE == EV_CAP_NO_GAIN)
    {
        return 0;
    }

    return MAX_TOTAL_EVS;
}
