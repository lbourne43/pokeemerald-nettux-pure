NettuxPure_Wally3_MapScripts::
	.byte 0

NettuxPure_Wally3_Wally::
        trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat, NettuxPure_Wally3_Complete
        msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Wally3_Complete::
        giveitem ITEM_POKE_BALL
        addmoney 20000
        setflag FLAG_NETTUX_FINISH_WALLY_3
        closemessage
        end
