NettuxPure_AquaMuseum_MapScripts::
	.byte 0

NettuxPure_AquaMuseum_AquaGrunt1::
        trainerbattle_single TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_AUTOCLOSE
        end

NettuxPure_AquaMuseum_AquaGrunt2::
        trainerbattle_single TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat, NettuxPure_AquaMuseum_Complete
        msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_AUTOCLOSE
        end

NettuxPure_AquaMuseum_Complete::
        addmoney 5000
        giveitem ITEM_POKE_BALL
        closemessage
        setflag FLAG_NETTUX_FINISH_AQUA_MUSEUM
        end
