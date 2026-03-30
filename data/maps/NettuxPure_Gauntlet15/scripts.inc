NettuxPure_Gauntlet15_MapScripts::
	.byte 0

NettuxPure_Gauntlet15_Complete::
        setflag FLAG_NETTUX_FINISH_GAUNTLET_15
        addmoney 15000
        giveitem ITEM_HEART_SCALE
        giveitem ITEM_WIDE_LENS
        giveitem ITEM_ROOM_SERVICE
        giveitem ITEM_PAYAPA_BERRY
        giveitem ITEM_SITRUS_BERRY
        giveitem ITEM_CUSTAP_BERRY
        giveitem ITEM_MARANGA_BERRY
        giveitem ITEM_MICLE_BERRY
        giveitem ITEM_PASSHO_BERRY
        call Nettux_RandomWildMon
        closemessage
        end

NettuxPure_Gauntlet15_Darius::
        trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat, NettuxPure_Gauntlet15_Complete
        msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
        end
