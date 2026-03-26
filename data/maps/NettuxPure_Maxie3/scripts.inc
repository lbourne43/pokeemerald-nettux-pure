NettuxPure_Maxie3_MapScripts::
	.byte 0

NettuxPure_Maxie3_Maxie::
        trainerbattle_single TRAINER_MAXIE_MOSSDEEP, MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand, NettuxPure_Maxie3_Complete
        msgbox MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand, MSGBOX_AUTOCLOSE
        end

NettuxPure_Maxie3_Tabitha::
        trainerbattle_single TRAINER_TABITHA_MOSSDEEP, MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere, MossdeepCity_SpaceCenter_Text_TabithaDefeat
        msgbox MossdeepCity_SpaceCenter_Text_TabithaDefeat, MSGBOX_AUTOCLOSE
	end

NettuxPure_Maxie3_Complete::
        addmoney 20000
        call Nettux_RandomWildMon
        closemessage
        setflag FLAG_NETTUX_FINISH_MAXIE3
        end
