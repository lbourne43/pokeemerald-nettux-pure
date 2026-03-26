NettuxPure_Magma1_MapScripts::
        map_script MAP_SCRIPT_ON_LOAD, NettuxPure_Magma1_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, NettuxPure_Magma1_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, NettuxPure_Magma1_OnTransition
	.byte 0

NettuxPure_Magma1_OnLoad:
        special nettuxSetPermanentMagmaStorm
	end

NettuxPure_Magma1_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

NettuxPure_Magma1_OnResume:
	setstepcallback STEP_CB_ASH
	end

NettuxPure_Magma1_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, NettuxPure_Magma1_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, NettuxPure_Magma1_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

NettuxPure_Magma1_EventScript_ArchieGoStopTeamMagma::
	msgbox NettuxPure_Magma1_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

NettuxPure_Magma1_EventScript_ArchieBusyFighting::
	msgbox NettuxPure_Magma1_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

NettuxPure_Magma1_EventScript_BusyAquaGrunt1::
	msgbox NettuxPure_Magma1_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

NettuxPure_Magma1_EventScript_BusyAquaGrunt2::
	msgbox NettuxPure_Magma1_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

NettuxPure_Magma1_EventScript_BusyAquaGrunt3::
	msgbox NettuxPure_Magma1_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

NettuxPure_Magma1_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, NettuxPure_Magma1_Text_TabithaIntro, NettuxPure_Magma1_Text_TabithaDefeat, NettuxPure_Magma1_Complete
	msgbox NettuxPure_Magma1_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Magma1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, NettuxPure_Magma1_Text_Grunt2Intro, NettuxPure_Magma1_Text_Grunt2Defeat
	msgbox NettuxPure_Magma1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Magma1_EventScript_BusyMagmaGrunt1::
	msgbox NettuxPure_Magma1_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

NettuxPure_Magma1_EventScript_BusyMagmaGrunt2::
	msgbox NettuxPure_Magma1_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

NettuxPure_Magma1_EventScript_BusyMagmaGrunt3::
	msgbox NettuxPure_Magma1_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

NettuxPure_Magma1_EventScript_BusyMagmaGrunt4::
	msgbox NettuxPure_Magma1_Text_AquasNameSimilar, MSGBOX_SIGN
	end

NettuxPure_Magma1_EventScript_BusyMagmaGrunt5::
	msgbox NettuxPure_Magma1_Text_DouseThemInFire, MSGBOX_SIGN
	end

NettuxPure_Magma1_EventScript_BusyMagmaGrunt6::
	msgbox NettuxPure_Magma1_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

NettuxPure_Magma1_EventScript_MagmaPoochyena::
	msgbox NettuxPure_Magma1_Text_Bufoh, MSGBOX_SIGN
	end

NettuxPure_Magma1_EventScript_AquaPoochyena::
	msgbox NettuxPure_Magma1_Text_Bushaa, MSGBOX_SIGN
	end

NettuxPure_Magma1_EventScript_RouteSign::
	msgbox NettuxPure_Magma1_Text_RouteSign, MSGBOX_SIGN
	end

NettuxPure_Magma1_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, NettuxPure_Magma1_Text_ShelbyIntro, NettuxPure_Magma1_Text_ShelbyDefeat, NettuxPure_Magma1_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NettuxPure_Magma1_EventScript_RematchShelby
	msgbox NettuxPure_Magma1_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

NettuxPure_Magma1_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NettuxPure_Magma1_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

NettuxPure_Magma1_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, NettuxPure_Magma1_Text_ShelbyRematchIntro, NettuxPure_Magma1_Text_ShelbyRematchDefeat
	msgbox NettuxPure_Magma1_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

NettuxPure_Magma1_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, NettuxPure_Magma1_Text_MelissaIntro, NettuxPure_Magma1_Text_MelissaDefeat
	msgbox NettuxPure_Magma1_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Magma1_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, NettuxPure_Magma1_Text_SheilaIntro, NettuxPure_Magma1_Text_SheilaDefeat
	msgbox NettuxPure_Magma1_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Magma1_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, NettuxPure_Magma1_Text_ShirleyIntro, NettuxPure_Magma1_Text_ShirleyDefeat
	msgbox NettuxPure_Magma1_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Magma1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, NettuxPure_Magma1_Text_Grunt1Intro, NettuxPure_Magma1_Text_Grunt1Defeat
	msgbox NettuxPure_Magma1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Magma1_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, NettuxPure_Magma1_Text_SawyerIntro, NettuxPure_Magma1_Text_SawyerDefeat, NettuxPure_Magma1_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NettuxPure_Magma1_EventScript_SawyerRematch
	msgbox NettuxPure_Magma1_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

NettuxPure_Magma1_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NettuxPure_Magma1_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

NettuxPure_Magma1_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, NettuxPure_Magma1_Text_SawyerRematchIntro, NettuxPure_Magma1_Text_SawyerRematchDefeat
	msgbox NettuxPure_Magma1_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

NettuxPure_Magma1_Complete::
        addmoney 10000
        giveitem ITEM_POKE_BALL
        closemessage
        setflag FLAG_NETTUX_FINISH_MAGMA1
        end

NettuxPure_Magma1_Text_MeteoriteWillActivateVolcano:
	.string "The power contained in the METEORITE…\p"
	.string "By amplifying its power with this\n"
	.string "machine, MT. CHIMNEY's volcanic\l"
	.string "activity will instantly intensify…\p"
	.string "Its energy will grow deep inside\n"
	.string "the crater and…\l"
	.string "Fufufu…$"

NettuxPure_Magma1_Text_TabithaIntro:
	.string "Hehehe!\p"
	.string "So you've come all the way here!\p"
	.string "But you're too late!\n"
	.string "I've already delivered the METEORITE\l"
	.string "from METEOR FALLS to the BOSS!$"

NettuxPure_Magma1_Text_TabithaDefeat:
	.string "Hehehe…\p"
	.string "Even though I've lost, if our leader\n"
	.string "awakens that thing…$"

NettuxPure_Magma1_Text_TabithaPostBattle:
	.string "BOSS, hurry!\n"
	.string "Give it the METEORITE's energy!\p"
	.string "Hehehe…$"

NettuxPure_Magma1_Text_Grunt2Intro:
	.string "We of TEAM MAGMA are working hard for\n"
	.string "everyone's sake.\p"
	.string "Like, if that thing's power made more\n"
	.string "land, there'd be more places to live.\p"
	.string "Everyone'd be happy!$"

NettuxPure_Magma1_Text_Grunt2Defeat:
	.string "Hunh?\n"
	.string "What do you mean I lost?$"

NettuxPure_Magma1_Text_Grunt2PostBattle:
	.string "Our BOSS says, “It will make everyone\n"
	.string "happy.”\p"
	.string "But why does everyone keep getting\n"
	.string "in our way?$"

NettuxPure_Magma1_Text_Grunt1Intro:
	.string "If there were more land, I'd be able\n"
	.string "to get a big house of my own!\p"
	.string "I'm going to build it on hardened lava!$"

NettuxPure_Magma1_Text_Grunt1Defeat:
	.string "My dream of a big house…$"

NettuxPure_Magma1_Text_Grunt1PostBattle:
	.string "A kid like you, you ought to be\n"
	.string "splashing about in the waves!$"

NettuxPure_Magma1_Text_TeamAquaAlwaysMessingWithPlans:
	.string "That annoying TEAM AQUA…\n"
	.string "They always mess with our plans!$"

NettuxPure_Magma1_Text_MeteoritesPackAmazingPower:
	.string "METEORITES pack amazing power!$"

NettuxPure_Magma1_Text_YouBetterNotMessWithUs:
	.string "You'd better not mess with us!\p"
	.string "We're trying to awaken that thing\n"
	.string "for the benefit of everyone!$"

NettuxPure_Magma1_Text_AquasNameSimilar:
	.string "We're TEAM MAGMA!\p"
	.string "They're TEAM AQUA!\p"
	.string "It totally annoys me that they'd\n"
	.string "use a name like ours!$"

NettuxPure_Magma1_Text_DouseThemInFire:
	.string "Yeah!\n"
	.string "Douse them in fire!$"

NettuxPure_Magma1_Text_KeepMakingMoreLand:
	.string "We're going to keep making more land!$"

NettuxPure_Magma1_Text_Bufoh:
	.string "Bufoh!$"

NettuxPure_Magma1_Text_ArchieGoStopTeamMagma:
	.string "ARCHIE: Grr, {PLAYER}!\n"
	.string "I should've guessed you'd show up!\p"
	.string "See for yourself what the fanatics\n"
	.string "of TEAM MAGMA are up to!\p"
	.string "They're trying to inject the stolen\n"
	.string "METEORITE's power into the volcano!\p"
	.string "Doing something like that will cause\n"
	.string "the volcano's eruption!$"

NettuxPure_Magma1_Text_ArchieIHaveMyHandsFull:
	.string "ARCHIE: Grrr…\p"
	.string "I want to stop that MAXIE,\n"
	.string "but I can't!\p"
	.string "Not when I have my hands full battling\n"
	.string "three opponents at once!$"

NettuxPure_Magma1_Text_ArchieThankYou:
	.string "ARCHIE: {PLAYER}!\n"
	.string "Thank you!\p"
	.string "With your help, we thwarted TEAM\n"
	.string "MAGMA's destructive plan!\p"
	.string "But… You…\n"
	.string "Whose side are you on?\p"
	.string "Ah, it doesn't matter.\p"
	.string "We will remain vigilant and keep up\n"
	.string "our pursuit of TEAM MAGMA.\p"
	.string "{PLAYER}, we shall meet again!$"

NettuxPure_Magma1_Text_MagmaOutnumbersUs:
	.string "Darn… TEAM MAGMA outnumbers us!\n"
	.string "We can't keep up with them!$"

NettuxPure_Magma1_Text_LessHabitatForWaterPokemon:
	.string "If they expand the land, there'll be\n"
	.string "less habitats for WATER POKéMON!$"

NettuxPure_Magma1_Text_MagmasNameSimilar:
	.string "We're TEAM AQUA!\p"
	.string "They're TEAM MAGMA!\p"
	.string "It burns me up that they'd use such\n"
	.string "a confusing name!$"

NettuxPure_Magma1_Text_Bushaa:
	.string "Bushaa!$"

NettuxPure_Magma1_Text_LavaCookiesJust200:
	.string "LAVA COOKIES are MT. CHIMNEY's local\n"
	.string "specialty.\p"
	.string "Try one. It's just ¥200.$"

NettuxPure_Magma1_Text_ThankYouDear:
	.string "Thank you, dear!$"

NettuxPure_Magma1_Text_YouveNotGotTheMoney:
	.string "Oh, dear. You can't buy a thing if\n"
	.string "you've not got the money.$"

NettuxPure_Magma1_Text_OhFineThen:
	.string "Oh, fine then.$"

NettuxPure_Magma1_Text_MetoriteFittedOnMachine:
	.string "A METEORITE is fitted on a mysterious\n"
	.string "machine…\p"
	.string "The machine seems to be storing\n"
	.string "energy in the METEORITE.$"

NettuxPure_Magma1_Text_RemoveTheMeteorite:
	.string "A METEORITE is fitted on a mysterious\n"
	.string "machine…\p"
	.string "Do you want to remove the METEORITE?$"

NettuxPure_Magma1_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} removed the METEORITE from\n"
	.string "the mysterious machine.$"

NettuxPure_Magma1_Text_PlayerLeftMeteorite:
	.string "{PLAYER} left the METEORITE where\n"
	.string "it was.$"

NettuxPure_Magma1_Text_MachineMakesNoResponse:
	.string "This mysterious machine…\n"
	.string "It makes no response whatsoever.$"

NettuxPure_Magma1_Text_RouteSign:
	.string "{DOWN_ARROW} JAGGED PATH\n"
	.string "LAVARIDGE TOWN AHEAD$"

NettuxPure_Magma1_Text_ShelbyIntro:
	.string "I've been to the hot springs and\n"
	.string "refreshed my tired bones.\l"
	.string "Right now I'm feeling strong!$"

NettuxPure_Magma1_Text_ShelbyDefeat:
	.string "Oh, my goodness.\n"
	.string "Now, aren't you something!$"

NettuxPure_Magma1_Text_ShelbyPostBattle:
	.string "Well, well, I've lost. I can't call\n"
	.string "myself an EXPERT now, can I?$"

NettuxPure_Magma1_Text_ShelbyRegister:
	.string "Thank you, child. It was fun, as if\n"
	.string "I were battling my own grandchild.\p"
	.string "Please, come see me again for\n"
	.string "a rematch.$"

NettuxPure_Magma1_Text_ShelbyRematchIntro:
	.string "If you can mesh your heart with those\n"
	.string "of your POKéMON, why, you should be\l"
	.string "able to achieve great things.$"

NettuxPure_Magma1_Text_ShelbyRematchDefeat:
	.string "Oh, my goodness.\n"
	.string "Now, aren't you something!$"

NettuxPure_Magma1_Text_ShelbyPostRematch:
	.string "Perhaps your heart has become one\n"
	.string "with the hearts of your POKéMON.$"

NettuxPure_Magma1_Text_MelissaIntro:
	.string "I've got the fire in me, baby.\n"
	.string "I can't stand it! I have to battle!$"

NettuxPure_Magma1_Text_MelissaDefeat:
	.string "Ooh, that was a scorching-hot match!$"

NettuxPure_Magma1_Text_MelissaPostBattle:
	.string "The heat of MT. CHIMNEY warms\n"
	.string "me up, baby!$"

NettuxPure_Magma1_Text_SheilaIntro:
	.string "I've finally made it to MT. CHIMNEY.\n"
	.string "I want to make my POKéMON battle!$"

NettuxPure_Magma1_Text_SheilaDefeat:
	.string "The way you battle…\n"
	.string "It's like a MT. CHIMNEY eruption!$"

NettuxPure_Magma1_Text_SheilaPostBattle:
	.string "Like I said, I've finally made it to\n"
	.string "MT. CHIMNEY. It would be a shame if\l"
	.string "I only do a little sightseeing…\p"
	.string "I want to get in some battles and buy\n"
	.string "COOKIES as souvenirs.$"

NettuxPure_Magma1_Text_ShirleyIntro:
	.string "Since I bathed in the hot springs,\n"
	.string "I've been feeling great!\l"
	.string "I'm sure I'm going to win!$"

NettuxPure_Magma1_Text_ShirleyDefeat:
	.string "Yowch!\n"
	.string "I'm getting a chill out of the water.$"

NettuxPure_Magma1_Text_ShirleyPostBattle:
	.string "I'll have to take another dip in the\n"
	.string "hot springs. Want to join me?\p"
	.string "Just joking!$"

NettuxPure_Magma1_Text_SawyerIntro:
	.string "This is one fine mountain! Plenty of\n"
	.string "hot people around for company!$"

NettuxPure_Magma1_Text_SawyerDefeat:
	.string "Oh, you're a real firebrand, too!$"

NettuxPure_Magma1_Text_SawyerPostBattle:
	.string "I think I need a dip in LAVARIDGE\n"
	.string "HOT SPRING with the locals!$"

NettuxPure_Magma1_Text_SawyerRegister:
	.string "I like little fireballs like you.\n"
	.string "Let me register you in my POKéNAV.$"

NettuxPure_Magma1_Text_SawyerRematchIntro:
	.string "I'm happily surrounded by hot people\n"
	.string "around these parts. I won't lose!$"

NettuxPure_Magma1_Text_SawyerRematchDefeat:
	.string "Gosh, you're still the same\n"
	.string "firebrand as before!$"

NettuxPure_Magma1_Text_SawyerPostRematch:
	.string "Actually, it really is hot here.\n"
	.string "I'm overdressed for these parts.$"

