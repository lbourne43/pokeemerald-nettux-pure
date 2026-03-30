NettuxPure_Gauntlet10_MapScripts::
	.byte 0

NettuxPure_Gauntlet10_EventScript_Bryan::
        trainerbattle_single TRAINER_BRYAN, Route111_Text_BryanIntro, Route111_Text_BryanDefeat, NettuxPure_Gauntlet10_Complete
        msgbox Route111_Text_BryanPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet10_Complete::
        setflag FLAG_NETTUX_FINISH_GAUNTLET_10
        addmoney 10000
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_SAFETY_GOGGLES
        giveitem ITEM_AIR_BALLOON
        giveitem ITEM_SUN_STONE
        giveitem ITEM_UTILITY_UMBRELLA
        giveitem ITEM_HARD_STONE
        giveitem ITEM_SMOOTH_ROCK
        call Nettux_RandomWildMon
        closemessage
        end
