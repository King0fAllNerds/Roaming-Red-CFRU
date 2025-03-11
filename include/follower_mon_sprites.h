#ifndef FOLLOWER_MON_SPRITES_H
#define FOLLOWER_MON_SPRITES_H

#include "global.h"
#include "constants/event_objects.h"

#ifdef FOLLOWING_POKEMON
#define EVENT_OBJ_PAL_TAG_NONE 0x1102
#define gEventObjectBaseOam_16x16 ((const struct OamData*) 0x83A36F8)
#define gEventObjectBaseOam_16x32 ((const struct OamData*) 0x83A3710)
#define gEventObjectBaseOam_32x32 ((const struct OamData*) 0x83A3718)
#define gEventObjectBaseOam_64x64 ((const struct OamData*) 0x83A3720)
#define gEventObjectSpriteOamTables_16x16 ((const struct SubspriteTable*) 0x83A3748)
#define gEventObjectSpriteOamTables_16x32 ((const struct SubspriteTable*) 0x83A379C)
#define gEventObjectSpriteOamTables_32x32 ((const struct SubspriteTable*) 0x83A37F0)
#define gEventObjectSpriteOamTables_64x64 ((const struct SubspriteTable*) 0x83A38D0)
#define gEventObjectImageAnimTable_PlayerNormal ((const union AnimCmd* const*) 0x83A3470)
#define gEventObjectImageAnimTable_Standard ((const union AnimCmd* const*) 0x83A3368)
#define gEventObjectImageAnimTable_Surfing ((const union AnimCmd* const*) 0x83A3584)
#define gEventObjectImageAnimTable_FieldMove ((const union AnimCmd* const*) 0x83A3638)
#define gEventObjectImageAnimTable_Fishing ((const union AnimCmd* const*) 0x83A3668)
#define gEventObjectImageAnimTable_VsSeekerBike ((const union AnimCmd* const*) 0x83A3640)

#define ANIM_STD_FACE_SOUTH       0
#define ANIM_STD_FACE_NORTH       1
#define ANIM_STD_FACE_WEST        2
#define ANIM_STD_FACE_EAST        3
#define ANIM_STD_GO_SOUTH         4
#define ANIM_STD_GO_NORTH         5
#define ANIM_STD_GO_WEST          6
#define ANIM_STD_GO_EAST          7
#define ANIM_STD_GO_FAST_SOUTH    8
#define ANIM_STD_GO_FAST_NORTH    9
#define ANIM_STD_GO_FAST_WEST     10
#define ANIM_STD_GO_FAST_EAST     11
#define ANIM_STD_GO_FASTER_SOUTH  12
#define ANIM_STD_GO_FASTER_NORTH  13
#define ANIM_STD_GO_FASTER_WEST   14
#define ANIM_STD_GO_FASTER_EAST   15
#define ANIM_STD_GO_FASTEST_SOUTH 16
#define ANIM_STD_GO_FASTEST_NORTH 17
#define ANIM_STD_GO_FASTEST_WEST  18
#define ANIM_STD_GO_FASTEST_EAST  19
#define ANIM_RAISE_HAND           20

static const union AnimCmd sMonAnim_FaceSouth[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_FaceNorth[] =
{
    ANIMCMD_FRAME(2, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_FaceWest[] =
{
    ANIMCMD_FRAME(4, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_FaceEast[] =
{
    ANIMCMD_FRAME(4, 16, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoSouth[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoNorth[] =
{
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoWest[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoEast[] =
{
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFastSouth[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFastNorth[] =
{
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFastWest[] =
{
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFastEast[] =
{
    ANIMCMD_FRAME(4, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 4, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFasterSouth[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFasterNorth[] =
{
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_FRAME(3, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFasterWest[] =
{
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(5, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFasterEast[] =
{
    ANIMCMD_FRAME(4, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 2, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFastestSouth[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFastestNorth[] =
{
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFastestWest[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFastestEast[] =
{
    ANIMCMD_FRAME(4, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 1, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gFollowerMonAnimTable[] =
{
    [ANIM_STD_FACE_SOUTH] = sMonAnim_FaceSouth,
    [ANIM_STD_FACE_NORTH] = sMonAnim_FaceNorth,
    [ANIM_STD_FACE_WEST] = sMonAnim_FaceWest,
    [ANIM_STD_FACE_EAST] = sMonAnim_FaceEast,
    [ANIM_STD_GO_SOUTH] = sMonAnim_GoSouth,
    [ANIM_STD_GO_NORTH] = sMonAnim_GoNorth,
    [ANIM_STD_GO_WEST] = sMonAnim_GoWest,
    [ANIM_STD_GO_EAST] = sMonAnim_GoEast,
    [ANIM_STD_GO_FAST_SOUTH] = sMonAnim_GoFastSouth,
    [ANIM_STD_GO_FAST_NORTH] = sMonAnim_GoFastNorth,
    [ANIM_STD_GO_FAST_WEST] = sMonAnim_GoFastWest,
    [ANIM_STD_GO_FAST_EAST] = sMonAnim_GoFastEast,
    [ANIM_STD_GO_FASTER_SOUTH] = sMonAnim_GoFasterSouth,
    [ANIM_STD_GO_FASTER_NORTH] = sMonAnim_GoFasterNorth,
    [ANIM_STD_GO_FASTER_WEST] = sMonAnim_GoFasterWest,
    [ANIM_STD_GO_FASTER_EAST] = sMonAnim_GoFasterEast,
    [ANIM_STD_GO_FASTEST_SOUTH] = sMonAnim_GoFastestSouth,
    [ANIM_STD_GO_FASTEST_NORTH] = sMonAnim_GoFastestNorth,
    [ANIM_STD_GO_FASTEST_WEST] = sMonAnim_GoFastestWest,
    [ANIM_STD_GO_FASTEST_EAST] = sMonAnim_GoFastestEast,
    [ANIM_RAISE_HAND] = sMonAnim_FaceSouth,
};

#define MON_OW_TEMPLATE_32x32_FRAMES(id, name)                          \
static const struct SpriteFrameImage sPicTable_##name[] = {             \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 4, 4, 0),    \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 4, 4, 1),    \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 4, 4, 2),    \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 4, 4, 3),    \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 4, 4, 4),    \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 4, 4, 5),    \
};

#define MON_OW_OBJECT_GRAPHICS(PalId, name)                 \
{                                                           \
    .tileTag = 0xFFFF,                                      \
    .paletteTag1 = PalId,                                   \
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,                  \
    .size = (32 * 32) / 2,                                  \
    .width = 32,                                            \
    .height = 32,                                           \
    .shadowSize = SHADOW_SIZE_M,                            \
    .inanimate = FALSE,                                     \
    .disableReflectionPaletteLoad = FALSE,                  \
    .tracks = TRACKS_FOOT,                                  \
    .gender = MALE,                                         \
    .oam = gEventObjectBaseOam_32x32,                       \
    .subspriteTables = gEventObjectSpriteOamTables_32x32,   \
    .anims = gFollowerMonAnimTable,                         \
    .images = sPicTable_##name,                             \
    .affineAnims = gDummySpriteAffineAnimTable,             \
},

#define MON_OW_TEMPLATE_64x64_FRAMES(id, name)                          \
static const struct SpriteFrameImage sPicTable_##name[] = {             \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 8, 8, 0),    \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 8, 8, 1),    \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 8, 8, 2),    \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 8, 8, 3),    \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 8, 8, 4),    \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 8, 8, 5),    \
};

#define MON_OW_OBJECT_GRAPHICS_64(PalId, name)                          \
{                                                                       \
        .tileTag = 0xFFFF,                                              \
        .paletteTag1 = PalId,                                           \
        .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,                          \
        .size = (64 * 64) / 2,                                          \
        .width = 64,                                                    \
        .height = 64,                                                   \
        .shadowSize = SHADOW_SIZE_M,                                    \
        .inanimate = FALSE,                                             \
        .disableReflectionPaletteLoad = FALSE,                          \
        .tracks = TRACKS_FOOT,                                          \
        .gender = MALE,                                                 \
        .oam = gEventObjectBaseOam_64x64,                               \
        .subspriteTables = gEventObjectSpriteOamTables_64x64,           \
        .anims = gFollowerMonAnimTable,                                \
        .images = sPicTable_##name,                                     \
        .affineAnims = gDummySpriteAffineAnimTable,                     \
},

//Tiles
//Paste follower mon Tiles defines here!!


//Tiles defines end
#endif
#endif