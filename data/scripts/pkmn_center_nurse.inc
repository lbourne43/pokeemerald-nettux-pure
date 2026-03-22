Common_EventScript_PkmnCenterNurse::
	lock
	faceplayer
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, CountPlayerTrainerStars
	goto_if_eq VAR_RESULT, 4, EventScript_PkmnCenterNurse_GoldCard
	message Nettux_WouldYouLikeToRestYourPkmn
        multichoice 25, 7, MULTICHOICE_NETTUX_HEAL_OR_STATUS, 0
        closemessage
        compare VAR_RESULT, 0
        goto_if_eq EventScript_PkmnCenterNurse_HealPkmn
        compare VAR_RESULT, 1
	goto_if_eq EventScript_NettuxInflictStatus
        goto EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_NettuxAskInflictStatus::
	msgbox NettuxWouldYouLikeToInflictAStatus, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NettuxInflictStatus
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_PkmnCenterNurse_Goodbye::
	message gText_WeHopeToSeeYouAgain
	return

@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
EventScript_PkmnCenterNurse_HealPkmn::
	incrementgamestat GAME_STAT_USED_POKECENTER
	call_if_eq VAR_0x8004, 0, EventScript_PkmnCenterNurse_IllTakeYourPkmn
	call_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_IllTakeYourPkmn2
	waitmessage
	goto EventScript_PkmnCenterNurse_TakeAndHealPkmn
	end

EventScript_PkmnCenterNurse_IllTakeYourPkmn::
	message gText_IllTakeYourPkmn
	return

EventScript_PkmnCenterNurse_IllTakeYourPkmn2::
	message gText_IllTakeYourPkmn2
	return

EventScript_PkmnCenterNurse_TakeAndHealPkmn::
	hidefollower 0
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Turn
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
.if OW_UNION_DISABLE_CHECK == FALSE && OW_FLAG_MOVE_UNION_ROOM_CHECK != 0
	setflag OW_FLAG_MOVE_UNION_ROOM_CHECK
	call CableClub_OnResume
	clearflag OW_FLAG_MOVE_UNION_ROOM_CHECK
.endif
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	return

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom::
	specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	goto_if_eq VAR_0x8008, 1, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
	end

@ VAR_0x8004 is 1 when player has Gold Card
EventScript_PkmnCenterNurse_ReturnPkmn::
	goto_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_ReturnPkmn2
	message gText_RestoredPkmnToFullHealth
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_ReturnPkmn2::
	message gText_ThankYouForWaiting
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn
	msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
	setflag FLAG_NURSE_UNION_ROOM_REMINDER
	message CableClub_Text_PlayerIsWaiting
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_CheckPokerus::
	specialvar VAR_RESULT, IsPokerusInParty
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_ExplainPokerus
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	end

EventScript_PkmnCenterNurse_ExplainPokerus::
	message gText_PokerusExplanation
	setflag FLAG_POKERUS_EXPLAINED
	return

EventScript_PkmnCenterNurse_GoldCard::
	goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_AskForUsual
	setflag FLAG_NURSE_MENTIONS_GOLD_CARD
	msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x800B, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x800B, Common_Movement_Delay48
	waitmovement 0
	msgbox gText_NoticesGoldCard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
	message gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_AskForUsual::
	msgbox gText_YouWantTheUsual, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
	message gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_GoldCardHealPkmn::
	setvar VAR_0x8004, 1
	goto EventScript_PkmnCenterNurse_HealPkmn
	end

Movement_PkmnCenterNurse_Bow:
	nurse_joy_bow
	delay_4
	step_end

Movement_PkmnCenterNurse_Turn:
	walk_in_place_faster_left
	step_end

NettuxPure_EventScript_Mart::
        lock
        faceplayer
        message gText_HowMayIServeYou
        waitmessage
        pokemart NettuxPure_Pokemart_Basic
        msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
        release
	end

        .align 2
NettuxPure_Pokemart_Basic:
        .2byte ITEM_PREMIER_BALL
        pokemartlistend

NettuxHelper_EventScript_MartHelper::
        lockall
        faceplayer
        message NettuxHelper_EventScript_MartHelper_Text_1
        multichoice 0, 0, MULTICHOICE_NETTUX_MART_HELPER, 0
        closemessage
        compare VAR_RESULT, 0
        goto_if_eq NettuxPure_EventScript_Mart
        compare VAR_RESULT, 1
        goto_if_eq NettuxPure_EventScript_TrainingMart
        compare VAR_RESULT, 2
        goto_if_eq NettuxPure_EventScript_Relearner
        compare VAR_RESULT, 3
        goto_if_eq NettuxHelper_HyperTrain
        compare VAR_RESULT, 4
        goto_if_eq NettuxHelper_SetNature
        compare VAR_RESULT, 5
        goto_if_eq NettuxHelper_EventScript_Tera_Train
	goto NettuxHelper_ButIRefuse
	end

NettuxPure_EventScript_Relearner::
        msgbox NettuxHelper_EventScript_Move_Relearner_Text_0
        call NettuxHelper_EventScript_ChooseMonToTutor
        releaseall
        return

NettuxHelper_EventScript_ChooseMonToTutor::
        checkitem ITEM_HEART_SCALE
        goto_if_eq VAR_RESULT, FALSE, NettuxHelper_EventScript_NoHeartScale
        msgbox NettuxHelper_Text_TutorWhichMon
        special ChooseMonForMoveRelearner
        waitstate
        goto_if_ge VAR_0x8004, PARTY_SIZE, NettuxHelper_EventScript_EndTutorMove
        special IsSelectedMonEgg
        goto_if_eq VAR_RESULT, TRUE, NettuxHelper_EventScript_CantTutorEgg
        goto_if_eq VAR_0x8005, 0, NettuxHelper_EventScript_NoMoveToTutorMon
        goto NettuxHelper_EventScript_ChooseMoveToTeach
        end

NettuxHelper_EventScript_ChooseMoveToTeach::
        msgbox NettuxHelper_Text_TeachWhichMove
        special TeachMoveRelearnerMove
        waitstate
        goto_if_eq VAR_0x8004, 0, NettuxHelper_EventScript_ChooseMonToTutor
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        removeitem ITEM_HEART_SCALE
	closemessage
        end

NettuxHelper_EventScript_NoMoveToTutorMon::
        msgbox NettuxHelper_Text_NoMoveICanTeachThatMon
        goto NettuxHelper_EventScript_ChooseMonToTutor
        end

NettuxHelper_EventScript_CantTutorEgg::
        msgbox NettuxHelper_Text_CantTeachAnEgg
        goto NettuxHelper_EventScript_ChooseMonToTutor
        end

NettuxHelper_EventScript_EndTutorMove::
        release
        end

NettuxPure_Text_HandedOverHeartScale:
        .string "{PLAYER} handed over one HEART SCALE\n"
        .string "in exchange.$"

NettuxHelper_Text_WantMeToTeachMove::
    .string "Do you want me to teach a move\n"
    .string "to a POKéMON of yours?$"

NettuxHelper_Text_TutorWhichMon::
    .string "Which POKéMON needs tutoring?$"

NettuxHelper_Text_TeachWhichMove::
    .string "Which move should I teach?$"

NettuxHelper_Text_NoMoveICanTeachThatMon::
    .string "Sorry…\p"
    .string "It doesn't appear as if I have a\n"
    .string "move I can teach that POKéMON.$"

NettuxHelper_Text_CantTeachAnEgg::
    .string "Hunh? There isn't a single move\n"
    .string "that I can teach an EGG.$"

NettuxHelper_EventScript_MartHelper_4:
        msgbox NettuxHelper_EventScript_MartHelper_Text_2
        waitmessage
        release
        return

NettuxHelper_EventScript_MartHelper_5:
        call NettuxHelper_EventScript_BattleMart
        goto NettuxHelper_EventScript_MartHelper_4

NettuxPure_EventScript_TrainingMart:
        call NettuxHelper_EventScript_TrainingMart
        goto NettuxHelper_EventScript_MartHelper_4

NettuxHelper_EventScript_MartHelper_7:
        call NettuxHelper_EventScript_TMMart
        goto NettuxHelper_EventScript_MartHelper_4

NettuxHelper_EventScript_MartHelper_8:
        call NettuxHelper_EventScript_EvolveMart
        goto NettuxHelper_EventScript_MartHelper_4


NettuxHelper_EventScript_BattleMart::
        lock
        message NettuxHelper_EventScript_BattleMart_Text_0
        waitmessage
        pokemart NettuxBattleMartItems
        msgbox NettuxHelper_EventScript_BattleMart_Text_1
        release
        return


NettuxHelper_EventScript_TrainingMart::
        lock
        message NettuxHelper_EventScript_TrainingMart_Text_0
        waitmessage
        pokemart NettuxTrainingMartItems
        msgbox NettuxHelper_EventScript_BattleMart_Text_1
        release
        return


NettuxHelper_EventScript_TMMart::
        lock
        message NettuxHelper_EventScript_TMMart_Text_0
        waitmessage
        pokemart NettuxTMMartItems
        msgbox NettuxHelper_EventScript_BattleMart_Text_1
        release
        return


NettuxHelper_EventScript_EvolveMart::
        lock
        message NettuxHelper_EventScript_EvolveMart_Text_0
        waitmessage
        pokemart NettuxEvolveMartItems
        msgbox NettuxHelper_EventScript_BattleMart_Text_1
        release
        return

        .align 2
NettuxBattleMartItems:
        .2byte ITEM_EXP_SHARE
        .2byte ITEM_NONE

        .align 2
NettuxTrainingMartItems:
        .2byte ITEM_EXP_CANDY_XS
        .2byte ITEM_NONE

        .align 2
NettuxTMMartItems:
        .2byte ITEM_TM_PROTECT
        .2byte ITEM_NONE

        .align 2
NettuxEvolveMartItems:
        .2byte ITEM_LINKING_CORD
        .2byte ITEM_NONE

NettuxHelper_EventScript_MartHelper_Text_1:
        .string "Do you want a pokemon?$"

NettuxHelper_EventScript_MartHelper_Text_2:
        .string "Come back anytime!$"

NettuxHelper_EventScript_BattleMart_Text_0:
        .string "Ready to Battle?$"

NettuxHelper_EventScript_BattleMart_Text_1:
        .string "Level up!$"

NettuxHelper_EventScript_TrainingMart_Text_0:
        .string "Ready to Train?$"

NettuxHelper_EventScript_TMMart_Text_0:
        .string "Ready to Learn?$"

NettuxHelper_EventScript_EvolveMart_Text_0:
        .string "Ready to Evolve?$"


NettuxHelper_Text_WhichStat:
    .string "Which stat shoud I raise?$"

NettuxHelper_Text_WhichStatus:
    .string "Which status shoud I inflict?$"

NettuxHelper_SetIVs::
        checkitem ITEM_HEART_SCALE
        goto_if_eq VAR_RESULT, FALSE, NettuxHelper_EventScript_NoHeartScale
        special ChoosePartyMon
        waitstate
        compare VAR_0x8004, PARTY_SIZE
        goto_if_ge NettuxHelper_ButIRefuse
        specialvar VAR_RESULT, ScriptGetPartyMonSpecies
        compare VAR_RESULT, SPECIES_EGG
        goto_if_eq NettuxHelper_Rejected
        message NettuxHelper_Text_WhichStat
        multichoice 0, 0, MULTICHOICE_NETTUX_HYPER_TRAINER, 0
        closemessage
        compare VAR_RESULT, 0
        goto_if_eq NettuxHelper_SetHpIVs_Proceed
        compare VAR_RESULT, 1
        goto_if_eq NettuxHelper_SetAtkIVs_Proceed
        compare VAR_RESULT, 2
        goto_if_eq NettuxHelper_SetDefIVs_Proceed
        compare VAR_RESULT, 3
        goto_if_eq NettuxHelper_SetSpaIVs_Proceed
        compare VAR_RESULT, 4
        goto_if_eq NettuxHelper_SetSpdIVs_Proceed
        compare VAR_RESULT, 5
        goto_if_eq NettuxHelper_SetSpeIVs_Proceed

        goto NettuxHelper_ButIRefuse


NettuxHelper_SetHpIVs_Proceed:
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special MaxHpIvs
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        msgbox NettuxHelper_IVsSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetAtkIVs_Proceed:
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special MaxAtkIvs
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        msgbox NettuxHelper_IVsSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetDefIVs_Proceed:
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special MaxDefIvs
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        msgbox NettuxHelper_IVsSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetSpaIVs_Proceed:
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special MaxSpAtkIvs
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        msgbox NettuxHelper_IVsSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetSpdIVs_Proceed:
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special MaxSpDefIvs
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        msgbox NettuxHelper_IVsSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetSpeIVs_Proceed:
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special MaxSpdIvs
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        msgbox NettuxHelper_IVsSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_ButIRefuse:
        lockall
        faceplayer
        msgbox NettuxHelper_ComeBackAnytime 6
        releaseall
        end

NettuxHelper_Rejected:
        lockall
        faceplayer
        msgbox NettuxHelper_Reject 6
        releaseall
        end

NettuxHelper_IVsSetSuccessfully:
        .string "Hyper training complete!\n"
        .string "Come back anytime.$"

NettuxHelper_Reject:
        .string "Sorry, I can't modify the stats\n"
        .string "of an EGG.$"

NettuxHelper_ComeBackAnytime:
        .string "Come back anytime.$"

NettuxHelper_HyperTrain::
        faceplayer
        msgbox NettuxHelper_HyperTrain_Text_0, MSGBOX_YESNO
        compare VAR_RESULT, YES
        goto_if_eq NettuxHelper_HyperTrain_1
        msgbox NettuxHelper_HyperTrain_Text_1, MSGBOX_NPC
        applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
        callnative UpdateFollowingPokemon
        return

NettuxHelper_HyperTrain_1:
        goto NettuxHelper_SetIVs
        return

NettuxHelper_EventScript_NoHeartScale::
        msgbox NettuxHelper_EventScript_Text_NoHeartScale, MSGBOX_NPC
        return

NettuxHelper_EventScript_NotEnoughMoneyHyperTrain::
        msgbox NettuxHelper_EventScript_Text_NoMoney, MSGBOX_NPC
        return

NettuxHelper_EventScript_Text_NoMoney:
        .string "Not enough money!$"

NettuxHelper_HyperTrain_Text_0:
        .string "Would you like to hyper train a POKéMON\n"
        .string "in exchange for a HEART SCALE?$"

NettuxHelper_HyperTrain_Text_1:
        .string "Come back anytime.$"

NettuxHelper_EventScript_Text_NoHeartScale:
        .string "You need a HEART SCALE.$"

NettuxHelper_SetNature::
        checkitem ITEM_HEART_SCALE
        goto_if_eq VAR_RESULT, FALSE, NettuxHelper_EventScript_NoHeartScale
        special ChoosePartyMon
        waitstate
        compare VAR_0x8004, PARTY_SIZE
        goto_if_ge NettuxHelper_ButIRefuse
        specialvar VAR_RESULT, ScriptGetPartyMonSpecies
        compare VAR_RESULT, SPECIES_EGG
        goto_if_eq NettuxHelper_Rejected
	msgbox NettuxPure_Text_WhichNature, MSGBOX_DEFAULT
        closemessage
        multichoicegrid 0, 0, MULTICHOICE_NETTUX_RENATURE, 4, 0
        compare VAR_RESULT, 0
        goto_if_eq NettuxPure_SetNatureAdamant
        compare VAR_RESULT, 1
        goto_if_eq NettuxPure_SetNatureBashful
        compare VAR_RESULT, 2
        goto_if_eq NettuxPure_SetNatureBold
        compare VAR_RESULT, 3
        goto_if_eq NettuxPure_SetNatureBrave
        compare VAR_RESULT, 4
        goto_if_eq NettuxPure_SetNatureCalm
        compare VAR_RESULT, 5
        goto_if_eq NettuxPure_SetNatureCareful
        compare VAR_RESULT, 6
        goto_if_eq NettuxPure_SetNatureGentle
        compare VAR_RESULT, 7
        goto_if_eq NettuxPure_SetNatureHardy
        compare VAR_RESULT, 8
        goto_if_eq NettuxPure_SetNatureHasty
        compare VAR_RESULT, 9
        goto_if_eq NettuxPure_SetNatureImpish
        compare VAR_RESULT, 10
        goto_if_eq NettuxPure_SetNatureJolly
        compare VAR_RESULT, 11
        goto_if_eq NettuxPure_SetNatureLax
        compare VAR_RESULT, 12
        goto_if_eq NettuxPure_SetNatureLonely
        compare VAR_RESULT, 13
        goto_if_eq NettuxPure_SetNatureMild
        compare VAR_RESULT, 14
        goto_if_eq NettuxPure_SetNatureModest
        compare VAR_RESULT, 15
        goto_if_eq NettuxPure_SetNatureNaive
        compare VAR_RESULT, 16
        goto_if_eq NettuxPure_SetNatureNaughty
        compare VAR_RESULT, 17
        goto_if_eq NettuxPure_SetNatureQuiet
        compare VAR_RESULT, 18
        goto_if_eq NettuxPure_SetNatureQuirky
        compare VAR_RESULT, 19
        goto_if_eq NettuxPure_SetNatureRash
        compare VAR_RESULT, 20
        goto_if_eq NettuxPure_SetNatureRelaxed
        compare VAR_RESULT, 21
        goto_if_eq NettuxPure_SetNatureSassy
        compare VAR_RESULT, 22
        goto_if_eq NettuxPure_SetNatureSerious
        compare VAR_RESULT, 23
        goto_if_eq NettuxPure_SetNatureTimid

        goto NettuxHelper_ButIRefuse

NettuxHelper_EventScript_Tera_Train::
        msgbox NettuxHelper_EventScript_Tera_Train_Text_0
        call NettuxHelper_TeraTrain
        releaseall
        return

NettuxHelper_SetTera::
        checkitem ITEM_HEART_SCALE
        goto_if_eq VAR_RESULT, FALSE, NettuxHelper_EventScript_NotEnoughMoneyHyperTrain
        special ChoosePartyMon
        waitstate
        compare VAR_0x8004, PARTY_SIZE
        goto_if_ge NettuxHelper_ButIRefuse
        specialvar VAR_RESULT, ScriptGetPartyMonSpecies
        compare VAR_RESULT, SPECIES_EGG
        goto_if_eq NettuxHelper_Rejected
        message NettuxHelper_Text_WhichStat
        multichoicegrid 0, 0, MULTICHOICE_NETTUX_TERA_TRAINER, 3, 0
        closemessage
        compare VAR_RESULT, 0
        goto_if_eq NettuxHelper_SetNormalTera_Proceed
        compare VAR_RESULT, 1
        goto_if_eq NettuxHelper_SetFireTera_Proceed
        compare VAR_RESULT, 2
        goto_if_eq NettuxHelper_SetWaterTera_Proceed
        compare VAR_RESULT, 3
        goto_if_eq NettuxHelper_SetElectricTera_Proceed
        compare VAR_RESULT, 4
        goto_if_eq NettuxHelper_SetGrassTera_Proceed
        compare VAR_RESULT, 5
        goto_if_eq NettuxHelper_SetIceTera_Proceed
        compare VAR_RESULT, 6
        goto_if_eq NettuxHelper_SetFightingTera_Proceed
        compare VAR_RESULT, 7
        goto_if_eq NettuxHelper_SetPoisonTera_Proceed
        compare VAR_RESULT, 8
        goto_if_eq NettuxHelper_SetGroundTera_Proceed
        compare VAR_RESULT, 9
        goto_if_eq NettuxHelper_SetFlyingTera_Proceed
        compare VAR_RESULT, 10
        goto_if_eq NettuxHelper_SetPsychicTera_Proceed
        compare VAR_RESULT, 11
        goto_if_eq NettuxHelper_SetBugTera_Proceed
        compare VAR_RESULT, 12
        goto_if_eq NettuxHelper_SetRockTera_Proceed
        compare VAR_RESULT, 13
        goto_if_eq NettuxHelper_SetGhostTera_Proceed
        compare VAR_RESULT, 14
        goto_if_eq NettuxHelper_SetDragonTera_Proceed
        compare VAR_RESULT, 15
        goto_if_eq NettuxHelper_SetDarkTera_Proceed
        compare VAR_RESULT, 16
        goto_if_eq NettuxHelper_SetSteelTera_Proceed
        compare VAR_RESULT, 17
        goto_if_eq NettuxHelper_SetFairyTera_Proceed
        compare VAR_RESULT, 18
        goto_if_eq NettuxHelper_SetStellarTera_Proceed

        goto NettuxHelper_ButIRefuse


NettuxHelper_SetNormalTera_Proceed:
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        setteratype TYPE_NORMAL VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetFireTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_FIRE VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetWaterTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_WATER VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetElectricTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_ELECTRIC VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetGrassTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_GRASS VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetIceTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_ICE VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetFightingTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_FIGHTING VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetPoisonTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_POISON VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetGroundTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_GROUND VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetFlyingTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_FLYING VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetPsychicTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_PSYCHIC VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetBugTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_BUG VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end


NettuxHelper_SetRockTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_ROCK VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetGhostTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_GHOST VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetDragonTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_DRAGON VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetDarkTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_DARK VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetSteelTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_STEEL VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetFairyTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_FAIRY VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetStellarTera_Proceed:
        lockall
        faceplayer
	removeitem ITEM_HEART_SCALE
        setteratype TYPE_STELLAR VAR_0x8004
        msgbox NettuxHelper_TeraSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_TeraTrain::
        faceplayer
        msgbox NettuxHelper_TeraTrain_Text_0, MSGBOX_YESNO
        compare VAR_RESULT, YES
        goto_if_eq NettuxHelper_TeraTrain_1
        msgbox NettuxHelper_TeraTrain_Text_1, MSGBOX_NPC
        applymovement VAR_LAST_TALKED, Movement_PkmnCenterNurse_Turn @ Changed from Common_Movement_WalkInPlaceFasterLeft to force the follower to enter their Poké Ball
        applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
        callnative UpdateFollowingPokemon
        return

NettuxHelper_TeraTrain_1:
        goto NettuxHelper_SetTera
        return

NettuxHelper_EventScript_NotEnoughMoneyTeraTrain::
        msgbox NettuxHelper_EventScript_NotEnoughMoneyTeraTrain_Text_0, MSGBOX_NPC
        return

EventScript_NettuxInflictStatus::
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge NettuxHelper_ButIRefuse
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq NettuxHelper_Rejected
	message NettuxHelper_Text_WhichStatus
	multichoice 0, 0, MULTICHOICE_NETTUX_STATUS, 0
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq NettuxHelper_SetBurn_Proceed
	compare VAR_RESULT, 1
	goto_if_eq NettuxHelper_SetFreeze_Proceed
	compare VAR_RESULT, 2
	goto_if_eq NettuxHelper_SetParalysis_Proceed
	compare VAR_RESULT, 3
	goto_if_eq NettuxHelper_SetSleep_Proceed
	compare VAR_RESULT, 4
	goto_if_eq NettuxHelper_SetPoison_Proceed
	compare VAR_RESULT, 5
	goto_if_eq NettuxHelper_SetToxic_Proceed
	compare VAR_RESULT, 6
        return

NettuxHelper_SetBurn_Proceed::
        lockall
        faceplayer
        special nettuxInflictBurn
        msgbox NettuxHelper_StatusSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetFreeze_Proceed::
        lockall
        faceplayer
        special nettuxInflictFreeze
        msgbox NettuxHelper_StatusSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetParalysis_Proceed::
        lockall
        faceplayer
        special nettuxInflictParalysis
        msgbox NettuxHelper_StatusSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetSleep_Proceed::
        lockall
        faceplayer
        special nettuxInflictSleep
        msgbox NettuxHelper_StatusSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetPoison_Proceed::
        lockall
        faceplayer
        special nettuxInflictPoison
        msgbox NettuxHelper_StatusSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxHelper_SetToxic_Proceed::
        lockall
        faceplayer
        special nettuxInflictToxicPoison
        msgbox NettuxHelper_StatusSetSuccessfully 4
        closemessage
        releaseall
        end

NettuxPure_SetNatureAdamant::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureAdamant
        msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureBashful::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureBashful
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureBold::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureBold
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureBrave::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureBrave
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureCalm::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureCalm
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureCareful::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureCareful
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureGentle::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureGentle
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureHardy::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureHardy
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureHasty::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureHasty
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureImpish::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureImpish
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureJolly::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureJolly
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureLax::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureLax
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureLonely::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureLonely
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureMild::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureMild
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureModest::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureModest
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureNaive::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureNaive
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureNaughty::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureNaughty
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureQuiet::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureQuiet
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureQuirky::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureQuirky
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureRash::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureRash
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureRelaxed::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureRelaxed
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureSassy::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureSassy
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureSerious::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureSerious
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxPure_SetNatureTimid::
        lockall
        faceplayer
        removeitem ITEM_HEART_SCALE
        special SetNatureTimid
	msgbox NettuxHelper_Text_NatureChanged 4
	playse SE_SHOP
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        msgbox NettuxPure_Text_HandedOverHeartScale, MSGBOX_DEFAULT
        closemessage
        releaseall
        end

NettuxHelper_Text_NatureChanged:
        .string "Nature changed.$"

NettuxHelper_TeraTrain_Text_0:
        .string "Tera train a pokemon in exchange\l"
        .string "for a HEART SCALE?$"

NettuxHelper_TeraTrain_Text_1:
        .string "Come back anytime.$"

NettuxHelper_EventScript_NotEnoughMoneyTeraTrain_Text_0:
        .string "Come back with a HEART SCALE.$"

NettuxHelper_EventScript_Tera_Train_Text_0:
        .string "Tera Train!$"

NettuxHelper_TeraSetSuccessfully:
        .string "Tera training complete!\n"
        .string "Come back anytime.$"

NettuxHelper_StatusSetSuccessfully:
        .string "Status inflicted!\n"
        .string "Come back anytime.$"

NettuxWouldYouLikeToInflictAStatus:
        .string "Inflict a status?$"

Nettux_WouldYouLikeToRestYourPkmn:
        .string "Would you like to heal\n"
	.string "or inflict a status?$"

NettuxHelper_EventScript_Move_Relearner_Text_0:
        .string "I can make your POKéMON relearn\n"
        .string "a move that it used to know in\p"
        .string "exchange for a HEART SCALE!$"

NettuxPure_Text_WhichNature:
        .string "Which nature would you like?$"
