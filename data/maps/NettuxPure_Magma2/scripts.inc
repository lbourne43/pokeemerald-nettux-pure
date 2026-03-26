NettuxPure_Magma2_MapScripts::
        map_script MAP_SCRIPT_ON_LOAD, NettuxPure_Magma2_OnLoad
        .byte 0

NettuxPure_Magma2_OnLoad:
        special nettuxSetPermanentMagmaStorm
	end

NettuxPure_Magma2_Tabitha::
        trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat, NettuxPure_Magma2_Complete
        msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
        end

NettuxPure_Magma2_Complete::
        addmoney 18000
        call Nettux_RandomWildMon
        closemessage
        setflag FLAG_NETTUX_FINISH_MAGMA_HIDEOUT
        end
