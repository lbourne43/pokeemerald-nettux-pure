NettuxPure_Gauntlet13_MapScripts::
	.byte 0

NettuxPure_Gauntlet13_Complete::
        addmoney 13000
        call Nettux_RandomWildMon
        closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_13
        end

NettuxPure_Gauntlet13_Jody::
        trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyIntro, PetalburgCity_Gym_Text_JodyDefeat, NettuxPure_Gauntlet13_Complete
        msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
        end
