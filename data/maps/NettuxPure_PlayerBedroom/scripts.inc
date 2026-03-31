NettuxPure_PlayerBedroom_MapScripts::
	.byte 0

NettuxPure_PlayerBedroom_GoDownstairsTrigger::
        goto NettuxPure_PlayerBedroom_ChooseStarterGen
        end

NettuxPure_PlayerBedroom_ChooseStarterGen::
        goto NettuxPure_PlayerBedroom_Gen4
	end

NettuxPure_PlayerBedroom_Gen4::
	setflag FLAG_NETTUX_STARTER_GEN_4
        goto NettuxPure_PlayerBedroom_GoDownstairs
	end

NettuxPure_PlayerBedroom_GoDownstairs::
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Base_Movement_GoToStairs
        waitmovement 0
        warp MAP_NETTUX_PURE_WILD00, 2
        end

NettuxPure_PlayerHouse_EventScript_WallClock::
        goto_if_set FLAG_SET_WALL_CLOCK, PlayersHouse_2F_EventScript_CheckWallClock
        msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
        call PlayersHouse_2F_EventScript_SetWallClock
        delay 30
        setvar VAR_LITTLEROOT_INTRO_STATE, 6
        setflag FLAG_SET_WALL_CLOCK
        playse SE_EXIT
        releaseall
        end

NettuxPure_Movement_GoDownstairs:
        walk_up
	      step_end

NettuxPure_PlayerBedroom_Text_StarterRegion:
        .string "Which region would you like your\n"
        .string "starter to be from?$"
