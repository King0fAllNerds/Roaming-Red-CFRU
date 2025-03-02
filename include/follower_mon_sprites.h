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
extern const u8 gFollowingMonPic_0001_BulbasaurTiles[];
extern const u8 gFollowingMonPic_0002_IvysaurTiles[];
extern const u8 gFollowingMonPic_0003_VenusaurTiles[];
extern const u8 gFollowingMonPic_0004_CharmanderTiles[];
extern const u8 gFollowingMonPic_0005_CharmeleonTiles[];
extern const u8 gFollowingMonPic_0006_CharizardTiles[];
extern const u8 gFollowingMonPic_0007_SquirtleTiles[];
extern const u8 gFollowingMonPic_0008_WartortleTiles[];
extern const u8 gFollowingMonPic_0009_BlastoiseTiles[];
extern const u8 gFollowingMonPic_0010_CaterpieTiles[];
extern const u8 gFollowingMonPic_0011_MetapodTiles[];
extern const u8 gFollowingMonPic_0012_ButterfreeTiles[];
extern const u8 gFollowingMonPic_0013_WeedleTiles[];
extern const u8 gFollowingMonPic_0014_KakunaTiles[];
extern const u8 gFollowingMonPic_0015_BeedrillTiles[];
extern const u8 gFollowingMonPic_0016_PidgeyTiles[];
extern const u8 gFollowingMonPic_0017_PidgeottoTiles[];
extern const u8 gFollowingMonPic_0018_PidgeotTiles[];
extern const u8 gFollowingMonPic_0019_RattataTiles[];
extern const u8 gFollowingMonPic_0020_RaticateTiles[];
extern const u8 gFollowingMonPic_0021_SpearowTiles[];
extern const u8 gFollowingMonPic_0022_FearowTiles[];
extern const u8 gFollowingMonPic_0023_EkansTiles[];
extern const u8 gFollowingMonPic_0024_ArbokTiles[];
extern const u8 gFollowingMonPic_0025_PikachuTiles[];
extern const u8 gFollowingMonPic_0026_RaichuTiles[];
extern const u8 gFollowingMonPic_0027_SandshrewTiles[];
extern const u8 gFollowingMonPic_0028_SandslashTiles[];
extern const u8 gFollowingMonPic_0029_Nidoran_FTiles[];
extern const u8 gFollowingMonPic_0030_NidorinaTiles[];
extern const u8 gFollowingMonPic_0031_NidoqueenTiles[];
extern const u8 gFollowingMonPic_0032_Nidoran_MTiles[];
extern const u8 gFollowingMonPic_0033_NidorinoTiles[];
extern const u8 gFollowingMonPic_0034_NidokingTiles[];
extern const u8 gFollowingMonPic_0035_ClefairyTiles[];
extern const u8 gFollowingMonPic_0036_ClefableTiles[];
extern const u8 gFollowingMonPic_0037_VulpixTiles[];
extern const u8 gFollowingMonPic_0038_NinetalesTiles[];
extern const u8 gFollowingMonPic_0039_JigglypuffTiles[];
extern const u8 gFollowingMonPic_0040_WigglytuffTiles[];
extern const u8 gFollowingMonPic_0041_ZubatTiles[];
extern const u8 gFollowingMonPic_0042_GolbatTiles[];
extern const u8 gFollowingMonPic_0043_OddishTiles[];
extern const u8 gFollowingMonPic_0044_GloomTiles[];
extern const u8 gFollowingMonPic_0045_VileplumeTiles[];
extern const u8 gFollowingMonPic_0046_ParasTiles[];
extern const u8 gFollowingMonPic_0047_ParasectTiles[];
extern const u8 gFollowingMonPic_0048_VenonatTiles[];
extern const u8 gFollowingMonPic_0049_VenomothTiles[];
extern const u8 gFollowingMonPic_0050_DiglettTiles[];
extern const u8 gFollowingMonPic_0051_DugtrioTiles[];
extern const u8 gFollowingMonPic_0052_MeowthTiles[];
extern const u8 gFollowingMonPic_0053_PersianTiles[];
extern const u8 gFollowingMonPic_0054_PsyduckTiles[];
extern const u8 gFollowingMonPic_0055_GolduckTiles[];
extern const u8 gFollowingMonPic_0056_MankeyTiles[];
extern const u8 gFollowingMonPic_0057_PrimeapeTiles[];
extern const u8 gFollowingMonPic_0058_GrowlitheTiles[];
extern const u8 gFollowingMonPic_0059_ArcanineTiles[];
extern const u8 gFollowingMonPic_0060_PoliwagTiles[];
extern const u8 gFollowingMonPic_0061_PoliwhirlTiles[];
extern const u8 gFollowingMonPic_0062_PoliwrathTiles[];
extern const u8 gFollowingMonPic_0063_AbraTiles[];
extern const u8 gFollowingMonPic_0064_KadabraTiles[];
extern const u8 gFollowingMonPic_0065_AlakazamTiles[];
extern const u8 gFollowingMonPic_0066_MachopTiles[];
extern const u8 gFollowingMonPic_0067_MachokeTiles[];
extern const u8 gFollowingMonPic_0068_MachampTiles[];
extern const u8 gFollowingMonPic_0069_BellsproutTiles[];
extern const u8 gFollowingMonPic_0070_WeepinbellTiles[];
extern const u8 gFollowingMonPic_0071_VictreebelTiles[];
extern const u8 gFollowingMonPic_0072_TentacoolTiles[];
extern const u8 gFollowingMonPic_0073_TentacruelTiles[];
extern const u8 gFollowingMonPic_0074_GeodudeTiles[];
extern const u8 gFollowingMonPic_0075_GravelerTiles[];
extern const u8 gFollowingMonPic_0076_GolemTiles[];
extern const u8 gFollowingMonPic_0077_PonytaTiles[];
extern const u8 gFollowingMonPic_0078_RapidashTiles[];
extern const u8 gFollowingMonPic_0079_SlowpokeTiles[];
extern const u8 gFollowingMonPic_0080_SlowbroTiles[];
extern const u8 gFollowingMonPic_0081_MagnemiteTiles[];
extern const u8 gFollowingMonPic_0082_MagnetonTiles[];
extern const u8 gFollowingMonPic_0083_FarfetchdTiles[];
extern const u8 gFollowingMonPic_0084_DoduoTiles[];
extern const u8 gFollowingMonPic_0085_DodrioTiles[];
extern const u8 gFollowingMonPic_0086_SeelTiles[];
extern const u8 gFollowingMonPic_0087_DewgongTiles[];
extern const u8 gFollowingMonPic_0088_GrimerTiles[];
extern const u8 gFollowingMonPic_0089_MukTiles[];
extern const u8 gFollowingMonPic_0090_ShellderTiles[];
extern const u8 gFollowingMonPic_0091_CloysterTiles[];
extern const u8 gFollowingMonPic_0092_GastlyTiles[];
extern const u8 gFollowingMonPic_0093_HaunterTiles[];
extern const u8 gFollowingMonPic_0094_GengarTiles[];
extern const u8 gFollowingMonPic_0095_OnixTiles[];
extern const u8 gFollowingMonPic_0096_DrowzeeTiles[];
extern const u8 gFollowingMonPic_0097_HypnoTiles[];
extern const u8 gFollowingMonPic_0098_KrabbyTiles[];
extern const u8 gFollowingMonPic_0099_KinglerTiles[];
extern const u8 gFollowingMonPic_0100_VoltorbTiles[];
extern const u8 gFollowingMonPic_0101_ElectrodeTiles[];
extern const u8 gFollowingMonPic_0102_ExeggcuteTiles[];
extern const u8 gFollowingMonPic_0103_ExeggutorTiles[];
extern const u8 gFollowingMonPic_0104_CuboneTiles[];
extern const u8 gFollowingMonPic_0105_MarowakTiles[];
extern const u8 gFollowingMonPic_0106_HitmonleeTiles[];
extern const u8 gFollowingMonPic_0107_HitmonchanTiles[];
extern const u8 gFollowingMonPic_0108_LickitungTiles[];
extern const u8 gFollowingMonPic_0109_KoffingTiles[];
extern const u8 gFollowingMonPic_0110_WeezingTiles[];
extern const u8 gFollowingMonPic_0111_RhyhornTiles[];
extern const u8 gFollowingMonPic_0112_RhydonTiles[];
extern const u8 gFollowingMonPic_0113_ChanseyTiles[];
extern const u8 gFollowingMonPic_0114_TangelaTiles[];
extern const u8 gFollowingMonPic_0115_KangaskhanTiles[];
extern const u8 gFollowingMonPic_0116_HorseaTiles[];
extern const u8 gFollowingMonPic_0117_SeadraTiles[];
extern const u8 gFollowingMonPic_0118_GoldeenTiles[];
extern const u8 gFollowingMonPic_0119_SeakingTiles[];
extern const u8 gFollowingMonPic_0120_StaryuTiles[];
extern const u8 gFollowingMonPic_0121_StarmieTiles[];
extern const u8 gFollowingMonPic_0122_Mr_MimeTiles[];
extern const u8 gFollowingMonPic_0123_ScytherTiles[];
extern const u8 gFollowingMonPic_0124_JynxTiles[];
extern const u8 gFollowingMonPic_0125_ElectabuzzTiles[];
extern const u8 gFollowingMonPic_0126_MagmarTiles[];
extern const u8 gFollowingMonPic_0127_PinsirTiles[];
extern const u8 gFollowingMonPic_0128_TaurosTiles[];
extern const u8 gFollowingMonPic_0129_MagikarpTiles[];
extern const u8 gFollowingMonPic_0130_GyaradosTiles[];
extern const u8 gFollowingMonPic_0131_LaprasTiles[];
extern const u8 gFollowingMonPic_0132_DittoTiles[];
extern const u8 gFollowingMonPic_0133_EeveeTiles[];
extern const u8 gFollowingMonPic_0134_VaporeonTiles[];
extern const u8 gFollowingMonPic_0135_JolteonTiles[];
extern const u8 gFollowingMonPic_0136_FlareonTiles[];
extern const u8 gFollowingMonPic_0137_PorygonTiles[];
extern const u8 gFollowingMonPic_0138_OmanyteTiles[];
extern const u8 gFollowingMonPic_0139_OmastarTiles[];
extern const u8 gFollowingMonPic_0140_KabutoTiles[];
extern const u8 gFollowingMonPic_0141_KabutopsTiles[];
extern const u8 gFollowingMonPic_0142_AerodactylTiles[];
extern const u8 gFollowingMonPic_0143_SnorlaxTiles[];
extern const u8 gFollowingMonPic_0144_ArticunoTiles[];
extern const u8 gFollowingMonPic_0145_ZapdosTiles[];
extern const u8 gFollowingMonPic_0146_MoltresTiles[];
extern const u8 gFollowingMonPic_0147_DratiniTiles[];
extern const u8 gFollowingMonPic_0148_DragonairTiles[];
extern const u8 gFollowingMonPic_0149_DragoniteTiles[];
extern const u8 gFollowingMonPic_0150_MewtwoTiles[];
extern const u8 gFollowingMonPic_0151_MewTiles[];
extern const u8 gFollowingMonPic_0152_ChikoritaTiles[];
extern const u8 gFollowingMonPic_0153_BayleefTiles[];
extern const u8 gFollowingMonPic_0154_MeganiumTiles[];
extern const u8 gFollowingMonPic_0155_CyndaquilTiles[];
extern const u8 gFollowingMonPic_0156_QuilavaTiles[];
extern const u8 gFollowingMonPic_0157_TyphlosionTiles[];
extern const u8 gFollowingMonPic_0158_TotodileTiles[];
extern const u8 gFollowingMonPic_0159_CroconawTiles[];
extern const u8 gFollowingMonPic_0160_FeraligatrTiles[];
extern const u8 gFollowingMonPic_0161_SentretTiles[];
extern const u8 gFollowingMonPic_0162_FurretTiles[];
extern const u8 gFollowingMonPic_0163_HoothootTiles[];
extern const u8 gFollowingMonPic_0164_NoctowlTiles[];
extern const u8 gFollowingMonPic_0165_LedybaTiles[];
extern const u8 gFollowingMonPic_0166_LedianTiles[];
extern const u8 gFollowingMonPic_0167_SpinarakTiles[];
extern const u8 gFollowingMonPic_0168_AriadosTiles[];
extern const u8 gFollowingMonPic_0169_CrobatTiles[];
extern const u8 gFollowingMonPic_0170_ChinchouTiles[];
extern const u8 gFollowingMonPic_0171_LanturnTiles[];
extern const u8 gFollowingMonPic_0172_PichuTiles[];
extern const u8 gFollowingMonPic_0173_CleffaTiles[];
extern const u8 gFollowingMonPic_0174_IgglybuffTiles[];
extern const u8 gFollowingMonPic_0175_TogepiTiles[];
extern const u8 gFollowingMonPic_0176_TogeticTiles[];
extern const u8 gFollowingMonPic_0177_NatuTiles[];
extern const u8 gFollowingMonPic_0178_XatuTiles[];
extern const u8 gFollowingMonPic_0179_MareepTiles[];
extern const u8 gFollowingMonPic_0180_FlaaffyTiles[];
extern const u8 gFollowingMonPic_0181_AmpharosTiles[];
extern const u8 gFollowingMonPic_0182_BellossomTiles[];
extern const u8 gFollowingMonPic_0183_MarillTiles[];
extern const u8 gFollowingMonPic_0184_AzumarillTiles[];
extern const u8 gFollowingMonPic_0185_SudowoodoTiles[];
extern const u8 gFollowingMonPic_0186_PolitoedTiles[];
extern const u8 gFollowingMonPic_0187_HoppipTiles[];
extern const u8 gFollowingMonPic_0188_SkiploomTiles[];
extern const u8 gFollowingMonPic_0189_JumpluffTiles[];
extern const u8 gFollowingMonPic_0190_AipomTiles[];
extern const u8 gFollowingMonPic_0191_SunkernTiles[];
extern const u8 gFollowingMonPic_0192_SunfloraTiles[];
extern const u8 gFollowingMonPic_0193_YanmaTiles[];
extern const u8 gFollowingMonPic_0194_WooperTiles[];
extern const u8 gFollowingMonPic_0195_QuagsireTiles[];
extern const u8 gFollowingMonPic_0196_EspeonTiles[];
extern const u8 gFollowingMonPic_0197_UmbreonTiles[];
extern const u8 gFollowingMonPic_0198_MurkrowTiles[];
extern const u8 gFollowingMonPic_0199_SlowkingTiles[];
extern const u8 gFollowingMonPic_0200_MisdreavusTiles[];
extern const u8 gFollowingMonPic_0201_UnownTiles[];
extern const u8 gFollowingMonPic_0202_WobbuffetTiles[];
extern const u8 gFollowingMonPic_0203_GirafarigTiles[];
extern const u8 gFollowingMonPic_0204_PinecoTiles[];
extern const u8 gFollowingMonPic_0205_ForretressTiles[];
extern const u8 gFollowingMonPic_0206_DunsparceTiles[];
extern const u8 gFollowingMonPic_0207_GligarTiles[];
extern const u8 gFollowingMonPic_0208_SteelixTiles[];
extern const u8 gFollowingMonPic_0209_SnubbullTiles[];
extern const u8 gFollowingMonPic_0210_GranbullTiles[];
extern const u8 gFollowingMonPic_0211_QwilfishTiles[];
extern const u8 gFollowingMonPic_0212_ScizorTiles[];
extern const u8 gFollowingMonPic_0213_ShuckleTiles[];
extern const u8 gFollowingMonPic_0214_HeracrossTiles[];
extern const u8 gFollowingMonPic_0215_SneaselTiles[];
extern const u8 gFollowingMonPic_0216_TeddiursaTiles[];
extern const u8 gFollowingMonPic_0217_UrsaringTiles[];
extern const u8 gFollowingMonPic_0218_SlugmaTiles[];
extern const u8 gFollowingMonPic_0219_MagcargoTiles[];
extern const u8 gFollowingMonPic_0220_SwinubTiles[];
extern const u8 gFollowingMonPic_0221_PiloswineTiles[];
extern const u8 gFollowingMonPic_0222_CorsolaTiles[];
extern const u8 gFollowingMonPic_0223_RemoraidTiles[];
extern const u8 gFollowingMonPic_0224_OctilleryTiles[];
extern const u8 gFollowingMonPic_0225_DelibirdTiles[];
extern const u8 gFollowingMonPic_0226_MantineTiles[];
extern const u8 gFollowingMonPic_0227_SkarmoryTiles[];
extern const u8 gFollowingMonPic_0228_HoundourTiles[];
extern const u8 gFollowingMonPic_0229_HoundoomTiles[];
extern const u8 gFollowingMonPic_0230_KingdraTiles[];
extern const u8 gFollowingMonPic_0231_PhanpyTiles[];
extern const u8 gFollowingMonPic_0232_DonphanTiles[];
extern const u8 gFollowingMonPic_0233_Porygon2Tiles[];
extern const u8 gFollowingMonPic_0234_StantlerTiles[];
extern const u8 gFollowingMonPic_0235_SmeargleTiles[];
extern const u8 gFollowingMonPic_0236_TyrogueTiles[];
extern const u8 gFollowingMonPic_0237_HitmontopTiles[];
extern const u8 gFollowingMonPic_0238_SmoochumTiles[];
extern const u8 gFollowingMonPic_0239_ElekidTiles[];
extern const u8 gFollowingMonPic_0240_MagbyTiles[];
extern const u8 gFollowingMonPic_0241_MiltankTiles[];
extern const u8 gFollowingMonPic_0242_BlisseyTiles[];
extern const u8 gFollowingMonPic_0243_RaikouTiles[];
extern const u8 gFollowingMonPic_0244_EnteiTiles[];
extern const u8 gFollowingMonPic_0245_SuicuneTiles[];
extern const u8 gFollowingMonPic_0246_LarvitarTiles[];
extern const u8 gFollowingMonPic_0247_PupitarTiles[];
extern const u8 gFollowingMonPic_0248_TyranitarTiles[];
extern const u8 gFollowingMonPic_0249_DLugiaTiles[];
extern const u8 gFollowingMonPic_0249_LugiaTiles[];
extern const u8 gFollowingMonPic_0250_Ho_OhTiles[];
extern const u8 gFollowingMonPic_0251_CelebiTiles[];
extern const u8 gFollowingMonPic_0277_TreeckoTiles[];
extern const u8 gFollowingMonPic_0278_GrovyleTiles[];
extern const u8 gFollowingMonPic_0279_SceptileTiles[];
extern const u8 gFollowingMonPic_0280_TorchicTiles[];
extern const u8 gFollowingMonPic_0281_CombuskenTiles[];
extern const u8 gFollowingMonPic_0282_BlazikenTiles[];
extern const u8 gFollowingMonPic_0283_MudkipTiles[];
extern const u8 gFollowingMonPic_0284_MarshtompTiles[];
extern const u8 gFollowingMonPic_0285_SwampertTiles[];
extern const u8 gFollowingMonPic_0286_PoochyenaTiles[];
extern const u8 gFollowingMonPic_0287_MightyenaTiles[];
extern const u8 gFollowingMonPic_0288_ZigzagoonTiles[];
extern const u8 gFollowingMonPic_0289_LinooneTiles[];
extern const u8 gFollowingMonPic_0290_WurmpleTiles[];
extern const u8 gFollowingMonPic_0291_SilcoonTiles[];
extern const u8 gFollowingMonPic_0292_BeautiflyTiles[];
extern const u8 gFollowingMonPic_0293_CascoonTiles[];
extern const u8 gFollowingMonPic_0294_DustoxTiles[];
extern const u8 gFollowingMonPic_0295_LotadTiles[];
extern const u8 gFollowingMonPic_0296_LombreTiles[];
extern const u8 gFollowingMonPic_0297_LudicoloTiles[];
extern const u8 gFollowingMonPic_0298_SeedotTiles[];
extern const u8 gFollowingMonPic_0299_NuzleafTiles[];
extern const u8 gFollowingMonPic_0300_ShiftryTiles[];
extern const u8 gFollowingMonPic_0301_NincadaTiles[];
extern const u8 gFollowingMonPic_0302_NinjaskTiles[];
extern const u8 gFollowingMonPic_0303_ShedinjaTiles[];
extern const u8 gFollowingMonPic_0304_TaillowTiles[];
extern const u8 gFollowingMonPic_0305_SwellowTiles[];
extern const u8 gFollowingMonPic_0306_ShroomishTiles[];
extern const u8 gFollowingMonPic_0307_BreloomTiles[];
extern const u8 gFollowingMonPic_0308_SpindaTiles[];
extern const u8 gFollowingMonPic_0309_WingullTiles[];
extern const u8 gFollowingMonPic_0310_PelipperTiles[];
extern const u8 gFollowingMonPic_0311_SurskitTiles[];
extern const u8 gFollowingMonPic_0312_MasquerainTiles[];
extern const u8 gFollowingMonPic_0313_WailmerTiles[];
extern const u8 gFollowingMonPic_0314_WailordTiles[];
extern const u8 gFollowingMonPic_0315_SkittyTiles[];
extern const u8 gFollowingMonPic_0316_DelcattyTiles[];
extern const u8 gFollowingMonPic_0317_KecleonTiles[];
extern const u8 gFollowingMonPic_0318_BaltoyTiles[];
extern const u8 gFollowingMonPic_0319_ClaydolTiles[];
extern const u8 gFollowingMonPic_0320_NosepassTiles[];
extern const u8 gFollowingMonPic_0321_TorkoalTiles[];
extern const u8 gFollowingMonPic_0322_SableyeTiles[];
extern const u8 gFollowingMonPic_0323_BarboachTiles[];
extern const u8 gFollowingMonPic_0324_WhiscashTiles[];
extern const u8 gFollowingMonPic_0325_LuvdiscTiles[];
extern const u8 gFollowingMonPic_0326_CorphishTiles[];
extern const u8 gFollowingMonPic_0327_CrawdauntTiles[];
extern const u8 gFollowingMonPic_0328_FeebasTiles[];
extern const u8 gFollowingMonPic_0329_MiloticTiles[];
extern const u8 gFollowingMonPic_0330_CarvanhaTiles[];
extern const u8 gFollowingMonPic_0331_SharpedoTiles[];
extern const u8 gFollowingMonPic_0332_TrapinchTiles[];
extern const u8 gFollowingMonPic_0333_VibravaTiles[];
extern const u8 gFollowingMonPic_0334_FlygonTiles[];
extern const u8 gFollowingMonPic_0335_MakuhitaTiles[];
extern const u8 gFollowingMonPic_0336_HariyamaTiles[];
extern const u8 gFollowingMonPic_0337_ElectrikeTiles[];
extern const u8 gFollowingMonPic_0338_ManectricTiles[];
extern const u8 gFollowingMonPic_0339_NumelTiles[];
extern const u8 gFollowingMonPic_0340_CameruptTiles[];
extern const u8 gFollowingMonPic_0341_SphealTiles[];
extern const u8 gFollowingMonPic_0342_SealeoTiles[];
extern const u8 gFollowingMonPic_0343_WalreinTiles[];
extern const u8 gFollowingMonPic_0344_CacneaTiles[];
extern const u8 gFollowingMonPic_0345_CacturneTiles[];
extern const u8 gFollowingMonPic_0346_SnoruntTiles[];
extern const u8 gFollowingMonPic_0347_GlalieTiles[];
extern const u8 gFollowingMonPic_0348_LunatoneTiles[];
extern const u8 gFollowingMonPic_0349_SolrockTiles[];
extern const u8 gFollowingMonPic_0350_AzurillTiles[];
extern const u8 gFollowingMonPic_0351_SpoinkTiles[];
extern const u8 gFollowingMonPic_0352_GrumpigTiles[];
extern const u8 gFollowingMonPic_0353_PlusleTiles[];
extern const u8 gFollowingMonPic_0354_MinunTiles[];
extern const u8 gFollowingMonPic_0355_MawileTiles[];
extern const u8 gFollowingMonPic_0356_MedititeTiles[];
extern const u8 gFollowingMonPic_0357_MedichamTiles[];
extern const u8 gFollowingMonPic_0358_SwabluTiles[];
extern const u8 gFollowingMonPic_0359_AltariaTiles[];
extern const u8 gFollowingMonPic_0360_WynautTiles[];
extern const u8 gFollowingMonPic_0361_DuskullTiles[];
extern const u8 gFollowingMonPic_0362_DusclopsTiles[];
extern const u8 gFollowingMonPic_0363_RoseliaTiles[];
extern const u8 gFollowingMonPic_0364_SlakothTiles[];
extern const u8 gFollowingMonPic_0365_VigorothTiles[];
extern const u8 gFollowingMonPic_0366_SlakingTiles[];
extern const u8 gFollowingMonPic_0367_GulpinTiles[];
extern const u8 gFollowingMonPic_0368_SwalotTiles[];
extern const u8 gFollowingMonPic_0369_TropiusTiles[];
extern const u8 gFollowingMonPic_0370_WhismurTiles[];
extern const u8 gFollowingMonPic_0371_LoudredTiles[];
extern const u8 gFollowingMonPic_0372_ExploudTiles[];
extern const u8 gFollowingMonPic_0373_ClamperlTiles[];
extern const u8 gFollowingMonPic_0374_HuntailTiles[];
extern const u8 gFollowingMonPic_0375_GorebyssTiles[];
extern const u8 gFollowingMonPic_0376_AbsolTiles[];
extern const u8 gFollowingMonPic_0377_ShuppetTiles[];
extern const u8 gFollowingMonPic_0378_BanetteTiles[];
extern const u8 gFollowingMonPic_0379_SeviperTiles[];
extern const u8 gFollowingMonPic_0380_ZangooseTiles[];
extern const u8 gFollowingMonPic_0381_RelicanthTiles[];
extern const u8 gFollowingMonPic_0382_AronTiles[];
extern const u8 gFollowingMonPic_0383_LaironTiles[];
extern const u8 gFollowingMonPic_0384_AggronTiles[];
extern const u8 gFollowingMonPic_0385_CastformTiles[];
extern const u8 gFollowingMonPic_0386_VolbeatTiles[];
extern const u8 gFollowingMonPic_0387_IllumiseTiles[];
extern const u8 gFollowingMonPic_0388_LileepTiles[];
extern const u8 gFollowingMonPic_0389_CradilyTiles[];
extern const u8 gFollowingMonPic_0390_AnorithTiles[];
extern const u8 gFollowingMonPic_0391_ArmaldoTiles[];
extern const u8 gFollowingMonPic_0392_RaltsTiles[];
extern const u8 gFollowingMonPic_0393_KirliaTiles[];
extern const u8 gFollowingMonPic_0394_GardevoirTiles[];
extern const u8 gFollowingMonPic_0395_BagonTiles[];
extern const u8 gFollowingMonPic_0396_ShelgonTiles[];
extern const u8 gFollowingMonPic_0397_SalamenceTiles[];
extern const u8 gFollowingMonPic_0398_BeldumTiles[];
extern const u8 gFollowingMonPic_0399_MetangTiles[];
extern const u8 gFollowingMonPic_0400_MetagrossTiles[];
extern const u8 gFollowingMonPic_0401_RegirockTiles[];
extern const u8 gFollowingMonPic_0402_RegiceTiles[];
extern const u8 gFollowingMonPic_0403_RegisteelTiles[];
extern const u8 gFollowingMonPic_0404_KyogreTiles[];
extern const u8 gFollowingMonPic_0405_GroudonTiles[];
extern const u8 gFollowingMonPic_0406_RayquazaTiles[];
extern const u8 gFollowingMonPic_0407_LatiasTiles[];
extern const u8 gFollowingMonPic_0408_LatiosTiles[];
extern const u8 gFollowingMonPic_0409_JirachiTiles[];
extern const u8 gFollowingMonPic_0410_DeoxysTiles[];
extern const u8 gFollowingMonPic_0411_ChimechoTiles[];
extern const u8 gFollowingMonPic_0440_TurtwigTiles[];
extern const u8 gFollowingMonPic_0441_GrotleTiles[];
extern const u8 gFollowingMonPic_0442_TorterraTiles[];
extern const u8 gFollowingMonPic_0443_ChimcharTiles[];
extern const u8 gFollowingMonPic_0444_MonfernoTiles[];
extern const u8 gFollowingMonPic_0445_InfernapeTiles[];
extern const u8 gFollowingMonPic_0446_PiplupTiles[];
extern const u8 gFollowingMonPic_0447_PrinplupTiles[];
extern const u8 gFollowingMonPic_0448_EmpoleonTiles[];
extern const u8 gFollowingMonPic_0449_StarlyTiles[];
extern const u8 gFollowingMonPic_0450_StaraviaTiles[];
extern const u8 gFollowingMonPic_0451_StaraptorTiles[];
extern const u8 gFollowingMonPic_0452_BidoofTiles[];
extern const u8 gFollowingMonPic_0453_BibarelTiles[];
extern const u8 gFollowingMonPic_0454_KricketotTiles[];
extern const u8 gFollowingMonPic_0455_KricketuneTiles[];
extern const u8 gFollowingMonPic_0456_ShinxTiles[];
extern const u8 gFollowingMonPic_0457_LuxioTiles[];
extern const u8 gFollowingMonPic_0458_LuxrayTiles[];
extern const u8 gFollowingMonPic_0459_BudewTiles[];
extern const u8 gFollowingMonPic_0460_RoseradeTiles[];
extern const u8 gFollowingMonPic_0461_CranidosTiles[];
extern const u8 gFollowingMonPic_0462_RampardosTiles[];
extern const u8 gFollowingMonPic_0463_ShieldonTiles[];
extern const u8 gFollowingMonPic_0464_BastiodonTiles[];
extern const u8 gFollowingMonPic_0465_BurmyTiles[];
extern const u8 gFollowingMonPic_0466_WormadamTiles[];
extern const u8 gFollowingMonPic_0467_MothimTiles[];
extern const u8 gFollowingMonPic_0468_CombeeTiles[];
extern const u8 gFollowingMonPic_0469_VespiquenTiles[];
extern const u8 gFollowingMonPic_0470_PachirisuTiles[];
extern const u8 gFollowingMonPic_0471_BuizelTiles[];
extern const u8 gFollowingMonPic_0472_FloatzelTiles[];
extern const u8 gFollowingMonPic_0473_CherubiTiles[];
extern const u8 gFollowingMonPic_0474_CherrimTiles[];
extern const u8 gFollowingMonPic_0475_ShellosTiles[];
extern const u8 gFollowingMonPic_0476_GastrodonTiles[];
extern const u8 gFollowingMonPic_0477_AmbipomTiles[];
extern const u8 gFollowingMonPic_0478_DrifloonTiles[];
extern const u8 gFollowingMonPic_0479_DrifblimTiles[];
extern const u8 gFollowingMonPic_0480_BunearyTiles[];
extern const u8 gFollowingMonPic_0481_LopunnyTiles[];
extern const u8 gFollowingMonPic_0482_MismagiusTiles[];
extern const u8 gFollowingMonPic_0483_HonchkrowTiles[];
extern const u8 gFollowingMonPic_0484_GlameowTiles[];
extern const u8 gFollowingMonPic_0485_PuruglyTiles[];
extern const u8 gFollowingMonPic_0486_ChinglingTiles[];
extern const u8 gFollowingMonPic_0487_StunkyTiles[];
extern const u8 gFollowingMonPic_0488_SkuntankTiles[];
extern const u8 gFollowingMonPic_0489_BronzorTiles[];
extern const u8 gFollowingMonPic_0490_BronzongTiles[];
extern const u8 gFollowingMonPic_0491_BonslyTiles[];
extern const u8 gFollowingMonPic_0492_Mime_JrTiles[];
extern const u8 gFollowingMonPic_0493_HappinyTiles[];
extern const u8 gFollowingMonPic_0494_ChatotTiles[];
extern const u8 gFollowingMonPic_0495_SpiritombTiles[];
extern const u8 gFollowingMonPic_0496_GibleTiles[];
extern const u8 gFollowingMonPic_0497_GabiteTiles[];
extern const u8 gFollowingMonPic_0498_GarchompTiles[];
extern const u8 gFollowingMonPic_0499_MunchlaxTiles[];
extern const u8 gFollowingMonPic_0500_RioluTiles[];
extern const u8 gFollowingMonPic_0501_LucarioTiles[];
extern const u8 gFollowingMonPic_0502_HippopotasTiles[];
extern const u8 gFollowingMonPic_0503_HippowdonTiles[];
extern const u8 gFollowingMonPic_0504_SkorupiTiles[];
extern const u8 gFollowingMonPic_0505_DrapionTiles[];
extern const u8 gFollowingMonPic_0506_CroagunkTiles[];
extern const u8 gFollowingMonPic_0507_ToxicroakTiles[];
extern const u8 gFollowingMonPic_0508_CarnivineTiles[];
extern const u8 gFollowingMonPic_0509_FinneonTiles[];
extern const u8 gFollowingMonPic_0510_LumineonTiles[];
extern const u8 gFollowingMonPic_0511_MantykeTiles[];
extern const u8 gFollowingMonPic_0512_SnoverTiles[];
extern const u8 gFollowingMonPic_0513_AbomasnowTiles[];
extern const u8 gFollowingMonPic_0514_WeavileTiles[];
extern const u8 gFollowingMonPic_0515_MagnezoneTiles[];
extern const u8 gFollowingMonPic_0516_LickilickyTiles[];
extern const u8 gFollowingMonPic_0517_RhyperiorTiles[];
extern const u8 gFollowingMonPic_0518_TangrowthTiles[];
extern const u8 gFollowingMonPic_0519_ElectivireTiles[];
extern const u8 gFollowingMonPic_0520_MagmortarTiles[];
extern const u8 gFollowingMonPic_0521_TogekissTiles[];
extern const u8 gFollowingMonPic_0522_YanmegaTiles[];
extern const u8 gFollowingMonPic_0523_LeafeonTiles[];
extern const u8 gFollowingMonPic_0524_GlaceonTiles[];
extern const u8 gFollowingMonPic_0525_GliscorTiles[];
extern const u8 gFollowingMonPic_0526_MamoswineTiles[];
extern const u8 gFollowingMonPic_0527_Porygon_ZTiles[];
extern const u8 gFollowingMonPic_0528_GalladeTiles[];
extern const u8 gFollowingMonPic_0529_ProbopassTiles[];
extern const u8 gFollowingMonPic_0530_DusknoirTiles[];
extern const u8 gFollowingMonPic_0531_FroslassTiles[];
extern const u8 gFollowingMonPic_0532_RotomTiles[];
extern const u8 gFollowingMonPic_0533_UxieTiles[];
extern const u8 gFollowingMonPic_0534_MespritTiles[];
extern const u8 gFollowingMonPic_0535_AzelfTiles[];
extern const u8 gFollowingMonPic_0536_DialgaTiles[];
extern const u8 gFollowingMonPic_0537_PalkiaTiles[];
extern const u8 gFollowingMonPic_0538_HeatranTiles[];
extern const u8 gFollowingMonPic_0539_RegigigasTiles[];
extern const u8 gFollowingMonPic_0540_GiratinaTiles[];
extern const u8 gFollowingMonPic_0541_CresseliaTiles[];
extern const u8 gFollowingMonPic_0542_PhioneTiles[];
extern const u8 gFollowingMonPic_0543_ManaphyTiles[];
extern const u8 gFollowingMonPic_0544_DarkraiTiles[];
extern const u8 gFollowingMonPic_0545_ShayminTiles[];
extern const u8 gFollowingMonPic_0546_ArceusTiles[];
extern const u8 gFollowingMonPic_0547_VictiniTiles[];
extern const u8 gFollowingMonPic_0548_SnivyTiles[];
extern const u8 gFollowingMonPic_0549_ServineTiles[];
extern const u8 gFollowingMonPic_0550_SerperiorTiles[];
extern const u8 gFollowingMonPic_0551_TepigTiles[];
extern const u8 gFollowingMonPic_0552_PigniteTiles[];
extern const u8 gFollowingMonPic_0553_EmboarTiles[];
extern const u8 gFollowingMonPic_0554_OshawottTiles[];
extern const u8 gFollowingMonPic_0555_DewottTiles[];
extern const u8 gFollowingMonPic_0556_SamurottTiles[];
extern const u8 gFollowingMonPic_0556_Samurott_1Tiles[];
extern const u8 gFollowingMonPic_0557_PatratTiles[];
extern const u8 gFollowingMonPic_0558_WatchogTiles[];
extern const u8 gFollowingMonPic_0559_LillipupTiles[];
extern const u8 gFollowingMonPic_0560_HerdierTiles[];
extern const u8 gFollowingMonPic_0561_StoutlandTiles[];
extern const u8 gFollowingMonPic_0562_PurrloinTiles[];
extern const u8 gFollowingMonPic_0563_LiepardTiles[];
extern const u8 gFollowingMonPic_0564_PansageTiles[];
extern const u8 gFollowingMonPic_0565_SimisageTiles[];
extern const u8 gFollowingMonPic_0566_PansearTiles[];
extern const u8 gFollowingMonPic_0567_SimisearTiles[];
extern const u8 gFollowingMonPic_0568_PanpourTiles[];
extern const u8 gFollowingMonPic_0569_SimipourTiles[];
extern const u8 gFollowingMonPic_0570_MunnaTiles[];
extern const u8 gFollowingMonPic_0571_MusharnaTiles[];
extern const u8 gFollowingMonPic_0572_PidoveTiles[];
extern const u8 gFollowingMonPic_0573_TranquillTiles[];
extern const u8 gFollowingMonPic_0574_UnfezantTiles[];
extern const u8 gFollowingMonPic_0575_BlitzleTiles[];
extern const u8 gFollowingMonPic_0576_ZebstrikaTiles[];
extern const u8 gFollowingMonPic_0577_RoggenrolaTiles[];
extern const u8 gFollowingMonPic_0578_BoldoreTiles[];
extern const u8 gFollowingMonPic_0579_GigalithTiles[];
extern const u8 gFollowingMonPic_0580_WoobatTiles[];
extern const u8 gFollowingMonPic_0581_SwoobatTiles[];
extern const u8 gFollowingMonPic_0582_DrilburTiles[];
extern const u8 gFollowingMonPic_0583_ExcadrillTiles[];
extern const u8 gFollowingMonPic_0584_AudinoTiles[];
extern const u8 gFollowingMonPic_0585_TimburrTiles[];
extern const u8 gFollowingMonPic_0586_GurdurrTiles[];
extern const u8 gFollowingMonPic_0587_ConkeldurrTiles[];
extern const u8 gFollowingMonPic_0588_TympoleTiles[];
extern const u8 gFollowingMonPic_0589_PalpitoadTiles[];
extern const u8 gFollowingMonPic_0590_SeismitoadTiles[];
extern const u8 gFollowingMonPic_0591_ThrohTiles[];
extern const u8 gFollowingMonPic_0592_SawkTiles[];
extern const u8 gFollowingMonPic_0593_SewaddleTiles[];
extern const u8 gFollowingMonPic_0594_SwadloonTiles[];
extern const u8 gFollowingMonPic_0595_LeavannyTiles[];
extern const u8 gFollowingMonPic_0596_VenipedeTiles[];
extern const u8 gFollowingMonPic_0597_WhirlipedeTiles[];
extern const u8 gFollowingMonPic_0598_ScolipedeTiles[];
extern const u8 gFollowingMonPic_0599_CottoneeTiles[];
extern const u8 gFollowingMonPic_0600_WhimsicottTiles[];
extern const u8 gFollowingMonPic_0601_PetililTiles[];
extern const u8 gFollowingMonPic_0602_LilligantTiles[];
extern const u8 gFollowingMonPic_0603_BasculinTiles[];
extern const u8 gFollowingMonPic_0604_SandileTiles[];
extern const u8 gFollowingMonPic_0605_KrokorokTiles[];
extern const u8 gFollowingMonPic_0606_KrookodileTiles[];
extern const u8 gFollowingMonPic_0607_DarumakaTiles[];
extern const u8 gFollowingMonPic_0608_DarmanitanTiles[];
extern const u8 gFollowingMonPic_0609_MaractusTiles[];
extern const u8 gFollowingMonPic_0610_DwebbleTiles[];
extern const u8 gFollowingMonPic_0611_CrustleTiles[];
extern const u8 gFollowingMonPic_0612_ScraggyTiles[];
extern const u8 gFollowingMonPic_0613_ScraftyTiles[];
extern const u8 gFollowingMonPic_0614_SigilyphTiles[];
extern const u8 gFollowingMonPic_0615_YamaskTiles[];
extern const u8 gFollowingMonPic_0616_CofagrigusTiles[];
extern const u8 gFollowingMonPic_0617_TirtougaTiles[];
extern const u8 gFollowingMonPic_0618_CarracostaTiles[];
extern const u8 gFollowingMonPic_0619_ArchenTiles[];
extern const u8 gFollowingMonPic_0620_ArcheopsTiles[];
extern const u8 gFollowingMonPic_0621_TrubbishTiles[];
extern const u8 gFollowingMonPic_0622_GarbodorTiles[];
extern const u8 gFollowingMonPic_0623_ZoruaTiles[];
extern const u8 gFollowingMonPic_0624_ZoroarkTiles[];
extern const u8 gFollowingMonPic_0625_MinccinoTiles[];
extern const u8 gFollowingMonPic_0626_CinccinoTiles[];
extern const u8 gFollowingMonPic_0627_GothitaTiles[];
extern const u8 gFollowingMonPic_0628_GothoritaTiles[];
extern const u8 gFollowingMonPic_0629_GothitelleTiles[];
extern const u8 gFollowingMonPic_0630_SolosisTiles[];
extern const u8 gFollowingMonPic_0631_DuosionTiles[];
extern const u8 gFollowingMonPic_0632_ReuniclusTiles[];
extern const u8 gFollowingMonPic_0633_DucklettTiles[];
extern const u8 gFollowingMonPic_0634_SwannaTiles[];
extern const u8 gFollowingMonPic_0635_VanilliteTiles[];
extern const u8 gFollowingMonPic_0636_VanillishTiles[];
extern const u8 gFollowingMonPic_0637_VanilluxeTiles[];
extern const u8 gFollowingMonPic_0638_DeerlingTiles[];
extern const u8 gFollowingMonPic_0639_SawsbuckTiles[];
extern const u8 gFollowingMonPic_0640_EmolgaTiles[];
extern const u8 gFollowingMonPic_0641_KarrablastTiles[];
extern const u8 gFollowingMonPic_0642_EscavalierTiles[];
extern const u8 gFollowingMonPic_0643_FoongusTiles[];
extern const u8 gFollowingMonPic_0644_AmoongussTiles[];
extern const u8 gFollowingMonPic_0645_FrillishTiles[];
extern const u8 gFollowingMonPic_0645_Frillish_FTiles[];
extern const u8 gFollowingMonPic_0646_JellicentTiles[];
extern const u8 gFollowingMonPic_0646_Jellicent_FTiles[];
extern const u8 gFollowingMonPic_0647_AlomomolaTiles[];
extern const u8 gFollowingMonPic_0648_JoltikTiles[];
extern const u8 gFollowingMonPic_0649_GalvantulaTiles[];
extern const u8 gFollowingMonPic_0650_FerroseedTiles[];
extern const u8 gFollowingMonPic_0651_FerrothornTiles[];
extern const u8 gFollowingMonPic_0652_KlinkTiles[];
extern const u8 gFollowingMonPic_0653_KlangTiles[];
extern const u8 gFollowingMonPic_0654_KlinklangTiles[];
extern const u8 gFollowingMonPic_0655_TynamoTiles[];
extern const u8 gFollowingMonPic_0656_EelektrikTiles[];
extern const u8 gFollowingMonPic_0657_EelektrossTiles[];
extern const u8 gFollowingMonPic_0658_ElgyemTiles[];
extern const u8 gFollowingMonPic_0659_BeheeyemTiles[];
extern const u8 gFollowingMonPic_0660_LitwickTiles[];
extern const u8 gFollowingMonPic_0661_LampentTiles[];
extern const u8 gFollowingMonPic_0662_ChandelureTiles[];
extern const u8 gFollowingMonPic_0663_AxewTiles[];
extern const u8 gFollowingMonPic_0664_FraxureTiles[];
extern const u8 gFollowingMonPic_0665_HaxorusTiles[];
extern const u8 gFollowingMonPic_0666_CubchooTiles[];
extern const u8 gFollowingMonPic_0667_BearticTiles[];
extern const u8 gFollowingMonPic_0668_CryogonalTiles[];
extern const u8 gFollowingMonPic_0669_ShelmetTiles[];
extern const u8 gFollowingMonPic_0670_AccelgorTiles[];
extern const u8 gFollowingMonPic_0671_StunfiskTiles[];
extern const u8 gFollowingMonPic_0672_MienfooTiles[];
extern const u8 gFollowingMonPic_0673_MienshaoTiles[];
extern const u8 gFollowingMonPic_0674_DruddigonTiles[];
extern const u8 gFollowingMonPic_0675_GolettTiles[];
extern const u8 gFollowingMonPic_0676_GolurkTiles[];
extern const u8 gFollowingMonPic_0677_PawniardTiles[];
extern const u8 gFollowingMonPic_0678_BisharpTiles[];
extern const u8 gFollowingMonPic_0679_BouffalantTiles[];
extern const u8 gFollowingMonPic_0680_RuffletTiles[];
extern const u8 gFollowingMonPic_0681_BraviaryTiles[];
extern const u8 gFollowingMonPic_0682_VullabyTiles[];
extern const u8 gFollowingMonPic_0683_MandibuzzTiles[];
extern const u8 gFollowingMonPic_0684_HeatmorTiles[];
extern const u8 gFollowingMonPic_0685_DurantTiles[];
extern const u8 gFollowingMonPic_0686_DeinoTiles[];
extern const u8 gFollowingMonPic_0687_ZweilousTiles[];
extern const u8 gFollowingMonPic_0688_HydreigonTiles[];
extern const u8 gFollowingMonPic_0689_LarvestaTiles[];
extern const u8 gFollowingMonPic_0690_VolcaronaTiles[];
extern const u8 gFollowingMonPic_0691_CobalionTiles[];
extern const u8 gFollowingMonPic_0692_TerrakionTiles[];
extern const u8 gFollowingMonPic_0693_VirizionTiles[];
extern const u8 gFollowingMonPic_0694_TornadusTiles[];
extern const u8 gFollowingMonPic_0695_ThundurusTiles[];
extern const u8 gFollowingMonPic_0696_ReshiramTiles[];
extern const u8 gFollowingMonPic_0697_ZekromTiles[];
extern const u8 gFollowingMonPic_0698_LandorusTiles[];
extern const u8 gFollowingMonPic_0699_KyuremTiles[];
extern const u8 gFollowingMonPic_0700_KeldeoTiles[];
extern const u8 gFollowingMonPic_0701_MeloettaTiles[];
extern const u8 gFollowingMonPic_0702_GenesectTiles[];
extern const u8 gFollowingMonPic_0703_Unfezant_FTiles[];
extern const u8 gFollowingMonPic_0711_Shellos_ETiles[];
extern const u8 gFollowingMonPic_0712_Gastrodon_ETiles[];
extern const u8 gFollowingMonPic_0713_Rotom_HTiles[];
extern const u8 gFollowingMonPic_0714_Rotom_WTiles[];
extern const u8 gFollowingMonPic_0715_Rotom_FRTiles[];
extern const u8 gFollowingMonPic_0716_Rotom_FTiles[];
extern const u8 gFollowingMonPic_0717_Rotom_MTiles[];
extern const u8 gFollowingMonPic_0718_Giratina_OTiles[];
extern const u8 gFollowingMonPic_0719_Shaymin_STiles[];
extern const u8 gFollowingMonPic_0736_Basculin_BTiles[];
extern const u8 gFollowingMonPic_0746_Meloetta_PTiles[];
extern const u8 gFollowingMonPic_0752_Kyurem_BTiles[];
extern const u8 gFollowingMonPic_0753_Kyurem_WTiles[];
extern const u8 gFollowingMonPic_0754_Tornadus_TTiles[];
extern const u8 gFollowingMonPic_0755_Thundurus_TTiles[];
extern const u8 gFollowingMonPic_0756_Landorus_TTiles[];
extern const u8 gFollowingMonPic_0758_ChespinTiles[];
extern const u8 gFollowingMonPic_0759_QuilladinTiles[];
extern const u8 gFollowingMonPic_0760_ChesnaughtTiles[];
extern const u8 gFollowingMonPic_0761_FennekinTiles[];
extern const u8 gFollowingMonPic_0762_BraixenTiles[];
extern const u8 gFollowingMonPic_0763_DelphoxTiles[];
extern const u8 gFollowingMonPic_0764_FroakieTiles[];
extern const u8 gFollowingMonPic_0765_FrogadierTiles[];
extern const u8 gFollowingMonPic_0766_GreninjaTiles[];
extern const u8 gFollowingMonPic_0767_BunnelbyTiles[];
extern const u8 gFollowingMonPic_0768_DiggersbyTiles[];
extern const u8 gFollowingMonPic_0769_FletchlingTiles[];
extern const u8 gFollowingMonPic_0770_FletchinderTiles[];
extern const u8 gFollowingMonPic_0771_TalonflameTiles[];
extern const u8 gFollowingMonPic_0772_ScatterbugTiles[];
extern const u8 gFollowingMonPic_0773_SpewpaTiles[];
extern const u8 gFollowingMonPic_0774_VivillonTiles[];
extern const u8 gFollowingMonPic_0775_LitleoTiles[];
extern const u8 gFollowingMonPic_0776_PyroarTiles[];
extern const u8 gFollowingMonPic_0777_FlabebeTiles[];
extern const u8 gFollowingMonPic_0778_FloetteTiles[];
extern const u8 gFollowingMonPic_0779_FlorgesTiles[];
extern const u8 gFollowingMonPic_0780_SkiddoTiles[];
extern const u8 gFollowingMonPic_0781_GogoatTiles[];
extern const u8 gFollowingMonPic_0782_PanchamTiles[];
extern const u8 gFollowingMonPic_0783_PangoroTiles[];
extern const u8 gFollowingMonPic_0784_FurfrouTiles[];
extern const u8 gFollowingMonPic_0785_EspurrTiles[];
extern const u8 gFollowingMonPic_0786_MeowsticTiles[];
extern const u8 gFollowingMonPic_0787_HonedgeTiles[];
extern const u8 gFollowingMonPic_0788_DoubladeTiles[];
extern const u8 gFollowingMonPic_0789_AegislashTiles[];
extern const u8 gFollowingMonPic_0790_SpritzeeTiles[];
extern const u8 gFollowingMonPic_0791_AromatisseTiles[];
extern const u8 gFollowingMonPic_0792_SwirlixTiles[];
extern const u8 gFollowingMonPic_0793_SlurpuffTiles[];
extern const u8 gFollowingMonPic_0794_InkayTiles[];
extern const u8 gFollowingMonPic_0795_MalamarTiles[];
extern const u8 gFollowingMonPic_0796_BinacleTiles[];
extern const u8 gFollowingMonPic_0797_BarbaracleTiles[];
extern const u8 gFollowingMonPic_0798_SkrelpTiles[];
extern const u8 gFollowingMonPic_0799_DragalgeTiles[];
extern const u8 gFollowingMonPic_0800_ClauncherTiles[];
extern const u8 gFollowingMonPic_0801_ClawitzerTiles[];
extern const u8 gFollowingMonPic_0802_HelioptileTiles[];
extern const u8 gFollowingMonPic_0803_HelioliskTiles[];
extern const u8 gFollowingMonPic_0804_TyruntTiles[];
extern const u8 gFollowingMonPic_0805_TyrantrumTiles[];
extern const u8 gFollowingMonPic_0806_AmauraTiles[];
extern const u8 gFollowingMonPic_0807_AurorusTiles[];
extern const u8 gFollowingMonPic_0808_SylveonTiles[];
extern const u8 gFollowingMonPic_0809_HawluchaTiles[];
extern const u8 gFollowingMonPic_0810_DedenneTiles[];
extern const u8 gFollowingMonPic_0811_CarbinkTiles[];
extern const u8 gFollowingMonPic_0812_GoomyTiles[];
extern const u8 gFollowingMonPic_0813_SliggooTiles[];
extern const u8 gFollowingMonPic_0814_GoodraTiles[];
extern const u8 gFollowingMonPic_0815_KlefkiTiles[];
extern const u8 gFollowingMonPic_0816_PhantumpTiles[];
extern const u8 gFollowingMonPic_0817_TrevenantTiles[];
extern const u8 gFollowingMonPic_0818_PumpkabooTiles[];
extern const u8 gFollowingMonPic_0819_GourgeistTiles[];
extern const u8 gFollowingMonPic_0820_BergmiteTiles[];
extern const u8 gFollowingMonPic_0821_AvaluggTiles[];
extern const u8 gFollowingMonPic_0822_NoibatTiles[];
extern const u8 gFollowingMonPic_0823_NoivernTiles[];
extern const u8 gFollowingMonPic_0824_XerneasTiles[];
extern const u8 gFollowingMonPic_0825_YveltalTiles[];
extern const u8 gFollowingMonPic_0826_ZygardeTiles[];
extern const u8 gFollowingMonPic_0827_DiancieTiles[];
extern const u8 gFollowingMonPic_0828_HoopaTiles[];
extern const u8 gFollowingMonPic_0829_Hoopa_UTiles[];
extern const u8 gFollowingMonPic_0830_VolcanionTiles[];
extern const u8 gFollowingMonPic_0831_Pyroar_FTiles[];
extern const u8 gFollowingMonPic_0832_Meowstic_FTiles[];
extern const u8 gFollowingMonPic_0837_Zygarde_10Tiles[];
extern const u8 gFollowingMonPic_0848_Floette_ETiles[];
extern const u8 gFollowingMonPic_0939_RowletTiles[];
extern const u8 gFollowingMonPic_0940_DartrixTiles[];
extern const u8 gFollowingMonPic_0941_DecidueyeTiles[];
extern const u8 gFollowingMonPic_0942_LittenTiles[];
extern const u8 gFollowingMonPic_0943_TorracatTiles[];
extern const u8 gFollowingMonPic_0944_IncineroarTiles[];
extern const u8 gFollowingMonPic_0945_PopplioTiles[];
extern const u8 gFollowingMonPic_0946_BrionneTiles[];
extern const u8 gFollowingMonPic_0947_PrimarinaTiles[];
extern const u8 gFollowingMonPic_0948_PikipekTiles[];
extern const u8 gFollowingMonPic_0949_TrumbeakTiles[];
extern const u8 gFollowingMonPic_0950_ToucannonTiles[];
extern const u8 gFollowingMonPic_0951_YungoosTiles[];
extern const u8 gFollowingMonPic_0952_GumshoosTiles[];
extern const u8 gFollowingMonPic_0953_GrubbinTiles[];
extern const u8 gFollowingMonPic_0954_CharjabugTiles[];
extern const u8 gFollowingMonPic_0955_VikavoltTiles[];
extern const u8 gFollowingMonPic_0956_CrabrawlerTiles[];
extern const u8 gFollowingMonPic_0957_CrabominableTiles[];
extern const u8 gFollowingMonPic_0958_OricorioTiles[];
extern const u8 gFollowingMonPic_0959_CutieflyTiles[];
extern const u8 gFollowingMonPic_0960_RibombeeTiles[];
extern const u8 gFollowingMonPic_0961_RockruffTiles[];
extern const u8 gFollowingMonPic_0962_LycanrocTiles[];
extern const u8 gFollowingMonPic_0963_WishiwashiTiles[];
extern const u8 gFollowingMonPic_0964_MareanieTiles[];
extern const u8 gFollowingMonPic_0965_ToxapexTiles[];
extern const u8 gFollowingMonPic_0966_MudbrayTiles[];
extern const u8 gFollowingMonPic_0967_MudsdaleTiles[];
extern const u8 gFollowingMonPic_0968_DewpiderTiles[];
extern const u8 gFollowingMonPic_0969_AraquanidTiles[];
extern const u8 gFollowingMonPic_0970_FomantisTiles[];
extern const u8 gFollowingMonPic_0971_LurantisTiles[];
extern const u8 gFollowingMonPic_0972_MorelullTiles[];
extern const u8 gFollowingMonPic_0973_ShiinoticTiles[];
extern const u8 gFollowingMonPic_0974_SalanditTiles[];
extern const u8 gFollowingMonPic_0975_SalazzleTiles[];
extern const u8 gFollowingMonPic_0976_StuffulTiles[];
extern const u8 gFollowingMonPic_0977_BewearTiles[];
extern const u8 gFollowingMonPic_0978_BounsweetTiles[];
extern const u8 gFollowingMonPic_0979_SteeneeTiles[];
extern const u8 gFollowingMonPic_0980_TsareenaTiles[];
extern const u8 gFollowingMonPic_0981_ComfeyTiles[];
extern const u8 gFollowingMonPic_0982_OranguruTiles[];
extern const u8 gFollowingMonPic_0983_PassimianTiles[];
extern const u8 gFollowingMonPic_0984_WimpodTiles[];
extern const u8 gFollowingMonPic_0985_GolisopodTiles[];
extern const u8 gFollowingMonPic_0986_SandygastTiles[];
extern const u8 gFollowingMonPic_0987_PalossandTiles[];
extern const u8 gFollowingMonPic_0988_PyukumukuTiles[];
extern const u8 gFollowingMonPic_0989_Type_NullTiles[];
extern const u8 gFollowingMonPic_0990_SilvallyTiles[];
extern const u8 gFollowingMonPic_0991_MiniorTiles[];
extern const u8 gFollowingMonPic_0992_KomalaTiles[];
extern const u8 gFollowingMonPic_0993_TurtonatorTiles[];
extern const u8 gFollowingMonPic_0994_TogedemaruTiles[];
extern const u8 gFollowingMonPic_0995_MimikyuTiles[];
extern const u8 gFollowingMonPic_0996_BruxishTiles[];
extern const u8 gFollowingMonPic_0997_DrampaTiles[];
extern const u8 gFollowingMonPic_0998_DhelmiseTiles[];
extern const u8 gFollowingMonPic_0999_Jangmo_oTiles[];
extern const u8 gFollowingMonPic_1000_Hakamo_oTiles[];
extern const u8 gFollowingMonPic_1001_Kommo_oTiles[];
extern const u8 gFollowingMonPic_1002_Tapu_KokoTiles[];
extern const u8 gFollowingMonPic_1003_Tapu_LeleTiles[];
extern const u8 gFollowingMonPic_1004_Tapu_BuluTiles[];
extern const u8 gFollowingMonPic_1005_Tapu_FiniTiles[];
extern const u8 gFollowingMonPic_1006_CosmogTiles[];
extern const u8 gFollowingMonPic_1007_CosmoemTiles[];
extern const u8 gFollowingMonPic_1008_SolgaleoTiles[];
extern const u8 gFollowingMonPic_1009_LunalaTiles[];
extern const u8 gFollowingMonPic_1010_NihilegoTiles[];
extern const u8 gFollowingMonPic_1011_BuzzwoleTiles[];
extern const u8 gFollowingMonPic_1012_PheromosaTiles[];
extern const u8 gFollowingMonPic_1013_XurkitreeTiles[];
extern const u8 gFollowingMonPic_1014_CelesteelaTiles[];
extern const u8 gFollowingMonPic_1015_KartanaTiles[];
extern const u8 gFollowingMonPic_1016_GuzzlordTiles[];
extern const u8 gFollowingMonPic_1017_NecrozmaTiles[];
extern const u8 gFollowingMonPic_1018_MagearnaTiles[];
extern const u8 gFollowingMonPic_1019_MarshadowTiles[];
extern const u8 gFollowingMonPic_1020_Rattata_ATiles[];
extern const u8 gFollowingMonPic_1021_Raticate_ATiles[];
extern const u8 gFollowingMonPic_1022_Raichu_ATiles[];
extern const u8 gFollowingMonPic_1023_Sandshrew_ATiles[];
extern const u8 gFollowingMonPic_1024_Sandslash_ATiles[];
extern const u8 gFollowingMonPic_1025_Vulpix_ATiles[];
extern const u8 gFollowingMonPic_1026_Ninetales_ATiles[];
extern const u8 gFollowingMonPic_1027_Diglett_ATiles[];
extern const u8 gFollowingMonPic_1028_Dugtrio_ATiles[];
extern const u8 gFollowingMonPic_1029_Meowth_ATiles[];
extern const u8 gFollowingMonPic_1030_Persian_ATiles[];
extern const u8 gFollowingMonPic_1031_Geodude_ATiles[];
extern const u8 gFollowingMonPic_1032_Graveler_ATiles[];
extern const u8 gFollowingMonPic_1033_Golem_ATiles[];
extern const u8 gFollowingMonPic_1034_Grimer_ATiles[];
extern const u8 gFollowingMonPic_1035_Muk_ATiles[];
extern const u8 gFollowingMonPic_1037_Exeggutor_ATiles[];
extern const u8 gFollowingMonPic_1039_Marowak_ATiles[];
extern const u8 gFollowingMonPic_1046_Lycanroc_NTiles[];
extern const u8 gFollowingMonPic_1074_PoipoleTiles[];
extern const u8 gFollowingMonPic_1075_NaganadelTiles[];
extern const u8 gFollowingMonPic_1076_StakatakaTiles[];
extern const u8 gFollowingMonPic_1077_BlacephalonTiles[];
extern const u8 gFollowingMonPic_1078_ZeraoraTiles[];
extern const u8 gFollowingMonPic_1079_Necrozma_DMTiles[];
extern const u8 gFollowingMonPic_1080_Necrozma_DWTiles[];
extern const u8 gFollowingMonPic_1082_Lycanroc_DTiles[];
extern const u8 gFollowingMonPic_1083_MeltanTiles[];
extern const u8 gFollowingMonPic_1084_MelmetalTiles[];
extern const u8 gFollowingMonPic_1100_Pichu_STiles[];
extern const u8 gFollowingMonPic_1102_GrookeyTiles[];
extern const u8 gFollowingMonPic_1103_ThwackeyTiles[];
extern const u8 gFollowingMonPic_1104_RillaboomTiles[];
extern const u8 gFollowingMonPic_1105_ScorbunnyTiles[];
extern const u8 gFollowingMonPic_1106_RabootTiles[];
extern const u8 gFollowingMonPic_1107_CinderaceTiles[];
extern const u8 gFollowingMonPic_1108_SobbleTiles[];
extern const u8 gFollowingMonPic_1109_DrizzileTiles[];
extern const u8 gFollowingMonPic_1110_InteleonTiles[];
extern const u8 gFollowingMonPic_1111_SkwovetTiles[];
extern const u8 gFollowingMonPic_1112_GreedentTiles[];
extern const u8 gFollowingMonPic_1113_RookideeTiles[];
extern const u8 gFollowingMonPic_1114_CorvisquireTiles[];
extern const u8 gFollowingMonPic_1115_CorviknightTiles[];
extern const u8 gFollowingMonPic_1116_BlipbugTiles[];
extern const u8 gFollowingMonPic_1117_DottlerTiles[];
extern const u8 gFollowingMonPic_1118_OrbeetleTiles[];
extern const u8 gFollowingMonPic_1119_NickitTiles[];
extern const u8 gFollowingMonPic_1120_ThievulTiles[];
extern const u8 gFollowingMonPic_1121_GossifleurTiles[];
extern const u8 gFollowingMonPic_1122_EldegossTiles[];
extern const u8 gFollowingMonPic_1123_WoolooTiles[];
extern const u8 gFollowingMonPic_1124_DubwoolTiles[];
extern const u8 gFollowingMonPic_1125_ChewtleTiles[];
extern const u8 gFollowingMonPic_1126_DrednawTiles[];
extern const u8 gFollowingMonPic_1127_YamperTiles[];
extern const u8 gFollowingMonPic_1128_BoltundTiles[];
extern const u8 gFollowingMonPic_1129_RolycolyTiles[];
extern const u8 gFollowingMonPic_1130_CarkolTiles[];
extern const u8 gFollowingMonPic_1131_CoalossalTiles[];
extern const u8 gFollowingMonPic_1132_ApplinTiles[];
extern const u8 gFollowingMonPic_1133_FlappleTiles[];
extern const u8 gFollowingMonPic_1134_AppletunTiles[];
extern const u8 gFollowingMonPic_1135_SilicobraTiles[];
extern const u8 gFollowingMonPic_1136_SandacondaTiles[];
extern const u8 gFollowingMonPic_1137_CramorantTiles[];
extern const u8 gFollowingMonPic_1138_ArrokudaTiles[];
extern const u8 gFollowingMonPic_1139_BarraskewdaTiles[];
extern const u8 gFollowingMonPic_1140_ToxelTiles[];
extern const u8 gFollowingMonPic_1141_ToxtricityTiles[];
extern const u8 gFollowingMonPic_1142_SizzlipedeTiles[];
extern const u8 gFollowingMonPic_1143_CentiskorchTiles[];
extern const u8 gFollowingMonPic_1144_ClobbopusTiles[];
extern const u8 gFollowingMonPic_1145_GrapploctTiles[];
extern const u8 gFollowingMonPic_1146_SinisteaTiles[];
extern const u8 gFollowingMonPic_1147_PolteageistTiles[];
extern const u8 gFollowingMonPic_1148_HatennaTiles[];
extern const u8 gFollowingMonPic_1149_HattremTiles[];
extern const u8 gFollowingMonPic_1150_HattereneTiles[];
extern const u8 gFollowingMonPic_1151_ImpidimpTiles[];
extern const u8 gFollowingMonPic_1152_MorgremTiles[];
extern const u8 gFollowingMonPic_1153_GrimmsnarlTiles[];
extern const u8 gFollowingMonPic_1154_ObstagoonTiles[];
extern const u8 gFollowingMonPic_1155_PerrserkerTiles[];
extern const u8 gFollowingMonPic_1156_CursolaTiles[];
extern const u8 gFollowingMonPic_1157_SirfetchdTiles[];
extern const u8 gFollowingMonPic_1158_Mr_RimeTiles[];
extern const u8 gFollowingMonPic_1159_RunerigusTiles[];
extern const u8 gFollowingMonPic_1160_MilceryTiles[];
extern const u8 gFollowingMonPic_1161_AlcremieTiles[];
extern const u8 gFollowingMonPic_1162_FalinksTiles[];
extern const u8 gFollowingMonPic_1163_PincurchinTiles[];
extern const u8 gFollowingMonPic_1164_SnomTiles[];
extern const u8 gFollowingMonPic_1165_FrosmothTiles[];
extern const u8 gFollowingMonPic_1166_StonjournerTiles[];
extern const u8 gFollowingMonPic_1167_EiscueTiles[];
extern const u8 gFollowingMonPic_1168_IndeedeeTiles[];
extern const u8 gFollowingMonPic_1169_MorpekoTiles[];
extern const u8 gFollowingMonPic_1170_CufantTiles[];
extern const u8 gFollowingMonPic_1171_CopperajahTiles[];
extern const u8 gFollowingMonPic_1172_DracozoltTiles[];
extern const u8 gFollowingMonPic_1173_ArctozoltTiles[];
extern const u8 gFollowingMonPic_1174_DracovishTiles[];
extern const u8 gFollowingMonPic_1175_ArctovishTiles[];
extern const u8 gFollowingMonPic_1176_DuraludonTiles[];
extern const u8 gFollowingMonPic_1177_DreepyTiles[];
extern const u8 gFollowingMonPic_1178_DrakloakTiles[];
extern const u8 gFollowingMonPic_1179_DragapultTiles[];
extern const u8 gFollowingMonPic_1180_ZacianTiles[];
extern const u8 gFollowingMonPic_1181_ZamazentaTiles[];
extern const u8 gFollowingMonPic_1182_EternatusTiles[];
extern const u8 gFollowingMonPic_1183_KubfuTiles[];
extern const u8 gFollowingMonPic_1184_UrshifuTiles[];
extern const u8 gFollowingMonPic_1185_ZarudeTiles[];
extern const u8 gFollowingMonPic_1186_RegielekiTiles[];
extern const u8 gFollowingMonPic_1187_RegidragoTiles[];
extern const u8 gFollowingMonPic_1188_GlastrierTiles[];
extern const u8 gFollowingMonPic_1189_SpectrierTiles[];
extern const u8 gFollowingMonPic_1190_CalyrexTiles[];
extern const u8 gFollowingMonPic_1193_Toxtricity_LKTiles[];
extern const u8 gFollowingMonPic_1203_Indeedee_FTiles[];
extern const u8 gFollowingMonPic_1205_Zacian_CTiles[];
extern const u8 gFollowingMonPic_1206_Zamazenta_CTiles[];
extern const u8 gFollowingMonPic_1210_Calyrex_IRTiles[];
extern const u8 gFollowingMonPic_1211_Calyrex_SRTiles[];
extern const u8 gFollowingMonPic_1212_Meowth_GTiles[];
extern const u8 gFollowingMonPic_1213_Ponyta_GTiles[];
extern const u8 gFollowingMonPic_1214_Rapidash_GTiles[];
extern const u8 gFollowingMonPic_1215_Slowpoke_GTiles[];
extern const u8 gFollowingMonPic_1216_Slowbro_GTiles[];
extern const u8 gFollowingMonPic_1217_Farfetchd_GTiles[];
extern const u8 gFollowingMonPic_1219_Weezing_GTiles[];
extern const u8 gFollowingMonPic_1220_Mr_Mime_GTiles[];
extern const u8 gFollowingMonPic_1221_Articuno_GTiles[];
extern const u8 gFollowingMonPic_1222_Zapdos_GTiles[];
extern const u8 gFollowingMonPic_1223_Moltres_GTiles[];
extern const u8 gFollowingMonPic_1224_Slowking_GTiles[];
extern const u8 gFollowingMonPic_1225_Corsola_GTiles[];
extern const u8 gFollowingMonPic_1226_Zigzagoon_GTiles[];
extern const u8 gFollowingMonPic_1227_Linoone_GTiles[];
extern const u8 gFollowingMonPic_1229_Darumaka_GTiles[];
extern const u8 gFollowingMonPic_1230_Darmanitan_GTiles[];
extern const u8 gFollowingMonPic_1232_Yamask_GTiles[];
extern const u8 gFollowingMonPic_1233_Stunfisk_GTiles[];
extern const u8 gFollowingMonPic_1234_Growlithe_HTiles[];
extern const u8 gFollowingMonPic_1235_Arcanine_HTiles[];
extern const u8 gFollowingMonPic_1236_Voltorb_HTiles[];
extern const u8 gFollowingMonPic_1237_Electrode_HTiles[];
extern const u8 gFollowingMonPic_1238_Typhlosion_HTiles[];
extern const u8 gFollowingMonPic_1239_Qwilfish_HTiles[];
extern const u8 gFollowingMonPic_1240_Sneasel_HTiles[];
extern const u8 gFollowingMonPic_1242_Lilligant_HTiles[];
extern const u8 gFollowingMonPic_1243_Basculin_WTiles[];
extern const u8 gFollowingMonPic_1244_Zorua_HTiles[];
extern const u8 gFollowingMonPic_1245_Zoroark_HTiles[];
extern const u8 gFollowingMonPic_1246_Braviary_HTiles[];
extern const u8 gFollowingMonPic_1247_Sliggoo_HTiles[];
extern const u8 gFollowingMonPic_1248_Goodra_HTiles[];
extern const u8 gFollowingMonPic_1249_Avalugg_HTiles[];
extern const u8 gFollowingMonPic_1250_Decidueye_HTiles[];
extern const u8 gFollowingMonPic_1251_WyrdeerTiles[];
extern const u8 gFollowingMonPic_1252_KleavorTiles[];
extern const u8 gFollowingMonPic_1253_UrsalunaTiles[];
extern const u8 gFollowingMonPic_1254_BasculegionTiles[];
extern const u8 gFollowingMonPic_1255_Basculegion_FTiles[];
extern const u8 gFollowingMonPic_1256_SneaslerTiles[];
extern const u8 gFollowingMonPic_1257_OverqwilTiles[];
extern const u8 gFollowingMonPic_1258_EnamorusTiles[];
extern const u8 gFollowingMonPic_1259_Enamorus_TTiles[];
extern const u8 gFollowingMonPic_1294_SprigatitoTiles[];
extern const u8 gFollowingMonPic_1295_FloragatoTiles[];
extern const u8 gFollowingMonPic_1296_MeowscaradaTiles[];
extern const u8 gFollowingMonPic_1297_FuecocoTiles[];
extern const u8 gFollowingMonPic_1298_CrocalorTiles[];
extern const u8 gFollowingMonPic_1299_SkeledirgeTiles[];
extern const u8 gFollowingMonPic_1300_QuaxlyTiles[];
extern const u8 gFollowingMonPic_1301_QuaxwellTiles[];
extern const u8 gFollowingMonPic_1302_QuaquavalTiles[];
extern const u8 gFollowingMonPic_1303_LechonkTiles[];
extern const u8 gFollowingMonPic_1304_OinkologneTiles[];
extern const u8 gFollowingMonPic_1305_TarountulaTiles[];
extern const u8 gFollowingMonPic_1306_SpidopsTiles[];
extern const u8 gFollowingMonPic_1307_NymbleTiles[];
extern const u8 gFollowingMonPic_1308_LokixTiles[];
extern const u8 gFollowingMonPic_1309_PawmiTiles[];
extern const u8 gFollowingMonPic_1310_PawmoTiles[];
extern const u8 gFollowingMonPic_1311_PawmotTiles[];
extern const u8 gFollowingMonPic_1312_TandemausTiles[];
extern const u8 gFollowingMonPic_1313_MausholdTiles[];
extern const u8 gFollowingMonPic_1314_FidoughTiles[];
extern const u8 gFollowingMonPic_1315_DachsbunTiles[];
extern const u8 gFollowingMonPic_1316_SmolivTiles[];
extern const u8 gFollowingMonPic_1317_DollivTiles[];
extern const u8 gFollowingMonPic_1318_ArbolivaTiles[];
extern const u8 gFollowingMonPic_1319_SquawkabillyTiles[];
extern const u8 gFollowingMonPic_1320_NacliTiles[];
extern const u8 gFollowingMonPic_1321_NaclstackTiles[];
extern const u8 gFollowingMonPic_1322_GarganaclTiles[];
extern const u8 gFollowingMonPic_1323_CharcadetTiles[];
extern const u8 gFollowingMonPic_1324_ArmarougeTiles[];
extern const u8 gFollowingMonPic_1325_CeruledgeTiles[];
extern const u8 gFollowingMonPic_1326_TadbulbTiles[];
extern const u8 gFollowingMonPic_1327_BelliboltTiles[];
extern const u8 gFollowingMonPic_1328_WattrelTiles[];
extern const u8 gFollowingMonPic_1329_KilowattrelTiles[];
extern const u8 gFollowingMonPic_1330_MaschiffTiles[];
extern const u8 gFollowingMonPic_1331_MabosstiffTiles[];
extern const u8 gFollowingMonPic_1332_ShroodleTiles[];
extern const u8 gFollowingMonPic_1333_GrafaiaiTiles[];
extern const u8 gFollowingMonPic_1334_BramblinTiles[];
extern const u8 gFollowingMonPic_1335_BrambleghastTiles[];
extern const u8 gFollowingMonPic_1336_ToedscoolTiles[];
extern const u8 gFollowingMonPic_1337_ToedscruelTiles[];
extern const u8 gFollowingMonPic_1338_KlawfTiles[];
extern const u8 gFollowingMonPic_1339_CapsakidTiles[];
extern const u8 gFollowingMonPic_1340_ScovillainTiles[];
extern const u8 gFollowingMonPic_1341_RellorTiles[];
extern const u8 gFollowingMonPic_1342_RabscaTiles[];
extern const u8 gFollowingMonPic_1343_FlittleTiles[];
extern const u8 gFollowingMonPic_1344_EspathraTiles[];
extern const u8 gFollowingMonPic_1345_TinkatinkTiles[];
extern const u8 gFollowingMonPic_1346_TinkatuffTiles[];
extern const u8 gFollowingMonPic_1347_TinkatonTiles[];
extern const u8 gFollowingMonPic_1348_WiglettTiles[];
extern const u8 gFollowingMonPic_1349_WugtrioTiles[];
extern const u8 gFollowingMonPic_1350_BombirdierTiles[];
extern const u8 gFollowingMonPic_1351_FinizenTiles[];
extern const u8 gFollowingMonPic_1352_PalafinTiles[];
extern const u8 gFollowingMonPic_1353_VaroomTiles[];
extern const u8 gFollowingMonPic_1354_RevavroomTiles[];
extern const u8 gFollowingMonPic_1355_CyclizarTiles[];
extern const u8 gFollowingMonPic_1356_OrthwormTiles[];
extern const u8 gFollowingMonPic_1357_GlimmetTiles[];
extern const u8 gFollowingMonPic_1358_GlimmoraTiles[];
extern const u8 gFollowingMonPic_1359_GreavardTiles[];
extern const u8 gFollowingMonPic_1360_HoundstoneTiles[];
extern const u8 gFollowingMonPic_1361_FlamigoTiles[];
extern const u8 gFollowingMonPic_1362_CetoddleTiles[];
extern const u8 gFollowingMonPic_1363_CetitanTiles[];
extern const u8 gFollowingMonPic_1364_VeluzaTiles[];
extern const u8 gFollowingMonPic_1365_DondozoTiles[];
extern const u8 gFollowingMonPic_1366_TatsugiriTiles[];
extern const u8 gFollowingMonPic_1367_AnnihilapeTiles[];
extern const u8 gFollowingMonPic_1368_ClodsireTiles[];
extern const u8 gFollowingMonPic_1369_FarigirafTiles[];
extern const u8 gFollowingMonPic_1370_DudunsparceTiles[];
extern const u8 gFollowingMonPic_1371_KingambitTiles[];
extern const u8 gFollowingMonPic_1372_Great_TuskTiles[];
extern const u8 gFollowingMonPic_1373_Scream_TailTiles[];
extern const u8 gFollowingMonPic_1374_Brute_BonnetTiles[];
extern const u8 gFollowingMonPic_1375_Flutter_ManeTiles[];
extern const u8 gFollowingMonPic_1376_Slither_WingTiles[];
extern const u8 gFollowingMonPic_1377_Sandy_ShocksTiles[];
extern const u8 gFollowingMonPic_1378_Iron_TreadsTiles[];
extern const u8 gFollowingMonPic_1379_Iron_BundleTiles[];
extern const u8 gFollowingMonPic_1380_Iron_HandsTiles[];
extern const u8 gFollowingMonPic_1381_Iron_JugulisTiles[];
extern const u8 gFollowingMonPic_1382_Iron_MothTiles[];
extern const u8 gFollowingMonPic_1383_Iron_ThornsTiles[];
extern const u8 gFollowingMonPic_1384_FrigibaxTiles[];
extern const u8 gFollowingMonPic_1385_ArctibaxTiles[];
extern const u8 gFollowingMonPic_1386_BaxcaliburTiles[];
extern const u8 gFollowingMonPic_1387_GimmighoulTiles[];
extern const u8 gFollowingMonPic_1388_GholdengoTiles[];
extern const u8 gFollowingMonPic_1389_Wo_ChienTiles[];
extern const u8 gFollowingMonPic_1390_Chien_PaoTiles[];
extern const u8 gFollowingMonPic_1391_Ting_LuTiles[];
extern const u8 gFollowingMonPic_1392_Chi_YuTiles[];
extern const u8 gFollowingMonPic_1393_Roaring_MoonTiles[];
extern const u8 gFollowingMonPic_1394_Iron_ValiantTiles[];
extern const u8 gFollowingMonPic_1395_KoraidonTiles[];
extern const u8 gFollowingMonPic_1396_MiraidonTiles[];
extern const u8 gFollowingMonPic_1397_Walking_WakeTiles[];
extern const u8 gFollowingMonPic_1398_Iron_LeavesTiles[];
extern const u8 gFollowingMonPic_1399_Oinkologne_FTiles[];
extern const u8 gFollowingMonPic_1406_Dudunsparce_2Tiles[];
extern const u8 gFollowingMonPic_1407_Tauros_CTiles[];
extern const u8 gFollowingMonPic_1408_Tauros_BTiles[];
extern const u8 gFollowingMonPic_1409_Tauros_ATiles[];
extern const u8 gFollowingMonPic_1410_Wooper_PTiles[];
extern const u8 gFollowingMonPic_1420_DipplinTiles[];
extern const u8 gFollowingMonPic_1421_PoltchageistTiles[];
extern const u8 gFollowingMonPic_1422_SinistchaTiles[];
extern const u8 gFollowingMonPic_1423_OkidogiTiles[];
extern const u8 gFollowingMonPic_1424_MunkidoriTiles[];
extern const u8 gFollowingMonPic_1425_FezandipitiTiles[];
extern const u8 gFollowingMonPic_1426_OgerponTiles[];
extern const u8 gFollowingMonPic_1426_Ogerpon_1Tiles[];
extern const u8 gFollowingMonPic_1426_Ogerpon_2Tiles[];
extern const u8 gFollowingMonPic_1426_Ogerpon_3Tiles[];
extern const u8 gFollowingMonPic_1430_ArchaludonTiles[];
extern const u8 gFollowingMonPic_1431_HydrappleTiles[];
extern const u8 gFollowingMonPic_1432_Gouging_FireTiles[];
extern const u8 gFollowingMonPic_1433_Raging_BoltTiles[];
extern const u8 gFollowingMonPic_1434_Iron_BoulderTiles[];
extern const u8 gFollowingMonPic_1435_Iron_CrownTiles[];
extern const u8 gFollowingMonPic_1436_TerapagosTiles[];
extern const u8 gFollowingMonPic_1436_Terapagos_1Tiles[];
extern const u8 gFollowingMonPic_1438_PecharuntTiles[];
extern const u8 gFollowingMonPic_1440_Maushold_FTiles[];
extern const u8 gFollowingMonPic_1493_Ursaluna_BMTiles[];

#endif
#endif