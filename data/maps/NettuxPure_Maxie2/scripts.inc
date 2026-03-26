.set LOCALID_GROUDON, 1
.set LOCALID_MAXIE, 2
.set LOCALID_GROUDON_SLEEPING, 3

NettuxPure_Maxie2_MapScripts::
        map_script MAP_SCRIPT_ON_LOAD, NettuxPure_Maxie2_OnLoad
        .byte 0

NettuxPure_Maxie2_OnLoad:
        special nettuxSetPermanentPrimalSun
        end

NettuxPure_Maxie2_Maxie::
        lockall
        playbgm MUS_ENCOUNTER_MAGMA, FALSE
        msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
        closemessage
        delay 20
        setvar VAR_RESULT, 1
        playse SE_M_DETECT
        dofieldeffectsparkle 18, 42, 0
        waitfieldeffect FLDEFF_SPARKLE
        setvar VAR_RESULT, 1
        playfanfare MUS_AWAKEN_LEGEND
        playse SE_ORB
        special DoOrbEffect
        applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
        waitmovement 0
        delay 150
        removeobject LOCALID_GROUDON_SLEEPING
        addobject LOCALID_GROUDON
        waitstate
        delay 60
        applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
        waitmovement 0
        special FadeOutOrbEffect
        waitstate
        setvar VAR_0x8004, 1  @ vertical pan
        setvar VAR_0x8005, 1  @ horizontal pan
        setvar VAR_0x8006, 8  @ num shakes
        setvar VAR_0x8007, 5  @ shake delay
        special ShakeCamera
        waitstate
        applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
        waitmovement 0
        removeobject LOCALID_GROUDON
        delay 4
        setvar VAR_0x8004, 2  @ vertical pan
        setvar VAR_0x8005, 2  @ horizontal pan
        setvar VAR_0x8006, 8  @ num shakes
        setvar VAR_0x8007, 5  @ shake delay
        special ShakeCamera
        waitstate
        delay 30
        applymovement LOCALID_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
        waitmovement 0
        msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
        closemessage
        applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
        waitmovement 0
        delay 30
        applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
        waitmovement 0
        msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
        closemessage
        trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
        msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
        closemessage
        setflag FLAG_NETTUX_FINISH_MAXIE2
        fadescreen FADE_TO_BLACK
        removeobject LOCALID_MAXIE
	addmoney 18000
  call Nettux_RandomWildMon
        closemessage
	end
