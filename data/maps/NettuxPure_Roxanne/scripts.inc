NettuxPure_Roxanne_MapScripts::
        map_script MAP_SCRIPT_ON_FRAME_TABLE, NettuxPure_Roxanne_OnFrame
        map_script MAP_SCRIPT_ON_LOAD, NettuxPure_Roxanne_OnLoad
        .byte 0

NettuxPure_Roxanne_OnLoad:
        special nettuxSetPermanentSand
	end

NettuxPure_Roxanne_OnFrame:
        map_script_2 VAR_TEMP_1, 0, NettuxPure_Roxanne
	.2byte 0

NettuxPure_RoxanneDefeated::
        message RustboroCity_Gym_Text_ReceivedStoneBadge
        waitmessage
        call Common_EventScript_PlayGymBadgeFanfare
        msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
        setflag FLAG_DEFEATED_RUSTBORO_GYM
        setflag FLAG_BADGE01_GET
        goto NettuxPure_Roxanne_EventScript_GiveRockTomb
        end

NettuxPure_Roxanne_EventScript_GiveRockTomb::
        giveitem ITEM_TM_ROCK_TOMB
        goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
        setflag FLAG_RECEIVED_TM_ROCK_TOMB
        msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
        giveitem ITEM_POKE_BALL
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Roxanne_Movement_LeaveBattle
        waitmovement 0
        releaseall
	warp MAP_NETTUX_PURE_ROXANNE_ENCOUNTER, 0
        end

NettuxPure_Roxanne::
	setvar VAR_TEMP_1, 1
	lockall
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Roxanne_Movement_ToBattle
        waitmovement 0
        releaseall
        msgbox NettuxPure_Roxanne_Text_RoxanneIntro, MSGBOX_DEFAULT
        trainerbattle_no_intro TRAINER_ROXANNE_1, NettuxPure_Roxanne_Text_RoxanneDefeat
	goto NettuxPure_RoxanneDefeated
        end

NettuxPure_Roxanne_Movement_ToBattle:
        walk_down
        walk_down
        walk_left
        walk_left
        walk_down
        walk_down
	face_right
        step_end

NettuxPure_Roxanne_Movement_LeaveBattle:
        walk_up
        walk_up
        walk_right
        walk_right
        walk_up
        walk_up
        walk_up
        step_end

NettuxPure_Roxanne_Text_RoxanneIntro:
        .string "Hello, I am ROXANNE, the RUSTBORO\n"
        .string "POKéMON GYM LEADER.\p"
        .string "I became a GYM LEADER so that I might\n"
        .string "apply what I learned at the POKéMON\l"
        .string "TRAINER'S SCHOOL in battle.\p"
        .string "Would you kindly demonstrate how you\n"
        .string "battle, and with which POKéMON?$"

NettuxPure_Roxanne_Text_RoxanneDefeat:
        .string "So…\n"
        .string "I lost…\p"
        .string "It seems that I still have much more\n"
        .string "to learn…\p"
        .string "I understand.\p"
        .string "The POKéMON LEAGUE's rules state\n"
        .string "that TRAINERS are to be given this\l"
        .string "if they defeat a GYM LEADER.\p"
        .string "Please accept the official POKéMON\n"
        .string "LEAGUE STONE BADGE.$"
