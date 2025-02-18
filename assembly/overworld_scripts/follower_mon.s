.align 2
.thumb

.include "../xse_commands.s"
.include "../xse_defines.s"

.global EventScript_FollowerMon

EventScript_FollowerMon:
    followerfaceplayer
    lock
    msgbox gText_FollowerMon_Test MSG_NORMAL
    release
    end
    