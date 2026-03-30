NettuxPure_Gauntlet17_MapScripts::
	.byte 0

NettuxPure_Gauntlet17_Walter::
        trainerbattle_single TRAINER_WALTER_1, Route121_Text_WalterIntro, Route121_Text_WalterDefeat, NettuxPure_Gauntlet17_Complete
	msgbox Route121_Text_WalterPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet17_Complete::
        setflag FLAG_NETTUX_FINISH_GAUNTLET_17
        addmoney 17000
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_PP_MAX
        giveitem ITEM_DRAGON_FANG
        giveitem ITEM_METAL_COAT
        giveitem ITEM_PERSIM_BERRY
        giveitem ITEM_ASPEAR_BERRY
        call Nettux_RandomWildMon
        closemessage
        end
