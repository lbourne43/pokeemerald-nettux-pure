NettuxPure_Gauntlet18_MapScripts::
	.byte 0

NettuxPure_Gauntlet18_William::
        trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat, NettuxPure_Gauntlet18_Complete
        msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet18_Complete::
        setflag FLAG_NETTUX_FINISH_GAUNTLET_18
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_SPELL_TAG
        giveitem ITEM_IRON_BALL
        giveitem ITEM_BLACK_SLUDGE
        giveitem ITEM_CHESTO_BERRY
        giveitem ITEM_RAWST_BERRY
        addmoney 18000
        call Nettux_RandomWildMon
        closemessage
        end
