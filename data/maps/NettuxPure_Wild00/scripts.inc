.set LOCALID_RED, 1

NettuxPure_Wild00_MapScripts::
        .byte 0

NettuxPure_Wild00_EventScript_Red::
	setvar VAR_TEMP_0, 1
  goto_if_unset FLAG_NETTUX_DEFEATED_RED_1, NettuxPure_Wild00_EventScript_RedBattle
	end

NettuxPure_Wild00_EventScript_RedBattle::
	addobject LOCALID_RED
	clearflag FLAG_NETTUX_HIDE_RED_1
        applymovement LOCALID_RED, NettuxPure_Wild00_Movement_RedApproaches
	waitmovement LOCALID_RED
        turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox NettuxPure_Wild00_Text_RedIntro, MSGBOX_DEFAULT
        trainerbattle_no_intro TRAINER_RED, NettuxPure_Wild00_Text_RedDefeat
	msgbox NettuxPure_Wild00_Text_RedDefeat, MSGBOX_DEFAULT
	closemessage
	setrespawn HEAL_LOCATION_NETTUX_PURE_BASE
	giveitem ITEM_HEART_SCALE
        applymovement LOCALID_RED, NettuxPure_Wild00_Movement_RedLeaves
	waitmovement LOCALID_RED
	setflag FLAG_NETTUX_DEFEATED_RED_1
	setflag FLAG_NETTUX_HIDE_RED_1
	removeobject LOCALID_RED
	closemessage
        end

NettuxPure_WildArea00_EventScript_Encounters::
        msgbox NettuxPure_Wild00_Text_Encounters, MSGBOX_DEFAULT
        closemessage
        end

NettuxPure_WildArea00_EventScript_ChosenStarterCheck::
        goto_if_unset FLAG_NETTUX_CHOSE_STARTER NettuxPure_WildArea00_EventScript_ChooseStarterPrompt
	      end

NettuxPure_WildArea00_EventScript_ChooseStarterPrompt::
       	msgbox NettuxPure_WildArea00_Text_ChooseStarter, MSGBOX_DEFAULT
        closemessage
        applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
       	waitmovement 0
      	end


NettuxPure_Wild00_Text_RedIntro:
        .string "...................$"

NettuxPure_Wild00_Text_RedDefeat:
        .string "...................$"

NettuxPure_Wild00_Movement_RedApproaches:
        walk_right
        walk_right
        walk_right
        walk_right
        walk_right
        walk_right
        walk_right
        walk_right
        walk_right
        walk_up
      	step_end

NettuxPure_Wild00_Movement_RedLeaves:
        walk_down
        walk_left
        walk_left
        walk_left
        walk_left
        walk_left
        walk_left
        walk_left
        walk_left
        walk_left
        step_end

NettuxPure_WildArea00_Text_ChooseStarter:
        .string "Head to the lab and get a POKéMON!$"

NettuxPure_Wild00_Text_Encounters:
        .string "POKéMON observed in this area:\l"
        .string "Phanpy\l"
        .string "Starly\l"
        .string "Maschiff\l"
        .string "Skorupi\l"
        .string "Timburr\l"
        .string "Shinx\l"
        .string "Jigglypuff\l"
        .string "Drifloon\l"
        .string "Rolycoly\l"
        .string "Snover$"
