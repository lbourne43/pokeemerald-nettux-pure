NettuxPure_TateAndLiza_MapScripts::
        map_script MAP_SCRIPT_ON_FRAME_TABLE, NettuxPure_TateAndLiza_OnFrame
        map_script MAP_SCRIPT_ON_LOAD, NettuxPure_TateAndLiza_OnLoad
        .byte 0

NettuxPure_TateAndLiza_OnLoad:
        special nettuxSetPermanentTrickRoom
        end

NettuxPure_TateAndLiza_OnFrame:
        map_script_2 VAR_TEMP_1, 0, NettuxPure_TateAndLiza
        .2byte 0

NettuxPure_TateAndLizaDefeated::
        message MossdeepCity_Gym_Text_ReceivedMindBadge
        waitmessage
        call Common_EventScript_PlayGymBadgeFanfare
        msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
        setflag FLAG_DEFEATED_MOSSDEEP_GYM
        setflag FLAG_BADGE07_GET
        goto NettuxPure_TateAndLiza_EventScript_GiveTM
        end

NettuxPure_TateAndLiza_EventScript_GiveTM::
        giveitem ITEM_TM_CALM_MIND
        goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
        setflag FLAG_RECEIVED_TM_CALM_MIND
        msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
        call Nettux_RandomWildMon
        closemessage
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_TateAndLiza_Movement_LeaveBattle
        waitmovement 0
        releaseall
        warp MAP_NETTUX_PURE_TATE_AND_LIZA_ENCOUNTER, 0
        end

NettuxPure_TateAndLiza::
        setvar VAR_TEMP_1, 1
        lockall
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_TateAndLiza_Movement_ToBattle
        waitmovement 0
        releaseall
        msgbox MossdeepCity_Gym_Text_TateAndLizaIntro, MSGBOX_DEFAULT
        trainerbattle_no_intro TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaDefeat
        goto NettuxPure_TateAndLizaDefeated
        end

NettuxPure_TateAndLiza_Movement_ToBattle:
        walk_left
        walk_left
        walk_down
        walk_down
        face_right
        step_end

NettuxPure_TateAndLiza_Movement_LeaveBattle:
        walk_up
        walk_up
        walk_right
        walk_right
        face_up
        step_end
