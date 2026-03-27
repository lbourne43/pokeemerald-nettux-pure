NettuxPure_Gauntlet11_MapScripts::
	.byte 0

NettuxPure_Gauntlet11_Complete::
        addmoney 10000
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_EJECT_BUTTON
        giveitem ITEM_MIRACLE_SEED
        giveitem ITEM_RINDO_BERRY
        giveitem ITEM_YACHE_BERRY
        giveitem ITEM_CHILAN_BERRY
        call Nettux_RandomWildMon
        closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_11
        end

NettuxPure_Gauntlet11_EventScript_Bernie::
        trainerbattle_single TRAINER_BERNIE_1, Route114_Text_BernieIntro, Route114_Text_BernieDefeat,, NettuxPure_Gauntlet11_Complete
        msgbox Route114_Text_BerniePostBattle, MSGBOX_AUTOCLOSE
        end
