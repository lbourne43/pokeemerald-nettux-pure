NettuxPure_Gauntlet10_MapScripts::
	.byte 0

NettuxPure_Gauntlet10_EventScript_Bryan::
        trainerbattle_single TRAINER_BRYAN, Route111_Text_BryanIntro, Route111_Text_BryanDefeat, NettuxPure_Gauntlet10_Complete
        msgbox Route111_Text_BryanPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet10_Complete::
        addmoney 10000
        giveitem ITEM_POKE_BALL
        closemessage
        setflag FLAG_NETTUX_FINISH_GAUNTLET_10
        end
