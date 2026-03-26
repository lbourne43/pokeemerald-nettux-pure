
.set LOCALID_RIVAL, 6

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
        call Nettux_RandomWildMon
	closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_5
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
