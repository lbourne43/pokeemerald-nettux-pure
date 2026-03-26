NettuxPure_Gauntlet3_MapScripts::
        map_script MAP_SCRIPT_ON_TRANSITION, NettuxPure_Gauntlet3_OnTransition
        .byte 0

NettuxPure_Gauntlet3_OnTransition:
        end

NettuxPure_Gauntlet3_EventScript_Jose::
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat, NettuxPure_Gauntlet3_EventScript_Complete
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Gauntlet3_EventScript_Complete::
        setflag FLAG_NETTUX_FINISH_GAUNTLET_3
        addmoney 4000
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_METRONOME
        giveitem ITEM_ABSORB_BULB
        giveitem ITEM_BIG_ROOT
        giveitem ITEM_SHUCA_BERRY
        giveitem ITEM_SITRUS_BERRY
        giveitem ITEM_CUSTAP_BERRY
        giveitem ITEM_KASIB_BERRY
       	closemessage
        call Nettux_RandomWildMon
        end

NettuxPure_Gauntlet3_EventScript_Encounters::
        msgbox NettuxPure_Gauntlet3_Text_Encounters, MSGBOX_DEFAULT
        closemessage
        end

NettuxPure_Gauntlet3_Text_Encounters:
        .string "POKéMON observed in this area:\l"
        .string "Marill\l"
        .string "Lotad\l"
        .string "Wingull\l"
        .string "Nidoran\l"
        .string "Ekans\l"
        .string "Mankey\l"
        .string "Whismur\l"
        .string "Bulbasaur\l"
        .string "Purrloin\l"
        .string "Stunky$"
