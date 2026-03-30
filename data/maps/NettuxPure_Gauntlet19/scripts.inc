NettuxPure_Gauntlet19_MapScripts::
	.byte 0

NettuxPure_Gauntlet19_Auron::
        trainerbattle_single TRAINER_AURON, Route125_Text_AuronIntro, Route125_Text_AuronDefeat, NettuxPure_Gauntlet19_Complete
        msgbox Route125_Text_AuronPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet19_Complete::
        setflag FLAG_NETTUX_FINISH_GAUNTLET_19
        addmoney 19000
        call Nettux_RandomWildMon
        closemessage
        end
