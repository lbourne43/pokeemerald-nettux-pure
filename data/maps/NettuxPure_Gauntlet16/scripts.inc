NettuxPure_Gauntlet16_MapScripts::
	.byte 0

NettuxPure_Gauntlet16_Complete::
        addmoney 16000
        giveitem ITEM_POKE_BALL
        closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_16
        end

NettuxPure_Gauntlet16_Jeffrey::
        trainerbattle_single TRAINER_JEFFREY_1, Route120_Text_JeffreyIntro, Route120_Text_JeffreyDefeat, NettuxPure_Gauntlet16_Complete
        msgbox Route120_Text_JeffreyPostBattle, MSGBOX_AUTOCLOSE
        end
