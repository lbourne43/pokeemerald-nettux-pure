NettuxPure_Aqua_Rusturf_MapScripts::
	.byte 0

NettuxPure_AquaTunnel_Grunt::
        trainerbattle_single TRAINER_GRUNT_RUSTURF_TUNNEL, RusturfTunnel_Text_GruntIntro, RusturfTunnel_Text_GruntDefeat, NettuxPure_AquaTunnel_Post
        msgbox RusturfTunnel_Text_GruntTakePackage, MSGBOX_AUTOCLOSE
        end

NettuxPure_AquaTunnel_Post::
        addmoney 4000
        giveitem ITEM_POKE_BALL
        closemessage
        setflag FLAG_NETTUX_FINISH_AQUA_TUNNEL
        end
