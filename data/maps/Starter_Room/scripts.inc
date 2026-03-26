.set LOCALID_BALL_BULBASAUR, 1
.set LOCALID_BALL_SQUIRTLE, 2
.set LOCALID_BALL_CHARMANDER, 3
.set LOCALID_BALL_CHIKORITA, 1
.set LOCALID_BALL_TOTODILE, 2
.set LOCALID_BALL_CYNDAQUIL, 3
.set LOCALID_BALL_TREECKO, 1
.set LOCALID_BALL_MUDKIP, 2
.set LOCALID_BALL_TORCHIC, 3
.set LOCALID_BALL_TURTWIG, 1
.set LOCALID_BALL_PIPLUP, 2
.set LOCALID_BALL_CHIMCHAR, 3
.set LOCALID_BALL_SNIVY, 1
.set LOCALID_BALL_TEPIG, 2
.set LOCALID_BALL_OSHAWOTT, 3
.set LOCALID_BALL_CHESPIN, 1
.set LOCALID_BALL_FENNEKIN, 2
.set LOCALID_BALL_FROAKIE, 3
.set LOCALID_BALL_ROWLET, 1
.set LOCALID_BALL_POPPLIO, 2
.set LOCALID_BALL_LITTEN, 3
.set LOCALID_BALL_GROOKEY, 1
.set LOCALID_BALL_SCORBUNNY, 2
.set LOCALID_BALL_SOBBLE, 3
.set LOCALID_BALL_SPRIGATITO, 1
.set LOCALID_BALL_QUAXLY, 2
.set LOCALID_BALL_FUECOCO, 3

Starter_Room_MapScripts::
        map_script MAP_SCRIPT_ON_TRANSITION, NettuxPure_StarterRoom_OnTransition
        .byte 0

NettuxPure_StarterRoom_OnTransition:
        setrespawn HEAL_LOCATION_STARTER_ROOM
	end

NettuxPure_StarterRoom_EventScript_ChosenStarterCheck::
        goto_if_unset FLAG_NETTUX_CHOSE_STARTER NettuxPure_StarterRoom_EventScript_ChooseStarterPrompt
	end

NettuxPure_StarterRoom_EventScript_ChooseStarterPrompt::
	msgbox NettuxPure_StarterRoom_Text_ChooseStarter, MSGBOX_DEFAULT
        closemessage
        applymovement OBJ_EVENT_ID_PLAYER, NettuxPure_StarterRoom_Movement_ToStarterTable
	waitmovement 0
	end

NettuxPure_StarterRoom_Text_ChooseStarter:
        .string "You haven't chosen a starter!$"

NettuxPure_StarterRoom_Movement_ToStarterTable:
        face_down
        walk_down
        walk_left
        walk_left
        walk_down
        walk_down
        walk_right
        face_up
        step_end

NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter::
        end

NettuxPure_StarterRoom_EventScript_TakeYourTime::
        hidemonpic
	closemessage
	release
        end

NettuxPure_StarterRoom_EventScript_TorchicBall::
        goto NettuxPure_StarterRoom_EventScript_Torchic
	end

NettuxPure_StarterRoom_EventScript_Torchic::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_TORCHIC, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveTorchic
	end

NettuxPure_StarterRoom_EventScript_GiveTorchic::
        bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORCHIC
        givemon SPECIES_TORCHIC, 5
        goto NettuxPure_StarterRoom_EventScript_SendTorchicToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendTorchicToParty::
        removeobject LOCALID_BALL_TORCHIC
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedTorchic
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
	goto NettuxPure_StarterRoom_EventScript_ReceivedTorchic
        end

NettuxPure_StarterRoom_EventScript_ReceivedTorchic::
	hidemonpic
	releaseall
	goto NettuxPure_StarterRoom_InitialiseGame
	end

NettuxPure_StarterRoom_EventScript_MudkipBall::
        goto NettuxPure_StarterRoom_EventScript_Mudkip
	end

NettuxPure_StarterRoom_EventScript_Mudkip::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_MUDKIP, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveMudkip
	end

NettuxPure_StarterRoom_EventScript_GiveMudkip::
        bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MUDKIP
        givemon SPECIES_MUDKIP, 5
        goto NettuxPure_StarterRoom_EventScript_SendMudkipToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendMudkipToParty::
        removeobject LOCALID_BALL_MUDKIP
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedMudkip
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
	goto NettuxPure_StarterRoom_EventScript_ReceivedMudkip
        end

NettuxPure_StarterRoom_EventScript_ReceivedMudkip::
	hidemonpic
	releaseall
	goto NettuxPure_StarterRoom_InitialiseGame
	end

NettuxPure_StarterRoom_EventScript_TreeckoBall::
        goto NettuxPure_StarterRoom_EventScript_Treecko

NettuxPure_StarterRoom_EventScript_Treecko::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_TREECKO, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveTreecko
	end

NettuxPure_StarterRoom_EventScript_GiveTreecko::
        bufferspeciesname STR_VAR_1, SPECIES_TREECKO
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TREECKO
        givemon SPECIES_TREECKO, 5
        goto NettuxPure_StarterRoom_EventScript_SendTreeckoToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendTreeckoToParty::
        removeobject LOCALID_BALL_TREECKO
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedTreecko
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
	goto NettuxPure_StarterRoom_EventScript_ReceivedTreecko
        end

NettuxPure_StarterRoom_EventScript_ReceivedTreecko::
	hidemonpic
	releaseall
	goto NettuxPure_StarterRoom_InitialiseGame
	end

NettuxPure_StarterRoom_InitialiseGame::
        setflag FLAG_NETTUX_CHOSE_STARTER
        setflag FLAG_SYS_POKEMON_GET
        setflag FLAG_SYS_POKEDEX_GET
        setflag FLAG_RECEIVED_RUNNING_SHOES
        setflag FLAG_NETTUX_HARD
        setflag FLAG_SYS_B_DASH
	setflag FLAG_NETTUX_HIDE_RED_1
	setflag FLAG_NETTUX_HIDE_WALLY_1
	giveitem ITEM_INFINITE_RARE_CANDY
	giveitem ITEM_INFINITE_EXP_CANDY
  call Nettux_RandomWildMon
        closemessage
	end

NettuxPure_StarterRoom_Text_YoullTakeThisOne:
        .string "You know how to pick a good one.\p"
        .string "So, you'll take this one?$"

NettuxPure_StarterRoom_EventScript_FireBall::
        goto_if_set FLAG_NETTUX_STARTER_GEN_9, NettuxPure_StarterRoom_EventScript_Fuecoco
        goto_if_set FLAG_NETTUX_STARTER_GEN_8, NettuxPure_StarterRoom_EventScript_Scorbunny
        goto_if_set FLAG_NETTUX_STARTER_GEN_7, NettuxPure_StarterRoom_EventScript_Litten
        goto_if_set FLAG_NETTUX_STARTER_GEN_6, NettuxPure_StarterRoom_EventScript_Fennekin
        goto_if_set FLAG_NETTUX_STARTER_GEN_5, NettuxPure_StarterRoom_EventScript_Tepig
        goto_if_set FLAG_NETTUX_STARTER_GEN_4, NettuxPure_StarterRoom_EventScript_Chimchar
        goto_if_set FLAG_NETTUX_STARTER_GEN_3, NettuxPure_StarterRoom_EventScript_Torchic
        goto_if_set FLAG_NETTUX_STARTER_GEN_2, NettuxPure_StarterRoom_EventScript_Cyndaquil
        goto NettuxPure_StarterRoom_EventScript_Charmander

NettuxPure_StarterRoom_EventScript_GrassBall::
        goto_if_set FLAG_NETTUX_STARTER_GEN_9, NettuxPure_StarterRoom_EventScript_Sprigatito
        goto_if_set FLAG_NETTUX_STARTER_GEN_8, NettuxPure_StarterRoom_EventScript_Grookey
        goto_if_set FLAG_NETTUX_STARTER_GEN_7, NettuxPure_StarterRoom_EventScript_Rowlet
        goto_if_set FLAG_NETTUX_STARTER_GEN_6, NettuxPure_StarterRoom_EventScript_Chespin
        goto_if_set FLAG_NETTUX_STARTER_GEN_5, NettuxPure_StarterRoom_EventScript_Snivy
        goto_if_set FLAG_NETTUX_STARTER_GEN_4, NettuxPure_StarterRoom_EventScript_Turtwig
        goto_if_set FLAG_NETTUX_STARTER_GEN_3, NettuxPure_StarterRoom_EventScript_Treecko
        goto_if_set FLAG_NETTUX_STARTER_GEN_2, NettuxPure_StarterRoom_EventScript_Chikorita
        goto NettuxPure_StarterRoom_EventScript_Bulbasaur

NettuxPure_StarterRoom_EventScript_WaterBall::
        goto_if_set FLAG_NETTUX_STARTER_GEN_9, NettuxPure_StarterRoom_EventScript_Quaxly
        goto_if_set FLAG_NETTUX_STARTER_GEN_8, NettuxPure_StarterRoom_EventScript_Sobble
        goto_if_set FLAG_NETTUX_STARTER_GEN_7, NettuxPure_StarterRoom_EventScript_Popplio
        goto_if_set FLAG_NETTUX_STARTER_GEN_6, NettuxPure_StarterRoom_EventScript_Froakie
        goto_if_set FLAG_NETTUX_STARTER_GEN_5, NettuxPure_StarterRoom_EventScript_Oshawott
        goto_if_set FLAG_NETTUX_STARTER_GEN_4, NettuxPure_StarterRoom_EventScript_Piplup
        goto_if_set FLAG_NETTUX_STARTER_GEN_3, NettuxPure_StarterRoom_EventScript_Mudkip
        goto_if_set FLAG_NETTUX_STARTER_GEN_2, NettuxPure_StarterRoom_EventScript_Totodile
        goto NettuxPure_StarterRoom_EventScript_Squirtle

NettuxPure_StarterRoom_EventScript_Charmander::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_CHARMANDER, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveCharmander
        end

NettuxPure_StarterRoom_EventScript_GiveCharmander::
        bufferspeciesname STR_VAR_1, SPECIES_CHARMANDER
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHARMANDER
        givemon SPECIES_CHARMANDER, 5
        goto NettuxPure_StarterRoom_EventScript_SendCharmanderToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendCharmanderToParty::
        removeobject LOCALID_BALL_CHARMANDER
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedCharmander
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedCharmander
        end

NettuxPure_StarterRoom_EventScript_ReceivedCharmander::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_Bulbasaur::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_BULBASAUR, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveBulbasaur
        end

NettuxPure_StarterRoom_EventScript_GiveBulbasaur::
        bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BULBASAUR
        givemon SPECIES_BULBASAUR, 5
        goto NettuxPure_StarterRoom_EventScript_SendBulbasaurToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendBulbasaurToParty::
        removeobject LOCALID_BALL_BULBASAUR
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedBulbasaur
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedBulbasaur
        end

NettuxPure_StarterRoom_EventScript_ReceivedBulbasaur::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end


NettuxPure_StarterRoom_EventScript_Squirtle::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_SQUIRTLE, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveSquirtle
        end

NettuxPure_StarterRoom_EventScript_GiveSquirtle::
        bufferspeciesname STR_VAR_1, SPECIES_SQUIRTLE
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SQUIRTLE
        givemon SPECIES_SQUIRTLE, 5
        goto NettuxPure_StarterRoom_EventScript_SendSquirtleToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendSquirtleToParty::
        removeobject LOCALID_BALL_SQUIRTLE
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedSquirtle
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedSquirtle
        end

NettuxPure_StarterRoom_EventScript_ReceivedSquirtle::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_CyndaquilBall::
        goto NettuxPure_StarterRoom_EventScript_Cyndaquil

NettuxPure_StarterRoom_EventScript_Cyndaquil::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_CYNDAQUIL, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveCyndaquil
        end

NettuxPure_StarterRoom_EventScript_GiveCyndaquil::
        bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CYNDAQUIL
        givemon SPECIES_CYNDAQUIL, 5
        goto NettuxPure_StarterRoom_EventScript_SendCyndaquilToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendCyndaquilToParty::
        removeobject LOCALID_BALL_CYNDAQUIL
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedCyndaquil
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedCyndaquil
        end

NettuxPure_StarterRoom_EventScript_ReceivedCyndaquil::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_ChikoritaBall::
        goto NettuxPure_StarterRoom_EventScript_Chikorita

NettuxPure_StarterRoom_EventScript_Chikorita::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_CHIKORITA, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveChikorita
        end

NettuxPure_StarterRoom_EventScript_GiveChikorita::
        bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIKORITA
        givemon SPECIES_CHIKORITA, 5
        goto NettuxPure_StarterRoom_EventScript_SendChikoritaToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendChikoritaToParty::
        removeobject LOCALID_BALL_CHIKORITA
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedChikorita
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedChikorita
        end

NettuxPure_StarterRoom_EventScript_ReceivedChikorita::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_TotodileBall::
        goto NettuxPure_StarterRoom_EventScript_Totodile

NettuxPure_StarterRoom_EventScript_Totodile::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_TOTODILE, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveTotodile
        end

NettuxPure_StarterRoom_EventScript_GiveTotodile::
        bufferspeciesname STR_VAR_1, SPECIES_TOTODILE
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TOTODILE
        givemon SPECIES_TOTODILE, 5
        goto NettuxPure_StarterRoom_EventScript_SendTotodileToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendTotodileToParty::
        removeobject LOCALID_BALL_TOTODILE
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedTotodile
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedTotodile
        end

NettuxPure_StarterRoom_EventScript_ReceivedTotodile::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_TurtwigBall::
        goto NettuxPure_StarterRoom_EventScript_Turtwig

NettuxPure_StarterRoom_EventScript_Turtwig::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_TURTWIG, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveTurtwig
        end

NettuxPure_StarterRoom_EventScript_GiveTurtwig::
        bufferspeciesname STR_VAR_1, SPECIES_TURTWIG
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TURTWIG
        givemon SPECIES_TURTWIG, 5
        goto NettuxPure_StarterRoom_EventScript_SendTurtwigToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendTurtwigToParty::
        removeobject LOCALID_BALL_TURTWIG
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedTurtwig
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedTurtwig
        end

NettuxPure_StarterRoom_EventScript_ReceivedTurtwig::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_PiplupBall::
        goto NettuxPure_StarterRoom_EventScript_Piplup

NettuxPure_StarterRoom_EventScript_Piplup::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_PIPLUP, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GivePiplup
        end

NettuxPure_StarterRoom_EventScript_GivePiplup::
        bufferspeciesname STR_VAR_1, SPECIES_PIPLUP
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_PIPLUP
        givemon SPECIES_PIPLUP, 5
        goto NettuxPure_StarterRoom_EventScript_SendPiplupToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendPiplupToParty::
        removeobject LOCALID_BALL_PIPLUP
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedPiplup
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedPiplup
        end

NettuxPure_StarterRoom_EventScript_ReceivedPiplup::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_ChimcharBall::
        goto NettuxPure_StarterRoom_EventScript_Chimchar

NettuxPure_StarterRoom_EventScript_Chimchar::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_CHIMCHAR, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveChimchar
        end

NettuxPure_StarterRoom_EventScript_GiveChimchar::
        bufferspeciesname STR_VAR_1, SPECIES_CHIMCHAR
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIMCHAR
        givemon SPECIES_CHIMCHAR, 5
        goto NettuxPure_StarterRoom_EventScript_SendChimcharToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendChimcharToParty::
        removeobject LOCALID_BALL_CHIMCHAR
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedChimchar
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedChimchar
        end

NettuxPure_StarterRoom_EventScript_ReceivedChimchar::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_SnivyBall::
        goto NettuxPure_StarterRoom_EventScript_Snivy

NettuxPure_StarterRoom_EventScript_Snivy::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_SNIVY, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveSnivy
        end

NettuxPure_StarterRoom_EventScript_GiveSnivy::
        bufferspeciesname STR_VAR_1, SPECIES_SNIVY
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SNIVY
        givemon SPECIES_SNIVY, 5
        goto NettuxPure_StarterRoom_EventScript_SendSnivyToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendSnivyToParty::
        removeobject LOCALID_BALL_SNIVY
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedSnivy
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedSnivy
        end

NettuxPure_StarterRoom_EventScript_ReceivedSnivy::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_TepigBall::
        goto NettuxPure_StarterRoom_EventScript_Tepig

NettuxPure_StarterRoom_EventScript_Tepig::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_TEPIG, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveTepig
        end

NettuxPure_StarterRoom_EventScript_GiveTepig::
        bufferspeciesname STR_VAR_1, SPECIES_TEPIG
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TEPIG
        givemon SPECIES_TEPIG, 5
        goto NettuxPure_StarterRoom_EventScript_SendTepigToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendTepigToParty::
        removeobject LOCALID_BALL_TEPIG
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedTepig
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedTepig
        end

NettuxPure_StarterRoom_EventScript_ReceivedTepig::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_OshawottBall::
        goto NettuxPure_StarterRoom_EventScript_Oshawott

NettuxPure_StarterRoom_EventScript_Oshawott::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_OSHAWOTT, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveOshawott
        end

NettuxPure_StarterRoom_EventScript_GiveOshawott::
        bufferspeciesname STR_VAR_1, SPECIES_OSHAWOTT
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_OSHAWOTT
        givemon SPECIES_OSHAWOTT, 5
        goto NettuxPure_StarterRoom_EventScript_SendOshawottToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendOshawottToParty::
        removeobject LOCALID_BALL_OSHAWOTT
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedOshawott
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedOshawott
        end

NettuxPure_StarterRoom_EventScript_ReceivedOshawott::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_ChespinBall::
        goto NettuxPure_StarterRoom_EventScript_Chespin

NettuxPure_StarterRoom_EventScript_Chespin::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_CHESPIN, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveChespin
        end

NettuxPure_StarterRoom_EventScript_GiveChespin::
        bufferspeciesname STR_VAR_1, SPECIES_CHESPIN
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHESPIN
        givemon SPECIES_CHESPIN, 5
        goto NettuxPure_StarterRoom_EventScript_SendChespinToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendChespinToParty::
        removeobject LOCALID_BALL_CHESPIN
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedChespin
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedChespin
        end

NettuxPure_StarterRoom_EventScript_ReceivedChespin::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_FennekinBall::
        goto NettuxPure_StarterRoom_EventScript_Fennekin

NettuxPure_StarterRoom_EventScript_Fennekin::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_FENNEKIN, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveFennekin
        end

NettuxPure_StarterRoom_EventScript_GiveFennekin::
        bufferspeciesname STR_VAR_1, SPECIES_FENNEKIN
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_FENNEKIN
        givemon SPECIES_FENNEKIN, 5
        goto NettuxPure_StarterRoom_EventScript_SendFennekinToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendFennekinToParty::
        removeobject LOCALID_BALL_FENNEKIN
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedFennekin
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedFennekin
        end

NettuxPure_StarterRoom_EventScript_ReceivedFennekin::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_FroakieBall::
        goto NettuxPure_StarterRoom_EventScript_Froakie

NettuxPure_StarterRoom_EventScript_Froakie::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_FROAKIE, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveFroakie
        end

NettuxPure_StarterRoom_EventScript_GiveFroakie::
        bufferspeciesname STR_VAR_1, SPECIES_FROAKIE
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_FROAKIE
        givemon SPECIES_FROAKIE, 5
        goto NettuxPure_StarterRoom_EventScript_SendFroakieToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendFroakieToParty::
        removeobject LOCALID_BALL_FROAKIE
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedFroakie
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedFroakie
        end

NettuxPure_StarterRoom_EventScript_ReceivedFroakie::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_RowletBall::
        goto NettuxPure_StarterRoom_EventScript_Rowlet

NettuxPure_StarterRoom_EventScript_Rowlet::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_ROWLET, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveRowlet
        end

NettuxPure_StarterRoom_EventScript_GiveRowlet::
        bufferspeciesname STR_VAR_1, SPECIES_ROWLET
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ROWLET
        givemon SPECIES_ROWLET, 5
        goto NettuxPure_StarterRoom_EventScript_SendRowletToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendRowletToParty::
        removeobject LOCALID_BALL_ROWLET
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedRowlet
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedRowlet
        end

NettuxPure_StarterRoom_EventScript_ReceivedRowlet::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_LittenBall::
        goto NettuxPure_StarterRoom_EventScript_Litten

NettuxPure_StarterRoom_EventScript_Litten::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_LITTEN, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveLitten
        end

NettuxPure_StarterRoom_EventScript_GiveLitten::
        bufferspeciesname STR_VAR_1, SPECIES_LITTEN
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LITTEN
        givemon SPECIES_LITTEN, 5
        goto NettuxPure_StarterRoom_EventScript_SendLittenToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendLittenToParty::
        removeobject LOCALID_BALL_LITTEN
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedLitten
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedLitten
        end

NettuxPure_StarterRoom_EventScript_ReceivedLitten::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_PopplioBall::
        goto NettuxPure_StarterRoom_EventScript_Popplio

NettuxPure_StarterRoom_EventScript_Popplio::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_POPPLIO, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GivePopplio
        end

NettuxPure_StarterRoom_EventScript_GivePopplio::
        bufferspeciesname STR_VAR_1, SPECIES_POPPLIO
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_POPPLIO
        givemon SPECIES_POPPLIO, 5
        goto NettuxPure_StarterRoom_EventScript_SendPopplioToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendPopplioToParty::
        removeobject LOCALID_BALL_POPPLIO
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedPopplio
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedPopplio
        end

NettuxPure_StarterRoom_EventScript_ReceivedPopplio::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_GrookeyBall::
        goto NettuxPure_StarterRoom_EventScript_Grookey

NettuxPure_StarterRoom_EventScript_Grookey::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_GROOKEY, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveGrookey
        end

NettuxPure_StarterRoom_EventScript_GiveGrookey::
        bufferspeciesname STR_VAR_1, SPECIES_GROOKEY
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GROOKEY
        givemon SPECIES_GROOKEY, 5
        goto NettuxPure_StarterRoom_EventScript_SendGrookeyToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendGrookeyToParty::
        removeobject LOCALID_BALL_GROOKEY
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedGrookey
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedGrookey
        end

NettuxPure_StarterRoom_EventScript_ReceivedGrookey::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_ScorbunnyBall::
        goto NettuxPure_StarterRoom_EventScript_Scorbunny

NettuxPure_StarterRoom_EventScript_Scorbunny::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_SCORBUNNY, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveScorbunny
        end

NettuxPure_StarterRoom_EventScript_GiveScorbunny::
        bufferspeciesname STR_VAR_1, SPECIES_SCORBUNNY
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SCORBUNNY
        givemon SPECIES_SCORBUNNY, 5
        goto NettuxPure_StarterRoom_EventScript_SendScorbunnyToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendScorbunnyToParty::
        removeobject LOCALID_BALL_SCORBUNNY
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedScorbunny
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedScorbunny
        end

NettuxPure_StarterRoom_EventScript_ReceivedScorbunny::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_SobbleBall::
        goto NettuxPure_StarterRoom_EventScript_Sobble

NettuxPure_StarterRoom_EventScript_Sobble::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_SOBBLE, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveSobble
        end

NettuxPure_StarterRoom_EventScript_GiveSobble::
        bufferspeciesname STR_VAR_1, SPECIES_SOBBLE
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SOBBLE
        givemon SPECIES_SOBBLE, 5
        goto NettuxPure_StarterRoom_EventScript_SendSobbleToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendSobbleToParty::
        removeobject LOCALID_BALL_SOBBLE
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedSobble
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedSobble
        end

NettuxPure_StarterRoom_EventScript_ReceivedSobble::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_SprigatitoBall::
        goto NettuxPure_StarterRoom_EventScript_Sprigatito

NettuxPure_StarterRoom_EventScript_Sprigatito::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_SPRIGATITO, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveSprigatito
        end

NettuxPure_StarterRoom_EventScript_GiveSprigatito::
        bufferspeciesname STR_VAR_1, SPECIES_SPRIGATITO
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SPRIGATITO
        givemon SPECIES_SPRIGATITO, 5
        goto NettuxPure_StarterRoom_EventScript_SendSprigatitoToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendSprigatitoToParty::
        removeobject LOCALID_BALL_SPRIGATITO
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedSprigatito
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedSprigatito
        end

NettuxPure_StarterRoom_EventScript_ReceivedSprigatito::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_QuaxlyBall::
        goto NettuxPure_StarterRoom_EventScript_Quaxly

NettuxPure_StarterRoom_EventScript_Quaxly::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_QUAXLY, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveQuaxly
        end

NettuxPure_StarterRoom_EventScript_GiveQuaxly::
        bufferspeciesname STR_VAR_1, SPECIES_QUAXLY
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_QUAXLY
        givemon SPECIES_QUAXLY, 5
        goto NettuxPure_StarterRoom_EventScript_SendQuaxlyToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendQuaxlyToParty::
        removeobject LOCALID_BALL_QUAXLY
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedQuaxly
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedQuaxly
        end

NettuxPure_StarterRoom_EventScript_ReceivedQuaxly::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

NettuxPure_StarterRoom_EventScript_FuecocoBall::
        goto NettuxPure_StarterRoom_EventScript_Fuecoco

NettuxPure_StarterRoom_EventScript_Fuecoco::
        release
        goto_if_set FLAG_NETTUX_CHOSE_STARTER, NettuxPure_StarterRoom_EventScript_AlreadyChoseStarter
        showmonpic SPECIES_FUECOCO, 10, 3
        msgbox NettuxPure_StarterRoom_Text_YoullTakeThisOne, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_TakeYourTime
        goto NettuxPure_StarterRoom_EventScript_GiveFuecoco
        end

NettuxPure_StarterRoom_EventScript_GiveFuecoco::
        bufferspeciesname STR_VAR_1, SPECIES_FUECOCO
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_FUECOCO
        givemon SPECIES_FUECOCO, 5
        goto NettuxPure_StarterRoom_EventScript_SendFuecocoToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendFuecocoToParty::
        removeobject LOCALID_BALL_FUECOCO
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedFuecoco
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
        goto NettuxPure_StarterRoom_EventScript_ReceivedFuecoco
        end

NettuxPure_StarterRoom_EventScript_ReceivedFuecoco::
        hidemonpic
        releaseall
        goto NettuxPure_StarterRoom_InitialiseGame
        end

