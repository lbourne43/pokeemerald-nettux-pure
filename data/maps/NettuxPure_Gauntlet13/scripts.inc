NettuxPure_Gauntlet13_MapScripts::
	.byte 0

NettuxPure_Gauntlet13_Complete::
        setflag FLAG_NETTUX_FINISH_GAUNTLET_13
        addmoney 13000
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_ASSAULT_VEST
        call Nettux_RandomWildMon
        closemessage
        end

NettuxPure_Gauntlet13_Jody::
        trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyIntro, PetalburgCity_Gym_Text_JodyDefeat, NettuxPure_Gauntlet13_Complete
        msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
        end
