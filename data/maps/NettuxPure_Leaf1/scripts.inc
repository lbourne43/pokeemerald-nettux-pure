NettuxPure_Leaf1_MapScripts::
	.byte 0

NettuxPure_Leaf1_Leaf::
        trainerbattle_single TRAINER_LEAF, NettuxPure_Leaf1_Text_LeafIntro, NettuxPure_Leaf1_Text_LeafDefeat, NettuxPure_Leaf1_Post
        msgbox NettuxPure_Leaf1_Text_LeafDefeat, MSGBOX_AUTOCLOSE
        end

NettuxPure_Leaf1_Post::
        addmoney 4000
        giveitem ITEM_POKE_BALL
        closemessage
        setflag FLAG_NETTUX_FINISH_LEAF_1
        end

NettuxPure_Leaf1_Text_LeafIntro:
        .string "...................$"

NettuxPure_Leaf1_Text_LeafDefeat:
        .string "...................$"
