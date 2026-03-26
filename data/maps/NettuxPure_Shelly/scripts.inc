NettuxPure_Shelly_MapScripts::
	.byte 0

NettuxPure_Shelly_Shelly::
        trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, NettuxPure_Shelly_Complete
        msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Shelly_Complete::
        addmoney 14000
        call Nettux_RandomWildMon
        closemessage
        setflag FLAG_NETTUX_FINISH_SHELLY_1
        end
