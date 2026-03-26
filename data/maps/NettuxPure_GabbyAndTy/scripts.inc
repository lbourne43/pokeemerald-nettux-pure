NettuxPure_GabbyAndTy_MapScripts::
	.byte 0

NettuxPure_GabbyAndTy_Battle::
        trainerbattle_single TRAINER_GABBY_AND_TY_1, GabbyAndTy_Text_TyPreFirstBattle, GabbyAndTy_Text_TyDefeatFirstTime, NettuxPure_GabbyAndTy_Complete
        msgbox GabbyAndTy_Text_TyDefeatFirstTime, MSGBOX_AUTOCLOSE
        end

NettuxPure_GabbyAndTy_Complete::
        addmoney 20000
        call Nettux_RandomWildMon
        closemessage
        setflag FLAG_NETTUX_FINISH_GABBY_AND_TY
        end

