.set LOCALID_RIVAL, 8

NettuxPure_Gauntlet2_MapScripts::
        map_script MAP_SCRIPT_ON_TRANSITION, NettuxPure_Gauntlet2_OnTransition
        .byte 0

NettuxPure_Gauntlet2_OnTransition:
        call Common_EventScript_SetupRivalGfxId
	end

NettuxPure_EventScript_Rival1::
        lockall
        checkplayergender
        goto_if_eq VAR_RESULT, MALE, NettuxPure_EventScript_Rival1_F
        goto_if_eq VAR_RESULT, FEMALE, NettuxPure_EventScript_Rival1_M
        end

NettuxPure_EventScript_Rival1_M:
	trainerbattle_single TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanRoute103Pokemon, Route103_Text_BrendanDefeated, NettuxPure_Gauntlet2_EventScript_Complete
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
	end

NettuxPure_EventScript_Rival1_F::
	trainerbattle_single TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayRoute103Pokemon, Route103_Text_MayDefeated, NettuxPure_Gauntlet2_EventScript_Complete
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
	end

NettuxPure_EventScript_RouteSignPetalburg::
	msgbox Route104_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

NettuxPure_EventScript_Boy2::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_BULLET_SEED, NettuxPure_EventScript_ReceivedBulletSeed
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_BULLET_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_BULLET_SEED
	release
	end

NettuxPure_EventScript_ReceivedBulletSeed::
	msgbox Route104_Text_TMsAreOneTimeUse, MSGBOX_DEFAULT
	release
	end

NettuxPure_Gauntlet2_EventScript_Complete::
        setflag FLAG_NETTUX_FINISH_GAUNTLET_2
        addmoney 3000
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_WHITE_HERB
        giveitem ITEM_SHARP_BEAK
        giveitem ITEM_CHERI_BERRY
        giveitem ITEM_ORAN_BERRY
        giveitem ITEM_CHESTO_BERRY
       	closemessage
        call Nettux_RandomWildMon
        applymovement LOCALID_RIVAL, NettuxPure_Gauntlet2_Movement_RivalLeaves
       	waitmovement LOCALID_RIVAL
	      removeobject LOCALID_RIVAL
        end

NettuxPure_Gauntlet2_EventScript_Encounters::
        msgbox NettuxPure_Gauntlet2_Text_Encounters, MSGBOX_DEFAULT
        closemessage
        end

NettuxPure_Gauntlet2_Text_Encounters:
        .string "POKéMON observed in this area:\l"
        .string "Shroomish\l"
        .string "Nymble\l"
        .string "Ralts\l"
        .string "Bellsprout\l"
        .string "Taillow\l"
        .string "Pikachu\l"
        .string "Hoot Hoot\l"
        .string "Taillow\l"
        .string "Spinarak\l"
        .string "Weedle$"

NettuxPure_Gauntlet2_Movement_RivalLeaves:
        walk_right
        walk_right
        walk_right
        walk_right
        walk_right
        walk_right
        walk_right
        walk_right
        walk_right
	step_end
