.set LOCALID_BALL_TREECKO, 1
.set LOCALID_BALL_MUDKIP, 2
.set LOCALID_BALL_TOCHIC, 3

NettuxPure_StarterRoom_MapScripts::


NettuxPure_StarterRoom_EventScript_TreeckoBall::
        NettuxPure_StarterRoom_EventScript_GiveTreecko

NettuxPure_StarterRoom_EventScript_MudkipBall::
        goto NettuxPure_StarterRoom_EventScript_GiveMudkip

NettuxPure_StarterRoom_EventScript_TorchicBall::
        goto NettuxPure_StarterRoom_EventScript_GiveTorchic

NettuxPure_StarterRoom_EventScript_GiveTorchic::
        bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORCHIC
        givemon SPECIES_CYNDAQUIL, 5
        NettuxPure_StarterRoom_EventScript_SendTorchicToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendTorchicToParty
        removeobject LOCALID_BALL_TORCHIC
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedTorchic
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
	goto NettuxPure_StarterRoom_EventScript_ReceivedTorchic
        end

NettuxPure_StarterRoom_EventScript_ReceivedTorchic
	hidemonpic
	releaseall
	end

NettuxPure_StarterRoom_EventScript_GiveMudkip::
        bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MUDKIP
        givemon SPECIES_MUDKIP, 5
        NettuxPure_StarterRoom_EventScript_SendMudkipToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendMudkipToParty
        removeobject LOCALID_BALL_MUDKIP
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedMudkip
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
	goto NettuxPure_StarterRoom_EventScript_ReceivedMudkip
        end

NettuxPure_StarterRoom_EventScript_ReceivedMudkip
	hidemonpic
	releaseall
	end

NettuxPure_StarterRoom_EventScript_GiveTreecko::
        bufferspeciesname STR_VAR_1, SPECIES_TREECKO
        setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TREECKO
        givemon SPECIES_TREECKO, 5
        NettuxPure_StarterRoom_EventScript_SendTreeckoToParty
        hidemonpic
        end

NettuxPure_StarterRoom_EventScript_SendTreeckoToParty
        removeobject LOCALID_BALL_TREECKO
        msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, NettuxPure_StarterRoom_EventScript_ReceivedTreecko
        call Common_EventScript_GetGiftMonPartySlot
        call Common_EventScript_NameReceivedPartyMon
	goto NettuxPure_StarterRoom_EventScript_ReceivedTreecko
        end

NettuxPure_StarterRoom_EventScript_ReceivedTreecko
	hidemonpic
	releaseall
	end

