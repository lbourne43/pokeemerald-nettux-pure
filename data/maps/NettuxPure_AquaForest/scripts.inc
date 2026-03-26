NettuxPure_AquaForest_MapScripts::
	.byte 0

NettuxPure_AquaForest_Grunt::
        trainerbattle_single TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_NoOneCrossesTeamAqua, PetalburgWoods_Text_YoureKiddingMe, NettuxPure_AquaForest_Post
        msgbox RusturfTunnel_Text_GruntTakePackage, MSGBOX_AUTOCLOSE
        end

NettuxPure_AquaForest_Post::
        setflag FLAG_NETTUX_FINISH_AQUA_FOREST
        addmoney 3000
        giveitem ITEM_HEART_SCALE
       	closemessage
        call Nettux_RandomWildMon
        end
