NettuxPure_Archie2_MapScripts::
        map_script MAP_SCRIPT_ON_LOAD, NettuxPure_Archie2_OnLoad
	.byte 0

NettuxPure_Archie2_OnLoad:
        special nettuxSetPermanentRain
        end

NettuxPure_Archie2_TeamAquaTrigger0::
        lockall
        setvar VAR_0x8008, 0
        goto NettuxPure_Archie2_TeamAquaExits
        end

NettuxPure_Archie2_TeamAquaTrigger1::
        lockall
        setvar VAR_0x8008, 1
        goto NettuxPure_Archie2_TeamAquaExits
        end

NettuxPure_Archie2_TeamAquaTrigger2::
        lockall
        setvar VAR_0x8008, 2
        goto NettuxPure_Archie2_TeamAquaExits
        end

NettuxPure_Archie2_TeamAquaExits::
        playbgm MUS_ENCOUNTER_AQUA, FALSE
        applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
        waitmovement 0
        applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
        waitmovement 0
        delay 50
        call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
        call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
        call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
        goto NettuxPure_Archie2_OrbSceneBattle

NettuxPure_Archie2_OrbSceneBattle::
        msgbox MtPyre_Summit_Text_ArchieBattle, MSGBOX_DEFAULT
        trainerbattle_no_intro TRAINER_ARCHIE_MTPYRE, MtPyre_Summit_Text_ArchieDefeat
        goto NettuxPure_Archie2_TeamAquaExitsPart2


NettuxPure_Archie2_TeamAquaExitsPart2::
        msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
        closemessage
        fadescreen FADE_TO_BLACK
        removeobject LOCALID_ARCHIE
        setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
        setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
        fadedefaultbgm
        fadescreen FADE_FROM_BLACK
        delay 20
        setvar VAR_MT_PYRE_STATE, 1
        call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
        call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
        call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
        msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
        giveitem ITEM_MAGMA_EMBLEM
        setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	      setflag FLAG_NETTUX_FINISH_ARCHIE2
        addmoney 20000
        call Nettux_RandomWildMon
        closemessage
        releaseall
        end


MtPyre_Summit_Text_ArchieBattle:
	.string "You again!\p"
	.string "I won't let you interfere! My Team\n"
	.string "have endured far worse conditions\p"
	.string "with me at sea...\p"
	.string "... Can you weather the storm?$"

MtPyre_Summit_Text_ArchieDefeat:
	.string "So you outlasted the storm\n"
	.string "but it doesn't matter!$"
