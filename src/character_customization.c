#include "defines.h"
#include "defines_battle.h"
#include "../include/dynamic_placeholder_text_util.h"
#include "../include/event_object_movement.h"
#include "../include/field_effect_helpers.h"
#include "../include/field_player_avatar.h"
#include "../include/link.h"
#include "../include/random.h"
#include "../include/sprite.h"
#include "../include/trainer_pokemon_sprites.h"
#include "../include/constants/character_customization.h"
#include "../include/constants/event_object_movement_constants.h"
#include "../include/constants/event_objects.h"
#include "../include/constants/trainers.h"

#include "../include/new/character_customization.h"
#include "../include/new/follow_me.h"
#include "../include/new/frontier.h"
#include "../include/new/multi.h"
#include "../include/new/util.h"

/*
character_customization.c
	functions for altering the player's sprite based on the current sprite/palette selections

tables to edit:
	gOverworldTableSwitcher
	sPlayerAvatarGfxIds

*/

#ifdef UNBOUND
//extern const u16 MalePlayer_Trainer_Outfit_RedPal[];
extern const u16 MalePlayer_Trainer_Outfit_BlackPal[];
extern const u16 MalePlayer_Trainer_Outfit_BluePal[];
extern const u16 MalePlayer_Trainer_Outfit_GrayPal[];
extern const u16 MalePlayer_Trainer_Outfit_PurplePal[];
extern const u16 MalePlayer_Trainer_Outfit_YellowPal[];
extern const u16 MalePlayer_Trainer_Outfit_GreenPal[];
extern const u16 MalePlayer_Trainer_Outfit_TealPal[];
extern const u16 MalePlayer_Trainer_Outfit_BrownPal[];
extern const u16 MalePlayer_Trainer_Outfit_OrangePal[];
extern const u16 MalePlayer_Trainer_Outfit_PinkPal[];

//extern const u16 MalePlayer_Trainer_Trim_GoldPal[];
extern const u16 MalePlayer_Trainer_Trim_BlackPal[];
extern const u16 MalePlayer_Trainer_Trim_BluePal[];
extern const u16 MalePlayer_Trainer_Trim_BrownPal[];
extern const u16 MalePlayer_Trainer_Trim_BrownOrangePal[];
extern const u16 MalePlayer_Trainer_Trim_GreenPal[];
extern const u16 MalePlayer_Trainer_Trim_LightBluePal[];
extern const u16 MalePlayer_Trainer_Trim_LightGreenPal[];
extern const u16 MalePlayer_Trainer_Trim_LightPinkPal[];
extern const u16 MalePlayer_Trainer_Trim_LightRedPal[];
extern const u16 MalePlayer_Trainer_Trim_OrangePal[];
extern const u16 MalePlayer_Trainer_Trim_PinkPal[];
extern const u16 MalePlayer_Trainer_Trim_PurplePal[];
extern const u16 MalePlayer_Trainer_Trim_Purple2Pal[];
extern const u16 MalePlayer_Trainer_Trim_RedPal[];
extern const u16 MalePlayer_Trainer_Trim_TealPal[];
extern const u16 MalePlayer_Trainer_Trim_WhitePal[];
extern const u16 MalePlayer_Trainer_Trim_YellowPal[];

//extern const u16 MalePlayer_Trainer_Hair_BrownPal[];
extern const u16 MalePlayer_Trainer_Hair_BlondePal[];
extern const u16 MalePlayer_Trainer_Hair_LBlondePal[];
extern const u16 MalePlayer_Trainer_Hair_BlackPal[];
extern const u16 MalePlayer_Trainer_Hair_RedPal[];
extern const u16 MalePlayer_Trainer_Hair_GreenPal[];
extern const u16 MalePlayer_Trainer_Hair_PurplePal[];
extern const u16 MalePlayer_Trainer_Hair_BluePal[];
extern const u16 MalePlayer_Trainer_Hair_TealPal[];
extern const u16 MalePlayer_Trainer_Hair_PinkPal[];
extern const u16 MalePlayer_Trainer_Hair_SilverPal[];
extern const u16 MalePlayer_Trainer_Hair_GreyPal[];
extern const u16 MalePlayer_Trainer_Hair_WhitePal[];
extern const u16 MalePlayer_Trainer_Hair_OrangePal[];
extern const u16 MalePlayer_Trainer_Hair_LightBrownPal[];
extern const u16 MalePlayer_Trainer_Hair_DarkBrownPal[];

//extern const u16 MalePlayer_Trainer_Skin_LightPal[];
extern const u16 MalePlayer_Trainer_Skin_LBrownPal[];
extern const u16 MalePlayer_Trainer_Skin_BrownPal[];
extern const u16 MalePlayer_Trainer_Skin_DarkBrownPal[];
extern const u16 MalePlayer_Trainer_Skin_YellowPal[];

//extern const u16 MalePlayer_Champion_RedPal[];
extern const u16 MalePlayer_Champion_RedPal[];
extern const u16 MalePlayer_Champion_BluePal[];
extern const u16 MalePlayer_Champion_TealPal[];
extern const u16 MalePlayer_Champion_LimePal[];
extern const u16 MalePlayer_Champion_GreenPal[];
extern const u16 MalePlayer_Champion_YellowPal[];
extern const u16 MalePlayer_Champion_BlackPal[];
extern const u16 MalePlayer_Champion_GrayPal[];
extern const u16 MalePlayer_Champion_WhitePal[];
extern const u16 MalePlayer_Champion_PurplePal[];
extern const u16 MalePlayer_Champion_PinkPal[];
extern const u16 MalePlayer_Champion_BrownPal[];
extern const u16 MalePlayer_Champion_OrangePal[];

//extern const u16 MalePlayer_Champion_Trim_LightOrangePal[];
extern const u16 MalePlayer_Champion_Trim_RedPal[];
extern const u16 MalePlayer_Champion_Trim_BluePal[];
extern const u16 MalePlayer_Champion_Trim_TealPal[];
extern const u16 MalePlayer_Champion_Trim_LimePal[];
extern const u16 MalePlayer_Champion_Trim_GreenPal[];
extern const u16 MalePlayer_Champion_Trim_YellowPal[];
extern const u16 MalePlayer_Champion_Trim_BlackPal[];
extern const u16 MalePlayer_Champion_Trim_GrayPal[];
extern const u16 MalePlayer_Champion_Trim_WhitePal[];
extern const u16 MalePlayer_Champion_Trim_PurplePal[];
extern const u16 MalePlayer_Champion_Trim_PinkPal[];
extern const u16 MalePlayer_Champion_Trim_BrownPal[];
extern const u16 MalePlayer_Champion_Trim_OrangePal[];

//extern const u16 MalePlayer_Marlon_RedPal[];
extern const u16 MalePlayer_Marlon_BluePal[];
extern const u16 MalePlayer_Marlon_TealPal[];
extern const u16 MalePlayer_Marlon_GreenPal[];
extern const u16 MalePlayer_Marlon_LimePal[];
extern const u16 MalePlayer_Marlon_YellowPal[];
extern const u16 MalePlayer_Marlon_BlackPal[];
extern const u16 MalePlayer_Marlon_WhitePal[];
extern const u16 MalePlayer_Marlon_PurplePal[];
extern const u16 MalePlayer_Marlon_PinkPal[];
extern const u16 MalePlayer_Marlon_BrownPal[];
extern const u16 MalePlayer_Marlon_OrangePal[];
extern const u16 MalePlayer_Marlon_BrightRedPal[];
	
static const u16* sPlayerOutfitColours[] =
{
	NULL /*MalePlayer_Trainer_Outfit_RedPal*/, //Defaults are loaded from elsewhere
	MalePlayer_Trainer_Outfit_BlackPal,
	MalePlayer_Trainer_Outfit_BluePal,
	MalePlayer_Trainer_Outfit_TealPal,
	MalePlayer_Trainer_Outfit_GrayPal,
	MalePlayer_Trainer_Outfit_GreenPal,
	MalePlayer_Trainer_Outfit_YellowPal,
	MalePlayer_Trainer_Outfit_OrangePal,
	MalePlayer_Trainer_Outfit_BrownPal,
	MalePlayer_Trainer_Outfit_PurplePal,
	MalePlayer_Trainer_Outfit_PinkPal,
};

static const u16* sPlayerTrimColours[] =
{
	NULL /*MalePlayer_Trainer_Trim_GoldPal*/,
	MalePlayer_Trainer_Trim_RedPal,
	MalePlayer_Trainer_Trim_LightRedPal,
	MalePlayer_Trainer_Trim_OrangePal,
	MalePlayer_Trainer_Trim_YellowPal,
	MalePlayer_Trainer_Trim_GreenPal,
	MalePlayer_Trainer_Trim_LightGreenPal,
	MalePlayer_Trainer_Trim_BrownPal,
	MalePlayer_Trainer_Trim_BrownOrangePal,
	MalePlayer_Trainer_Trim_BlackPal,
	MalePlayer_Trainer_Trim_WhitePal,
	MalePlayer_Trainer_Trim_BluePal,
	MalePlayer_Trainer_Trim_TealPal,
	MalePlayer_Trainer_Trim_LightBluePal,
	MalePlayer_Trainer_Trim_PinkPal,
	MalePlayer_Trainer_Trim_LightPinkPal,
	MalePlayer_Trainer_Trim_Purple2Pal,
	MalePlayer_Trainer_Trim_PurplePal,
};

static const u16* sPlayerHairColours[] =
{
	NULL /*MalePlayer_Trainer_Hair_BrownPal*/,
	MalePlayer_Trainer_Hair_LBlondePal,
	MalePlayer_Trainer_Hair_BlondePal,
	MalePlayer_Trainer_Hair_BlackPal,
	MalePlayer_Trainer_Hair_RedPal,
	MalePlayer_Trainer_Hair_GreenPal,
	MalePlayer_Trainer_Hair_PurplePal,
	MalePlayer_Trainer_Hair_BluePal,
	MalePlayer_Trainer_Hair_PinkPal,
	MalePlayer_Trainer_Hair_SilverPal,
	MalePlayer_Trainer_Hair_GreyPal,
	MalePlayer_Trainer_Hair_WhitePal,
	MalePlayer_Trainer_Hair_TealPal,
	MalePlayer_Trainer_Hair_OrangePal,
	MalePlayer_Trainer_Hair_LightBrownPal,
	MalePlayer_Trainer_Hair_DarkBrownPal,
};

static const u16* sPlayerSkinColours[] =
{
    NULL /*MalePlayer_Trainer_Skin_LightPal*/,
    MalePlayer_Trainer_Skin_LBrownPal,
    MalePlayer_Trainer_Skin_BrownPal,
    MalePlayer_Trainer_Skin_DarkBrownPal,
    MalePlayer_Trainer_Skin_YellowPal,
};

static const u16* sPlayerChampionOutfitColours[] =
{
	NULL /*MalePlayer_Champion_ReddishOrangePal*/, //Defaults are loaded from elsewhere
	MalePlayer_Champion_RedPal,
	MalePlayer_Champion_BluePal,
	MalePlayer_Champion_TealPal,
	MalePlayer_Champion_LimePal,
	MalePlayer_Champion_GreenPal,
	MalePlayer_Champion_YellowPal,
	MalePlayer_Champion_BlackPal,
	MalePlayer_Champion_GrayPal,
	MalePlayer_Champion_WhitePal,
	MalePlayer_Champion_PinkPal,
	MalePlayer_Champion_PurplePal,
	MalePlayer_Champion_BrownPal,
	MalePlayer_Champion_OrangePal,
};

static const u16* sPlayerChampionTrimColours[] =
{
	NULL /*MalePlayer_Champion_Trim_LightOrangePal*/, //Defaults are loaded from elsewhere
	MalePlayer_Champion_Trim_RedPal,
	MalePlayer_Champion_Trim_BluePal,
	MalePlayer_Champion_Trim_TealPal,
	MalePlayer_Champion_Trim_LimePal,
	MalePlayer_Champion_Trim_GreenPal,
	MalePlayer_Champion_Trim_YellowPal,
	MalePlayer_Champion_Trim_BlackPal,
	MalePlayer_Champion_Trim_GrayPal,
	MalePlayer_Champion_Trim_WhitePal,
	MalePlayer_Champion_Trim_PinkPal,
	MalePlayer_Champion_Trim_PurplePal,
	MalePlayer_Champion_Trim_BrownPal,
	MalePlayer_Champion_Trim_OrangePal,
};

static const u16* sPlayerMarlonOutfitColours[] =
{
	NULL /*MalePlayer_Marlon_RedPal*/, //Defaults are loaded from elsewhere
	MalePlayer_Marlon_BluePal,
	MalePlayer_Marlon_TealPal,
	MalePlayer_Marlon_LimePal,
	MalePlayer_Marlon_GreenPal,
	MalePlayer_Marlon_YellowPal,
	MalePlayer_Marlon_BlackPal,
	MalePlayer_Marlon_WhitePal,
	MalePlayer_Marlon_PurplePal,
	MalePlayer_Marlon_PinkPal,
	MalePlayer_Marlon_BrownPal,
	MalePlayer_Marlon_OrangePal,
	MalePlayer_Marlon_BrightRedPal,
};
#endif

#ifdef EXISTING_OW_TABLE_ADDRESS
	#define gOverworldTableSwitcher ((struct EventObjectGraphicsInfo***) EXISTING_OW_TABLE_ADDRESS)
#elif defined UNBOUND //For Pokemon Unbound
	const struct EventObjectGraphicsInfo** const gOverworldTableSwitcher[] =
	{
		(NPCPtr*) 0x88110E0,
		(NPCPtr*) 0x88B2720,
		(NPCPtr*) 0x88B2B20,
	};

#else //Modify this

extern const struct EventObjectGraphicsInfo gFollowerMonGfxTable0[];

static NPCPtr sOverworldTable2[] =
{
	&gFollowerMonGfxTable0[0],
	&gFollowerMonGfxTable0[1],
	&gFollowerMonGfxTable0[2],
	&gFollowerMonGfxTable0[3],
	&gFollowerMonGfxTable0[4],
	&gFollowerMonGfxTable0[5],
	&gFollowerMonGfxTable0[6],
	&gFollowerMonGfxTable0[7],
	&gFollowerMonGfxTable0[8],
	&gFollowerMonGfxTable0[9],
	&gFollowerMonGfxTable0[10],
	&gFollowerMonGfxTable0[11],
	&gFollowerMonGfxTable0[12],
	&gFollowerMonGfxTable0[13],
	&gFollowerMonGfxTable0[14],
	&gFollowerMonGfxTable0[15],
	&gFollowerMonGfxTable0[16],
	&gFollowerMonGfxTable0[17],
	&gFollowerMonGfxTable0[18],
	&gFollowerMonGfxTable0[19],
	&gFollowerMonGfxTable0[20],
	&gFollowerMonGfxTable0[21],
	&gFollowerMonGfxTable0[22],
	&gFollowerMonGfxTable0[23],
	&gFollowerMonGfxTable0[24],
	&gFollowerMonGfxTable0[25],
	&gFollowerMonGfxTable0[26],
	&gFollowerMonGfxTable0[27],
	&gFollowerMonGfxTable0[28],
	&gFollowerMonGfxTable0[29],
	&gFollowerMonGfxTable0[30],
	&gFollowerMonGfxTable0[31],
	&gFollowerMonGfxTable0[32],
	&gFollowerMonGfxTable0[33],
	&gFollowerMonGfxTable0[34],
	&gFollowerMonGfxTable0[35],
	&gFollowerMonGfxTable0[36],
	&gFollowerMonGfxTable0[37],
	&gFollowerMonGfxTable0[38],
	&gFollowerMonGfxTable0[39],
	&gFollowerMonGfxTable0[40],
	&gFollowerMonGfxTable0[41],
	&gFollowerMonGfxTable0[42],
	&gFollowerMonGfxTable0[43],
	&gFollowerMonGfxTable0[44],
	&gFollowerMonGfxTable0[45],
	&gFollowerMonGfxTable0[46],
	&gFollowerMonGfxTable0[47],
	&gFollowerMonGfxTable0[48],
	&gFollowerMonGfxTable0[49],
	&gFollowerMonGfxTable0[50],
	&gFollowerMonGfxTable0[51],
	&gFollowerMonGfxTable0[52],
	&gFollowerMonGfxTable0[53],
	&gFollowerMonGfxTable0[54],
	&gFollowerMonGfxTable0[55],
	&gFollowerMonGfxTable0[56],
	&gFollowerMonGfxTable0[57],
	&gFollowerMonGfxTable0[58],
	&gFollowerMonGfxTable0[59],
	&gFollowerMonGfxTable0[60],
	&gFollowerMonGfxTable0[61],
	&gFollowerMonGfxTable0[62],
	&gFollowerMonGfxTable0[63],
	&gFollowerMonGfxTable0[64],
	&gFollowerMonGfxTable0[65],
	&gFollowerMonGfxTable0[66],
	&gFollowerMonGfxTable0[67],
	&gFollowerMonGfxTable0[68],
	&gFollowerMonGfxTable0[69],
	&gFollowerMonGfxTable0[70],
	&gFollowerMonGfxTable0[71],
	&gFollowerMonGfxTable0[72],
	&gFollowerMonGfxTable0[73],
	&gFollowerMonGfxTable0[74],
	&gFollowerMonGfxTable0[75],
	&gFollowerMonGfxTable0[76],
	&gFollowerMonGfxTable0[77],
	&gFollowerMonGfxTable0[78],
	&gFollowerMonGfxTable0[79],
	&gFollowerMonGfxTable0[80],
	&gFollowerMonGfxTable0[81],
};


	// create 255 OW tables
	const struct EventObjectGraphicsInfo** const gOverworldTableSwitcher[255] =
	{
		(NPCPtr*) 0x839FDB0,
		sOverworldTable2,
		// etc...
		// please note that this method makes compatability with OW Manager challenging
	};
	
	static const struct SpritePalette gObjectEventSpritePalettes11[] = {
		{gObjectEventPallete_1, 0x1100},
		{gObjectEventPallete_2, 0x1101},
		{gObjectEventPallete_3, 0x1102},
		{gObjectEventPallete_4, 0x1103},
		{gObjectEventPallete_5, 0x1104},
		{gObjectEventPallete_6, 0x1105},
		{gObjectEventPallete_7, 0x1106},
		{gObjectEventPallete_8, 0x1107},
		{gObjectEventPallete_9, 0x1108},
		{gObjectEventPallete_10, 0x1109},
		{gObjectEventPallete_11, 0x110A},
		{gObjectEventPallete_12, 0x110B},
		{gObjectEventPallete_13, 0x110C},
		{gObjectEventPallete_14, 0x1110},
		{gObjectEventPallete_15, 0x1111},
		{gObjectEventPallete_16, 0x1113},
		{gObjectEventPallete_17, 0x1115},
		{gObjectEventPallete_18, 0x1114},
		{gObjectEventPallete_19, 0x1116},
		{gObjectEventPallete_20, 0x1117},
		{gObjectEventPallete_21, 0x1118},
		{gObjectEventPallete_22, 0x1119},
		{gObjectEventPallete_23, 0x111A},
		{gObjectEventPallete_24, 0x111B},
		{gObjectEventPallete_25, 0x111C},
		{gObjectEventPallete_26, 0x111D},
		{gObjectEventPallete_27, 0x111E},
		{gObjectEventPallete_28, 0x111F},
		{gObjectEventPallete_29, 0x1120},
		{gObjectEventPallete_30, 0x1121},
		{gObjectEventPallete_31, 0x1122},
		{gObjectEventPallete_32, 0x1123},
		{gObjectEventPallete_33, 0x1124},
		{gObjectEventPallete_34, 0x1125},
		{gObjectEventPallete_35, 0x1126},
		{gObjectEventPallete_36, 0x1127},
		{gObjectEventPallete_37, 0x1128},
		{gObjectEventPallete_38, 0x1129},
		{gObjectEventPallete_39, 0x112A},
		{gObjectEventPallete_40, 0x112B},
		{gObjectEventPallete_41, 0x112C},
		{gObjectEventPallete_42, 0x112D},
		{gObjectEventPallete_43, 0x112E},
		{gObjectEventPallete_44, 0x112F},
		{gObjectEventPallete_45, 0x1130},
		{gObjectEventPallete_46, 0x1131},
		{gObjectEventPallete_47, 0x1132},
		{gObjectEventPallete_48, 0x1133},
		{gObjectEventPallete_49, 0x1134},
		{gObjectEventPallete_50, 0x1135},
		{gObjectEventPallete_51, 0x1136},
		{gObjectEventPallete_52, 0x1137},
		{gObjectEventPallete_53, 0x1138},
		{gObjectEventPallete_54, 0x1139},
		{gObjectEventPallete_55, 0x113A},
		{gObjectEventPallete_56, 0x113B},
		{gObjectEventPallete_57, 0x113C},
		{gObjectEventPallete_58, 0x113D},
		{gObjectEventPallete_59, 0x113E},
		{gObjectEventPallete_60, 0x113F},
		{gObjectEventPallete_61, 0x1140},
		{gObjectEventPallete_62, 0x1141},
		{gObjectEventPallete_63, 0x1142},
		{gObjectEventPallete_64, 0x1143},
		{gObjectEventPallete_65, 0x1144},
		{gObjectEventPallete_66, 0x1145},
		{gObjectEventPallete_67, 0x1146},
		{gObjectEventPallete_68, 0x1147},
		{gObjectEventPallete_69, 0x1148},
		{gObjectEventPallete_70, 0x1149},
		{gObjectEventPallete_71, 0x114A},
		{gObjectEventPallete_72, 0x114B},
		{gObjectEventPallete_73, 0x114C},
		{gObjectEventPallete_74, 0x114D},
		{gObjectEventPallete_75, 0x114E},
		{NULL, 0x11FF}
	};

	static const struct SpritePalette gObjectEventSpritePalettes12[] = {
		{gFollowerMonPic0001_BulbasaurPal, 0x1200},
		{gFollowerMonPic0002_IvysaurPal, 0x1201},
		{gFollowerMonPic0003_VenusaurPal, 0x1202},
		{gFollowerMonPic0004_CharmanderPal, 0x1203},
		{gFollowerMonPic0005_CharmeleonPal, 0x1204},
		{gFollowerMonPic0006_CharizardPal, 0x1205},
		{gFollowerMonPic0007_SquirtlePal, 0x1206},
		{gFollowerMonPic0008_WartortlePal, 0x1207},
		{gFollowerMonPic0009_BlastoisePal, 0x1208},
		{gFollowerMonPic0152_ChikoritaPal, 0x1209},
		{gFollowerMonPic0153_BayleefPal, 0x120A},
		{gFollowerMonPic0154_MeganiumPal, 0x120B},
		{gFollowerMonPic0155_CyndaquilPal, 0x120C},
		{gFollowerMonPic0156_QuilavaPal, 0x120D},
		{gFollowerMonPic0157_TyphlosionPal, 0x120E},
		{gFollowerMonPic0158_TotodilePal, 0x120F},
		{gFollowerMonPic0159_CroconawPal, 0x1210},
		{gFollowerMonPic0160_FeraligatrPal, 0x1211},
		{gFollowerMonPic0252_TreeckoPal,  0x1212},
		{gFollowerMonPic0253_GrovylePal,  0x1213},
		{gFollowerMonPic0254_SceptilePal, 0x1214},
		{gFollowerMonPic0255_TorchicPal,  0x1215},
		{gFollowerMonPic0256_CombuskenPal,0x1216},
		{gFollowerMonPic0257_BlazikenPal, 0x1217},
		{gFollowerMonPic0258_MudkipPal,   0x1218},
		{gFollowerMonPic0259_MarshtompPal,0x1219},
		{gFollowerMonPic0260_SwampertPal, 0x121A},
		{gFollowerMonPic0258_MudkipPal,    0x1218},
		{gFollowerMonPic0259_MarshtompPal, 0x1219},
		{gFollowerMonPic0260_SwampertPal,  0x121A},
		{gFollowerMonPic0387_TurtwigPal,   0x121B},
		{gFollowerMonPic0388_GrotlePal,    0x121C},
		{gFollowerMonPic0389_TorterraPal,  0x121D},
		{gFollowerMonPic0390_ChimcharPal,  0x121E},
		{gFollowerMonPic0391_MonfernoPal,  0x121F},
		{gFollowerMonPic0392_InfernapePal, 0x1220},
		{gFollowerMonPic0393_PiplupPal,    0x1221},
		{gFollowerMonPic0394_PrinplupPal,  0x1222},
		{gFollowerMonPic0395_EmpoleonPal,  0x1223},
		{gFollowerMonPic0495_SnivyPal,      0x1224},
		{gFollowerMonPic0496_ServinePal,    0x1225},
		{gFollowerMonPic0497_SerperiorPal,  0x1226},
		{gFollowerMonPic0498_TepigPal,      0x1227},
		{gFollowerMonPic0499_PignitePal,    0x1228},
		{gFollowerMonPic0500_EmboarPal,     0x1229},
		{gFollowerMonPic0501_OshawottPal,   0x122A},
		{gFollowerMonPic0502_DewottPal,     0x122B},
		{gFollowerMonPic0503_SamurottPal,   0x122C},
		{gFollowerMonPic0650_ChespinPal,    0x122D},
		{gFollowerMonPic0651_QuilladinPal,  0x122E},
		{gFollowerMonPic0652_ChesnaughtPal, 0x122F},
		{gFollowerMonPic0653_FennekinPal,   0x1230},
		{gFollowerMonPic0654_BraixenPal,    0x1231},
		{gFollowerMonPic0655_DelphoxPal,    0x1232},
		{gFollowerMonPic0656_FroakiePal,    0x1233},
		{gFollowerMonPic0657_FrogadierPal,  0x1234},
		{gFollowerMonPic0658_GreninjaPal,   0x1235},
		{gFollowerMonPic0722_RowletPal,     0x1236},
		{gFollowerMonPic0723_DartrixPal,    0x1237},
		{gFollowerMonPic0724_DecidueyePal,  0x1238},
		{gFollowerMonPic0725_LittenPal,     0x1239},
		{gFollowerMonPic0726_TorracatPal,   0x123A},
		{gFollowerMonPic0727_IncineroarPal, 0x123B},
		{gFollowerMonPic0728_PopplioPal,    0x123C},
		{gFollowerMonPic0729_BrionnePal,    0x123D},
		{gFollowerMonPic0730_PrimarinaPal,  0x123E},
		{gFollowerMonPic0810_GrookeyPal,    0x123F},
		{gFollowerMonPic0811_ThwackeyPal,   0x1240},
		{gFollowerMonPic0812_RillaboomPal,  0x1241},
		{gFollowerMonPic0813_ScorbunnyPal,  0x1242},
		{gFollowerMonPic0814_RabootPal,     0x1243},
		{gFollowerMonPic0815_CinderacePal,  0x1244},
		{gFollowerMonPic0816_SobblePal,     0x1245},
		{gFollowerMonPic0817_DrizzilePal,   0x1246},
		{gFollowerMonPic0818_InteleonPal,   0x1247},
		{gFollowerMonPic0906_SprigatitoPal, 0x1248},
		{gFollowerMonPic0907_FloragatoPal,  0x1249},
		{gFollowerMonPic0908_MeowscaradaPal,0x124A},
		{gFollowerMonPic0909_FuecocoPal,    0x124B},
		{gFollowerMonPic0910_CrocalorPal,   0x124C},
		{gFollowerMonPic0911_SkeledirgePal, 0x124D},
		{gFollowerMonPic0912_QuaxlyPal,     0x124E},
		{gFollowerMonPic0913_QuaxwellPal,   0x124F},
		{gFollowerMonPic0914_QuaquavalPal,  0x1250},
		// Shiny
		{gFollowerMonPic0915_BulbasaurShinyPal, 0x1251},
		{NULL, 0x11FF}
	};
	
	const struct SpritePalette* const gObjectEventSpritePalettesSwitcher[255] =
	{
		[0x11] = gObjectEventSpritePalettes11,
		[0x12] = gObjectEventSpritePalettes12,
	};
#endif

struct PlayerGraphics
{
	u16 graphicsId;
	u8 stateFlag;
};

static const struct PlayerGraphics sPlayerAvatarGfxIds[][2] =
{
	[PLAYER_AVATAR_STATE_NORMAL] =     {{EVENT_OBJ_GFX_RED_NORMAL, PLAYER_AVATAR_FLAG_ON_FOOT},          {EVENT_OBJ_GFX_LEAF_NORMAL, PLAYER_AVATAR_FLAG_ON_FOOT}},
	[PLAYER_AVATAR_STATE_BIKE] =       {{EVENT_OBJ_GFX_RED_BIKE, PLAYER_AVATAR_FLAG_BIKE},               {EVENT_OBJ_GFX_LEAF_BIKE, PLAYER_AVATAR_FLAG_BIKE}},
	[PLAYER_AVATAR_STATE_SURFING] =    {{EVENT_OBJ_GFX_RED_SURFING, PLAYER_AVATAR_FLAG_SURFING},         {EVENT_OBJ_GFX_LEAF_SURFING, PLAYER_AVATAR_FLAG_SURFING}},
	[PLAYER_AVATAR_STATE_FIELD_MOVE] = {{EVENT_OBJ_GFX_RED_FIELD_MOVE, PLAYER_AVATAR_FLAG_FIELD_MOVE},   {EVENT_OBJ_GFX_LEAF_FIELD_MOVE, PLAYER_AVATAR_FLAG_FIELD_MOVE}},
	[PLAYER_AVATAR_STATE_FISHING] =    {{EVENT_OBJ_GFX_RED_FISHING, 0},                                  {EVENT_OBJ_GFX_LEAF_FISHING, 0}},
	[PLAYER_AVATAR_STATE_VS_SEEKER] =  {{EVENT_OBJ_GFX_RED_VS_SEEKER, 0},                                {EVENT_OBJ_GFX_LEAF_VS_SEEKER, 0}},
	[PLAYER_AVATAR_STATE_UNDERWATER] = {{EVENT_OBJ_GFX_RED_UNDERWATER, PLAYER_AVATAR_FLAG_UNDERWATER},   {EVENT_OBJ_GFX_LEAF_UNDERWATER, PLAYER_AVATAR_FLAG_UNDERWATER}},
};

//npc_get_type hack for character customization
//hook at 0805F2C8 via r1
NPCPtr GetEventObjectGraphicsInfo(u16 graphicsId)
{
	u16 newId;
	u8 tableId = (graphicsId >> 8) & 0xFF;	// upper byte
	u8 spriteId = graphicsId & 0xFF;		// lower byte

	//Check runtime changeable OWs
	if (tableId == 0xFF && spriteId <= 0xF)
	{
		//Runtime changeable
		newId = VarGet(VAR_RUNTIME_CHANGEABLE + spriteId);
		tableId = (newId >> 8) & 0xFF;	// upper byte
		spriteId = (newId & 0xFF);		// lower byte
	}
	else
	{
		switch (spriteId) {
			case EVENT_OBJ_GFX_RED_BIKE_VS_SEEKER:
			case EVENT_OBJ_GFX_LEAF_BIKE_VS_SEEKER:
				if (tableId == 0) //Actually the Vs. Seeker sprites
				{
					newId = VarGet(VAR_PLAYER_VS_SEEKER_ON_BIKE);
					if (newId != 0) //Actually set to something different
					{
						tableId = (newId >> 8) & 0xFF;	// upper byte
						spriteId = (newId & 0xFF);		// lower byte
					}
				}
				break;
		}

		#ifndef UNBOUND
		if (spriteId > 239 && tableId == 0)
		{
			newId = VarGetEventObjectGraphicsId(spriteId + 16);
			tableId = (newId >> 8) & 0xFF;	// upper byte
			spriteId = (newId & 0xFF);		// lower byte
		}
		#endif
	}

	NPCPtr spriteAddr;
	#ifndef EXISTING_OW_TABLE_ADDRESS
	if (tableId >= NELEMS(gOverworldTableSwitcher)
	|| gOverworldTableSwitcher[tableId] == 0)
		spriteAddr = gOverworldTableSwitcher[0][spriteId];
	else
	#endif
		spriteAddr = gOverworldTableSwitcher[tableId][spriteId];

	if (spriteAddr == NULL)
		spriteAddr = gOverworldTableSwitcher[0][EVENT_OBJ_GFX_LITTLE_BOY];	// first non-player sprite in first table default

	return spriteAddr;
};

NPCPtr GetEventObjectGraphicsInfoByEventObj(struct EventObject* eventObj)
{
	return GetEventObjectGraphicsInfo(GetEventObjectGraphicsId(eventObj));
}

static u16 GetCustomGraphicsIdByState(u8 state)
{
	u16 gfxId = 0;

	switch (state) {
		case PLAYER_AVATAR_STATE_NORMAL:
			gfxId = VarGet(VAR_PLAYER_WALKRUN);
			break;
		case PLAYER_AVATAR_STATE_BIKE:
			gfxId = VarGet(VAR_PLAYER_BIKING);
			break;
		case PLAYER_AVATAR_STATE_SURFING:
			gfxId = VarGet(VAR_PLAYER_SURFING);
			break;
		case PLAYER_AVATAR_STATE_FIELD_MOVE: //HM Use
			gfxId = VarGet(VAR_PLAYER_HM_USE);
			break;
		case PLAYER_AVATAR_STATE_VS_SEEKER:
			gfxId = VarGet(VAR_PLAYER_VS_SEEKER);
			break;
		case PLAYER_AVATAR_STATE_FISHING:
			gfxId = VarGet(VAR_PLAYER_FISHING);
			break;
		case PLAYER_AVATAR_STATE_UNDERWATER:
			gfxId = VarGet(VAR_PLAYER_UNDERWATER);
			break;
	}

	return gfxId;
}

u16 GetPlayerAvatarGraphicsIdByStateIdAndGender(u8 state, u8 gender)
{
	u16 graphicsId = GetCustomGraphicsIdByState(state);
	if (graphicsId != 0)
		return graphicsId;

	return sPlayerAvatarGfxIds[state][gender].graphicsId;
}

u16 GetPlayerAvatarGraphicsIdByStateId(u8 state)
{
	return GetPlayerAvatarGraphicsIdByStateIdAndGender(state, gPlayerAvatar->gender);
}

u8 GetPlayerAvatarStateTransitionByGraphicsId(u16 graphicsId, u8 gender)
{
    for (u8 state = 0; state < NELEMS(sPlayerAvatarGfxIds); ++state)
    {
		u16 customGraphicsId = GetCustomGraphicsIdByState(state);
		if (customGraphicsId == graphicsId)
			graphicsId = sPlayerAvatarGfxIds[state][gender].graphicsId;

        if (sPlayerAvatarGfxIds[state][gender].graphicsId == graphicsId)
            return sPlayerAvatarGfxIds[state][gender].stateFlag;
    }

    return PLAYER_AVATAR_FLAG_ON_FOOT;
}

u16 GetPlayerAvatarGraphicsIdByCurrentState(void)
{
	u8 state = 0;
	u8 gender = gPlayerAvatar->gender;
    u8 flags = gPlayerAvatar->flags;

    for (; state < NELEMS(sPlayerAvatarGfxIds); ++state)
    {
        if (sPlayerAvatarGfxIds[state][gender].stateFlag & flags)
		{
			u16 graphicsId = sPlayerAvatarGfxIds[state][gender].graphicsId;
			u16 customGraphicsId = GetCustomGraphicsIdByState(state);
			if (customGraphicsId != 0)
				graphicsId = customGraphicsId;

			return graphicsId;
		}
    }

    return sPlayerAvatarGfxIds[0][0].graphicsId;
}

u8 GetPlayerAvatarGenderByGraphicsId(u8 gfxId)
{
    for (u8 state = 0; state < NELEMS(sPlayerAvatarGfxIds); ++state)
    {
		for (u8 gender = 0; gender < NELEMS(sPlayerAvatarGfxIds[0]); ++gender)
		{
			if (sPlayerAvatarGfxIds[state][gender].graphicsId == gfxId)
				return gender;

			u16 customGraphicsId = GetCustomGraphicsIdByState(state);
			if (customGraphicsId != 0 && customGraphicsId == gfxId)
				return gSaveBlock2->playerGender;
		}
	}

	return MALE;
}

static void SetPlayerAvatarExtraStateTransition(u16 graphicsId, u8 b)
{
    u8 unk = GetPlayerAvatarStateTransitionByGraphicsId(graphicsId, gPlayerAvatar->gender);
	SetPlayerAvatarTransitionFlags(unk | b);
}

u16 GetEventObjectGraphicsId(struct EventObject* eventObj)
{
	u8 lowerByte = eventObj->graphicsIdLowerByte;
	u8 upperByte = eventObj->graphicsIdUpperByte;

	#ifndef EXISTING_OW_TABLE_ADDRESS
	if (upperByte >= NELEMS(gOverworldTableSwitcher)
	&& upperByte != 0xFF) //Dynamic OW table
		return lowerByte;
	#endif

	if (upperByte == 0xFF && lowerByte <= 0xF)
		return VarGet(VAR_RUNTIME_CHANGEABLE + lowerByte); //Runtime changeable

	return lowerByte | (upperByte << 8);
}

void SetPlayerAvatarEventObjectIdAndObjectId(u8 eventObjectId, u8 spriteId)
{
    gPlayerAvatar->eventObjectId = eventObjectId;
    gPlayerAvatar->spriteId = spriteId;
    gPlayerAvatar->gender = GetPlayerAvatarGenderByGraphicsId(GetEventObjectGraphicsId(&gEventObjects[eventObjectId]));
    SetPlayerAvatarExtraStateTransition(GetEventObjectGraphicsId(&gEventObjects[eventObjectId]), 0x20);
}

static u8 GetColorFromTextColorTableNew(u16 gfxId)
{
	#ifdef UNBOUND
	u8 gender = GetEventObjectGraphicsInfo(gfxId)->gender;
	return gender == MALE ? 0 : gender == FEMALE ? 1 : 2; //Blue, Red, Black
	#else
	return GetColorFromTextColorTable(gfxId);
	#endif
}

u8 ContextNpcGetTextColor(void)
{
	u16 gfxId;

	if (gSpecialVar_TextColor != 0xFF)
	{
		return gSpecialVar_TextColor;
	}
	else if (gSelectedEventObject == 0)
	{
		return 3;
	}
	else
	{
		gfxId = GetEventObjectGraphicsId(&gEventObjects[gSelectedEventObject]);

		#ifndef UNBOUND
		if (gfxId >= EVENT_OBJ_GFX_VAR_0 && gfxId <= 0xFF) //Vanilla dynamic id
			gfxId = VarGetEventObjectGraphicsId(gfxId - EVENT_OBJ_GFX_VAR_0);
		#endif

		return GetColorFromTextColorTableNew(gfxId);
	}
}

// load trainer card sprite based on variables
// 	hook at 810c374 via r2
u8 PlayerGenderToFrontTrainerPicId(u8 gender, bool8 modify)
{
	if (modify != TRUE)
		return gender;

	u16 trainerId = VarGet(VAR_TRAINERCARD_MALE + gender);
	if (trainerId == 0)
		trainerId = TRAINER_PIC_PLAYER_M + gender;

	return trainerId;
};

void InitPlayerAvatar(s16 x, s16 y, u8 direction, u8 gender)
{
	u8 eventObjectId;
	struct EventObject* eventObject;
	struct EventObjectTemplate playerEventObjTemplate = {0};
	u16 graphicsId = GetPlayerAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_NORMAL, gender);

	playerEventObjTemplate.localId = EVENT_OBJ_ID_PLAYER;
	playerEventObjTemplate.graphicsIdLowerByte = graphicsId & 0xFF;
	playerEventObjTemplate.graphicsIdUpperByte = graphicsId >> 8;
	playerEventObjTemplate.x = x - 7;
	playerEventObjTemplate.y = y - 7;
	playerEventObjTemplate.movementType = MOVEMENT_TYPE_PLAYER;

	eventObjectId = SpawnSpecialEventObject(&playerEventObjTemplate);
	eventObject = &gEventObjects[eventObjectId];
	eventObject->isPlayer = 1;
	eventObject->warpArrowSpriteId = CreateWarpArrowSprite();
	EventObjectTurn(eventObject, direction);
	ClearPlayerAvatarInfo();

	gPlayerAvatar->runningState = NOT_MOVING;
	gPlayerAvatar->tileTransitionState = T_NOT_MOVING;
	gPlayerAvatar->eventObjectId = eventObjectId;
	gPlayerAvatar->spriteId = eventObject->spriteId;
	gPlayerAvatar->gender = gender;
	SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_FIELD_MOVE | PLAYER_AVATAR_FLAG_ON_FOOT);
	CreateFollowerAvatar();
}

void PlayerHandleDrawTrainerPic(void)
{
	s16 xPos, yPos;
	u32 trainerPicId = GetBackspriteId();

	if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
	{
		if ((GetBattlerPosition(gActiveBattler) & BIT_FLANK) != B_FLANK_LEFT) // Second mon, on the right.
			xPos = 90;
		else // First mon, on the left.
			xPos = 32;

		yPos = (8 - gTrainerBackPicCoords[trainerPicId].coords) * 4 + 80;
	}

	else
	{
		xPos = 80;
		yPos = (8 - gTrainerBackPicCoords[trainerPicId].coords) * 4 + 80;
	}

	LoadTrainerBackPal(trainerPicId, gActiveBattler);
	SetMultiuseSpriteTemplateToTrainerBack(trainerPicId, GetBattlerPosition(gActiveBattler));
	gBattlerSpriteIds[gActiveBattler] = CreateSprite(&gMultiuseSpriteTemplate[0], xPos, yPos, GetBattlerSpriteSubpriority(gActiveBattler));

	if (IS_DOUBLE_BATTLE)
		gSprites[gBattlerSpriteIds[gActiveBattler]].oam.priority = 0; //So it appears above enemy healthbars

	gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = gActiveBattler;
	gSprites[gBattlerSpriteIds[gActiveBattler]].pos2.x = 240;
	gSprites[gBattlerSpriteIds[gActiveBattler]].data[0] = -3; //-2; //Speed scrolling in
	gSprites[gBattlerSpriteIds[gActiveBattler]].callback = SpriteCB_TrainerSlideIn; //sub_805D7AC in Emerald

	gBattlerControllerFuncs[gActiveBattler] = Player_CompleteOnBattlerSpriteCallbackDummy;
}

void PlayerHandleTrainerSlide(void)
{
	u32 trainerPicId = GetBackspriteId();

	LoadTrainerBackPal(trainerPicId, gActiveBattler);
	SetMultiuseSpriteTemplateToTrainerBack(trainerPicId, GetBattlerPosition(gActiveBattler));
	gBattlerSpriteIds[gActiveBattler] = CreateSprite(&gMultiuseSpriteTemplate[0], 80, (8 - gTrainerBackPicCoords[trainerPicId].coords) * 4 + 80, 30);

	if (IS_DOUBLE_BATTLE)
		gSprites[gBattlerSpriteIds[gActiveBattler]].oam.priority = 0;

	gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = gActiveBattler;
	gSprites[gBattlerSpriteIds[gActiveBattler]].pos2.x = -96;
	gSprites[gBattlerSpriteIds[gActiveBattler]].data[0] = 2;
	gSprites[gBattlerSpriteIds[gActiveBattler]].callback = SpriteCB_TrainerSlideIn;

	gBattlerControllerFuncs[gActiveBattler] = Player_CompleteOnBattlerSpriteCallbackDummy2;
}

u16 GetBackspriteId(void)
{
	u16 trainerPicId;

	if (gBattleTypeFlags & BATTLE_TYPE_LINK)
	{
		if ((gLinkPlayers[GetMultiplayerId()].version & 0xFF) == VERSION_FIRE_RED
		|| (gLinkPlayers[GetMultiplayerId()].version & 0xFF) == VERSION_LEAF_GREEN)
			trainerPicId = gLinkPlayers[GetMultiplayerId()].gender;
		else
			trainerPicId = gLinkPlayers[GetMultiplayerId()].gender + BACK_PIC_BRENDAN;
	}
	else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gActiveBattler == 2)
	{
		trainerPicId = LoadPartnerBackspriteIndex();
	}
	else if (IsAIControlledBattle())
	{
		trainerPicId = LoadPartnerBackspriteIndex(); //The trainer's backsprite for the Battle Sands is stored in the multi partner var
	}
	else
	{
		if (VarGet(VAR_BACKSPRITE_SWITCH))
			trainerPicId = VarGet(VAR_BACKSPRITE_SWITCH);
		else
			trainerPicId = gSaveBlock2->playerGender;
	}

	return trainerPicId;
}

#ifdef UNBOUND
bool8 IsPaletteTagAffectedByCharacterCustomization(u16 tag)
{
	switch (tag)
	{
		case EVENT_OBJ_PAL_TAG_DEFAULT:
		case EVENT_OBJ_PAL_TAG_MOM:
		case EVENT_OBJ_PAL_TAG_AROS:
		case EVENT_OBJ_PAL_TAG_RED_PLAYER:
		case EVENT_OBJ_PAL_TAG_LEAF_PLAYER:
		case EVENT_OBJ_PAL_TAG_ETHAN_PLAYER:
		case EVENT_OBJ_PAL_TAG_LYRA_PLAYER:
		case EVENT_OBJ_PAL_TAG_LUCAS_PLAYER:
		case EVENT_OBJ_PAL_TAG_DAWN_PLAYER:
		case EVENT_OBJ_PAL_TAG_SHADOW_GRUNT_PLAYER:
		case EVENT_OBJ_PAL_TAG_MARLON_PLAYER:
		case EVENT_OBJ_PAL_TAG_PLAYER_CHAMPION:
			return TRUE;
		default:
			return FALSE;
	}
}

static bool8 IsPaletteTagAffectedBySkinCharacterCustomization(unusedArg u16 tag)
{
	return tag != EVENT_OBJ_PAL_TAG_MARLON_PLAYER;
}

static bool8 IsPaletteTagAffectedByHairCharacterCustomization(u16 tag)
{
	return tag != EVENT_OBJ_PAL_TAG_AROS
		&& tag != EVENT_OBJ_PAL_TAG_MARLON_PLAYER;
}

static u8 GetOutfitStyleByEventObjTag(u16 tag)
{
	switch (tag)
	{
		case EVENT_OBJ_PAL_TAG_DEFAULT:
			return OUTFIT_STYLE_DEFAULT;
		case EVENT_OBJ_PAL_TAG_PLAYER_CHAMPION:
			return OUTFIT_STYLE_CHAMPION;
		case EVENT_OBJ_PAL_TAG_MARLON_PLAYER:
			return OUTFIT_STYLE_MARLON;
		default:
			return OUTFIT_STYLE_NONE;
	}
}

#define SKIN_TONE_OFFSET 1
#define HAIR_COLOUR_OFFSET 4
#define OUTFIT_OFFSET 7
#define DEFAULT_TRIM_OFFSET (OUTFIT_OFFSET + 2)
static void ChangePlayerPaletteByPaletteAndOffset(u16 paletteOffset, bool8 changeSkin, bool8 changeHair, u8 outfitStyle)
{
	u16 skinTone = VarGet(VAR_PLAYER_SKIN_TONE);
	u16 hairColour = VarGet(VAR_PLAYER_HAIR_COLOUR);

	if (changeSkin && skinTone > 0 && skinTone < NELEMS(sPlayerSkinColours))
	{
		u16 skinOffset = paletteOffset + SKIN_TONE_OFFSET;
		CpuCopy16(sPlayerSkinColours[skinTone] + SKIN_TONE_OFFSET, gPlttBufferUnfaded + skinOffset, 3 * sizeof(u16));
		CpuCopy16(sPlayerSkinColours[skinTone] + SKIN_TONE_OFFSET, gPlttBufferFaded + skinOffset, 3 * sizeof(u16));
	}

	if (changeHair && hairColour > 0 && hairColour < NELEMS(sPlayerHairColours))
	{
		u16 hairOffset = paletteOffset + HAIR_COLOUR_OFFSET;
		CpuCopy16(sPlayerHairColours[hairColour] + HAIR_COLOUR_OFFSET, gPlttBufferUnfaded + hairOffset, 3 * sizeof(u16));
		CpuCopy16(sPlayerHairColours[hairColour] + HAIR_COLOUR_OFFSET, gPlttBufferFaded + hairOffset, 3 * sizeof(u16));
	}

	if (outfitStyle != OUTFIT_STYLE_NONE)
	{
		const u16* const* outfitPals;
		const u16* const* trimPals;
		u16 outfitColour, trimColour;
		u32 outfitPalCount, trimPalCount, copyAmount;
		trimColour = 0;

		if (outfitStyle == OUTFIT_STYLE_CHAMPION)
		{
			outfitColour = VarGet(VAR_PLAYER_CHAMPION_OUTFIT_COLOUR);
			trimColour = VarGet(VAR_PLAYER_CHAMPION_TRIM_COLOUR);
			outfitPals = sPlayerChampionOutfitColours;
			outfitPalCount = NELEMS(sPlayerChampionOutfitColours);
			trimPals = sPlayerChampionTrimColours;
			trimPalCount = NELEMS(sPlayerChampionTrimColours);
			copyAmount = 3;
		}
		else if (outfitStyle == OUTFIT_STYLE_MARLON)
		{
			outfitColour = VarGet(VAR_PLAYER_MARLON_OUTFIT_COLOUR);
			outfitPals = sPlayerMarlonOutfitColours;
			outfitPalCount = NELEMS(sPlayerMarlonOutfitColours);
			copyAmount = 3;
		}
		else
		{
			//Default outfit
			outfitColour = VarGet(VAR_PLAYER_OUTFIT_COLOUR);
			trimColour = VarGet(VAR_PLAYER_TRIM_COLOUR);
			outfitPals = sPlayerOutfitColours;
			outfitPalCount = NELEMS(sPlayerOutfitColours);
			trimPals = sPlayerTrimColours;
			trimPalCount = NELEMS(sPlayerTrimColours);
			copyAmount = 2;
		}

		if (outfitColour > 0 && outfitColour < outfitPalCount)
		{
			u16 outfitOffset = paletteOffset + OUTFIT_OFFSET;
			CpuCopy16(outfitPals[outfitColour] + OUTFIT_OFFSET, gPlttBufferUnfaded + outfitOffset, copyAmount * sizeof(u16));
			CpuCopy16(outfitPals[outfitColour] + OUTFIT_OFFSET, gPlttBufferFaded + outfitOffset, copyAmount * sizeof(u16));
		}

		if (trimColour > 0 && trimColour < trimPalCount)
		{
			u8 baseTrimOffset = OUTFIT_OFFSET + copyAmount;
			u16 trimOffset = paletteOffset + baseTrimOffset;
			CpuCopy16(trimPals[trimColour] + baseTrimOffset, gPlttBufferUnfaded + trimOffset, 2 * sizeof(u16));
			CpuCopy16(trimPals[trimColour] + baseTrimOffset, gPlttBufferFaded + trimOffset, 2 * sizeof(u16));
		}
	}
}
#endif

void ChangeEventObjPal(unusedArg u16 paletteOffset, unusedArg u16 palTag)
{
	#ifdef UNBOUND
	ChangePlayerPaletteByPaletteAndOffset(paletteOffset, IsPaletteTagAffectedBySkinCharacterCustomization(palTag),
	                                                     IsPaletteTagAffectedByHairCharacterCustomization(palTag),
	                                                     GetOutfitStyleByEventObjTag(palTag));
	#endif
}

void ChangeTrainerPicPal(unusedArg u16 paletteOffset, unusedArg u8 outfitStyle)
{
	#ifdef UNBOUND
	if (outfitStyle == OUTFIT_STYLE_MARLON)
		ChangePlayerPaletteByPaletteAndOffset(paletteOffset, FALSE, FALSE, outfitStyle); //Just outfit, no skin and hair
	else
		ChangePlayerPaletteByPaletteAndOffset(paletteOffset, TRUE, TRUE, outfitStyle);
	#endif
}

void ChangeTrainerBackPal(unusedArg u16 backPicId, unusedArg u8 palSot)
{
	#ifdef UNBOUND
	//Dynamically changes the palette of the player character in Unbound
	switch (backPicId)
	{
		case TRAINER_BACK_PIC_RED: //Player M
		case TRAINER_BACK_PIC_LEAF: //Player F
			ChangeTrainerPicPal(0x100 + palSot * 16, OUTFIT_STYLE_DEFAULT); //All colours
			break;
		case TRAINER_BACK_PIC_PLAYER_CHAMPION_M:
		case TRAINER_BACK_PIC_PLAYER_CHAMPION_F:
			ChangeTrainerPicPal(0x100 + palSot * 16, OUTFIT_STYLE_CHAMPION); //All colours
			break;
		case TRAINER_BACK_PIC_MARLON_PLAYER_M:
		case TRAINER_BACK_PIC_MARLON_PLAYER_F:
		case TRAINER_BACK_PIC_IVORY_PLAYER_M:
		case TRAINER_BACK_PIC_IVORY_PLAYER_F:
			ChangePlayerPaletteByPaletteAndOffset(0x100 + palSot * 16, TRUE, FALSE, OUTFIT_STYLE_MARLON); //Just skin and outfit - no hair
			break;
		case TRAINER_BACK_PIC_RED_PLAYER:
		case TRAINER_BACK_PIC_LEAF_PLAYER:
		case TRAINER_BACK_PIC_ETHAN_PLAYER:
		case TRAINER_BACK_PIC_LYRA_PLAYER:
		case TRAINER_BACK_PIC_LUCAS_PLAYER:
		case TRAINER_BACK_PIC_DAWN_PLAYER:
			ChangePlayerPaletteByPaletteAndOffset(0x100 + palSot * 16, TRUE, TRUE, OUTFIT_STYLE_NONE); //Just skin & hair
			break;
	}
	#endif
}

void LoadTrainerBackPal(u16 backPicId, u8 battlerId)
{
	DecompressTrainerBackPalette(backPicId, battlerId);
	ChangeTrainerBackPal(backPicId, battlerId);
}

const u8* GetTrainerSpritePal(u16 trainerPicId)
{
	return gTrainerFrontPicPaletteTable[trainerPicId].data;
}

#ifdef UNBOUND
static bool8 IsTrainerPicAffectedByCustomization(u16 trainerPicId)
{
	return trainerPicId == TRAINER_PIC_PLAYER_M
		|| trainerPicId == TRAINER_PIC_PLAYER_F
		|| trainerPicId == TRAINER_PIC_PLAYER_CHAMPION_M
		|| trainerPicId == TRAINER_PIC_PLAYER_CHAMPION_F
		|| trainerPicId == TRAINER_PIC_PLAYER_MARLON_M
		|| trainerPicId == TRAINER_PIC_PLAYER_MARLON_F
		|| trainerPicId == TRAINER_PIC_PLAYER_RED
		|| trainerPicId == TRAINER_PIC_PLAYER_LEAF
		|| trainerPicId == TRAINER_PIC_PLAYER_ETHAN
		|| trainerPicId == TRAINER_PIC_PLAYER_LYRA;
}

u8 GetOutfitStyleByTrainerPic(u16 trainerPicId)
{
	if (trainerPicId == TRAINER_PIC_PLAYER_CHAMPION_M
	|| trainerPicId == TRAINER_PIC_PLAYER_CHAMPION_F)
	{
		return OUTFIT_STYLE_CHAMPION;
	}
	else if (trainerPicId == TRAINER_PIC_PLAYER_M
		|| trainerPicId == TRAINER_PIC_PLAYER_F)
	{
		return OUTFIT_STYLE_DEFAULT;
	}
	else if (trainerPicId == TRAINER_PIC_PLAYER_MARLON_M
	|| trainerPicId == TRAINER_PIC_PLAYER_MARLON_F)
	{
		return OUTFIT_STYLE_MARLON;
	}

	return OUTFIT_STYLE_NONE;
}
#endif

void TryUpdateTrainerPicPalTrainerCard(u16 trainerPicId, u16 palOffset)
{
	LoadCompressedPalette(GetTrainerSpritePal(trainerPicId), palOffset * 16, 0x20);
	#ifdef UNBOUND
	if (IsTrainerPicAffectedByCustomization(trainerPicId))
	{
		u32 offset = palOffset * 16;
		ChangeTrainerPicPal(offset, GetOutfitStyleByTrainerPic(trainerPicId));
	}
	#endif
}

u16 CreateTrainerPicSprite(u16 species, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag)
{
    u16 spriteId = CreatePicSprite_HandleDeoxys(species, 0, 0, isFrontPic, x, y, paletteSlot, paletteTag, TRUE);
	#ifdef UNBOUND
	if (isFrontPic && IsTrainerPicAffectedByCustomization(species))
	{
		u32 offset = 0x100 + gSprites[spriteId].oam.paletteNum * 16;
		ChangeTrainerPicPal(offset, GetOutfitStyleByTrainerPic(species));
	}
	#endif
	return spriteId;
}

void TryModifyMugshotTrainerPicPal(unusedArg u16 trainerPicId, unusedArg u8 index)
{
	#ifdef UNBOUND
	if (IsTrainerPicAffectedByCustomization(trainerPicId)) //Is player sprite
	{
		if (index != 0xFF)
		{
			u32 offset = 0x100 + index * 16;
			ChangeTrainerPicPal(offset, GetOutfitStyleByTrainerPic(trainerPicId));
		}
	}
	#endif
}

void TryUpdateRegionMapIconPal(void)
{
	#ifdef UNBOUND
	u8 paletteSlot = IndexOfSpritePaletteTag(1);
	if (paletteSlot != 0xFF)
		ChangeEventObjPal(0x100 + paletteSlot * 16, EVENT_OBJ_PAL_TAG_DEFAULT);
	#endif
}
