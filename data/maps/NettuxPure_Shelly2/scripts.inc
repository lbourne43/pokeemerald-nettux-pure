NettuxPure_Shelly2_MapScripts::
	.byte 0

NettuxPure_Shelly2_Shelly::
        trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat, NettuxPure_Shelly2_Complete
        msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Shelly2_Complete::
        addmoney 20000
        call Nettux_RandomWildMon
        closemessage
        setflag FLAG_NETTUX_FINISH_AQUA_UNDERWATER
        end
