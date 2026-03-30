NettuxPure_Gauntlet14_MapScripts::
	.byte 0

NettuxPure_Gauntlet14_Rachel::
        trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat, NettuxPure_Gauntlet14_Complete
        msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet14_Complete::
        setflag FLAG_NETTUX_FINISH_GAUNTLET_14
        addmoney 14000
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_POWER_HERB
        giveitem ITEM_WISE_GLASSES
        giveitem ITEM_THROAT_SPRAY
        giveitem ITEM_WEAKNESS_POLICY
        giveitem ITEM_LEAF_STONE
        giveitem ITEM_COLBUR_BERRY
        giveitem ITEM_BABIRI_BERRY
        giveitem ITEM_COBA_BERRY
        giveitem ITEM_SITRUS_BERRY
        giveitem ITEM_GANLON_BERRY
        giveitem ITEM_KEBIA_BERRY
        giveitem ITEM_HABAN_BERRY
        call Nettux_RandomWildMon
        closemessage
        end
