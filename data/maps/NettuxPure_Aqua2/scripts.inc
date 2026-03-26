NettuxPure_Aqua2_MapScripts::
	.byte 0

NettuxPure_Aqua2_Grunt5::
        trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat, NettuxPure_Aqua2_Complete
        msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Aqua2_Complete::
        addmoney 14000
        giveitem ITEM_POKE_BALL
        closemessage
        setflag FLAG_NETTUX_FINISH_AQUA2
        end
