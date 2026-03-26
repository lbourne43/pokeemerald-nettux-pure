.set LOCALID_NURSE, 1
.set LOCALID_DOOR_GUY, 4

NettuxPure_Base_MapScripts::
        map_script MAP_SCRIPT_ON_TRANSITION, NettuxPure_Base_OnTransition
        .byte 0

NettuxPure_Base_OnTransition:
        setrespawn HEAL_LOCATION_NETTUX_PURE_BASE
	setflag FLAG_NETTUX_DEFEATED_RED_1
        end

NettuxPure_Base_GoNextLevelWarp::
	turnobject LOCALID_DOOR_GUY, DIR_WEST
	setvar VAR_TEMP_1, 1
	clearflag FLAG_NETTUX_LEVEL_SCALE
	goto NettuxPure_Base_SetupNextLevelWarp
	end

NettuxPure_Base_DoorGuy::
        faceplayer
	goto NettuxPure_Base_SetupNextLevelWarp
	end

NettuxPure_Base_SetupNextLevelWarp::
        call NettuxPure_ResetAllBerries
        goto_if_set FLAG_NETTUX_FINISH_WALLY_3, NettuxPure_Base_League
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_20, NettuxPure_Base_Wally3
        goto_if_set FLAG_BADGE08_GET, NettuxPure_Base_Gauntlet20
        goto_if_set FLAG_NETTUX_FINISH_RED_AND_LEAF, NettuxPure_Base_Juan
        goto_if_set FLAG_NETTUX_FINISH_GABBY_AND_TY, NettuxPure_Base_RedAndLeaf
        goto_if_set FLAG_NETTUX_FINISH_ARCHIE3, NettuxPure_Base_GabbyAndTy
        goto_if_set FLAG_NETTUX_FINISH_AQUA_UNDERWATER, NettuxPure_Base_Archie3
        goto_if_set FLAG_NETTUX_FINISH_MAXIE3, NettuxPure_Base_Shelly2
        goto_if_set FLAG_NETTUX_FINISH_MAGMA_SPACE, NettuxPure_Base_Maxie3
        goto_if_set FLAG_BADGE07_GET, NettuxPure_Base_Magma3
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_19, NettuxPure_Base_TateAndLiza
        goto_if_set FLAG_NETTUX_FINISH_MATT, NettuxPure_Base_Gauntlet19
        goto_if_set FLAG_NETTUX_FINISH_AQUA_HIDEOUT, NettuxPure_Base_Aqua4_2
        goto_if_set FLAG_NETTUX_FINISH_MAXIE2, NettuxPure_Base_Aqua4
        goto_if_set FLAG_NETTUX_FINISH_MAGMA_HIDEOUT, NettuxPure_Base_Maxie2
        goto_if_set FLAG_NETTUX_FINISH_ARCHIE2, NettuxPure_Base_Magma2
        goto_if_set FLAG_NETTUX_FINISH_AQUA_MTPYRE, NettuxPure_Base_Archie2
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_18, NettuxPure_Base_Aqua3
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_17, NettuxPure_Base_Gauntlet18
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_16, NettuxPure_Base_Gauntlet17
        goto_if_set FLAG_BADGE06_GET, NettuxPure_Base_Gauntlet16
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_15, NettuxPure_Base_Winona
        goto_if_set FLAG_NETTUX_FINISH_LEAF_2, NettuxPure_Base_Gauntlet15
        goto_if_set FLAG_NETTUX_FINISH_SHELLY_1, NettuxPure_Base_Leaf2
        goto_if_set FLAG_NETTUX_FINISH_AQUA2, NettuxPure_Base_Shelly1
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_14, NettuxPure_Base_Aqua2
        goto_if_set FLAG_BADGE05_GET, NettuxPure_Base_Gauntlet14
        goto_if_set FLAG_NETTUX_FINISH_WALLY_2, NettuxPure_Base_Norman
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_13, NettuxPure_Base_Wally2
        goto_if_set FLAG_BADGE04_GET, NettuxPure_Base_Gauntlet13
        goto_if_set FLAG_NETTUX_FINISH_RED_2, NettuxPure_Base_Flannery
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_12, NettuxPure_Base_Red2
        goto_if_set FLAG_NETTUX_FINISH_MAXIE1, NettuxPure_Base_Gauntlet12
        goto_if_set FLAG_NETTUX_FINISH_MAGMA1, NettuxPure_Base_Maxie1
        goto_if_set FLAG_NETTUX_FINISH_AQUA1, NettuxPure_Base_Magma1
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_11, NettuxPure_Base_Aqua1
	goto_if_set FLAG_NETTUX_FINISH_WINSTRATES, NettuxPure_Base_Gauntlet11
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_10, NettuxPure_Base_Winstrates
        goto_if_set FLAG_BADGE03_GET, NettuxPure_Base_Gauntlet10
        goto_if_set FLAG_NETTUX_FINISH_WALLY_1, NettuxPure_Base_Wattson
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_9, NettuxPure_Base_Wally1
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_8, NettuxPure_Base_Gauntlet9
        goto_if_set FLAG_NETTUX_FINISH_AQUA_MUSEUM, NettuxPure_Base_Gauntlet8
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_7, NettuxPure_Base_AquaMuseum
        goto_if_set FLAG_BADGE02_GET, NettuxPure_Base_Gauntlet7
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_6, NettuxPure_Base_Brawly
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_5, NettuxPure_Base_Gauntlet6
        goto_if_set FLAG_NETTUX_FINISH_AQUA_TUNNEL, NettuxPure_Base_Gauntlet5
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_4, NettuxPure_Base_AquaTunnel
        goto_if_set FLAG_BADGE01_GET, NettuxPure_Base_Gauntlet4
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_3, NettuxPure_Base_Roxanne
        goto_if_set FLAG_NETTUX_FINISH_LEAF_1, NettuxPure_Base_Gauntlet3
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_2, NettuxPure_Base_Leaf1
        goto_if_set FLAG_NETTUX_FINISH_AQUA_FOREST, NettuxPure_Base_Gauntlet2
        goto_if_set FLAG_NETTUX_FINISH_GAUNTLET_1, NettuxPure_Base_AquaForest
	goto NettuxPure_Base_Gauntlet1
	end

NettuxPure_Base_Exit::
        closemessage
	turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoDown
	waitmovement 0
	setvar VAR_TEMP_1, 0
        end


NettuxPure_Base_League::
        msgbox NettuxPure_Text_League, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoLeague
	turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoLeague::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_LEAGUE, 0
        end

NettuxPure_Base_Wally3::
        msgbox NettuxPure_Text_Wally3, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoWally3
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoWally3::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_WALLY3, 0
        end

NettuxPure_Base_Gauntlet20::
        msgbox NettuxPure_Text_Gauntlet20, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet20
	turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoGauntlet20::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET20, 0
        end

NettuxPure_Base_Juan::
        msgbox NettuxPure_Text_Juan, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoJuan
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoJuan::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_JUAN, 0
        end

NettuxPure_Base_RedAndLeaf::
        msgbox NettuxPure_Text_RedAndLeaf, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoRedAndLeaf
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoRedAndLeaf::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_RED_AND_LEAF, 0
        end

NettuxPure_Base_GabbyAndTy::
        msgbox NettuxPure_Text_GabbyAndTy, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGabbyAndTy
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoGabbyAndTy::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_GABBY_AND_TY, 0
        end

NettuxPure_Base_Archie3::
        msgbox NettuxPure_Text_Archie3, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoArchie3
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoArchie3::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_ARCHIE3, 0
        end

NettuxPure_Base_Shelly2::
        msgbox NettuxPure_Text_Shelly2, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoShelly2
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoShelly2::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_SHELLY2, 0
        end

NettuxPure_Base_Maxie3::
        msgbox NettuxPure_Text_Maxie3, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoMaxie3
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoMaxie3::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_MAXIE3, 0
        end

NettuxPure_Base_Magma3::
        msgbox NettuxPure_Text_Magma3, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoMagma3
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoMagma3::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_MAGMA3, 0
        end

NettuxPure_Base_TateAndLiza::
        msgbox NettuxPure_Text_TateAndLiza, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoTateAndLiza
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoTateAndLiza::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_TATE_AND_LIZA, 0
        end

NettuxPure_Base_Gauntlet19::
        msgbox NettuxPure_Text_Gauntlet19, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet19
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoGauntlet19::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET19, 0
        end

NettuxPure_Base_Aqua4_2::
        msgbox NettuxPure_Text_Aqua4_2, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoAqua4_2
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoAqua4_2::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_AQUA4_2, 0
        end

NettuxPure_Base_Aqua4::
        msgbox NettuxPure_Text_Aqua4, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoAqua4
	turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoAqua4::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_AQUA4, 0
        end

NettuxPure_Base_Maxie2::
        msgbox NettuxPure_Text_Maxie2, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoMaxie2
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoMaxie2::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_MAXIE2, 0
        end

NettuxPure_Base_Magma2::
        msgbox NettuxPure_Text_Magma2, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoMagma2
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoMagma2::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_MAGMA2, 0
        end

NettuxPure_Base_Archie2::
        msgbox NettuxPure_Text_Archie2, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoArchie2
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoArchie2::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_ARCHIE2, 1
        end

NettuxPure_Base_Aqua3::
        msgbox NettuxPure_Text_Aqua3, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoAqua3
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoAqua3::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_AQUA3, 0
        end

NettuxPure_Base_Gauntlet18::
        msgbox NettuxPure_Text_Gauntlet18, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet18
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoGauntlet18::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET18, 0
        end

NettuxPure_Base_Gauntlet17::
        msgbox NettuxPure_Text_Gauntlet17, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet17
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoGauntlet17::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET17, 0
        end

NettuxPure_Base_Gauntlet16::
        msgbox NettuxPure_Text_Gauntlet16, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet16
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoGauntlet16::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET16, 0
        end

NettuxPure_Base_Winona::
        msgbox NettuxPure_Text_Winona, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoWinona
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoWinona::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_WINONA, 0
        end

NettuxPure_Base_Gauntlet15::
        msgbox NettuxPure_Text_Gauntlet15, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet15
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoGauntlet15::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET15, 0
        end

NettuxPure_Base_Leaf2::
        msgbox NettuxPure_Text_Leaf2, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoLeaf2
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoLeaf2::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_LEAF2, 0
        end

NettuxPure_Base_Shelly1::
        msgbox NettuxPure_Text_Shelly1, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoShelly1
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoShelly1::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_SHELLY, 0
        end

NettuxPure_Base_Aqua2::
        msgbox NettuxPure_Text_Aqua2, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoAqua2
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoAqua2::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_AQUA2, 0
        end

NettuxPure_Base_Gauntlet14::
        msgbox NettuxPure_Text_Gauntlet14, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet14
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoGauntlet14::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET14, 0
        end

NettuxPure_Base_Gauntlet13::
        msgbox NettuxPure_Text_Gauntlet13, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet13
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoGauntlet13::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET13, 0
        end

NettuxPure_Base_Norman::
        msgbox NettuxPure_Text_Norman, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoNorman
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoNorman::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_NORMAN, 0
        end

NettuxPure_Base_Wally2::
        msgbox NettuxPure_Text_Wally2, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoWally2
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoWally2::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_WALLY2, 0
        end

NettuxPure_Base_Red2::
        msgbox NettuxPure_Text_Red2, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoRed2
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoRed2::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_RED2, 0
        end

NettuxPure_Base_Flannery::
        msgbox NettuxPure_Text_Flannery, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoFlannery
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoFlannery::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_FLANNERY, 0
        end

NettuxPure_Base_Maxie1::
        msgbox NettuxPure_Text_Maxie1, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoMaxie1
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoMaxie1::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_MAXIE1, 0
        end

NettuxPure_Base_Magma1::
        msgbox NettuxPure_Text_Magma1, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoMagma1
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoMagma1::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_MAGMA1, 0
        end

NettuxPure_Base_Aqua1::
        msgbox NettuxPure_Text_Aqua1, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoAqua1
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoAqua1::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_AQUA1, 0
        end

NettuxPure_Base_Gauntlet12::
        msgbox NettuxPure_Text_Gauntlet12, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet12
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoGauntlet12::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET12, 0
        end

NettuxPure_Base_Gauntlet11::
        msgbox NettuxPure_Text_Gauntlet11, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet11
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoGauntlet11::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET11, 0
        end

NettuxPure_Base_Winstrates::
        msgbox NettuxPure_Text_Winstrates, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoWinstrates
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoWinstrates::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_WINSTRATES, 0
        end

NettuxPure_Base_Gauntlet10::
        msgbox NettuxPure_Text_Gauntlet10, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet10
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoGauntlet10::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET10, 0
        end

NettuxPure_Base_Wattson::
        msgbox NettuxPure_Text_Wattson, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoWattson
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoWattson::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_WATTSON, 0
	end

NettuxPure_Base_Wally1::
        msgbox NettuxPure_Text_Wally1, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoWally1
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoWally1::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_WALLY1, 0
        end

NettuxPure_Base_Gauntlet9::
        msgbox NettuxPure_Text_Gauntlet9, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet9
	turnobject LOCALID_DOOR_GUY, DIR_SOUTH
	end

NettuxPure_Base_GoGauntlet9::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
	waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET9, 0
	end

NettuxPure_Base_Gauntlet8::
        msgbox NettuxPure_Text_Gauntlet8, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet8
	turnobject LOCALID_DOOR_GUY, DIR_SOUTH
	end

NettuxPure_Base_GoGauntlet8::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
	waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET8, 0
	end

NettuxPure_Base_AquaMuseum::
        msgbox NettuxPure_Text_AquaMuseum, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoAquaMuseum
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoAquaMuseum::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_AQUA_MUSEUM, 0
        end

NettuxPure_Base_Gauntlet7::
        msgbox NettuxPure_Text_Gauntlet7, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet7
	turnobject LOCALID_DOOR_GUY, DIR_SOUTH
	end

NettuxPure_Base_GoGauntlet7::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
	waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET7, 0
	end

NettuxPure_Base_Brawly::
        msgbox NettuxPure_Text_Brawly, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoBrawly
	turnobject LOCALID_DOOR_GUY, DIR_SOUTH
	end

NettuxPure_Base_GoBrawly::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
	waitmovement 0
        warp MAP_NETTUX_PURE_BRAWLY, 0
	end

NettuxPure_Base_Gauntlet6::
        msgbox NettuxPure_Text_Gauntlet6, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet6
	turnobject LOCALID_DOOR_GUY, DIR_SOUTH
	end

NettuxPure_Base_GoGauntlet6::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
	waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET6, 0
	end

NettuxPure_Base_Gauntlet5::
        msgbox NettuxPure_Text_Gauntlet5, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet5
	turnobject LOCALID_DOOR_GUY, DIR_SOUTH
	end

NettuxPure_Base_GoGauntlet5::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
	waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET5, 0
	end

NettuxPure_Base_AquaTunnel::
        msgbox NettuxPure_Text_AquaTunnel, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoAquaTunnel
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoAquaTunnel::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_AQUA_RUSTURF, 0
	end

NettuxPure_Base_Gauntlet4::
        msgbox NettuxPure_Text_Gauntlet4, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet4
	turnobject LOCALID_DOOR_GUY, DIR_SOUTH
	end

NettuxPure_Base_GoGauntlet4::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
	waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET4, 0
	end

NettuxPure_Base_Roxanne::
        msgbox NettuxPure_Text_Roxanne, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoRoxanne
	turnobject LOCALID_DOOR_GUY, DIR_SOUTH
	end

NettuxPure_Base_GoRoxanne::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
	waitmovement 0
        warp MAP_NETTUX_PURE_ROXANNE, 0
	end

NettuxPure_Base_Gauntlet3::
        msgbox NettuxPure_Text_Gauntlet3, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet3
	turnobject LOCALID_DOOR_GUY, DIR_SOUTH
	end

NettuxPure_Base_GoGauntlet3::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
	waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET3, 0
	end

NettuxPure_Base_Leaf1::
        msgbox NettuxPure_Text_Leaf1, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoLeaf1
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoLeaf1::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_LEAF1, 0
        end

NettuxPure_Base_Gauntlet2::
        msgbox NettuxPure_Text_Gauntlet2, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet2
	turnobject LOCALID_DOOR_GUY, DIR_SOUTH
	end

NettuxPure_Base_GoGauntlet2::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
	waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET2, 0
	end

NettuxPure_Base_AquaForest::
        msgbox NettuxPure_Text_AquaForest, MSGBOX_DEFAULT
        closemessage
        goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoAquaForest
        turnobject LOCALID_DOOR_GUY, DIR_SOUTH
        end

NettuxPure_Base_GoAquaForest::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_AQUA_FOREST, 0
        end

NettuxPure_Base_Gauntlet1::
        msgbox NettuxPure_Text_Gauntlet1, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_TEMP_1, 1, NettuxPure_Base_GoGauntlet1
	turnobject LOCALID_DOOR_GUY, DIR_SOUTH
	end
	
NettuxPure_Base_GoGauntlet1::
        msgbox NettuxPure_Text_AreYouReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NettuxPure_Base_Exit
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
	waitmovement 0
        warp MAP_NETTUX_PURE_GAUNTLET1, 0
	end

NettuxPure_Base_EventScript_Nurse::
        setvar VAR_0x800B, LOCALID_NURSE
        call Common_EventScript_PkmnCenterNurse
        waitmessage
        waitbuttonpress
        release
        end

NettuxPure_Base_EventScript_Clerk::
        call NettuxHelper_EventScript_MartHelper
        end

NettuxPure_ResetAllBerries::
        setberrytree BERRY_TREE_GAUNTLET_1_PECHA, ITEM_TO_BERRY(ITEM_PECHA_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_1_ORAN, ITEM_TO_BERRY(ITEM_ORAN_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_2_CHERI, ITEM_TO_BERRY(ITEM_CHERI_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_2_CHESTO, ITEM_TO_BERRY(ITEM_CHESTO_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_2_ORAN, ITEM_TO_BERRY(ITEM_ORAN_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_2_RAWST, ITEM_TO_BERRY(ITEM_RAWST_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_2_TANGA, ITEM_TO_BERRY(ITEM_TANGA_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_2_PERSIM, ITEM_TO_BERRY(ITEM_PERSIM_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_2_CHARTI, ITEM_TO_BERRY(ITEM_CHARTI_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_3_SHUCA, ITEM_TO_BERRY(ITEM_SHUCA_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_3_KASIB, ITEM_TO_BERRY(ITEM_KASIB_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_3_SITRUS, ITEM_TO_BERRY(ITEM_SITRUS_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_3_CUSTAP, ITEM_TO_BERRY(ITEM_CUSTAP_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_5_ASPEAR, ITEM_TO_BERRY(ITEM_ASPEAR_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_5_CHOPLE, ITEM_TO_BERRY(ITEM_CHOPLE_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_8_PASSHO, ITEM_TO_BERRY(ITEM_PASSHO_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_8_PAYAPA, ITEM_TO_BERRY(ITEM_PAYAPA_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_8_SALAC, ITEM_TO_BERRY(ITEM_SALAC_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_8_ROSELI, ITEM_TO_BERRY(ITEM_ROSELI_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_8_PETAYA, ITEM_TO_BERRY(ITEM_PETAYA_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_8_MICLE, ITEM_TO_BERRY(ITEM_MICLE_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_9_LEPPA, ITEM_TO_BERRY(ITEM_LEPPA_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_9_MARANGA, ITEM_TO_BERRY(ITEM_MARANGA_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_9_WACAN, ITEM_TO_BERRY(ITEM_WACAN_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_WINSTRATES_LIECHI, ITEM_TO_BERRY(ITEM_LIECHI_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_WINSTRATES_OCCA, ITEM_TO_BERRY(ITEM_OCCA_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_WINSTRATES_KEE, ITEM_TO_BERRY(ITEM_KEE_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_WINSTRATES_APICOT, ITEM_TO_BERRY(ITEM_APICOT_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_11_RINDO, ITEM_TO_BERRY(ITEM_RINDO_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_11_YACHE, ITEM_TO_BERRY(ITEM_YACHE_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_11_CHILAN, ITEM_TO_BERRY(ITEM_CHILAN_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_14_COBA, ITEM_TO_BERRY(ITEM_COBA_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_14_SITRUS, ITEM_TO_BERRY(ITEM_SITRUS_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_14_GANLON, ITEM_TO_BERRY(ITEM_GANLON_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_14_KEBIA, ITEM_TO_BERRY(ITEM_KEBIA_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_14_HABAN, ITEM_TO_BERRY(ITEM_HABAN_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_14_COLBUR, ITEM_TO_BERRY(ITEM_COLBUR_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_14_BABIRI, ITEM_TO_BERRY(ITEM_BABIRI_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_16_PAYAPA, ITEM_TO_BERRY(ITEM_PAYAPA_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_16_SITRUS, ITEM_TO_BERRY(ITEM_SITRUS_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_16_CUSTAP, ITEM_TO_BERRY(ITEM_CUSTAP_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_16_PASSHO, ITEM_TO_BERRY(ITEM_PASSHO_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_16_BABIRI, ITEM_TO_BERRY(ITEM_BABIRI_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_16_KEE, ITEM_TO_BERRY(ITEM_KEE_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_16_LEPPA, ITEM_TO_BERRY(ITEM_LEPPA_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_16_MARANGA, ITEM_TO_BERRY(ITEM_MARANGA_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_16_MICLE, ITEM_TO_BERRY(ITEM_MICLE_BERRY),  BERRY_STAGE_BERRIES
        setberrytree BERRY_TREE_GAUNTLET_16_WACAN, ITEM_TO_BERRY(ITEM_WACAN_BERRY),  BERRY_STAGE_BERRIES
	return

NettuxPure_Base_Movement_GoToStairs:
	walk_up
        step_end

NettuxPure_Base_Movement_GoDown:
	walk_down
        step_end

NettuxPure_Text_AreYouReady:
        .string "Are you ready?$"

NettuxPure_Text_Gauntlet1:
        .string "Area 1 Stage 1\n"
        .string "Road to Petalburg city.\l"
	.string "Level Cap: 10$"

NettuxPure_Text_AquaForest:
        .string "Area 1 Aqua\n"
        .string "Petalburg Woods.\l"
	.string "Level Cap: 12$"

NettuxPure_Text_Gauntlet2:
        .string "Area 1 Stage 2\n"
        .string "Road to Rustboro city.\l"
	.string "Level Cap: 15$"

NettuxPure_Text_Leaf1:
        .string "Area 1 Rival\n"
        .string "Fight Leaf.\l"
	.string "Level Cap: 17$"

NettuxPure_Text_Gauntlet3:
        .string "Area 1 Stage 3\n"
        .string "Rusturf tunnel exterior.\l"
	.string "Level Cap: 18$"

NettuxPure_Text_Roxanne:
        .string "Area 1 Gym Leader\n"
        .string "Take on Roxanne!\l"
	.string "Level Cap: 20$"

NettuxPure_Text_Gauntlet4:
        .string "Area 2 Stage 1\n"
        .string "Rusturf Tunnel.\l"
	.string "Level Cap: 22$"

NettuxPure_Text_AquaTunnel:
        .string "Area 2 Aqua\n"
        .string "Team Aqua in Rusturf Tunnel1\l"
	.string "Level Cap: 24$"

NettuxPure_Text_Gauntlet5:
        .string "Area 2 Stage 2\n"
        .string "Dewford Beach.\l"
	.string "Level Cap: 25$"

NettuxPure_Text_Gauntlet6:
        .string "Area 2 Stage 3\n"
        .string "Granite Cave.\l"
	.string "Level Cap: 28$"

NettuxPure_Text_Brawly:
        .string "Area 2 Gym Leader\n"
        .string "Take on Brawly!\l"
	.string "Level Cap: 30$"

NettuxPure_Text_Gauntlet7:
        .string "Area 3 Stage 1\n"
        .string "Slateport Beach.\l"
	.string "Level Cap: 35$"

NettuxPure_Text_AquaMuseum:
        .string "Area 3 Aqua\n"
        .string "Team Aqua in the Oceanic Museum.\l"
	.string "Level Cap: 36$"

NettuxPure_Text_Gauntlet8:
        .string "Area 3 Stage 2\n"
        .string "Cycling Road.\l"
	.string "Level Cap: 38$"

NettuxPure_Text_Gauntlet9:
        .string "Area 3 Stage 3\n"
        .string "New Mauville.\l"
	.string "Level Cap: 42$"

NettuxPure_Text_Wattson:
        .string "Area 3 Gym Leader\n"
        .string "Take on Wattson!\l"
	.string "Level Cap: 44$"

NettuxPure_Text_Wally1:
        .string "Area 3 Rival\n"
        .string "Take on Wally!\l"
	.string "Level Cap: 44$"

NettuxPure_Text_Gauntlet10:
        .string "Area 4 Stage 1\n"
        .string "Desert Pass.\l"
	.string "Level Cap: 45$"

NettuxPure_Text_Winstrates:
        .string "Area 4 Stage 2\n"
        .string "Take on the Winstrates!\l"
	.string "Level Cap: 45$"

NettuxPure_Text_Gauntlet11:
        .string "Area 4 Stage 3\n"
        .string "Meteor Falls Exterior.\l"
	.string "Level Cap: 47$"

NettuxPure_Text_Aqua1:
        .string "Area 4 Aqua Boss\n"
        .string "Confront Archie at Meteor Falls!\l"
	.string "Level Cap: 49$"

NettuxPure_Text_Magma1:
        .string "Area 4 Magma\n"
        .string "Confront Team Magma at Mt Chimney!\l"
	.string "Level Cap: 51$"

NettuxPure_Text_Maxie1:
        .string "Area 4 Magma Boss\n"
        .string "Take on Maxie at Mt Chimney!\l"
	.string "Level Cap: 51$"

NettuxPure_Text_Gauntlet12:
        .string "Area 4 Stage 4\n"
        .string "Jagged Pass.\l"
	.string "Level Cap: 53$"

NettuxPure_Text_Red2:
        .string "Area 4 Rival\n"
        .string "Take on Red!\l"
	.string "Level Cap: 55$"

NettuxPure_Text_Flannery:
        .string "Area 4 Gym Leader\n"
        .string "Take on Flannery!\l"
	.string "Level Cap: 55$"

NettuxPure_Text_Gauntlet13:
        .string "Area 5 Stage 1\n"
        .string "Return to Petalburg\l"
	.string "Level Cap: 57$"

NettuxPure_Text_Wally2:
        .string "Area 5 Rival\n"
        .string "Take on Wally!\l"
	.string "Level Cap: 57$"

NettuxPure_Text_Norman:
        .string "Area 5 Gym Leader\n"
        .string "Take on Dad!\l"
	.string "Level Cap: 60$"

NettuxPure_Text_Gauntlet14:
        .string "Area 6 Stage 1\n"
        .string "Weather Institute Exterior\l"
	.string "Level Cap: 62$"

NettuxPure_Text_Aqua2:
        .string "Area 6 Aqua\n"
        .string "Weather Institute Interior\l"
	.string "Level Cap: 64$"

NettuxPure_Text_Shelly1:
        .string "Area 6 Aqua Admin\n"
        .string "Confront Shelly\l"
	.string "Level Cap: 64$"

NettuxPure_Text_Leaf2:
        .string "Area 6 Rival\n"
        .string "Take on Leaf!\l"
	.string "Level Cap: 66$"

NettuxPure_Text_Gauntlet15:
        .string "Area 6 Stage 2\n"
        .string "Fortree Town\l"
	.string "Level Cap: 66$"

NettuxPure_Text_Winona:
        .string "Area 6 Gym Leader\n"
        .string "Take on Winona!\l"
	.string "Level Cap: 70$"

NettuxPure_Text_Gauntlet19:
        .string "Area 8 Stage 1\n"
        .string "Shoal Cavern\l"
        .string "Level Cap: 84$"

NettuxPure_Text_Aqua4_2:
        .string "Area 7 Aqua Admin\n"
        .string "Confront Matt!\l"
        .string "Level Cap: 83$"

NettuxPure_Text_Aqua4:
        .string "Area 7 Aqua Hideout\n"
        .string "Infiltrate Team Aqua's Hideout!\l"
        .string "Level Cap: 83$"

NettuxPure_Text_Maxie2:
        .string "Area 7 Magma Leader\n"
        .string "Confront Maxie\l"
        .string "Level Cap: 81$"

NettuxPure_Text_Magma2:
        .string "Area 7 Magma Hideout\n"
        .string "Infiltrate Team Magma's Hideout\l"
        .string "Level Cap: 81$"

NettuxPure_Text_Archie2:
        .string "Area 7 Aqua Leader\n"
        .string "Confront Archie!\l"
        .string "Level Cap: 78$"

NettuxPure_Text_Aqua3:
        .string "Area 7 Team Aqua\n"
        .string "Mt Pyre Exterior\l"
        .string "Level Cap: 78$"

NettuxPure_Text_Gauntlet18:
        .string "Area 7 Stage 3\n"
        .string "Mt Pyre Interior\l"
        .string "Level Cap: 76$"

NettuxPure_Text_Gauntlet17:
        .string "Area 7 Stage 2\n"
        .string "Path to Lilycove\l"
        .string "Level Cap: 74$"

NettuxPure_Text_Gauntlet16:
        .string "Area 7 Stage 1\n"
        .string "Path to Lilycove\l"
        .string "Level Cap: 72$"

NettuxPure_Text_League:
        .string "Final Challenge\n"
        .string "Take on the league!\l"
        .string "Level Cap: 100$"

NettuxPure_Text_Wally3:
        .string "Area 9 Rival\n"
        .string "Take on Wally!\l"
        .string "Level Cap: 100$"

NettuxPure_Text_Gauntlet20:
        .string "Area 9 Stage 1\n"
        .string "Path to Lilycove\l"
        .string "Level Cap: 100$"

NettuxPure_Text_Juan:
        .string "Area 8 Gym Leader\n"
        .string "Take on Juan\l"
        .string "Level Cap: 96$"

NettuxPure_Text_RedAndLeaf:
        .string "Area 8 Stage 2\n"
        .string "Take on Red and Leaf!\l"
        .string "Level Cap: 93$"

NettuxPure_Text_GabbyAndTy:
        .string "Area 8 Stage 1\n"
        .string "Take on Gabby and Ty!\l"
        .string "Level Cap: 93$"

NettuxPure_Text_Archie3:
        .string "Area 8 Aqua Boss\n"
        .string "Take on Archie\l"
        .string "Level Cap: 90$"

NettuxPure_Text_Shelly2:
        .string "Area 8 Team Aqua\n"
        .string "Take on Shelly\l"
        .string "Level Cap: 90$"

NettuxPure_Text_Maxie3:
        .string "Area 8 Magma Boss\n"
        .string "Confront Maxie and Tabitha\l"
        .string "Level Cap: 88$"

NettuxPure_Text_Magma3:
        .string "Area 8 Team Magma\n"
        .string "Confront Team Magma\l"
        .string "Level Cap: 88$"

NettuxPure_Text_TateAndLiza:
        .string "Area 7 Gym Leader\n"
        .string "Take on Tate and Liza\l"
        .string "Level Cap: 86$"
