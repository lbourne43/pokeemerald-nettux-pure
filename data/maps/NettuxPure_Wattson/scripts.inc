NettuxPure_Wattson_MapScripts::
        map_script MAP_SCRIPT_ON_FRAME_TABLE, NettuxPure_Wattson_OnFrame
        map_script MAP_SCRIPT_ON_LOAD, NettuxPure_Wattson_OnLoad
        .byte 0

NettuxPure_Wattson_OnLoad:
        special nettuxSetPermanentThunder
	end

NettuxPure_Wattson_OnFrame:
        map_script_2 VAR_TEMP_1, 0, NettuxPure_Wattson
	.2byte 0

NettuxPure_WattsonDefeated::
        message MauvilleCity_Gym_Text_ReceivedDynamoBadge
        waitmessage
        call Common_EventScript_PlayGymBadgeFanfare
        msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
        setflag FLAG_DEFEATED_MAUVILLE_GYM
        setflag FLAG_BADGE03_GET
        goto NettuxPure_Wattson_EventScript_GiveTM
        end

NettuxPure_Wattson_EventScript_GiveTM::
        giveitem ITEM_TM_THUNDERBOLT
        goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
        setflag FLAG_RECEIVED_TM_SHOCK_WAVE
        msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
        call Nettux_RandomWildMon
        closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Wattson_Movement_LeaveBattle
        waitmovement 0
        releaseall
	warp MAP_NETTUX_PURE_BASE, 1
        end

NettuxPure_Wattson::
	setvar VAR_TEMP_1, 1
	lockall
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Wattson_Movement_ToBattle
        waitmovement 0
        releaseall
        msgbox MauvilleCity_Gym_Text_WattsonIntro, MSGBOX_DEFAULT
        trainerbattle_no_intro TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonDefeat
	goto NettuxPure_WattsonDefeated
        end

NettuxPure_Wattson_Movement_ToBattle:
        walk_left
        walk_left
        walk_down
        walk_down
        face_right
        step_end

NettuxPure_Wattson_Movement_LeaveBattle:
        walk_up
        walk_up
        walk_right
        walk_right
	face_up
        step_end
