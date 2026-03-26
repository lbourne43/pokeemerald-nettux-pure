NettuxPure_Gauntlet12_MapScripts::
	.byte 0

NettuxPure_Gauntlet12_Complete::
        addmoney 10000
        giveitem ITEM_POKE_BALL
        closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_12
        end

NettuxPure_Gauntlet12_EventScript_Shelby::
        trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, NettuxPure_Gauntlet12_Complete
        msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_AUTOCLOSE
        end
