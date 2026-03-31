NettuxPure_Gauntlet6_MapScripts::
        .byte 0

NettuxPure_Gauntlet6_EventScript_Complete::
        addmoney 5000
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_MUSCLE_BAND
        giveitem ITEM_LIGHT_CLAY
        giveitem ITEM_BLACK_BELT
        giveitem ITEM_EXPERT_BELT
        giveitem ITEM_ROCKY_HELMET
        call Nettux_RandomWildMon
       	closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_6
        end

NettuxPure_Gauntlet6_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, NettuxPure_Gauntlet6_Text_TakaoIntro, NettuxPure_Gauntlet6_Text_TakaoDefeat
	msgbox NettuxPure_Gauntlet6_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Gauntlet6_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, NettuxPure_Gauntlet6_Text_JocelynIntro, NettuxPure_Gauntlet6_Text_JocelynDefeat
	msgbox NettuxPure_Gauntlet6_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Gauntlet6_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, NettuxPure_Gauntlet6_Text_LauraIntro, NettuxPure_Gauntlet6_Text_LauraDefeat
	msgbox NettuxPure_Gauntlet6_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Gauntlet6_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, NettuxPure_Gauntlet6_Text_BrendenIntro, NettuxPure_Gauntlet6_Text_BrendenDefeat
	msgbox NettuxPure_Gauntlet6_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Gauntlet6_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, NettuxPure_Gauntlet6_Text_CristianIntro, NettuxPure_Gauntlet6_Text_CristianDefeat
	msgbox NettuxPure_Gauntlet6_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Gauntlet6_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, NettuxPure_Gauntlet6_Text_LilithIntro, NettuxPure_Gauntlet6_Text_LilithDefeat, NettuxPure_Gauntlet6_EventScript_Complete
	msgbox NettuxPure_Gauntlet6_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Gauntlet6_Text_TakaoIntro:
	.string "Might is right!\n"
	.string "Come on!$"

NettuxPure_Gauntlet6_Text_TakaoDefeat:
	.string "Not enough power…$"

NettuxPure_Gauntlet6_Text_TakaoPostBattle:
	.string "Your skill overcame my strength!\n"
	.string "Your technique is commendable!$"

NettuxPure_Gauntlet6_Text_JocelynIntro:
	.string "There's no need for BRAWLY to be\n"
	.string "involved!\p"
	.string "I'll crush you!$"

NettuxPure_Gauntlet6_Text_JocelynDefeat:
	.string "But… How?\n"
	.string "How could I lose so easily?$"

NettuxPure_Gauntlet6_Text_JocelynPostBattle:
	.string "I'm not going to waste this loss.\n"
	.string "I'll use it to motivate me to train!\p"
	.string "One day I'll become a GYM LEADER…\p"
	.string "No, I'll become the POKéMON LEAGUE\n"
	.string "CHAMPION!$"

NettuxPure_Gauntlet6_Text_LauraIntro:
	.string "Don't you dare brush me off!\n"
	.string "It's not my fault if you cry!$"

NettuxPure_Gauntlet6_Text_LauraDefeat:
	.string "Waaaaaaah!\n"
	.string "I lost!$"

NettuxPure_Gauntlet6_Text_LauraPostBattle:
	.string "I battle in the dark to make my heart\n"
	.string "stronger.\p"
	.string "But because it's so dark, I can never\n"
	.string "see BRAWLY's face…$"

NettuxPure_Gauntlet6_Text_LilithIntro:
	.string "Ufufu…\n"
	.string "Are you stumbling around in the dark?$"

NettuxPure_Gauntlet6_Text_LilithDefeat:
	.string "Oh, you…\n"
	.string "I don't want to know you!$"

NettuxPure_Gauntlet6_Text_LilithPostBattle:
	.string "You deserve to stay lost and end up\n"
	.string "back at the entrance again!$"

NettuxPure_Gauntlet6_Text_BrendenIntro:
	.string "I'll show you the gumption of\n"
	.string "a sailing man!$"

NettuxPure_Gauntlet6_Text_BrendenDefeat:
	.string "How'd this happen?\n"
	.string "It's not like me to lose this way!$"

NettuxPure_Gauntlet6_Text_BrendenPostBattle:
	.string "Oh, aye! You're worthy of seeing\n"
	.string "our GYM LEADER.$"

NettuxPure_Gauntlet6_Text_CristianIntro:
	.string "If you mean to pass, it has to be\n"
	.string "through me!$"

NettuxPure_Gauntlet6_Text_CristianDefeat:
	.string "Grrrrr!\n"
	.string "Vastly overpowered!$"

NettuxPure_Gauntlet6_Text_CristianPostBattle:
	.string "You win!\n"
	.string "Go after that BADGE!$"
