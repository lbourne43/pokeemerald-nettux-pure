NettuxPure_Red2_MapScripts::
	.byte 0

NettuxPure_Red2_Red2::
        trainerbattle_single TRAINER_RED_2, NettuxPure_Red2_Text_Red2Intro, NettuxPure_Red2_Text_Red2Defeat, NettuxPure_Red2_Complete
        msgbox NettuxPure_Red2_Text_Red2Post, MSGBOX_AUTOCLOSE
	end

NettuxPure_Red2_Complete::
        giveitem ITEM_TERA_ORB
        giveitem ITEM_POKE_BALL
        addmoney 12000
        setflag FLAG_NETTUX_FINISH_RED_2
        setflag B_FLAG_TERA_ORB_CHARGED
        closemessage
        end

NettuxPure_Red2_Text_Red2Intro:
        .string "..........$"

NettuxPure_Red2_Text_Red2Post:
        .string "..........$"

NettuxPure_Red2_Text_Red2Defeat:
        .string "..........$"

