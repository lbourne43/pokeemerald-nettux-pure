NettuxPure_Leaf1_MapScripts::
	.byte 0

NettuxPure_Leaf1_Leaf::
        trainerbattle_single TRAINER_LEAF, NettuxPure_Leaf1_Text_LeafIntro, NettuxPure_Leaf1_Text_LeafDefeat, NettuxPure_Leaf1_Post
        msgbox NettuxPure_Leaf1_Text_LeafDefeat, MSGBOX_AUTOCLOSE
        end

NettuxPure_Leaf1_Post::
        setflag FLAG_NETTUX_FINISH_LEAF_1
        addmoney 4000
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_MENTAL_HERB
        giveitem ITEM_SILVER_POWDER
        giveitem ITEM_PERSIM_BERRY
        giveitem ITEM_CHARTI_BERRY
        call Nettux_RandomWildMon
       	closemessage
        end

NettuxPure_Leaf1_Text_LeafIntro:
        .string "...................$"

NettuxPure_Leaf1_Text_LeafDefeat:
        .string "...................$"
