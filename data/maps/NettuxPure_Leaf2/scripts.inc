NettuxPure_Leaf2_MapScripts::
	.byte 0

NettuxPure_Leaf2_Leaf::
        trainerbattle_single TRAINER_LEAF_2, NettuxPure_Leaf2_Text_LeafIntro, NettuxPure_Leaf2_Text_LeafDefeat, NettuxPure_Leaf2_Post
        msgbox NettuxPure_Leaf1_Text_LeafDefeat, MSGBOX_AUTOCLOSE
        end

NettuxPure_Leaf2_Post::
        addmoney 14000
        call Nettux_RandomWildMon
        closemessage
        setflag FLAG_NETTUX_FINISH_LEAF_2
        end

NettuxPure_Leaf2_Text_LeafIntro:
        .string "...................$"

NettuxPure_Leaf2_Text_LeafDefeat:
        .string "...................$"
