NettuxPure_Gauntlet16_MapScripts::
	.byte 0

NettuxPure_Gauntlet16_Complete::
        setflag FLAG_NETTUX_FINISH_GAUNTLET_16
        addmoney 16000
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_CHOICE_SPECS
        giveitem ITEM_CHOICE_BAND
        giveitem ITEM_CHOICE_SCARF
        giveitem ITEM_WACAN_BERRY
        giveitem ITEM_BABIRI_BERRY
        giveitem ITEM_KEE_BERRY
        giveitem ITEM_LEPPA_BERRY
        call Nettux_RandomWildMon
        closemessage
        end

NettuxPure_Gauntlet16_Jeffrey::
        trainerbattle_single TRAINER_JEFFREY_1, Route120_Text_JeffreyIntro, Route120_Text_JeffreyDefeat, NettuxPure_Gauntlet16_Complete
        msgbox Route120_Text_JeffreyPostBattle, MSGBOX_AUTOCLOSE
        end
