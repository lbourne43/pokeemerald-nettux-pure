.set LOCALID_WALLY, 1

NettuxPure_Gauntlet9_1_MapScripts::
	.byte 0

NettuxPure_Gauntlet9_EventScript_Encounters::
        msgbox NettuxPure_Gauntlet9_Text_Encounters, MSGBOX_DEFAULT
        closemessage
        end

NettuxPure_Gauntlet9_Text_Encounters:
        .string "POKéMON observed in this area:\n"
        .string "Voltorb\p"
        .string "Mareep\p"
        .string "Pikachu\p"
        .string "Onix\p"
        .string "Magnemite\p"
        .string "Electrike\l"
        .string "Electabuzz\l"
        .string "Koffing\l"
        .string "Scyther\l"
        .string "Torchic$"
