NettuxPure_Gauntlet19_MapScripts::
	.byte 0

NettuxPure_Gauntlet19_Auron::
        trainerbattle_single TRAINER_AURON, Route125_Text_AuronIntro, Route125_Text_AuronDefeat, NettuxPure_Gauntlet19_Complete
        msgbox Route125_Text_AuronPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet19_Complete::
        addmoney 19000
        giveitem ITEM_POKE_BALL
        closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_19
        end
