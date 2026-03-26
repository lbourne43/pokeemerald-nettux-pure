NettuxPure_Gauntlet14_MapScripts::
	.byte 0

NettuxPure_Gauntlet14_Rachel::
        trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat, NettuxPure_Gauntlet14_Complete
        msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet14_Complete::
        addmoney 14000
        call Nettux_RandomWildMon
        closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_14
        end
