NettuxPure_Gauntlet4_MapScripts::
        .byte 0

NettuxPure_Gauntlet4_Post::
        addmoney 4000
        giveitem ITEM_POKE_BALL
	closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_4
        end

NettuxPure_Gauntlet4_Mike::
	trainerbattle_single TRAINER_MIKE_1, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat, NettuxPure_Gauntlet4_Post
	msgbox RusturfTunnel_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

NettuxPure_Gauntlet4_Josh::
        trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, NettuxPure_Gauntlet4_Text_JoshDefeat
        msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet4_Tommy::
        trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
        msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet4_Marc::
        trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
        msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet4_Text_JoshDefeat:
        .string "You already beat her?!$"
