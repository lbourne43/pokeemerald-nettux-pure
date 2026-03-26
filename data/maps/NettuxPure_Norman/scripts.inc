NettuxPure_Norman_MapScripts::
        map_script MAP_SCRIPT_ON_FRAME_TABLE, NettuxPure_Norman_OnFrame
        .byte 0

NettuxPure_Norman_OnFrame:
        map_script_2 VAR_TEMP_1, 0, NettuxPure_Norman
        .2byte 0

NettuxPure_NormanDefeated::
        message PetalburgCity_Gym_Text_ReceivedBalanceBadge
        waitmessage
        call Common_EventScript_PlayGymBadgeFanfare
        msgbox PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis, MSGBOX_DEFAULT
        setflag FLAG_DEFEATED_PETALBURG_GYM
        setflag FLAG_BADGE05_GET
        goto NettuxPure_Norman_EventScript_GiveTM
        end

NettuxPure_Norman_EventScript_GiveTM::
        giveitem ITEM_TM_FACADE
        goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
        setflag FLAG_RECEIVED_TM_FACADE
        msgbox PetalburgCity_Gym_Text_ExplainFacade, MSGBOX_DEFAULT
        giveitem ITEM_POKE_BALL
        giveitem ITEM_HM_SURF
        closemessage
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Norman_Movement_LeaveBattle
        waitmovement 0
        releaseall
        warp MAP_NETTUX_PURE_NORMAN_ENCOUNTERS, 0
        end

NettuxPure_Norman::
        setvar VAR_TEMP_1, 1
        lockall
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Norman_Movement_ToBattle
        waitmovement 0
        releaseall
        msgbox PetalburgCity_Gym_Text_NormanIntro, MSGBOX_DEFAULT
        trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanDefeat
        goto NettuxPure_NormanDefeated
        end

NettuxPure_Norman_Movement_ToBattle:
        walk_left
        walk_left
        walk_down
        walk_down
        face_right
        step_end

NettuxPure_Norman_Movement_LeaveBattle:
        walk_up
        walk_up
        walk_right
        walk_right
        face_up
        step_end
