NettuxPure_Aqua4_MapScripts::
	.byte 0

NettuxPure_Aqua4_Grunt3::
	      trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_3, AquaHideout_B1F_Text_Grunt3Intro, AquaHideout_B1F_Text_Grunt3Defeat, NettuxPure_Aqua4_Complete
	      msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Aqua4_Complete::
        setflag FLAG_NETTUX_FINISH_AQUA_HIDEOUT
        addmoney 20000
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_PP_MAX
        call Nettux_RandomWildMon
        closemessage
        end
