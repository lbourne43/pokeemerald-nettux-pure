NettuxPure_Gauntlet15_MapScripts::
	.byte 0

NettuxPure_Gauntlet15_Complete::
        addmoney 15000
        giveitem ITEM_POKE_BALL
        closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_15
        end

NettuxPure_Gauntlet15_Darius::
        trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat, NettuxPure_Gauntlet15_Complete
        msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
        end
