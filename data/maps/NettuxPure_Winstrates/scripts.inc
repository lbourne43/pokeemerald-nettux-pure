.set LOCALID_VICTOR, 1
.set LOCALID_VICTORIA, 2
.set LOCALID_VIVI, 3
.set LOCALID_VICKY, 4

NettuxPure_Winstrates_MapScripts::
        map_script MAP_SCRIPT_ON_TRANSITION, NettuxPure_Winstrates_OnTransition
        .byte 0

NettuxPure_Winstrates_OnTransition:
        goto_if_not_defeated TRAINER_VICKY, NettuxPure_Winstrates_EventScript_SetWinstratesNotDefeated
        end

NettuxPure_Winstrates_EventScript_SetWinstratesNotDefeated::
        clearflag FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE
        setflag FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE
        setflag FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE
        setflag FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE
        cleartrainerflag TRAINER_VICTOR
        cleartrainerflag TRAINER_VICTORIA
        cleartrainerflag TRAINER_VIVI
        end

NettuxPure_Winstrates_EventScript_Victor::
        lock
        faceplayer
        setflag FLAG_LANDMARK_WINSTRATE_FAMILY
        msgbox Route111_Text_BattleOurFamily, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, YES, NettuxPure_Winstrates_EventScript_BattleWinstrates
        msgbox Route111_Text_IsThatSo, MSGBOX_DEFAULT
        release
        end

NettuxPure_Winstrates_EventScript_BattleWinstrates::
        msgbox Route111_Text_VictorIntro, MSGBOX_DEFAULT
        trainerbattle_no_intro TRAINER_VICTOR, Route111_Text_VictorDefeat
        applymovement LOCALID_VICTOR, Common_Movement_WalkInPlaceFasterUp
        waitmovement 0
        call NettuxPure_Winstrates_EventScript_OpenWinstrateDoor
        msgbox Route111_Text_VictorPostBattle, MSGBOX_DEFAULT
        closemessage
        applymovement LOCALID_VICTOR, Route111_Movement_WinstrateEnterHouse
        waitmovement 0
        removeobject LOCALID_VICTOR
        call NettuxPure_Winstrates_EventScript_CloseWinstrateDoor
        applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
        waitmovement 0
        call NettuxPure_Winstrates_EventScript_OpenWinstrateDoor
        addobject LOCALID_VICTORIA
        applymovement LOCALID_VICTORIA, Route111_Movement_WinstrateExitHouse
        waitmovement 0
        call NettuxPure_Winstrates_EventScript_CloseWinstrateDoor
        msgbox Route111_Text_VictoriaIntro, MSGBOX_DEFAULT
        trainerbattle_no_intro TRAINER_VICTORIA, Route111_Text_VictoriaDefeat
        applymovement LOCALID_VICTORIA, Common_Movement_WalkInPlaceFasterUp
        waitmovement 0
        call NettuxPure_Winstrates_EventScript_OpenWinstrateDoor
        msgbox Route111_Text_VictoriaPostBattle, MSGBOX_DEFAULT
        closemessage
        applymovement LOCALID_VICTORIA, Route111_Movement_WinstrateEnterHouse
        waitmovement 0
        removeobject LOCALID_VICTORIA
        call NettuxPure_Winstrates_EventScript_CloseWinstrateDoor
        applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
        waitmovement 0
        call Route111_EventScript_OpenWinstrateDoor
        addobject LOCALID_VIVI
        applymovement LOCALID_VIVI, Route111_Movement_WinstrateExitHouse
        waitmovement 0
        call NettuxPure_Winstrates_EventScript_CloseWinstrateDoor
        msgbox Route111_Text_ViviIntro, MSGBOX_DEFAULT
        trainerbattle_no_intro TRAINER_VIVI, Route111_Text_ViviDefeat
        applymovement LOCALID_VIVI, Common_Movement_WalkInPlaceFasterUp
        waitmovement 0
        call NettuxPure_Winstrates_EventScript_OpenWinstrateDoor
        msgbox Route111_Text_ViviPostBattle, MSGBOX_DEFAULT
        closemessage
        applymovement LOCALID_VIVI, Route111_Movement_WinstrateEnterHouse
        waitmovement 0
        removeobject LOCALID_VIVI
        call NettuxPure_Winstrates_EventScript_CloseWinstrateDoor
        applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
        waitmovement 0
        call NettuxPure_Winstrates_EventScript_OpenWinstrateDoor
        addobject LOCALID_VICKY
        applymovement LOCALID_VICKY, Route111_Movement_WinstrateExitHouse
        waitmovement 0
        call NettuxPure_Winstrates_EventScript_CloseWinstrateDoor
        msgbox Route111_Text_VickyIntro, MSGBOX_DEFAULT
        trainerbattle_no_intro TRAINER_VICKY, Route111_Text_VickyDefeat
        msgbox Route111_Text_VickyPostBattle, MSGBOX_DEFAULT
        closemessage
        applymovement LOCALID_VICKY, Common_Movement_WalkInPlaceFasterUp
        waitmovement 0
        call Route111_EventScript_OpenWinstrateDoor
        applymovement LOCALID_VICKY, Route111_Movement_WinstrateEnterHouse
        waitmovement 0
        removeobject LOCALID_VICKY
        call NettuxPure_Winstrates_EventScript_CloseWinstrateDoor
        release
        goto NettuxPure_Winstrates_Complete
        end

NettuxPure_Winstrates_EventScript_OpenWinstrateDoor::
        opendoor 27, 18
        waitdooranim
        return

NettuxPure_Winstrates_EventScript_CloseWinstrateDoor::
        closedoor 27, 18
        waitdooranim
        return

NettuxPure_Winstrates_Complete::
        addmoney 10000
        giveitem ITEM_POKE_BALL
        closemessage
        setflag FLAG_NETTUX_FINISH_WINSTRATES
        end
