.set LOCALID_MATT, 1
.set LOCALID_SUBMARINE, 2

NettuxPure_Aqua4_2_MapScripts::
	.byte 0

NettuxPure_Aqua4_2_Matt::
        trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, NettuxPure_Aqua4_2_SubmarineEscape
        msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
        release
        end

NettuxPure_Aqua4_2_SubmarineEscape::
        setvar VAR_0x8008, LOCALID_MATT
        setvar VAR_0x8009, LOCALID_SUBMARINE
        applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
        waitmovement 0
        delay 20
        applymovement VAR_0x8008, Common_Movement_FacePlayer
        waitmovement 0
        msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
        closemessage
        applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
        applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
        waitmovement 0
        removeobject VAR_0x8009
        delay 20
        applymovement VAR_0x8008, Common_Movement_FacePlayer
        waitmovement 0
        msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
        setflag FLAG_NETTUX_FINISH_MATT
	addmoney 18000
	giveitem ITEM_POKE_BALL
	closemessage
        release
        end

NettuxPure_Aqua4_2_MattNoticePlayer1::
        lockall
        setvar VAR_0x8008, LOCALID_MATT
        playse SE_PIN
        applymovement VAR_0x8008, Common_Movement_ExclamationMark
        waitmovement 0
        applymovement VAR_0x8008, Common_Movement_FacePlayer
        waitmovement 0
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Matt_Movement_ToBattle1
        setvar VAR_TEMP_1, 1
        releaseall
	goto NettuxPure_Aqua4_2_Matt
        end

NettuxPure_Aqua4_2_MattNoticePlayer2::
        lockall
        setvar VAR_0x8008, LOCALID_MATT
        playse SE_PIN
        applymovement VAR_0x8008, Common_Movement_ExclamationMark
        waitmovement 0
        applymovement VAR_0x8008, Common_Movement_FacePlayer
        waitmovement 0
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_Matt_Movement_ToBattle2
        setvar VAR_TEMP_1, 1
        releaseall
	goto NettuxPure_Aqua4_2_Matt
        end

NettuxPure_Matt_Movement_ToBattle1:
        walk_down
        walk_down
        walk_down
        walk_left
        walk_left
        walk_left
        walk_left
        step_end

NettuxPure_Matt_Movement_ToBattle2:
        walk_down
        walk_down
        walk_left
        walk_left
        walk_left
        walk_left
        step_end
