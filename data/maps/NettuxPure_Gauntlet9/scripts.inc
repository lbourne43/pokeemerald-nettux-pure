NettuxPure_Gauntlet9_MapScripts::
	.byte 0

NettuxPure_Gauntlet9_EventScript_Edwin::
        trainerbattle_single TRAINER_EDWIN_1, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated
        msgbox Route110_Text_EdwinPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Gauntlet9_EventScript_Kirk::
        trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat, NettuxPure_Gauntlet9_Complete
        msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE

NettuxPure_Gauntlet9_Complete::
call Nettux_RandomWildMon
        addmoney 7500
        setflag FLAG_NETTUX_FINISH_GAUNTLET_9
        call Nettux_RandomWildMon
        closemessage
        end
