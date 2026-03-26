NettuxPure_Base_Upstairs_MapScripts::
	.byte 0

NettuxPure_Base_Upstairs_Go::
        warp MAP_NETTUX_PURE_HUB, 0

NettuxPure_Base_Tutors_Weather::
        lock
        faceplayer
        showmoneybox 15, 0
        msgbox NettuxPure_Tutor_Text_WeatherTutor, MSGBOX_DEFAULT
        checkmoney 1000
        goto_if_eq VAR_RESULT, FALSE, NettuxPure_Base_NotEnoughMoney
        multichoice 0, 0, MULTICHOICE_NETTUX_TUTORS_WEATHER, 0
        closemessage
	hidemoneybox
        compare VAR_RESULT, 0
        goto_if_eq NettuxPure_Base_Tutors_TeachSunnyDay
        compare VAR_RESULT, 1
        goto_if_eq NettuxPure_Base_Tutors_TeachRainDance
        compare VAR_RESULT, 2
        goto_if_eq NettuxPure_Base_Tutors_TeachSnowscape
        compare VAR_RESULT, 3
        goto_if_eq NettuxPure_Base_Tutors_TeachSandstorm
        compare VAR_RESULT, 4
        goto_if_eq NettuxPure_Base_Tutors_TeachWeatherBall
        goto NettuxPure_Tutor_Declined
	end

NettuxPure_Base_Tutors_TeachSunnyDay::
        movetutor MOVE_SUNNY_DAY, NettuxPure_Tutor_Text_TeachSunnyDay
	end

NettuxPure_Base_Tutors_TeachRainDance::
        movetutor MOVE_RAIN_DANCE, NettuxPure_Tutor_Text_TeachRainDance
        end

NettuxPure_Base_Tutors_TeachSnowscape::
        movetutor MOVE_SNOWSCAPE, NettuxPure_Tutor_Text_TeachSnowscape
        end

NettuxPure_Base_Tutors_TeachSandstorm::
        movetutor MOVE_SANDSTORM, NettuxPure_Tutor_Text_TeachSandstorm
        end

NettuxPure_Base_Tutors_TeachWeatherBall::
        movetutor MOVE_WEATHER_BALL, NettuxPure_Tutor_Text_TeachWeatherBall
        end



NettuxPure_Base_Tutors_Switch::
        lock
        faceplayer
	goto_if_unset FLAG_BADGE02_GET, NettuxPure_Tutor_Need2Badges
	showmoneybox 15, 0
        msgbox NettuxPure_Tutor_Text_SwitchTutor, MSGBOX_DEFAULT
        checkmoney 2000
        goto_if_eq VAR_RESULT, FALSE, NettuxPure_Base_NotEnoughMoney
        multichoice 0, 0, MULTICHOICE_NETTUX_TUTORS_SWITCH, 0
        closemessage
	hidemoneybox
        compare VAR_RESULT, 0
        goto_if_eq NettuxPure_Base_Tutors_TeachUTurn
        compare VAR_RESULT, 1
        goto_if_eq NettuxPure_Base_Tutors_TeachVoltSwitch
        compare VAR_RESULT, 2
        goto_if_eq NettuxPure_Base_Tutors_TeachFlipTurn
        compare VAR_RESULT, 3
        goto_if_eq NettuxPure_Base_Tutors_TeachPartingShot
        compare VAR_RESULT, 4
        goto_if_eq NettuxPure_Base_Tutors_TeachBatonPass
        goto NettuxPure_Tutor_Declined
        end

NettuxPure_Base_Tutors_TeachUTurn::
        movetutor MOVE_U_TURN, NettuxPure_Tutor_Text_TeachUTurn
        end

NettuxPure_Base_Tutors_TeachVoltSwitch::
        movetutor MOVE_VOLT_SWITCH, NettuxPure_Tutor_Text_TeachVoltSwitch
        end

NettuxPure_Base_Tutors_TeachFlipTurn::
        movetutor MOVE_FLIP_TURN, NettuxPure_Tutor_Text_TeachFlipTurn
        end

NettuxPure_Base_Tutors_TeachPartingShot::
        movetutor MOVE_PARTING_SHOT, NettuxPure_Tutor_Text_TeachPartingShot
        end

NettuxPure_Base_Tutors_TeachBatonPass::
        movetutor MOVE_BATON_PASS, NettuxPure_Tutor_Text_TeachBatonPass
        end

NettuxPure_Base_Tutors_Priority::
        lock
        faceplayer
	goto_if_unset FLAG_BADGE02_GET, NettuxPure_Tutor_Need2Badges
	showmoneybox 15, 0
        msgbox NettuxPure_Tutor_Text_PriorityTutor, MSGBOX_DEFAULT
        checkmoney 1000
        goto_if_eq VAR_RESULT, FALSE, NettuxPure_Base_NotEnoughMoney
        multichoice 0, 0, MULTICHOICE_NETTUX_TUTORS_PRIORITY, 0
        closemessage
	hidemoneybox
        compare VAR_RESULT, 0
        goto_if_eq NettuxPure_Base_Tutors_TeachQuickAttack
        compare VAR_RESULT, 1
        goto_if_eq NettuxPure_Base_Tutors_TeachMachPunch
        compare VAR_RESULT, 2
        goto_if_eq NettuxPure_Base_Tutors_TeachIceShard
        compare VAR_RESULT, 3
        goto_if_eq NettuxPure_Base_Tutors_TeachAquaJet
        compare VAR_RESULT, 4
        goto_if_eq NettuxPure_Base_Tutors_TeachShadowSneak
        compare VAR_RESULT, 5
        goto_if_eq NettuxPure_Base_Tutors_TeachBulletPunch
        goto NettuxPure_Tutor_Declined
        end

NettuxPure_Base_Tutors_Punch::
        lock
        faceplayer
	goto_if_unset FLAG_BADGE02_GET, NettuxPure_Tutor_Need2Badges
	showmoneybox 15, 0
        msgbox NettuxPure_Tutor_Text_PunchTutor, MSGBOX_DEFAULT
        checkmoney 3000
        goto_if_eq VAR_RESULT, FALSE, NettuxPure_Base_NotEnoughMoney
        multichoice 0, 0, MULTICHOICE_NETTUX_TUTORS_PUNCH, 0
        closemessage
	hidemoneybox
        compare VAR_RESULT, 0
        goto_if_eq NettuxPure_Base_Tutors_TeachThunderPunch
        compare VAR_RESULT, 1
        goto_if_eq NettuxPure_Base_Tutors_TeachFirePunch
        compare VAR_RESULT, 2
        goto_if_eq NettuxPure_Base_Tutors_TeachIcePunch
        compare VAR_RESULT, 3
        goto_if_eq NettuxPure_Base_Tutors_TeachPoisonJab
        compare VAR_RESULT, 4
        goto_if_eq NettuxPure_Base_Tutors_TeachDrainPunch
        compare VAR_RESULT, 5
        goto_if_eq NettuxPure_Base_Tutors_TeachSuckerPunch
        compare VAR_RESULT, 6
        goto_if_eq NettuxPure_Base_Tutors_TeachBrickBreak
        goto NettuxPure_Tutor_Declined
        end

NettuxPure_Base_Tutors_TeachThunderPunch::
        movetutor MOVE_THUNDER_PUNCH, NettuxPure_Tutor_Text_TeachThunderPunch
        end

NettuxPure_Base_Tutors_TeachFirePunch::
        movetutor MOVE_FIRE_PUNCH, NettuxPure_Tutor_Text_TeachFirePunch
        end

NettuxPure_Base_Tutors_TeachIcePunch::
        movetutor MOVE_ICE_PUNCH, NettuxPure_Tutor_Text_TeachIcePunch
        end

NettuxPure_Base_Tutors_TeachSludgeBomb::
        movetutor MOVE_SLUDGE_BOMB, NettuxPure_Tutor_Text_TeachSludgeBomb
        end

NettuxPure_Base_Tutors_TeachPoisonJab::
        movetutor MOVE_POISON_JAB, NettuxPure_Tutor_Text_TeachPoisonJab
        end

NettuxPure_Base_Tutors_TeachBrickBreak::
        movetutor MOVE_BRICK_BREAK, NettuxPure_Tutor_Text_TeachBrickBreak
        end

NettuxPure_Base_Tutors_TeachDrainPunch::
        movetutor MOVE_DRAIN_PUNCH, NettuxPure_Tutor_Text_TeachDrainPunch
        end

NettuxPure_Base_Tutors_TeachSuckerPunch::
        movetutor MOVE_SUCKER_PUNCH, NettuxPure_Tutor_Text_TeachSuckerPunch
        end

NettuxPure_Base_Tutors_TeachMachPunch::
        movetutor MOVE_MACH_PUNCH, NettuxPure_Tutor_Text_TeachMachPunch
        end

NettuxPure_Base_Tutors_TeachBulletPunch::
        movetutor MOVE_BULLET_PUNCH, NettuxPure_Tutor_Text_TeachBulletPunch
        end

NettuxPure_Base_Tutors_TeachQuickAttack::
        movetutor MOVE_QUICK_ATTACK, NettuxPure_Tutor_Text_TeachQuickAttack
        end

NettuxPure_Base_Tutors_TeachAquaJet::
        movetutor MOVE_AQUA_JET, NettuxPure_Tutor_Text_TeachAquaJet
        end

NettuxPure_Base_Tutors_TeachIceShard::
        movetutor MOVE_ICE_SHARD, NettuxPure_Tutor_Text_TeachIceShard
        end

NettuxPure_Base_Tutors_TeachShadowSneak::
        movetutor MOVE_SHADOW_SNEAK, NettuxPure_Tutor_Text_TeachShadowSneak
        end

NettuxPure_Base_Tutors_Bite::
        lock
        faceplayer
	goto_if_unset FLAG_BADGE02_GET, NettuxPure_Tutor_Need2Badges
	showmoneybox 15, 0
        msgbox NettuxPure_Tutor_Text_BiteTutor, MSGBOX_DEFAULT
        checkmoney 3000
        goto_if_eq VAR_RESULT, FALSE, NettuxPure_Base_NotEnoughMoney
        multichoice 0, 0, MULTICHOICE_NETTUX_TUTORS_BITE, 0
        closemessage
	hidemoneybox
        compare VAR_RESULT, 0
        goto_if_eq NettuxPure_Base_Tutors_TeachPsychicFangs
        compare VAR_RESULT, 1
        goto_if_eq NettuxPure_Base_Tutors_TeachThunderFang
        compare VAR_RESULT, 2
        goto_if_eq NettuxPure_Base_Tutors_TeachFireFang
        compare VAR_RESULT, 3
        goto_if_eq NettuxPure_Base_Tutors_TeachIceFang
	compare VAR_RESULT, 4
        goto_if_eq NettuxPure_Base_Tutors_TeachPoisonFang
	compare VAR_RESULT, 5
        goto_if_eq NettuxPure_Base_Tutors_TeachCrunch
        goto NettuxPure_Tutor_Declined
        end

NettuxPure_Base_Tutors_TeachPsychicFangs::
        movetutor MOVE_PSYCHIC_FANGS, NettuxPure_Tutor_Text_TeachPsychicFangs
        end

NettuxPure_Base_Tutors_TeachThunderFang::
        movetutor MOVE_THUNDER_FANG, NettuxPure_Tutor_Text_TeachThunderFang
        end

NettuxPure_Base_Tutors_TeachFireFang::
        movetutor MOVE_FIRE_FANG, NettuxPure_Tutor_Text_TeachFireFang
        end

NettuxPure_Base_Tutors_TeachIceFang::
        movetutor MOVE_ICE_FANG, NettuxPure_Tutor_Text_TeachIceFang
        end

NettuxPure_Base_Tutors_TeachPoisonFang::
        movetutor MOVE_POISON_FANG, NettuxPure_Tutor_Text_TeachPoisonFang
        end

NettuxPure_Base_Tutors_TeachCrunch::
        movetutor MOVE_CRUNCH, NettuxPure_Tutor_Text_TeachCrunch
        end


NettuxPure_Base_Tutors_Accuracy::
        lock
        faceplayer
	goto_if_unset FLAG_BADGE02_GET, NettuxPure_Tutor_Need4Badges
	showmoneybox 15, 0
        msgbox NettuxPure_Tutor_Text_AccuracyTutor, MSGBOX_DEFAULT
        checkmoney 4000
        goto_if_eq VAR_RESULT, FALSE, NettuxPure_Base_NotEnoughMoney
        multichoice 0, 0, MULTICHOICE_NETTUX_TUTORS_ACCURACY, 0
        closemessage
	hidemoneybox
        compare VAR_RESULT, 0
        goto_if_eq NettuxPure_Base_Tutors_TeachAerialAce
        compare VAR_RESULT, 1
        goto_if_eq NettuxPure_Base_Tutors_TeachSwift
        compare VAR_RESULT, 2
        goto_if_eq NettuxPure_Base_Tutors_TeachShadowPunch
        compare VAR_RESULT, 3
        goto_if_eq NettuxPure_Base_Tutors_TeachSmartStrike
        compare VAR_RESULT, 4
        goto_if_eq NettuxPure_Base_Tutors_TeachAuraSphere
        compare VAR_RESULT, 5
        goto_if_eq NettuxPure_Base_Tutors_TeachShockWave
        compare VAR_RESULT, 6
        goto_if_eq NettuxPure_Base_Tutors_TeachMagicalLeaf
        compare VAR_RESULT, 7
        goto_if_eq NettuxPure_Base_Tutors_TeachFeintAttack
        goto NettuxPure_Tutor_Declined
        end

NettuxPure_Base_Tutors_TeachAerialAce::
        movetutor MOVE_AERIAL_ACE, NettuxPure_Tutor_Text_TeachAerialAce
        end

NettuxPure_Base_Tutors_TeachSwift::
        movetutor MOVE_SWIFT, NettuxPure_Tutor_Text_TeachSwift
        end

NettuxPure_Base_Tutors_TeachShadowPunch::
        movetutor MOVE_SHADOW_PUNCH, NettuxPure_Tutor_Text_TeachShadowPunch
        end

NettuxPure_Base_Tutors_TeachSmartStrike::
        movetutor MOVE_SMART_STRIKE, NettuxPure_Tutor_Text_TeachSmartStrike
        end

NettuxPure_Base_Tutors_TeachAuraSphere::
        movetutor MOVE_AURA_SPHERE, NettuxPure_Tutor_Text_TeachAuraSphere
        end

NettuxPure_Base_Tutors_TeachShockWave::
        movetutor MOVE_SHOCK_WAVE, NettuxPure_Tutor_Text_TeachShockWave
        end

NettuxPure_Base_Tutors_TeachMagicalLeaf::
        movetutor MOVE_MAGICAL_LEAF, NettuxPure_Tutor_Text_TeachMagicalLeaf
        end

NettuxPure_Base_Tutors_TeachFeintAttack::
        movetutor MOVE_FEINT_ATTACK, NettuxPure_Tutor_Text_TeachFeintAttack
        end


NettuxPure_Base_Tutors_Special::
        lock
        faceplayer
	goto_if_unset FLAG_BADGE04_GET, NettuxPure_Tutor_Need4Badges
	showmoneybox 15, 0
        msgbox NettuxPure_Tutor_Text_SpecialTutor, MSGBOX_DEFAULT
        checkmoney 5000
        goto_if_eq VAR_RESULT, FALSE, NettuxPure_Base_NotEnoughMoney
        multichoice 0, 0, MULTICHOICE_NETTUX_TUTORS_SPECIAL, 0
        closemessage
	hidemoneybox
        compare VAR_RESULT, 0
        goto_if_eq NettuxPure_Base_Tutors_TeachThunderbolt
        compare VAR_RESULT, 1
        goto_if_eq NettuxPure_Base_Tutors_TeachEnergyBall
        compare VAR_RESULT, 2
        goto_if_eq NettuxPure_Base_Tutors_TeachFlamethrower
        compare VAR_RESULT, 3
        goto_if_eq NettuxPure_Base_Tutors_TeachPsychic
        compare VAR_RESULT, 4
        goto_if_eq NettuxPure_Base_Tutors_TeachShadowBall
        compare VAR_RESULT, 5
        goto_if_eq NettuxPure_Base_Tutors_TeachEarthPower
        compare VAR_RESULT, 6
        goto_if_eq NettuxPure_Base_Tutors_TeachIceBeam
        compare VAR_RESULT, 7
        goto_if_eq NettuxPure_Base_Tutors_TeachWaterPulse
        compare VAR_RESULT, 8
        goto_if_eq NettuxPure_Base_Tutors_TeachSludgeBomb
        goto NettuxPure_Tutor_Declined
        end

NettuxPure_Base_Tutors_TeachThunderbolt::
        movetutor MOVE_THUNDERBOLT, NettuxPure_Tutor_Text_TeachThunderbolt
        end

NettuxPure_Base_Tutors_TeachFlamethrower::
        movetutor MOVE_FLAMETHROWER, NettuxPure_Tutor_Text_TeachFlamethrower
        end

NettuxPure_Base_Tutors_TeachEnergyBall::
        movetutor MOVE_ENERGY_BALL, NettuxPure_Tutor_Text_TeachEnergyBall
        end

NettuxPure_Base_Tutors_TeachPsychic::
        movetutor MOVE_PSYCHIC, NettuxPure_Tutor_Text_TeachPsychic
        end

NettuxPure_Base_Tutors_TeachShadowBall::
        movetutor MOVE_SHADOW_BALL, NettuxPure_Tutor_Text_TeachShadowBall
        end

NettuxPure_Base_Tutors_TeachEarthPower::
        movetutor MOVE_EARTH_POWER, NettuxPure_Tutor_Text_TeachEarthPower
        end

NettuxPure_Base_Tutors_TeachIceBeam::
        movetutor MOVE_ICE_BEAM, NettuxPure_Tutor_Text_TeachIceBeam
        end

NettuxPure_Base_Tutors_TeachWaterPulse::
        movetutor MOVE_WATER_PULSE, NettuxPure_Tutor_Text_TeachWaterPulse
        end


NettuxPure_Base_Tutors_Physical::
        lock
        faceplayer
	goto_if_unset FLAG_BADGE04_GET, NettuxPure_Tutor_Need4Badges
	showmoneybox 15, 0
        msgbox NettuxPure_Tutor_Text_PhysicalTutor, MSGBOX_DEFAULT
        checkmoney 5000
        goto_if_eq VAR_RESULT, FALSE, NettuxPure_Base_NotEnoughMoney
        multichoice 0, 0, MULTICHOICE_NETTUX_TUTORS_PHYSICAL, 0
        closemessage
	hidemoneybox
        compare VAR_RESULT, 0
        goto_if_eq NettuxPure_Base_Tutors_TeachRockSlide
        compare VAR_RESULT, 1
        goto_if_eq NettuxPure_Base_Tutors_TeachEarthquake
        compare VAR_RESULT, 2
        goto_if_eq NettuxPure_Base_Tutors_TeachWaterfall
        compare VAR_RESULT, 3
        goto_if_eq NettuxPure_Base_Tutors_TeachBodySlam
        compare VAR_RESULT, 4
        goto_if_eq NettuxPure_Base_Tutors_TeachLeafBlade
        compare VAR_RESULT, 5
        goto_if_eq NettuxPure_Base_Tutors_TeachPsychoCut
        goto NettuxPure_Tutor_Declined
        end

NettuxPure_Base_Tutors_TeachRockSlide::
        movetutor MOVE_ROCK_SLIDE, NettuxPure_Tutor_Text_TeachRockSlide
        end

NettuxPure_Base_Tutors_TeachEarthquake::
        movetutor MOVE_EARTHQUAKE, NettuxPure_Tutor_Text_TeachEarthquake
        end

NettuxPure_Base_Tutors_TeachWaterfall::
        movetutor MOVE_WATERFALL, NettuxPure_Tutor_Text_TeachWaterfall
        end

NettuxPure_Base_Tutors_TeachBodySlam::
        movetutor MOVE_BODY_SLAM, NettuxPure_Tutor_Text_TeachBodySlam
        end

NettuxPure_Base_Tutors_TeachLeafBlade::
        movetutor MOVE_LEAF_BLADE, NettuxPure_Tutor_Text_TeachLeafBlade
        end

NettuxPure_Base_Tutors_TeachPsychoCut::
        movetutor MOVE_PSYCHO_CUT, NettuxPure_Tutor_Text_TeachPsychoCut
        end

NettuxPure_Base_Tutors_Utility::
        lock
        faceplayer
	showmoneybox 15, 0
        msgbox NettuxPure_Tutor_Text_UtilityTutor, MSGBOX_DEFAULT
        checkmoney 500
        goto_if_eq VAR_RESULT, FALSE, NettuxPure_Base_NotEnoughMoney
        multichoice 0, 0, MULTICHOICE_NETTUX_TUTORS_UTILITY, 0
        closemessage
	hidemoneybox
        compare VAR_RESULT, 0
        goto_if_eq NettuxPure_Base_Tutors_TeachProtect
        compare VAR_RESULT, 1
        goto_if_eq NettuxPure_Base_Tutors_TeachFakeOut
        compare VAR_RESULT, 2
        goto_if_eq NettuxPure_Base_Tutors_TeachEncore
        compare VAR_RESULT, 3
        goto_if_eq NettuxPure_Base_Tutors_TeachTaunt
        compare VAR_RESULT, 4
        goto_if_eq NettuxPure_Base_Tutors_TeachTrickRoom
        compare VAR_RESULT, 5
        goto_if_eq NettuxPure_Base_Tutors_TeachTailwind
        goto NettuxPure_Tutor_Declined
        end

NettuxPure_Base_Tutors_TeachProtect::
        movetutor MOVE_PROTECT, NettuxPure_Tutor_Text_TeachProtect
        end

NettuxPure_Base_Tutors_TeachFakeOut::
        movetutor MOVE_FAKE_OUT, NettuxPure_Tutor_Text_TeachFakeOut
        end

NettuxPure_Base_Tutors_TeachEncore::
        movetutor MOVE_ENCORE, NettuxPure_Tutor_Text_TeachEncore
        end

NettuxPure_Base_Tutors_TeachTaunt::
        movetutor MOVE_TAUNT, NettuxPure_Tutor_Text_TeachTaunt
        end

NettuxPure_Base_Tutors_TeachTrickRoom::
        movetutor MOVE_TRICK_ROOM, NettuxPure_Tutor_Text_TeachTrickRoom
        end

NettuxPure_Base_Tutors_TeachTailwind::
        movetutor MOVE_TAILWIND, NettuxPure_Tutor_Text_TeachTailwind
        end

NettuxPure_Base_Tutors_Reckless::
        lock
        faceplayer
	goto_if_unset FLAG_BADGE06_GET, NettuxPure_Tutor_Need6Badges
        checkmoney 6000
        msgbox NettuxPure_Tutor_Text_RecklessTutor, MSGBOX_DEFAULT
        multichoice 0, 0, MULTICHOICE_NETTUX_TUTORS_RECKLESS, 0
        closemessage
        compare VAR_RESULT, 0
        goto_if_eq NettuxPure_Base_Tutors_TeachFlareBlitz
        compare VAR_RESULT, 1
        goto_if_eq NettuxPure_Base_Tutors_TeachBraveBird
        compare VAR_RESULT, 2
        goto_if_eq NettuxPure_Base_Tutors_TeachWildCharge
        compare VAR_RESULT, 3
        goto_if_eq NettuxPure_Base_Tutors_TeachCloseCombat
        compare VAR_RESULT, 4
        goto_if_eq NettuxPure_Base_Tutors_TeachThunder
        compare VAR_RESULT, 5
        goto_if_eq NettuxPure_Base_Tutors_TeachBlizzard
        compare VAR_RESULT, 6
        goto_if_eq NettuxPure_Base_Tutors_TeachHurricane
        goto NettuxPure_Tutor_Declined
        end


NettuxPure_Base_Tutors_TeachFlareBlitz::
        movetutor MOVE_FLARE_BLITZ, NettuxPure_Tutor_Text_TeachFlareBlitz
        end

NettuxPure_Base_Tutors_TeachBraveBird::
        movetutor MOVE_BRAVE_BIRD, NettuxPure_Tutor_Text_TeachBraveBird
        end

NettuxPure_Base_Tutors_TeachWildCharge::
        movetutor MOVE_WILD_CHARGE, NettuxPure_Tutor_Text_TeachWildCharge
        end

NettuxPure_Base_Tutors_TeachCloseCombat::
        movetutor MOVE_CLOSE_COMBAT, NettuxPure_Tutor_Text_TeachCloseCombat
        end

NettuxPure_Base_Tutors_TeachThunder::
        movetutor MOVE_THUNDER, NettuxPure_Tutor_Text_TeachThunder
	end

NettuxPure_Base_Tutors_TeachBlizzard::
        movetutor MOVE_BLIZZARD, NettuxPure_Tutor_Text_TeachBlizzard
	end

NettuxPure_Base_Tutors_TeachHurricane::
        movetutor MOVE_HURRICANE, NettuxPure_Tutor_Text_TeachHurricane
	end

NettuxPure_Base_Tutors_Go::
        msgbox NettuxPure_Tutor_Text_WhichMon, MSGBOX_DEFAULT
        call MoveTutor_EventScript_OpenPartyMenu
        goto_if_eq VAR_RESULT, 0, NettuxPure_Tutor_Declined
	msgbox NettuxPure_Tutor_Text_Taught, MSGBOX_DEFAULT
        release
        end

NettuxPure_Tutor_Declined::
        msgbox NettuxPure_Tutor_Text_Declined, MSGBOX_DEFAULT
        release
        end

NettuxPure_Tutor_Need2Badges::
        msgbox NettuxPure_Tutor_Text_Need2Badges, MSGBOX_AUTOCLOSE
	end

NettuxPure_Tutor_Need4Badges::
        msgbox NettuxPure_Tutor_Text_Need4Badges, MSGBOX_AUTOCLOSE
	end

NettuxPure_Tutor_Need6Badges::
        msgbox NettuxPure_Tutor_Text_Need6Badges, MSGBOX_AUTOCLOSE
	end

NettuxPure_Base_NotEnoughMoney::
        msgbox NettuxPure_Base_Text_NotEnoughMoney, MSGBOX_AUTOCLOSE
	end

NettuxPure_Tutor_Text_Need2Badges:
        .string "Come back when you have 2 Badges.$"

NettuxPure_Tutor_Text_Need4Badges:
        .string "Come back when you have 4 Badges.$"

NettuxPure_Tutor_Text_Need6Badges:
        .string "Come back when you have 6 Badges.$"

NettuxPure_Tutor_Text_WeatherTutor:
        .string "I'm the Weather Tutor!$"

NettuxPure_Tutor_Text_TeachSunnyDay:
        .string "I can teach SUNNY DAY!$"

NettuxPure_Tutor_Text_TeachRainDance:
        .string "I can teach RAIN DANCE!$"

NettuxPure_Tutor_Text_TeachSnowscape:
        .string "I can teach SNOWSCAPE!$"

NettuxPure_Tutor_Text_TeachSandstorm:
        .string "I can teach SANDSTORM!$"

NettuxPure_Tutor_Text_TeachWeatherBall:
        .string "I can teach WEATHER BALL!$"

NettuxPure_Tutor_Text_SwitchTutor:
        .string "I'm the Pivot Tutor! ¥2000!$"

NettuxPure_Tutor_Text_TeachUTurn:
        .string "I can teach U-TURN!$"

NettuxPure_Tutor_Text_TeachVoltSwitch:
        .string "I can teach VOLT SWITCH!$"

NettuxPure_Tutor_Text_TeachFlipTurn:
        .string "I can teach FLIP TURN!$"

NettuxPure_Tutor_Text_TeachPartingShot:
        .string "I can teach PARTING SHOT!$"

NettuxPure_Tutor_Text_TeachBatonPass:
        .string "I can teach BATON PASS!$"

NettuxPure_Tutor_Text_PunchTutor:
        .string "I'm the Punch Tutor! ¥3000!$"

NettuxPure_Tutor_Text_TeachThunderPunch:
        .string "I can teach THUNDER PUNCH!$"

NettuxPure_Tutor_Text_TeachFirePunch:
        .string "I can teach FIRE PUNCH!$"

NettuxPure_Tutor_Text_TeachIcePunch:
        .string "I can teach ICE PUNCH!$"

NettuxPure_Tutor_Text_TeachPoisonJab:
        .string "I can teach POISON JAB!$"

NettuxPure_Tutor_Text_TeachBrickBreak:
        .string "I can teach BRICK BREAK!$"

NettuxPure_Tutor_Text_TeachDrainPunch:
        .string "I can teach DRAIN PUNCH!$"

NettuxPure_Tutor_Text_TeachMachPunch:
        .string "I can teach MACH PUNCH!$"

NettuxPure_Tutor_Text_TeachBulletPunch:
        .string "I can teach BULLET PUNCH!$"

NettuxPure_Tutor_Text_TeachPsychicFangs:
        .string "I can teach PSYCHIC FANGS!$"

NettuxPure_Tutor_Text_TeachPoisonFang:
        .string "I can teach POISON FANG!$"

NettuxPure_Tutor_Text_TeachThunderFang:
        .string "I can teach THUNDER FANG!$"

NettuxPure_Tutor_Text_TeachFireFang:
        .string "I can teach FIRE FANG!$"

NettuxPure_Tutor_Text_TeachIceFang:
        .string "I can teach ICE FANG!$"

NettuxPure_Tutor_Text_TeachCrunch:
        .string "I can teach CRUNCH!$"

NettuxPure_Tutor_Text_TeachAerialAce:
        .string "I can teach AERIAL ACE!$"

NettuxPure_Tutor_Text_TeachSwift:
        .string "I can teach SWIFT!$"

NettuxPure_Tutor_Text_TeachShadowPunch:
        .string "I can teach SHADOW PUNCH!$"

NettuxPure_Tutor_Text_TeachSmartStrike:
        .string "I can teach SMART STRIKE!$"

NettuxPure_Tutor_Text_TeachAuraSphere:
        .string "I can teach AURA SPHERE!$"

NettuxPure_Tutor_Text_TeachShockWave:
        .string "I can teach SHOCK WAVE!$"

NettuxPure_Tutor_Text_TeachMagicalLeaf:
        .string "I can teach MAGICAL LEAF!$"

NettuxPure_Tutor_Text_TeachFeintAttack:
        .string "I can teach FEINT ATTACK!$"

NettuxPure_Tutor_Text_TeachThunderbolt:
        .string "I can teach THUNDERBOLT!$"

NettuxPure_Tutor_Text_TeachEnergyBall:
        .string "I can teach ENERGY BALL!$"

NettuxPure_Tutor_Text_TeachFlamethrower:
        .string "I can teach FLAMETHROWER!$"

NettuxPure_Tutor_Text_TeachPsychic:
        .string "I can teach PSYCHIC!$"

NettuxPure_Tutor_Text_TeachShadowBall:
        .string "I can teach SHADOW BALL!$"

NettuxPure_Tutor_Text_TeachEarthPower:
        .string "I can teach EARTH POWER!$"

NettuxPure_Tutor_Text_TeachIceBeam:
        .string "I can teach ICE BEAM!$"

NettuxPure_Tutor_Text_TeachWaterPulse:
        .string "I can teach WATER PULSE!$"

NettuxPure_Tutor_Text_TeachRockSlide:
        .string "I can teach ROCK SLIDE!$"

NettuxPure_Tutor_Text_TeachEarthquake:
        .string "I can teach EARTHQUAKE!$"

NettuxPure_Tutor_Text_TeachWaterfall:
        .string "I can teach WATERFALL!$"

NettuxPure_Tutor_Text_TeachBodySlam:
        .string "I can teach BODY SLAM!$"

NettuxPure_Tutor_Text_TeachLeafBlade:
        .string "I can teach LEAF BLADE!$"

NettuxPure_Tutor_Text_TeachPsychoCut:
        .string "I can teach PSYCHO CUT!$"

NettuxPure_Tutor_Text_TeachFlareBlitz:
        .string "I can teach FLARE BLITZ!$"

NettuxPure_Tutor_Text_TeachBraveBird:
        .string "I can teach BRAVE BIRD!$"

NettuxPure_Tutor_Text_TeachWildCharge:
        .string "I can teach WILD CHARGE!$"

NettuxPure_Tutor_Text_TeachCloseCombat:
        .string "I can teach CLOSE COMBAT!$"

NettuxPure_Tutor_Text_TeachThunder:
        .string "I can teach THUNDER!$"

NettuxPure_Tutor_Text_TeachBlizzard:
        .string "I can teach BLIZZARD!$"

NettuxPure_Tutor_Text_TeachHurricane:
        .string "I can teach HURRICANE!$"

NettuxPure_Tutor_Text_TeachQuickAttack:
        .string "I can teach QUICK ATTACK!$"

NettuxPure_Tutor_Text_TeachIceShard:
        .string "I can teach ICE SHARD!$"

NettuxPure_Tutor_Text_TeachAquaJet:
        .string "I can teach AQUA JET!$"

NettuxPure_Tutor_Text_TeachShadowSneak:
        .string "I can teach SHADOW SNEAK!$"

NettuxPure_Tutor_Text_TeachSuckerPunch:
        .string "I can teach SUCKER PUNCH!$"

NettuxPure_Tutor_Text_TeachSludgeBomb:
        .string "I can teach SLUDGE BOMB!$"

NettuxPure_Tutor_Text_TeachProtect:
        .string "I can teach PROTECT!$"

NettuxPure_Tutor_Text_TeachFakeOut:
        .string "I can teach FAKE OUT!$"

NettuxPure_Tutor_Text_TeachEncore:
        .string "I can teach ENCORE!$"

NettuxPure_Tutor_Text_TeachTaunt:
        .string "I can teach TAUNT!$"

NettuxPure_Tutor_Text_TeachTrickRoom:
        .string "I can teach TRICK ROOM!$"

NettuxPure_Tutor_Text_TeachTailwind:
        .string "I can teach TAILWIND!$"

NettuxPure_Tutor_Text_BiteTutor:
        .string "I'm the Bite Tutor! ¥3000!$"

NettuxPure_Tutor_Text_AccuracyTutor:
        .string "I'm the Accuracy Tutor! ¥4000!$"

NettuxPure_Tutor_Text_SpecialTutor:
        .string "I'm the Special Tutor! ¥5000!$"

NettuxPure_Tutor_Text_PhysicalTutor:
        .string "I'm the Physical Tutor! ¥5000!$"

NettuxPure_Tutor_Text_PriorityTutor:
        .string "I'm the Priority Tutor! ¥1000!$"

NettuxPure_Tutor_Text_RecklessTutor:
        .string "I'm the Power Tutor! ¥6000!$"

NettuxPure_Tutor_Text_UtilityTutor:
        .string "I'm the Utility Tutor! ¥500!$"

NettuxPure_Base_Text_NotEnoughMoney:
        .string "You need more money.$"

NettuxPure_Tutor_Text_Declined:
        .string "OK, come back again!$"
