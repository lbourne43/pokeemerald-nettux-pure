NettuxPure_Flannery_MapScripts::
        map_script MAP_SCRIPT_ON_FRAME_TABLE, NettuxPure_Flannery_OnFrame
        map_script MAP_SCRIPT_ON_LOAD, NettuxPure_Flannery_OnLoad
        .byte 0

NettuxPure_Flannery_OnLoad:
        special nettuxSetPermanentSun
	end

NettuxPure_Flannery_OnFrame:
        map_script_2 VAR_TEMP_1, 0, NettuxPure_Flannery
        .2byte 0

NettuxPure_FlanneryDefeated::
        message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
        waitmessage
        call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
        setflag FLAG_DEFEATED_LAVARIDGE_GYM
        setflag FLAG_BADGE04_GET
        goto NettuxPure_Flannery_EventScript_GiveTM
        end

NettuxPure_Flannery_EventScript_GiveTM::
        giveitem ITEM_TM_FLAMETHROWER
        goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
        setflag FLAG_RECEIVED_TM_OVERHEAT
        msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
        call Nettux_RandomWildMon
        closemessage
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Flannery_Movement_LeaveBattle
        waitmovement 0
        releaseall
        warp MAP_NETTUX_PURE_FLANNERY_ENCOUNTERS, 0
        end

NettuxPure_Flannery::
        setvar VAR_TEMP_1, 1
        lockall
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Flannery_Movement_ToBattle
        waitmovement 0
        releaseall
        msgbox LavaridgeTown_Gym_1F_Text_FlanneryIntro, MSGBOX_DEFAULT
        trainerbattle_no_intro TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryDefeat
        goto NettuxPure_FlanneryDefeated
        end

NettuxPure_Flannery_Movement_ToBattle:
        walk_left
        walk_left
        walk_down
        walk_down
        face_right
        step_end

NettuxPure_Flannery_Movement_LeaveBattle:
        walk_up
        walk_up
        walk_right
        walk_right
        face_up
        step_end
