NettuxPure_Gauntlet1_MapScripts::
        map_script MAP_SCRIPT_ON_TRANSITION, NettuxPure_Gauntlet1_OnTransition
        .byte 0

NettuxPure_Gauntlet1_OnTransition:
        cleartrainerflag TRAINER_CALVIN_1
        cleartrainerflag TRAINER_RICK
        cleartrainerflag TRAINER_TIANA
        cleartrainerflag TRAINER_ALLEN
	end

NettuxPure_Gauntlet1_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

NettuxPure_Gauntlet1_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Gauntlet1_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated, NettuxPure_Gauntlet1_EventScript_Complete
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Gauntlet1_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Gauntlet1_EventScript_Complete::
        setflag FLAG_NETTUX_FINISH_GAUNTLET_1
        addmoney 1000
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_SILK_SCARF
        giveitem ITEM_ORAN_BERRY
        giveitem ITEM_PECHA_BERRY
       	closemessage
        goto Nettux_RandomWildMon
        end

NettuxPure_Gauntlet1_EventScript_Encounters::
        msgbox NettuxPure_Gauntlet1_Text_Encounters, MSGBOX_DEFAULT
        closemessage
        end

NettuxPure_Gauntlet1_Text_Encounters:
        .string "POKéMON observed in this area:\l"
        .string "Wurmple\l"
        .string "Poochyena\l"
        .string "Wingull\l"
        .string "Zigzagoon\l"
        .string "Taillow\l"
        .string "Ralts\l"
        .string "Rattata\l"
        .string "Shroomish\l"
        .string "Sentret\l"
        .string "Mankey$"
