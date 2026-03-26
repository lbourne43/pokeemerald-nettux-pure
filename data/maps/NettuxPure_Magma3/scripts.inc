NettuxPure_Magma3_MapScripts::
	.byte 0

NettuxPure_Magma3_Grunt1::
        trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_1, MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat, NettuxPure_Magma3_Complete
        msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Magma3_Complete::
        addmoney 20000
        call Nettux_RandomWildMon
        closemessage
        setflag FLAG_NETTUX_FINISH_MAGMA_SPACE
        end
