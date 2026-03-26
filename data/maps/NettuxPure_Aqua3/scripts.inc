NettuxPure_Aqua3_MapScripts::
	.byte 0

NettuxPure_Aqua3_Grunt3::
        trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat, NettuxPure_Aqua3_Complete
        msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Aqua3_Complete::
        addmoney 18000
        giveitem ITEM_POKE_BALL
        closemessage
        setflag FLAG_NETTUX_FINISH_AQUA_MTPYRE
        end
