NettuxPure_Wally2_MapScripts::
	.byte 0

NettuxPure_Wally2_Wally2::
        trainerbattle_single TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, VictoryRoad_1F_Text_WallyEntranceDefeat, NettuxPure_Wally2_Complete
        msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Wally2_Complete::
        giveitem ITEM_POKE_BALL
        addmoney 12000
        setflag FLAG_NETTUX_FINISH_WALLY_2
        closemessage
        end
