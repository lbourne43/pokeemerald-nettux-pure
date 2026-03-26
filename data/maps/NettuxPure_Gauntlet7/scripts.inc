NettuxPure_Gauntlet7_MapScripts::
	.byte 0

NettuxPure_Gauntlet7_EventScript_Ricky::
        trainerbattle_single TRAINER_RICKY_1, Route109_Text_RickyIntro, Route109_Text_RickyDefeated
        msgbox Route109_Text_RickyPostBattle, MSGBOX_DEFAULT
	closemessage
        end

NettuxPure_Gauntlet7_EventScript_Lola::
        trainerbattle_single TRAINER_LOLA_1, Route109_Text_LolaIntro, Route109_Text_LolaDefeated
        msgbox Route109_Text_LolaPostBattle, MSGBOX_DEFAULT
        closemessage
        end

NettuxPure_Gauntlet7_ShedShellGirl::
        msgbox NettuxPure_Gauntlet7_Text_SandIsGreat, MSGBOX_AUTOCLOSE
        goto_if_unset FLAG_NETTUX_GIVE_SHED_SHELL, NettuxPure_Gauntlet7_GiveShedShell
        end

NettuxPure_Gauntlet7_GiveShedShell::
        setflag FLAG_NETTUX_GIVE_SHED_SHELL
        giveitem ITEM_SHED_SHELL
        closemessage
        end 

NettuxPure_Gauntlet7_EventScript_Huey::
        trainerbattle_single TRAINER_HUEY, Route109_Text_HueyIntro, Route109_Text_HueyDefeated, NettuxPure_Gauntlet7_Complete
        msgbox Route109_Text_HueyPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet7_Complete::
	addmoney 5000
  call Nettux_RandomWildMon
        closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_7
        end

NettuxPure_Gauntlet7_SoftSandWoman::
        msgbox NettuxPure_Gauntlet7_Text_SandIsGreat, MSGBOX_AUTOCLOSE
	goto_if_unset FLAG_NETTUX_GIVE_SOFTSAND, NettuxPure_Gauntlet7_GiveSoftSand
	end

NettuxPure_Gauntlet7_GiveSoftSand::
        setflag FLAG_NETTUX_GIVE_SOFTSAND
	giveitem ITEM_SOFT_SAND
	closemessage
	end

NettuxPure_Gauntlet7_RockSlideMan::
        msgbox NettuxPure_Gauntlet7_Text_SeeThoseRocks, MSGBOX_AUTOCLOSE
	goto_if_unset FLAG_NETTUX_GIVE_ROCKSLIDE, NettuxPure_Gauntlet7_GiveRockSlide
	end

NettuxPure_Gauntlet7_GiveRockSlide::
        setflag FLAG_NETTUX_GIVE_ROCKSLIDE
	giveitem ITEM_TM61
	closemessage
	end

NettuxPure_Gauntlet7_EventScript_Encounters::
        msgbox NettuxPure_Gauntlet7_Text_Encounters, MSGBOX_DEFAULT
        closemessage
        end

NettuxPure_Gauntlet7_Text_SandIsGreat:
        .string "Sand is great... look!$"

NettuxPure_Gauntlet7_Text_SeeThoseRocks:
        .string "See those rocks? My POKéMON did that!$"

NettuxPure_Gauntlet7_Text_Encounters:
        .string "POKéMON observed in this area:\l"
        .string "Diglett\l"
        .string "Growlithe\l"
        .string "Electrike\l"
        .string "Roselia\l"
        .string "Marill\l"
        .string "Wattrel\l"
        .string "Krabby\l"
        .string "Bellsprout\l"
        .string "Poochyena\l"
        .string "Squirtle$"
