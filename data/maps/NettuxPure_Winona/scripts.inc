NettuxPure_Winona_MapScripts::
        map_script MAP_SCRIPT_ON_FRAME_TABLE, NettuxPure_Winona_OnFrame
        .byte 0

NettuxPure_Winona_OnFrame:
        map_script_2 VAR_TEMP_1, 0, NettuxPure_Winona
        .2byte 0

NettuxPure_WinonaDefeated::
        message FortreeCity_Gym_Text_ReceivedFeatherBadge
        waitmessage
        call Common_EventScript_PlayGymBadgeFanfare
        msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
        setflag FLAG_DEFEATED_FORTREE_GYM
        setflag FLAG_BADGE06_GET
        goto NettuxPure_Winona_EventScript_GiveTM
        end

NettuxPure_Winona_EventScript_GiveTM::
        giveitem ITEM_TM_AERIAL_ACE
        goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
        setflag FLAG_RECEIVED_TM_AERIAL_ACE
        msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
        call Nettux_RandomWildMon
        closemessage
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Winona_Movement_LeaveBattle
        waitmovement 0
        releaseall
        warp MAP_NETTUX_PURE_WINONA_ENCOUNTER, 0
        end

NettuxPure_Winona::
        setvar VAR_TEMP_1, 1
        lockall
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Winona_Movement_ToBattle
        waitmovement 0
        releaseall
        msgbox FortreeCity_Gym_Text_WinonaIntro, MSGBOX_DEFAULT
        trainerbattle_no_intro TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaDefeat
        goto NettuxPure_WinonaDefeated
        end

NettuxPure_Winona_Movement_ToBattle:
        walk_left
        walk_left
        walk_down
        walk_down
        face_right
        step_end

NettuxPure_Winona_Movement_LeaveBattle:
        walk_up
        walk_up
        walk_right
        walk_right
        face_up
        step_end
