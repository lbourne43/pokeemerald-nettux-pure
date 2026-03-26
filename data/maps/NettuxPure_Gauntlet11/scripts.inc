NettuxPure_Gauntlet11_MapScripts::
	.byte 0

NettuxPure_Gauntlet11_Complete::
        addmoney 10000
        call Nettux_RandomWildMon
        closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_11
        end

NettuxPure_Gauntlet11_EventScript_Bernie::
        trainerbattle_single TRAINER_BERNIE_1, Route114_Text_BernieIntro, Route114_Text_BernieDefeat,, NettuxPure_Gauntlet11_Complete
        msgbox Route114_Text_BerniePostBattle, MSGBOX_AUTOCLOSE
        end
