NettuxPure_Gauntlet18_MapScripts::
	.byte 0

NettuxPure_Gauntlet18_William::
        trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat, NettuxPure_Gauntlet18_Complete
        msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet18_Complete::
        addmoney 18000
        giveitem ITEM_POKE_BALL
        closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_18
        end
