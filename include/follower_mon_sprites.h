#ifndef FOLLOWER_MON_SPRITES_H
#define FOLLOWER_MON_SPRITES_H

#include "global.h"
#include "constants/event_objects.h"

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

#define MON_OW_TEMPLATE_32x32_FRAMES(Id, name)                        \
static const struct SpriteFrameImage sMonPicTable_##name[] =          \
{                                                                     \
    overworld_frame(gFollowerMonPic##Id##_##name##Tiles, 4, 4, 0),    \
    overworld_frame(gFollowerMonPic##Id##_##name##Tiles, 4, 4, 1),    \
    overworld_frame(gFollowerMonPic##Id##_##name##Tiles, 4, 4, 2),    \
    overworld_frame(gFollowerMonPic##Id##_##name##Tiles, 4, 4, 3),    \
    overworld_frame(gFollowerMonPic##Id##_##name##Tiles, 4, 4, 4),    \
    overworld_frame(gFollowerMonPic##Id##_##name##Tiles, 4, 4, 5),    \
    overworld_frame(gFollowerMonPic##Id##_##name##Tiles, 4, 4, 6),    \
    overworld_frame(gFollowerMonPic##Id##_##name##Tiles, 4, 4, 7),    \
    overworld_frame(gFollowerMonPic##Id##_##name##Tiles, 4, 4, 8),    \
};

#define MON_OW_OBJECT_GRAPHICS(PalId, name)                 \
{                                                           \
    .tileTag = 0xFFFF,                                      \
    .paletteTag1 = 0x##PalId,                               \
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
    .images = sMonPicTable_##name,                          \
    .affineAnims = gDummySpriteAffineAnimTable,             \
},

extern const u16 gFollowerMonSpriteIdTable[];
extern const u16 gFollowerMonShinySpriteIdTable[];
extern const union AnimCmd *const gFollowerMonAnimTable[];

// Overworld Tables
extern const struct EventObjectGraphicsInfo gFollowerMonGfxTable0[];

// Images declarations
//Gen 1
extern const u8 gFollowerMonPic0001_BulbasaurTiles[];
extern const u8 gFollowerMonPic2000_BulbasaurShinyTiles[];
extern const u8 gFollowerMonPic0002_IvysaurTiles[];
extern const u8 gFollowerMonPic2001_IvysaurShinyTiles[];
extern const u8 gFollowerMonPic0003_VenusaurTiles[];
extern const u8 gFollowerMonPic0004_CharmanderTiles[];
extern const u8 gFollowerMonPic0005_CharmeleonTiles[];
extern const u8 gFollowerMonPic0006_CharizardTiles[];
extern const u8 gFollowerMonPic0007_SquirtleTiles[];
extern const u8 gFollowerMonPic0008_WartortleTiles[];
extern const u8 gFollowerMonPic0009_BlastoiseTiles[];
// Gen 2
extern const u8 gFollowerMonPic0152_ChikoritaTiles[];
extern const u8 gFollowerMonPic0153_BayleefTiles[];
extern const u8 gFollowerMonPic0154_MeganiumTiles[];
extern const u8 gFollowerMonPic0155_CyndaquilTiles[];
extern const u8 gFollowerMonPic0156_QuilavaTiles[];
extern const u8 gFollowerMonPic0157_TyphlosionTiles[];
extern const u8 gFollowerMonPic0158_TotodileTiles[];
extern const u8 gFollowerMonPic0159_CroconawTiles[];
extern const u8 gFollowerMonPic0160_FeraligatrTiles[];
// Gen 3
extern const u8 gFollowerMonPic0252_TreeckoTiles[];
extern const u8 gFollowerMonPic0253_GrovyleTiles[];
extern const u8 gFollowerMonPic0254_SceptileTiles[];
extern const u8 gFollowerMonPic0255_TorchicTiles[];
extern const u8 gFollowerMonPic0256_CombuskenTiles[];
extern const u8 gFollowerMonPic0257_BlazikenTiles[];
extern const u8 gFollowerMonPic0258_MudkipTiles[];
extern const u8 gFollowerMonPic0259_MarshtompTiles[];
extern const u8 gFollowerMonPic0260_SwampertTiles[];
// Gen 4
extern const u8 gFollowerMonPic0387_TurtwigTiles[];
extern const u8 gFollowerMonPic0388_GrotleTiles[];
extern const u8 gFollowerMonPic0389_TorterraTiles[];
extern const u8 gFollowerMonPic0390_ChimcharTiles[];
extern const u8 gFollowerMonPic0391_MonfernoTiles[];
extern const u8 gFollowerMonPic0392_InfernapeTiles[];
extern const u8 gFollowerMonPic0393_PiplupTiles[];
extern const u8 gFollowerMonPic0394_PrinplupTiles[];
extern const u8 gFollowerMonPic0395_EmpoleonTiles[];
// Gen 5
extern const u8 gFollowerMonPic0495_SnivyTiles[];
extern const u8 gFollowerMonPic0496_ServineTiles[];
extern const u8 gFollowerMonPic0497_SerperiorTiles[];
extern const u8 gFollowerMonPic0498_TepigTiles[];
extern const u8 gFollowerMonPic0499_PigniteTiles[];
extern const u8 gFollowerMonPic0500_EmboarTiles[];
extern const u8 gFollowerMonPic0501_OshawottTiles[];
extern const u8 gFollowerMonPic0502_DewottTiles[];
extern const u8 gFollowerMonPic0503_SamurottTiles[];
// Gen 6
extern const u8 gFollowerMonPic0650_ChespinTiles[];
extern const u8 gFollowerMonPic0651_QuilladinTiles[];
extern const u8 gFollowerMonPic0652_ChesnaughtTiles[];
extern const u8 gFollowerMonPic0653_FennekinTiles[];
extern const u8 gFollowerMonPic0654_BraixenTiles[];
extern const u8 gFollowerMonPic0655_DelphoxTiles[];
extern const u8 gFollowerMonPic0656_FroakieTiles[];
extern const u8 gFollowerMonPic0657_FrogadierTiles[];
extern const u8 gFollowerMonPic0658_GreninjaTiles[];
// Gen 7
extern const u8 gFollowerMonPic0722_RowletTiles[];
extern const u8 gFollowerMonPic0723_DartrixTiles[];
extern const u8 gFollowerMonPic0724_DecidueyeTiles[];
extern const u8 gFollowerMonPic0725_LittenTiles[];
extern const u8 gFollowerMonPic0726_TorracatTiles[];
extern const u8 gFollowerMonPic0727_IncineroarTiles[];
extern const u8 gFollowerMonPic0728_PopplioTiles[];
extern const u8 gFollowerMonPic0729_BrionneTiles[];
extern const u8 gFollowerMonPic0730_PrimarinaTiles[];
// Gen 8
extern const u8 gFollowerMonPic0810_GrookeyTiles[];
extern const u8 gFollowerMonPic0811_ThwackeyTiles[];
extern const u8 gFollowerMonPic0812_RillaboomTiles[];
extern const u8 gFollowerMonPic0813_ScorbunnyTiles[];
extern const u8 gFollowerMonPic0814_RabootTiles[];
extern const u8 gFollowerMonPic0815_CinderaceTiles[];
extern const u8 gFollowerMonPic0816_SobbleTiles[];
extern const u8 gFollowerMonPic0817_DrizzileTiles[];
extern const u8 gFollowerMonPic0818_InteleonTiles[];
// Gen 9
extern const u8 gFollowerMonPic0906_SprigatitoTiles[];
extern const u8 gFollowerMonPic0907_FloragatoTiles[];
extern const u8 gFollowerMonPic0908_MeowscaradaTiles[];
extern const u8 gFollowerMonPic0909_FuecocoTiles[];
extern const u8 gFollowerMonPic0910_CrocalorTiles[];
extern const u8 gFollowerMonPic0911_SkeledirgeTiles[];
extern const u8 gFollowerMonPic0912_QuaxlyTiles[];
extern const u8 gFollowerMonPic0913_QuaxwellTiles[];
extern const u8 gFollowerMonPic0914_QuaquavalTiles[];

// Palettes declarations
// Gen 1
extern const u16 gFollowerMonPic0001_BulbasaurPal[];
extern const u16 gFollowerMonPic2000_BulbasaurShinyPal[];
extern const u16 gFollowerMonPic0002_IvysaurPal[];
extern const u16 gFollowerMonPic2001_IvysaurShinyPal[];
extern const u16 gFollowerMonPic0003_VenusaurPal[];
extern const u16 gFollowerMonPic0004_CharmanderPal[];
extern const u16 gFollowerMonPic0005_CharmeleonPal[];
extern const u16 gFollowerMonPic0006_CharizardPal[];
extern const u16 gFollowerMonPic0007_SquirtlePal[];
extern const u16 gFollowerMonPic0008_WartortlePal[];
extern const u16 gFollowerMonPic0009_BlastoisePal[];
// Gen 2
extern const u16 gFollowerMonPic0152_ChikoritaPal[];
extern const u16 gFollowerMonPic0153_BayleefPal[];
extern const u16 gFollowerMonPic0154_MeganiumPal[];
extern const u16 gFollowerMonPic0155_CyndaquilPal[];
extern const u16 gFollowerMonPic0156_QuilavaPal[];
extern const u16 gFollowerMonPic0157_TyphlosionPal[];
extern const u16 gFollowerMonPic0158_TotodilePal[];
extern const u16 gFollowerMonPic0159_CroconawPal[];
extern const u16 gFollowerMonPic0160_FeraligatrPal[];
// Gen 3
extern const u16 gFollowerMonPic0252_TreeckoPal[];
extern const u16 gFollowerMonPic0253_GrovylePal[];
extern const u16 gFollowerMonPic0254_SceptilePal[];
extern const u16 gFollowerMonPic0255_TorchicPal[];
extern const u16 gFollowerMonPic0256_CombuskenPal[];
extern const u16 gFollowerMonPic0257_BlazikenPal[];
extern const u16 gFollowerMonPic0258_MudkipPal[];
extern const u16 gFollowerMonPic0259_MarshtompPal[];
extern const u16 gFollowerMonPic0260_SwampertPal[];
// Gen 4
extern const u16 gFollowerMonPic0387_TurtwigPal[];
extern const u16 gFollowerMonPic0388_GrotlePal[];
extern const u16 gFollowerMonPic0389_TorterraPal[];
extern const u16 gFollowerMonPic0390_ChimcharPal[];
extern const u16 gFollowerMonPic0391_MonfernoPal[];
extern const u16 gFollowerMonPic0392_InfernapePal[];
extern const u16 gFollowerMonPic0393_PiplupPal[];
extern const u16 gFollowerMonPic0394_PrinplupPal[];
extern const u16 gFollowerMonPic0395_EmpoleonPal[];
// Gen 5
extern const u16 gFollowerMonPic0495_SnivyPal[];
extern const u16 gFollowerMonPic0496_ServinePal[];
extern const u16 gFollowerMonPic0497_SerperiorPal[];
extern const u16 gFollowerMonPic0498_TepigPal[];
extern const u16 gFollowerMonPic0499_PignitePal[];
extern const u16 gFollowerMonPic0500_EmboarPal[];
extern const u16 gFollowerMonPic0501_OshawottPal[];
extern const u16 gFollowerMonPic0502_DewottPal[];
extern const u16 gFollowerMonPic0503_SamurottPal[];
// Gen 6
extern const u16 gFollowerMonPic0650_ChespinPal[];
extern const u16 gFollowerMonPic0651_QuilladinPal[];
extern const u16 gFollowerMonPic0652_ChesnaughtPal[];
extern const u16 gFollowerMonPic0653_FennekinPal[];
extern const u16 gFollowerMonPic0654_BraixenPal[];
extern const u16 gFollowerMonPic0655_DelphoxPal[];
extern const u16 gFollowerMonPic0656_FroakiePal[];
extern const u16 gFollowerMonPic0657_FrogadierPal[];
extern const u16 gFollowerMonPic0658_GreninjaPal[];
// Gen 7
extern const u16 gFollowerMonPic0722_RowletPal[];
extern const u16 gFollowerMonPic0723_DartrixPal[];
extern const u16 gFollowerMonPic0724_DecidueyePal[];
extern const u16 gFollowerMonPic0725_LittenPal[];
extern const u16 gFollowerMonPic0726_TorracatPal[];
extern const u16 gFollowerMonPic0727_IncineroarPal[];
extern const u16 gFollowerMonPic0728_PopplioPal[];
extern const u16 gFollowerMonPic0729_BrionnePal[];
extern const u16 gFollowerMonPic0730_PrimarinaPal[];
// Gen 8
extern const u16 gFollowerMonPic0810_GrookeyPal[];
extern const u16 gFollowerMonPic0811_ThwackeyPal[];
extern const u16 gFollowerMonPic0812_RillaboomPal[];
extern const u16 gFollowerMonPic0813_ScorbunnyPal[];
extern const u16 gFollowerMonPic0814_RabootPal[];
extern const u16 gFollowerMonPic0815_CinderacePal[];
extern const u16 gFollowerMonPic0816_SobblePal[];
extern const u16 gFollowerMonPic0817_DrizzilePal[];
extern const u16 gFollowerMonPic0818_InteleonPal[];
// Gen 9
extern const u16 gFollowerMonPic0906_SprigatitoPal[];
extern const u16 gFollowerMonPic0907_FloragatoPal[];
extern const u16 gFollowerMonPic0908_MeowscaradaPal[];
extern const u16 gFollowerMonPic0909_FuecocoPal[];
extern const u16 gFollowerMonPic0910_CrocalorPal[];
extern const u16 gFollowerMonPic0911_SkeledirgePal[];
extern const u16 gFollowerMonPic0912_QuaxlyPal[];
extern const u16 gFollowerMonPic0913_QuaxwellPal[];
extern const u16 gFollowerMonPic0914_QuaquavalPal[];

#endif