
.set LOCALID_RIVAL, 2

NettuxPure_Gauntlet5_MapScripts::
        map_script MAP_SCRIPT_ON_TRANSITION, NettuxPure_Gauntlet5_OnTransition
        .byte 0

NettuxPure_Gauntlet5_OnTransition:
        call Common_EventScript_SetupRivalGfxId
        end

NettuxPure_EventScript_Rival2::
        lockall
        checkplayergender
        goto_if_eq VAR_RESULT, MALE, NettuxPure_EventScript_Rival2_F
        goto_if_eq VAR_RESULT, FEMALE, NettuxPure_EventScript_Rival2_M
        end

NettuxPure_EventScript_Rival2_M:
        trainerbattle_single TRAINER_BRENDAN_ROUTE_103_MUDKIP, RustboroCity_Text_OhComeOnBattleMe, RustboroCity_Text_BrendanDefeat, NettuxPure_Gauntlet5_EventScript_Complete
        msgbox RustboroCity_Text_BrendanDefeat, MSGBOX_DEFAULT
        end

NettuxPure_EventScript_Rival2_F::
        trainerbattle_single TRAINER_MAY_ROUTE_103_MUDKIP, RustboroCity_Text_OhComeOnBattleMe, RustboroCity_Text_MayDefeat, NettuxPure_Gauntlet5_EventScript_Complete
        msgbox RustboroCity_Text_MayDefeat, MSGBOX_DEFAULT
        end

NettuxPure_Gauntlet5_EventScript_Complete::
        addmoney 5000
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_MYSTIC_WATER
        giveitem ITEM_KINGS_ROCK
        giveitem ITEM_DAWN_STONE
        giveitem ITEM_CELL_BATTERY
        giveitem ITEM_PP_MAX
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_MOON_STONE
        giveitem ITEM_ASPEAR_BERRY
        giveitem ITEM_CHOPLE_BERRY
        call Nettux_RandomWildMon
       	closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_5
        applymovement LOCALID_RIVAL, NettuxPure_Gauntlet5_Movement_RivalLeaves
       	waitmovement LOCALID_RIVAL
	      removeobject LOCALID_RIVAL
        end

NettuxPure_Gauntlet5_EventScript_Encounters::
        msgbox NettuxPure_Gauntlet5_Text_Encounters, MSGBOX_DEFAULT
        closemessage
        end

NettuxPure_Gauntlet5_Text_Encounters:
        .string "POKéMON observed in this area:\l"
        .string "Wattrel\l"
        .string "Wingull\l"
        .string "Fletchling\l"
        .string "Slowpoke\l"
        .string "Clefairy\l"
        .string "Abra\l"
        .string "Poliwag\l"
        .string "Totodile\l"
        .string "Abra\l"
        .string "Diglett$"

RustboroCity_Text_OhComeOnBattleMe:
        .string "Oh come on! Lets go!$"

NettuxPure_Gauntlet5_Movement_RivalLeaves:
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
