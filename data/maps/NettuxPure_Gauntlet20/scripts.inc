NettuxPure_Gauntlet20_MapScripts::
	.byte 0

NettuxPure_Gauntlet20_Olivia::
        trainerbattle_single TRAINER_OLIVIA, SootopolisCity_Gym_B1F_Text_OliviaIntro, SootopolisCity_Gym_B1F_Text_OliviaDefeat, NettuxPure_Gauntlet20_Complete
        msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet20_Complete::
        setflag FLAG_NETTUX_FINISH_GAUNTLET_20
        addmoney 20000
        call Nettux_RandomWildMon
        closemessage
        end
