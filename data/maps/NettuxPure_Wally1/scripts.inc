.set LOCALID_WALLY, 1

NettuxPure_Wally1_MapScripts::
	.byte 0

NettuxPure_Wally1_EventScript_Wally::
        setvar VAR_TEMP_0, 1
        goto_if_unset FLAG_NETTUX_FINISH_WALLY_1, NettuxPure_Wally1_EventScript_BattleWally
        end

NettuxPure_Wally1_EventScript_BattleWally::
        addobject LOCALID_WALLY
        clearflag FLAG_NETTUX_HIDE_WALLY_1
        applymovement LOCALID_WALLY, NettuxPure_Wally1_Movement_WallyApproaches
        waitmovement LOCALID_WALLY
        turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
        msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
        trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, NettuxPure_Wally1_Text_WallyDefeat
        msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
        giveitem ITEM_MEGA_RING
        giveitem ITEM_POKE_BALL
        addmoney 7500
        applymovement LOCALID_WALLY, NettuxPure_Wally1_Movement_WallyLeaves
        waitmovement LOCALID_WALLY
        setflag FLAG_NETTUX_FINISH_WALLY_1
        setflag FLAG_NETTUX_HIDE_WALLY_1
        removeobject LOCALID_WALLY
        closemessage
        end

NettuxPure_Wally1_Movement_WallyApproaches:
        walk_up
        walk_up
        walk_up
        walk_up
        walk_up
        walk_right
        walk_right
        walk_up
        walk_up
        walk_up
        walk_up
        step_end

NettuxPure_Wally1_Movement_WallyLeaves:
        walk_down
        walk_down
        walk_down
        walk_down
        walk_left
        walk_left
        walk_down
        walk_down
        walk_down
        walk_down
        walk_down
        step_end

NettuxPure_Wally1_Text_WallyDefeat:
        .string "Damn.$"
