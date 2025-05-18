.align 2
.thumb

.include "../xse_commands.s"
.include "../xse_defines.s"

.global EventScript_Pallet_FatGuy

EventScript_Pallet_FatGuy:
    faceplayer
    lock
    setflag 0x926
    setflag 0x828
    setflag 0x4BD
    givepokemon 0x11A 0x5 0x0 0x0 0x0 0x0
    givepokemon 0x510 0x5 0x0 0x0 0x0 0x0
    givepokemon 0x456 0x5 0x0 0x0 0x0 0x0
    givepokemon 0x22C 0x5 0x0 0x0 0x0 0x0
    givepokemon 0x99 0x5 0x0 0x0 0x0 0x0
    giveegg 0x1
    setvar 0x8001 0xFD
    special 0xD1
    msgbox gText_TestScript MSG_NORMAL
    release
    end

.align 2
.global EventScript_Pallet_Girl

EventScript_Pallet_Girl:
    faceplayer
    lock
    msgbox gText_PalletGirl_Text1 MSG_YESNO
    compare LASTRESULT 0x1
    if YES _goto PalletGirl_ShowFollowerMon
    setflag 0xa02
    setflag 0xa03
    hidefollowermon
    clearflag 0x4BD
    special 0xD2
    release
    end

PalletGirl_ShowFollowerMon:
    showfollowermon
    special 0xD1
    setflag 0x4BD
    release
    end
    
