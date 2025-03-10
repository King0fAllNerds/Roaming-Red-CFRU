.align 2
.thumb

.include "../xse_commands.s"
.include "../xse_defines.s"

.global EventScript_FollowerMon

EventScript_FollowerMon:
    special 0xD3
    lock
    storemonid
    bufferpokemon 0x0 0x4004
    showpokepic 0x4004 0x15 0x6
    cry 0x4004 0x0
    msgbox gText_FollowerMon_Test MSG_NORMAL
    hidepokepic
    release
    end
    