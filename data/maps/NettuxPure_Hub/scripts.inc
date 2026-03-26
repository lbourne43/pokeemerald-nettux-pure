.set LOCALID_WILD_GAURD1, 23

NettuxPure_Hub_MapScripts::
        .byte 0

NettuxPure_WeatherSign1::
        msgbox NettuxPure_Text_PrimalRain, MSGBOX_AUTOCLOSE
        special nettuxSetPermanentPrimalRain
        end

NettuxPure_WeatherSign2::
        msgbox NettuxPure_Text_PrimalSun, MSGBOX_AUTOCLOSE
        special nettuxSetPermanentPrimalSun
        end

NettuxPure_WeatherSign3::
        msgbox NettuxPure_Text_DeltaStream, MSGBOX_AUTOCLOSE
        special nettuxSetPermanentDeltaStream
        end

NettuxPure_MegaBeedrillGuardian::
        faceplayer
        setflag FLAG_NETTUX_LEVEL_SCALE
        msgbox NettuxPure_MegaBeedrillGuardianGreet, MSGBOX_AUTOCLOSE
        trainerbattle_no_intro TRAINER_DREW, NettuxPure_MegaBeedrillGuardianDefeat
        giveitem ITEM_BEEDRILLITE
        closemessage
        clearflag FLAG_NETTUX_LEVEL_SCALE
        end

NettuxPure_MegaGardevoirGuardian::
        faceplayer
        setflag FLAG_NETTUX_LEVEL_SCALE
	msgbox NettuxPure_MegaGardevoirGuardianGreet, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_TIMOTHY_1, NettuxPure_MegaGardevoirGuardianDefeat
	giveitem ITEM_GARDEVOIRITE
	closemessage
        clearflag FLAG_NETTUX_LEVEL_SCALE
        end

NettuxPure_MegaGengarGuardian::
        faceplayer
        setflag FLAG_NETTUX_LEVEL_SCALE
	msgbox NettuxPure_MegaGengarGuardianGreet, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_WILTON_1, NettuxPure_MegaGengarGuardianDefeat
	giveitem ITEM_GENGARITE
	closemessage
        clearflag FLAG_NETTUX_LEVEL_SCALE
        end

NettuxPure_MegaPidgeotGuardian::
        faceplayer
        setflag FLAG_NETTUX_LEVEL_SCALE
	msgbox NettuxPure_MegaPidgeotGuardianGreet, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_BECKY, NettuxPure_MegaPidgeotGuardianDefeat
	giveitem ITEM_PIDGEOTITE
	closemessage
        clearflag FLAG_NETTUX_LEVEL_SCALE
        end

NettuxPure_MegaAggronGuardian::
        faceplayer
        setflag FLAG_NETTUX_LEVEL_SCALE
        msgbox NettuxPure_MegaAggronGuardianGreet, MSGBOX_AUTOCLOSE
        trainerbattle_no_intro TRAINER_JAIDEN, NettuxPure_MegaAggronGuardianDefeat
        giveitem ITEM_AGGRONITE
        closemessage
        clearflag FLAG_NETTUX_LEVEL_SCALE
        end

NettuxPure_MegaHeracrossGuardian::
        faceplayer
        setflag FLAG_NETTUX_LEVEL_SCALE
        msgbox NettuxPure_MegaHeracrossGuardianGreet, MSGBOX_AUTOCLOSE
        trainerbattle_no_intro TRAINER_GREG, NettuxPure_MegaHeracrossGuardianDefeat
        giveitem ITEM_HERACRONITE
        closemessage
        clearflag FLAG_NETTUX_LEVEL_SCALE
	end

NettuxPure_MegaCameruptGuardian::
        faceplayer
        setflag FLAG_NETTUX_LEVEL_SCALE
        msgbox NettuxPure_MegaCameruptGuardianGreet, MSGBOX_AUTOCLOSE
        trainerbattle_no_intro TRAINER_SAWYER_1, NettuxPure_MegaCameruptGuardianDefeat
        giveitem ITEM_CAMERUPTITE
        closemessage
        clearflag FLAG_NETTUX_LEVEL_SCALE
	end

NettuxPure_MegaHoundoomGuardian::
        faceplayer
        setflag FLAG_NETTUX_LEVEL_SCALE
        msgbox NettuxPure_MegaHoundoomGuardianGreet, MSGBOX_AUTOCLOSE
        trainerbattle_no_intro TRAINER_TRAVIS, NettuxPure_MegaHoundoomGuardianDefeat
        giveitem ITEM_HOUNDOOMINITE
        closemessage
        clearflag FLAG_NETTUX_LEVEL_SCALE
	end

NettuxPure_MegaMetagrossGuardian::
        faceplayer
        setflag FLAG_NETTUX_LEVEL_SCALE
        msgbox NettuxPure_MegaMetagrossGuardianGreet, MSGBOX_AUTOCLOSE
        trainerbattle_no_intro TRAINER_PARKER, NettuxPure_MegaMetagrossGuardianDefeat
        giveitem ITEM_METAGROSSITE
        closemessage
        clearflag FLAG_NETTUX_LEVEL_SCALE
	end

NettuxPure_WildGuardian1::
        faceplayer
        setflag FLAG_NETTUX_LEVEL_SCALE
        msgbox NettuxPure_WildGuardian1Greet, MSGBOX_AUTOCLOSE
        trainerbattle_no_intro TRAINER_CELIA, NettuxPure_WildGuardian1Defeat
        giveitem ITEM_POKE_BALL
        closemessage
	setflag FLAG_NETTUX_FINISH_WILD_GUARD_1
	applymovement LOCALID_WILD_GAURD1, NettuxPure_WildGuardian1_Movement_Open
        clearflag FLAG_NETTUX_LEVEL_SCALE
        end

NettuxPure_MegaAggronGuardianGreet:
        .string "Hello, I am the guardian of\n"
	.string "Aggron's mega stone.$"

NettuxPure_MegaAggronGuardianDefeat:
        .string "Well done. Here is your stone.$"

NettuxPure_MegaGardevoirGuardianGreet:
        .string "Hello, I am the guardian of\n"
	.string "Gardevoir's mega stone.$"

NettuxPure_MegaGardevoirGuardianDefeat:
        .string "Well done. Here is your stone.$"

NettuxPure_MegaGengarGuardianGreet:
        .string "Hello, I am the guardian of\n"
	.string "Gengar's mega stone.$"

NettuxPure_MegaGengarGuardianDefeat:
        .string "Well done. Here is your stone.$"

NettuxPure_MegaBeedrillGuardianGreet:
        .string "Hello, I am the guardian of\n"
	.string "Beedrill's mega stone.$"

NettuxPure_MegaBeedrillGuardianDefeat:
        .string "Well done. Here is your stone.$"

NettuxPure_MegaPidgeotGuardianGreet:
        .string "Hello, I am the guardian of\n"
        .string "Pidgeot's mega stone.$"

NettuxPure_MegaPidgeotGuardianDefeat:
        .string "Well done. Here is your stone.$"

NettuxPure_MegaHeracrossGuardianGreet:
        .string "Hello, I am the guardian of\n"
        .string "Heracross's mega stone.$"

NettuxPure_MegaHeracrossGuardianDefeat:
        .string "Well done. Here is your stone.$"

NettuxPure_MegaHoundoomGuardianGreet:
        .string "Hello, I am the guardian of\n"
        .string "Houndoom's mega stone.$"

NettuxPure_MegaHoundoomGuardianDefeat:
        .string "Well done. Here is your stone.$"

NettuxPure_MegaMetagrossGuardianGreet:
        .string "Hello, I am the guardian of\n"
        .string "Metagross's mega stone.$"

NettuxPure_MegaMetagrossGuardianDefeat:
        .string "Well done. Here is your stone.$"

NettuxPure_MegaCameruptGuardianGreet:
        .string "Hello, I am the guardian of\n"
        .string "Camerupt's mega stone.$"

NettuxPure_MegaCameruptGuardianDefeat:
        .string "Well done. Here is your stone.$"

NettuxPure_WildGuardian1Greet:
        .string "Hello, fight me for an encounter\n"
	.string "You need at least 1 badge.$"

NettuxPure_WildGuardian1Defeat:
        .string "Well done.$"

NettuxPure_Text_PrimalRain:
        .string "Primal Rain.$"

NettuxPure_Text_PrimalSun:
        .string "Primal Sun.$"

NettuxPure_Text_DeltaStream:
        .string "Delta Stream.$"

NettuxPure_WildGuardian1_Movement_Open:
        walk_left
        walk_left
	step_end
