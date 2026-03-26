.set LOCALID_KYOGRE, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_MAXIE, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_KYOGRE_SLEEPING, 7

NettuxPure_Archie3_MapScripts::
	.byte 0

NettuxPure_Archie3_ArchieAwakenKyogre::
        special nettuxSetPermanentPrimalRain
        lockall
        setvar VAR_0x8004, LOCALID_ARCHIE
        applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
        waitmovement 0
        applymovement OBJ_EVENT_ID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
        waitmovement 0
        playbgm MUS_ENCOUNTER_AQUA, FALSE
        msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
        closemessage
        addobject VAR_0x8004
        applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
        waitmovement 0
        applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
        waitmovement 0
        msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
        applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
        waitmovement 0
        msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
        applymovement VAR_0x8004, Common_Movement_FacePlayer
        waitmovement 0
        msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
        trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
        msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
        setweather WEATHER_NONE
        doweather
        special Script_FadeOutMapMusic
        waitstate
        msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
        special WaitWeather
        waitstate
        setvar VAR_RESULT, 1
        playse SE_M_DETECT
        dofieldeffectsparkle 16, 42, 0
        waitfieldeffect FLDEFF_SPARKLE
        closemessage
        setvar VAR_RESULT, 0
        playfanfare MUS_AWAKEN_LEGEND
        playse SE_ORB
        special DoOrbEffect
        applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
        applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
        waitmovement 0
        delay 150
        removeobject LOCALID_KYOGRE_SLEEPING
        addobject LOCALID_KYOGRE
        waitstate
        delay 60
        applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
        waitmovement 0
        special FadeOutOrbEffect
        waitstate
        setvar VAR_0x8004, 1  @ vertical pan
        setvar VAR_0x8005, 1  @ horizontal pan
        setvar VAR_0x8006, 8  @ num shakes
        setvar VAR_0x8007, 5  @ shake delay
        special ShakeCamera
        waitstate
        applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
        waitmovement 0
        removeobject LOCALID_KYOGRE
        delay 4
        setvar VAR_0x8004, 2  @ vertical pan
        setvar VAR_0x8005, 2  @ horizontal pan
        setvar VAR_0x8006, 8  @ num shakes
        setvar VAR_0x8007, 5  @ shake delay
        special ShakeCamera
        waitstate
        delay 30
        msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
        playse SE_PC_LOGIN
        applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
        waitmovement 0
        msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
        closemessage
        applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
        waitmovement 0
        msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
        closemessage
        playse SE_PC_OFF
        delay 20
        applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
        waitmovement 0
        msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
        closemessage
        setvar VAR_ROUTE128_STATE, 1
        setvar VAR_SOOTOPOLIS_CITY_STATE, 1
        clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
        clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
        clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
        clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
        clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
        clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
        setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
        setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
        clearflag FLAG_HIDE_ROUTE_128_ARCHIE
        clearflag FLAG_HIDE_ROUTE_128_MAXIE
        setflag FLAG_SYS_WEATHER_CTRL
        setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
        setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
        setvar VAR_STEVENS_HOUSE_STATE, 2
        setvar VAR_SEAFLOOR_CAVERN_STATE, 1
        setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
        setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
        setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
        setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
        setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
        setflag FLAG_HIDE_MAP_NAME_POPUP
        addmoney 20000
        giveitem ITEM_POKE_BALL
        closemessage
        setflag FLAG_NETTUX_FINISH_ARCHIE3
        waitstate
        releaseall
        end
