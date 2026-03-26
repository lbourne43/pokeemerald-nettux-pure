#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "caps.h"
#include "pokemon.h"


u32 GetCurrentLevelCap(void)
{
    static const u32 sLevelCapFlagMap[][2] =
    {
        {FLAG_NETTUX_DEFEATED_RED_1, 10},
        {FLAG_NETTUX_FINISH_GAUNTLET_1, 10},
        {FLAG_NETTUX_FINISH_AQUA_FOREST, 15},
        {FLAG_NETTUX_FINISH_GAUNTLET_2, 15},
        {FLAG_NETTUX_FINISH_LEAF_1, 20},
        {FLAG_NETTUX_FINISH_GAUNTLET_3, 20},
        {FLAG_BADGE01_GET, 20},
        {FLAG_NETTUX_FINISH_GAUNTLET_4, 26},
        {FLAG_NETTUX_FINISH_AQUA_TUNNEL, 26},
        {FLAG_NETTUX_FINISH_GAUNTLET_5, 26},
        {FLAG_NETTUX_FINISH_GAUNTLET_6, 30},
        {FLAG_BADGE02_GET, 30},
        {FLAG_NETTUX_FINISH_GAUNTLET_7, 36},
        {FLAG_NETTUX_FINISH_AQUA_MUSEUM, 36},
        {FLAG_NETTUX_FINISH_GAUNTLET_8, 40},
        {FLAG_NETTUX_FINISH_GAUNTLET_9, 44},
        {FLAG_BADGE03_GET, 44},
        {FLAG_NETTUX_FINISH_WINSTRATES, 45},
        {FLAG_NETTUX_FINISH_GAUNTLET_11, 47},
        {FLAG_NETTUX_FINISH_AQUA1, 49},
        {FLAG_NETTUX_FINISH_MAXIE1, 51},
        {FLAG_NETTUX_FINISH_GAUNTLET_12, 53},
        {FLAG_BADGE04_GET, 55},
        {FLAG_NETTUX_FINISH_WALLY_2, 57},
        {FLAG_BADGE05_GET, 60},
        {FLAG_NETTUX_FINISH_GAUNTLET_14, 62},
        {FLAG_NETTUX_FINISH_SHELLY_1, 64},
        {FLAG_NETTUX_FINISH_GAUNTLET_15, 66},
        {FLAG_BADGE06_GET, 70},
        {FLAG_NETTUX_FINISH_GAUNTLET_16, 72},
        {FLAG_NETTUX_FINISH_GAUNTLET_17, 74},
        {FLAG_NETTUX_FINISH_GAUNTLET_18, 76},
        {FLAG_NETTUX_FINISH_ARCHIE2, 78},
        {FLAG_NETTUX_FINISH_MAXIE2, 81},
        {FLAG_NETTUX_FINISH_MATT, 83},
        {FLAG_NETTUX_FINISH_GAUNTLET_19, 84},
        {FLAG_BADGE07_GET, 86},
        {FLAG_NETTUX_FINISH_MAXIE3, 88},
        {FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 90},
        {FLAG_NETTUX_FINISH_RED_AND_LEAF, 93},
        {FLAG_BADGE08_GET, 96},
        {FLAG_IS_CHAMPION, 100},
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
