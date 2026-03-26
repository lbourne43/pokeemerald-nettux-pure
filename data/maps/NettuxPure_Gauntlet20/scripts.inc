NettuxPure_Gauntlet20_MapScripts::
	.byte 0

NettuxPure_Gauntlet20_Olivia::
        trainerbattle_single TRAINER_OLIVIA, SootopolisCity_Gym_B1F_Text_OliviaIntro, SootopolisCity_Gym_B1F_Text_OliviaDefeat, NettuxPure_Gauntlet20_Complete
        msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet20_Complete::
        addmoney 20000
        giveitem ITEM_POKE_BALL
        closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_20
        end
