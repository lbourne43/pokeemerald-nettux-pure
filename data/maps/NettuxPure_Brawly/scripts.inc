NettuxPure_Brawly_MapScripts::
        map_script MAP_SCRIPT_ON_FRAME_TABLE, NettuxPure_Brawly_OnFrame
	.byte 0

NettuxPure_Brawly_OnFrame:
        map_script_2 VAR_TEMP_1, 0, NettuxPure_Brawly
	.2byte 0

NettuxPure_BrawlyDefeated::
        message DewfordTown_Gym_Text_ReceivedKnuckleBadge
        waitmessage
        call Common_EventScript_PlayGymBadgeFanfare
        msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
        setflag FLAG_DEFEATED_DEWFORD_GYM
        setflag FLAG_BADGE02_GET
        goto NettuxPure_Brawly_EventScript_GiveTM
        end

NettuxPure_Brawly_EventScript_GiveTM::
        giveitem ITEM_TM_BULK_UP
        goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
        setflag FLAG_RECEIVED_TM_BULK_UP
        msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL
        closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Brawly_Movement_LeaveBattle
        waitmovement 0
        releaseall
	warp MAP_NETTUX_PURE_BRAWLY_ENCOUNTER, 0
        end

NettuxPure_Brawly::
	setvar VAR_TEMP_1, 1
	lockall
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Brawly_Movement_ToBattle
        waitmovement 0
        releaseall
        msgbox DewfordTown_Gym_Text_BrawlyIntro, MSGBOX_DEFAULT
        trainerbattle_no_intro TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyDefeat
	goto NettuxPure_BrawlyDefeated
        end

NettuxPure_Brawly_Movement_ToBattle:
        walk_down
        walk_down
        walk_left
        walk_left
        walk_down
        face_right
        step_end

NettuxPure_Brawly_Movement_LeaveBattle:
        walk_up
        walk_right
        walk_right
        walk_up
        walk_up
        walk_up
        step_end
