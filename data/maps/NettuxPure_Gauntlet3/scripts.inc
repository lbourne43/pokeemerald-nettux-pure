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
        addmoney 3000
        giveitem ITEM_POKE_BALL
	closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_3
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
