NettuxPure_RedAndLeaf_MapScripts::
	.byte 0

NettuxPure_RedAndLeaf_Red::
        trainerbattle_single TRAINER_RED_3, NettuxPure_RedAndLeaf_Text_Red3Intro, NettuxPure_RedAndLeaf_Text_Red3Defeat, NettuxPure_Red3_Complete
        msgbox NettuxPure_RedAndLeaf_Text_Red3Post, MSGBOX_AUTOCLOSE
        end

NettuxPure_RedAndLeaf_Leaf::
        trainerbattle_single TRAINER_LEAF_3, NettuxPure_RedAndLeaf_Text_Red3Intro, NettuxPure_RedAndLeaf_Text_Red3Defeat, NettuxPure_Red3_Complete
        msgbox NettuxPure_RedAndLeaf_Text_Red3Post, MSGBOX_AUTOCLOSE
        end

NettuxPure_Red3_Complete::
        addmoney 20000
        setflag FLAG_NETTUX_FINISH_RED_AND_LEAF
        call Nettux_RandomWildMon
        closemessage
        end

NettuxPure_RedAndLeaf_Text_Red3Intro:
        .string "..........$"

NettuxPure_RedAndLeaf_Text_Red3Post:
        .string "..........$"

NettuxPure_RedAndLeaf_Text_Red3Defeat:
        .string "..........$"
