.set LOCALID_RIVAL, 15

NettuxPure_Gauntlet8_MapScripts::
        map_script MAP_SCRIPT_ON_TRANSITION, NettuxPure_Gauntlet2_OnTransition
        .byte 0

NettuxPure_Gauntlet8_OnTransition:
        call Common_EventScript_SetupRivalGfxId
        end

NettuxPure_EventScript_Rival3::
        lockall
        checkplayergender
        goto_if_eq VAR_RESULT, MALE, NettuxPure_EventScript_Rival3_F
        goto_if_eq VAR_RESULT, FEMALE, NettuxPure_EventScript_Rival3_M
        end

NettuxPure_EventScript_Rival3_M:
        trainerbattle_single TRAINER_BRENDAN_ROUTE_110_MUDKIP, Route110_Text_BrendanLetsBattle, Route110_Text_BrendanDefeated, NettuxPure_Gauntlet8_Complete
        msgbox Route110_Text_BrendanDefeated, MSGBOX_DEFAULT
        end

NettuxPure_EventScript_Rival3_F::
        trainerbattle_single TRAINER_MAY_ROUTE_110_MUDKIP, Route110_Text_MayLetsBattle, Route110_Text_MayDefeated, NettuxPure_Gauntlet8_Complete
        msgbox Route110_Text_MayDefeated, MSGBOX_DEFAULT
        end
	.byte 0

NettuxPure_Gauntlet8_BikeCheck::
        lockall
        specialvar VAR_RESULT, GetPlayerAvatarBike
        goto_if_eq VAR_RESULT, 0, Route110_SeasideCyclingRoadNorthEntrance_EventScript_NoBike
        setflag FLAG_SYS_CYCLING_ROAD
        setvar VAR_TEMP_1, 1
        releaseall
        end

NettuxPure_Gauntlet8_Complete::
        addmoney 5000
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_LEAF_STONE
        giveitem ITEM_FIRE_STONE
        giveitem ITEM_LAGGING_TAIL
        giveitem ITEM_ROSELI_BERRY
        giveitem ITEM_PETAYA_BERRY
        giveitem ITEM_MICLE_BERRY
        giveitem ITEM_PASSHO_BERRY
        giveitem ITEM_MICLE_BERRY
        giveitem ITEM_PAYAPA_BERRY
        giveitem ITEM_SALAC_BERRY
        call Nettux_RandomWildMon
        closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_8
        end

NettuxPure_Gauntlet8_EventScript_Encounters::
        msgbox NettuxPure_Gauntlet8_Text_Encounters, MSGBOX_DEFAULT
        closemessage
        end

NettuxPure_Gauntlet8_Text_Encounters:
        .string "POKéMON observed in this area:\l"
        .string "Mareep\l"
        .string "Wattrel\l"
        .string "Diglett\l"
        .string "Cubone\l"
        .string "Ponyta\l"
        .string "Oddish\l"
        .string "Snivy\l"
        .string "Electrike\l"
        .string "Sudowoodo\l"
        .string "Marill\l"

NettuxPure_Gauntlet8_Text_GoFaster:
        .string "Go faster with this!$"

