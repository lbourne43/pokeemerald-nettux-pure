NettuxPure_Gauntlet17_MapScripts::
	.byte 0

NettuxPure_Gauntlet17_Walter::
        trainerbattle_single TRAINER_WALTER_1, Route121_Text_WalterIntro, Route121_Text_WalterDefeat, NettuxPure_Gauntlet17_Complete
	msgbox Route121_Text_WalterPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet17_Complete::
        addmoney 17000
        call Nettux_RandomWildMon
        closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_17
        end
