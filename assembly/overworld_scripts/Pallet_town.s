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
    setflag FLAG_FOLLOWER_POKEMON
    givepokemon SPECIES_ROWLET 0x5 0x0 0x0 0x0 0x0
    givepokemon SPECIES_CYNDAQUIL 0x5 0x0 0x0 0x0 0x0
    givepokemon SPECIES_MUDKIP 0x5 0x0 0x0 0x0 0x0
    givepokemon SPECIES_SALAMENCE 0x5 0x0 0x0 0x0 0x0
    givepokemon SPECIES_ROOKIDEE 0x5 0x0 0x0 0x0 0x0
    giveegg 0x1
    addfollower 30 //You can remove this if have already defined an object event in the map to be a follower
    followerbehindplayer 30 //Change 30 to the object event Local Id.
    setfollower 30 0x7E //Change 30 to the object event Local Id.
    updatefollowerpokemonsprite
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
    special 0xd1
    showfollowermon
    setflag 0x4BD
    release
    end
    
