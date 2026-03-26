.set LOCALID_MAXIE, 1

NettuxPure_Maxie1_MapScripts::
        map_script MAP_SCRIPT_ON_FRAME_TABLE, NettuxPure_Maxie1_OnFrame
        .byte 0

NettuxPure_Maxie1_OnFrame:
        map_script_2 VAR_TEMP_1, 0, NettuxPure_Magma1_EventScript_Maxie
        .2byte 0

NettuxPure_Magma1_EventScript_Maxie::
        setvar VAR_TEMP_1, 1
        lockall
        special nettuxSetPermanentMagmaStorm
        lockall
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Maxie1_Movement_PlayerToBattle
        waitmovement 0
        releaseall
        msgbox NettuxPure_Magma1_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
        applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
        waitmovement 0
        playse SE_PIN
        applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
        waitmovement 0
        applymovement LOCALID_MAXIE, Common_Movement_Delay48
        waitmovement 0
        msgbox NettuxPure_Magma1_Text_MaxieIntro, MSGBOX_DEFAULT
        trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, NettuxPure_Magma1_Text_MaxieDefeat
        msgbox NettuxPure_Magma1_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
        closemessage
        delay 30
        fadescreen FADE_TO_BLACK
        removeobject LOCALID_MAXIE
        fadescreen FADE_FROM_BLACK
        clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
        setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
        releaseall
        goto NettuxPure_Maxie1_Complete
        end

NettuxPure_Maxie1_Complete::
        addmoney 10000
        call Nettux_RandomWildMon
        closemessage
        setflag FLAG_NETTUX_FINISH_MAXIE1
        end

NettuxPure_Magma1_EventScript_MeteoriteMachine::
        lockall
        goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, NettuxPure_Magma1_EventScript_MachineOn
        goto_if_set FLAG_RECEIVED_METEORITE, NettuxPure_Magma1_EventScript_MachineOff
        msgbox NettuxPure_Magma1_Text_RemoveTheMeteorite, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Magma1_EventScript_LeaveMeteoriteAlone
        msgbox NettuxPure_Magma1_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
        giveitem ITEM_METEORITE
        goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
        setflag FLAG_RECEIVED_METEORITE
        releaseall
        end

NettuxPure_Magma1_EventScript_LeaveMeteoriteAlone::
        msgbox NettuxPure_Magma1_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
        releaseall
        end

NettuxPure_Magma1_EventScript_MachineOff::
        msgbox NettuxPure_Magma1_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
        releaseall
        end

NettuxPure_Magma1_EventScript_MachineOn::
        msgbox NettuxPure_Magma1_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
        releaseall
        end

NettuxPure_Magma1_Text_MaxieIntro:
        .string "MAXIE: Hm?\n"
        .string "Who are you?\p"
        .string "… … … … … …\n"
        .string "… … … … … …\p"
        .string "I'd heard ARCHIE bemoaning a child\n"
        .string "who's been meddling in TEAM AQUA's\l"
        .string "affairs.\p"
        .string "It must be you he meant.\p"
        .string "Humph! So you're thinking of\n"
        .string "interfering with us, TEAM MAGMA?\p"
        .string "Now you listen.\n"
        .string "Long ago, living things used the\l"
        .string "land to live and grow.\p"
        .string "That is why land is all important!\n"
        .string "It is the cradle of all!\p"
        .string "That is why TEAM MAGMA is dedicated\n"
        .string "to the expansion of the land mass.\p"
        .string "It is for further advancement of\n"
        .string "humankind and POKéMON!\p"
        .string "And for that, we need the power of\n"
        .string "what sleeps within this mountain…\p"
        .string "Oh! There was no need for you to\n"
        .string "learn that much.\p"
        .string "But, no matter!\n"
        .string "I'll teach you the consequences of\l"
        .string "meddling in our grand design!$"

NettuxPure_Magma1_Text_MaxieDefeat:
        .string "What?!\p"
        .string "I, MAXIE, was caught off guard?!$"

NettuxPure_Magma1_Text_MaxieYouHaventSeenLastOfMagma:
        .string "MAXIE: But, enough.\n"
        .string "I will back off this time.\p"
        .string "But don't think that this is the last\n"
        .string "you've seen of TEAM MAGMA.\p"
        .string "Fufufu…\p"
        .string "Even without the METEORITE, if we\n"
        .string "obtain that ORB… Fufufu…$"

NettuxPure_Maxie1_Movement_PlayerToBattle:
        walk_right
        walk_right
        walk_right
        walk_right
        step_end
