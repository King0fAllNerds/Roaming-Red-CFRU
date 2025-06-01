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
extern const struct EventObjectGraphicsInfo gFollowerMonGfxTable1[];

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
	&gFollowerMonGfxTable0[82],
	&gFollowerMonGfxTable0[83],
	&gFollowerMonGfxTable0[84],
	&gFollowerMonGfxTable0[85],
	&gFollowerMonGfxTable0[86],
	&gFollowerMonGfxTable0[87],
	&gFollowerMonGfxTable0[88],
	&gFollowerMonGfxTable0[89],
	&gFollowerMonGfxTable0[90],
	&gFollowerMonGfxTable0[91],
	&gFollowerMonGfxTable0[92],
	&gFollowerMonGfxTable0[93],
	&gFollowerMonGfxTable0[94],
	&gFollowerMonGfxTable0[95],
	&gFollowerMonGfxTable0[96],
	&gFollowerMonGfxTable0[97],
	&gFollowerMonGfxTable0[98],
	&gFollowerMonGfxTable0[99],
	&gFollowerMonGfxTable0[100],
	&gFollowerMonGfxTable0[101],
	&gFollowerMonGfxTable0[102],
	&gFollowerMonGfxTable0[103],
	&gFollowerMonGfxTable0[104],
	&gFollowerMonGfxTable0[105],
	&gFollowerMonGfxTable0[106],
	&gFollowerMonGfxTable0[107],
	&gFollowerMonGfxTable0[108],
	&gFollowerMonGfxTable0[109],
	&gFollowerMonGfxTable0[110],
	&gFollowerMonGfxTable0[111],
	&gFollowerMonGfxTable0[112],
	&gFollowerMonGfxTable0[113],
	&gFollowerMonGfxTable0[114],
	&gFollowerMonGfxTable0[115],
	&gFollowerMonGfxTable0[116],
	&gFollowerMonGfxTable0[117],
	&gFollowerMonGfxTable0[118],
	&gFollowerMonGfxTable0[119],
	&gFollowerMonGfxTable0[120],
	&gFollowerMonGfxTable0[121],
	&gFollowerMonGfxTable0[122],
	&gFollowerMonGfxTable0[123],
	&gFollowerMonGfxTable0[124],
	&gFollowerMonGfxTable0[125],
	&gFollowerMonGfxTable0[126],
	&gFollowerMonGfxTable0[127],
	&gFollowerMonGfxTable0[128],
	&gFollowerMonGfxTable0[129],
	&gFollowerMonGfxTable0[130],
	&gFollowerMonGfxTable0[131],
	&gFollowerMonGfxTable0[132],
	&gFollowerMonGfxTable0[133],
	&gFollowerMonGfxTable0[134],
	&gFollowerMonGfxTable0[135],
	&gFollowerMonGfxTable0[136],
	&gFollowerMonGfxTable0[137],
	&gFollowerMonGfxTable0[138],
	&gFollowerMonGfxTable0[139],
	&gFollowerMonGfxTable0[140],
	&gFollowerMonGfxTable0[141],
	&gFollowerMonGfxTable0[142],
	&gFollowerMonGfxTable0[143],
	&gFollowerMonGfxTable0[144],
	&gFollowerMonGfxTable0[145],
	&gFollowerMonGfxTable0[146],
	&gFollowerMonGfxTable0[147],
	&gFollowerMonGfxTable0[148],
	&gFollowerMonGfxTable0[149],
	&gFollowerMonGfxTable0[150],

};
static NPCPtr sOverworldTable3[] =
{
	&gFollowerMonGfxTable1[0],
	&gFollowerMonGfxTable1[1],
	&gFollowerMonGfxTable1[2],
	&gFollowerMonGfxTable1[3],
	&gFollowerMonGfxTable1[4],
	&gFollowerMonGfxTable1[5],
	&gFollowerMonGfxTable1[6],
	&gFollowerMonGfxTable1[7],
	&gFollowerMonGfxTable1[8],
	&gFollowerMonGfxTable1[9],
	&gFollowerMonGfxTable1[10],
	&gFollowerMonGfxTable1[11],
	&gFollowerMonGfxTable1[12],
	&gFollowerMonGfxTable1[13],
	&gFollowerMonGfxTable1[14],
	&gFollowerMonGfxTable1[15],
	&gFollowerMonGfxTable1[16],
	&gFollowerMonGfxTable1[17],
	&gFollowerMonGfxTable1[18],
	&gFollowerMonGfxTable1[19],
	&gFollowerMonGfxTable1[20],
	&gFollowerMonGfxTable1[21],
	&gFollowerMonGfxTable1[22],
	&gFollowerMonGfxTable1[23],
	&gFollowerMonGfxTable1[24],
	&gFollowerMonGfxTable1[25],
	&gFollowerMonGfxTable1[26],
	&gFollowerMonGfxTable1[27],
	&gFollowerMonGfxTable1[28],
	&gFollowerMonGfxTable1[29],
	&gFollowerMonGfxTable1[30],
	&gFollowerMonGfxTable1[31],
	&gFollowerMonGfxTable1[32],
	&gFollowerMonGfxTable1[33],
	&gFollowerMonGfxTable1[34],
	&gFollowerMonGfxTable1[35],
	&gFollowerMonGfxTable1[36],
	&gFollowerMonGfxTable1[37],
	&gFollowerMonGfxTable1[38],
	&gFollowerMonGfxTable1[39],
	&gFollowerMonGfxTable1[40],
	&gFollowerMonGfxTable1[41],
	&gFollowerMonGfxTable1[42],
	&gFollowerMonGfxTable1[43],
	&gFollowerMonGfxTable1[44],
	&gFollowerMonGfxTable1[45],
	&gFollowerMonGfxTable1[46],
	&gFollowerMonGfxTable1[47],
	&gFollowerMonGfxTable1[48],
	&gFollowerMonGfxTable1[49],
	&gFollowerMonGfxTable1[50],
	&gFollowerMonGfxTable1[51],
	&gFollowerMonGfxTable1[52],
	&gFollowerMonGfxTable1[53],
	&gFollowerMonGfxTable1[54],
	&gFollowerMonGfxTable1[55],
	&gFollowerMonGfxTable1[56],
	&gFollowerMonGfxTable1[57],
	&gFollowerMonGfxTable1[58],
	&gFollowerMonGfxTable1[59],
	&gFollowerMonGfxTable1[60],
	&gFollowerMonGfxTable1[61],
	&gFollowerMonGfxTable1[62],
	&gFollowerMonGfxTable1[63],
	&gFollowerMonGfxTable1[64],
	&gFollowerMonGfxTable1[65],
	&gFollowerMonGfxTable1[66],
	&gFollowerMonGfxTable1[67],
	&gFollowerMonGfxTable1[68],
	&gFollowerMonGfxTable1[69],
	&gFollowerMonGfxTable1[70],
	&gFollowerMonGfxTable1[71],
	&gFollowerMonGfxTable1[72],
	&gFollowerMonGfxTable1[73],
	&gFollowerMonGfxTable1[74],
	&gFollowerMonGfxTable1[75],
	&gFollowerMonGfxTable1[76],
	&gFollowerMonGfxTable1[77],
	&gFollowerMonGfxTable1[78],
	&gFollowerMonGfxTable1[79],
	&gFollowerMonGfxTable1[80],
	&gFollowerMonGfxTable1[81],
	&gFollowerMonGfxTable1[82],
	&gFollowerMonGfxTable1[83],
	&gFollowerMonGfxTable1[84],
	&gFollowerMonGfxTable1[85],
	&gFollowerMonGfxTable1[86],
	&gFollowerMonGfxTable1[87],
	&gFollowerMonGfxTable1[88],
	&gFollowerMonGfxTable1[89],
	&gFollowerMonGfxTable1[90],
	&gFollowerMonGfxTable1[91],
	&gFollowerMonGfxTable1[92],
	&gFollowerMonGfxTable1[93],
	&gFollowerMonGfxTable1[94],
	&gFollowerMonGfxTable1[95],
	&gFollowerMonGfxTable1[96],
	&gFollowerMonGfxTable1[97],
	&gFollowerMonGfxTable1[98],
	&gFollowerMonGfxTable1[99],
	&gFollowerMonGfxTable1[100],
	&gFollowerMonGfxTable1[101],
	&gFollowerMonGfxTable1[102],
	&gFollowerMonGfxTable1[103],
	&gFollowerMonGfxTable1[104],
	&gFollowerMonGfxTable1[105],
	&gFollowerMonGfxTable1[106],
	&gFollowerMonGfxTable1[107],
	&gFollowerMonGfxTable1[108],
	&gFollowerMonGfxTable1[109],
	&gFollowerMonGfxTable1[110],
	&gFollowerMonGfxTable1[111],
	&gFollowerMonGfxTable1[112],
	&gFollowerMonGfxTable1[113],
	&gFollowerMonGfxTable1[114],
	&gFollowerMonGfxTable1[115],
	&gFollowerMonGfxTable1[116],
	&gFollowerMonGfxTable1[117],
	&gFollowerMonGfxTable1[118],
	&gFollowerMonGfxTable1[119],
	&gFollowerMonGfxTable1[120],
	&gFollowerMonGfxTable1[121],
	&gFollowerMonGfxTable1[122],
	&gFollowerMonGfxTable1[123],
	&gFollowerMonGfxTable1[124],
	&gFollowerMonGfxTable1[125],
	&gFollowerMonGfxTable1[126],
	&gFollowerMonGfxTable1[127],
	&gFollowerMonGfxTable1[128],
	&gFollowerMonGfxTable1[129],
	&gFollowerMonGfxTable1[130],
	&gFollowerMonGfxTable1[131],
	&gFollowerMonGfxTable1[132],
	&gFollowerMonGfxTable1[133],
	&gFollowerMonGfxTable1[134],
	&gFollowerMonGfxTable1[135],
	&gFollowerMonGfxTable1[136],
	&gFollowerMonGfxTable1[137],
	&gFollowerMonGfxTable1[138],
	&gFollowerMonGfxTable1[139],
	&gFollowerMonGfxTable1[140],
	&gFollowerMonGfxTable1[141],
	&gFollowerMonGfxTable1[142],
	&gFollowerMonGfxTable1[143],
	&gFollowerMonGfxTable1[144],
	&gFollowerMonGfxTable1[145],
	&gFollowerMonGfxTable1[146],
	&gFollowerMonGfxTable1[147],
	&gFollowerMonGfxTable1[148],
	&gFollowerMonGfxTable1[149],
	&gFollowerMonGfxTable1[150],

};


	// create 255 OW tables
	const struct EventObjectGraphicsInfo** const gOverworldTableSwitcher[255] =
	{
		(NPCPtr*) 0x839FDB0,
		sOverworldTable2,
		sOverworldTable3,
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
		{gFollowerMonPic0010_CaterpiePal, 0x1209},
		{gFollowerMonPic0011_MetapodPal, 0x120A},
		{gFollowerMonPic0012_ButterfreePal, 0x120B},
		{gFollowerMonPic0013_WeedlePal, 0x120C},
		{gFollowerMonPic0014_KakunaPal, 0x120D},
		{gFollowerMonPic0015_BeedrillPal, 0x120E},
		{gFollowerMonPic0016_PidgeyPal, 0x120F},
		{gFollowerMonPic0017_PidgeottoPal, 0x1210},
		{gFollowerMonPic0018_PidgeotPal, 0x1211},
		{gFollowerMonPic0019_RattataPal, 0x1212},
		{gFollowerMonPic0020_RaticatePal, 0x1213},
		{gFollowerMonPic0021_SpearowPal, 0x1214},
		{gFollowerMonPic0022_FearowPal, 0x1215},
		{gFollowerMonPic0023_EkansPal, 0x1216},
		{gFollowerMonPic0024_ArbokPal, 0x1217},
		{gFollowerMonPic0025_PikachuPal, 0x1218},
		{gFollowerMonPic0026_RaichuPal, 0x1219},
		{gFollowerMonPic0027_SandshrewPal, 0x121A},
		{gFollowerMonPic0028_SandslashPal, 0x121B},
		{gFollowerMonPic0029_NidoranFPal, 0x121C},
		{gFollowerMonPic0030_NidorinaPal, 0x121D},
		{gFollowerMonPic0031_NidoqueenPal, 0x121E},
		{gFollowerMonPic0032_NidoranMPal, 0x121F},
		{gFollowerMonPic0033_NidorinoPal, 0x1220},
		{gFollowerMonPic0034_NidokingPal, 0x1221},
		{gFollowerMonPic0035_ClefairyPal, 0x1222},
		{gFollowerMonPic0036_ClefablePal, 0x1223},
		{gFollowerMonPic0037_VulpixPal, 0x1224},
		{gFollowerMonPic0038_NinetalesPal, 0x1225},
		{gFollowerMonPic0039_JigglypuffPal, 0x1226},
		{gFollowerMonPic0040_WigglytuffPal, 0x1227},
		{gFollowerMonPic0041_ZubatPal, 0x1228},
		{gFollowerMonPic0042_GolbatPal, 0x1229},
		{gFollowerMonPic0043_OddishPal, 0x122A},
		{gFollowerMonPic0044_GloomPal, 0x122B},
		{gFollowerMonPic0045_VileplumePal, 0x122C},
		{gFollowerMonPic0046_ParasPal, 0x122D},
		{gFollowerMonPic0047_ParasectPal, 0x122E},
		{gFollowerMonPic0048_VenonatPal, 0x122F},
		{gFollowerMonPic0049_VenomothPal, 0x1230},
		{gFollowerMonPic0050_DiglettPal, 0x1231},
		{gFollowerMonPic0051_DugtrioPal, 0x1232},
		{gFollowerMonPic0052_MeowthPal, 0x1233},
		{gFollowerMonPic0053_PersianPal, 0x1234},
		{gFollowerMonPic0054_PsyduckPal, 0x1235},
		{gFollowerMonPic0055_GolduckPal, 0x1236},
		{gFollowerMonPic0056_MankeyPal, 0x1237},
		{gFollowerMonPic0057_PrimeapePal, 0x1238},
		{gFollowerMonPic0058_GrowlithePal, 0x1239},
		{gFollowerMonPic0059_ArcaninePal, 0x123A},
		{gFollowerMonPic0060_PoliwagPal, 0x123B},
		{gFollowerMonPic0061_PoliwhirlPal, 0x123C},
		{gFollowerMonPic0062_PoliwrathPal, 0x123D},
		{gFollowerMonPic0063_AbraPal, 0x123E},
		{gFollowerMonPic0064_KadabraPal, 0x123F},
		{gFollowerMonPic0065_AlakazamPal, 0x1240},
		{gFollowerMonPic0066_MachopPal, 0x1241},
		{gFollowerMonPic0067_MachokePal, 0x1242},
		{gFollowerMonPic0068_MachampPal, 0x1243},
		{gFollowerMonPic0069_BellsproutPal, 0x1244},
		{gFollowerMonPic0070_WeepinbellPal, 0x1245},
		{gFollowerMonPic0071_VictreebelPal, 0x1246},
		{gFollowerMonPic0072_TentacoolPal, 0x1247},
		{gFollowerMonPic0073_TentacruelPal, 0x1248},
		{gFollowerMonPic0074_GeodudePal, 0x1249},
		{gFollowerMonPic0075_GravelerPal, 0x124A},
		{gFollowerMonPic0076_GolemPal, 0x124B},
		{gFollowerMonPic0077_PonytaPal, 0x124C},
		{gFollowerMonPic0078_RapidashPal, 0x124D},
		{gFollowerMonPic0079_SlowpokePal, 0x124E},
		{gFollowerMonPic0080_SlowbroPal, 0x124F},
		{gFollowerMonPic0081_MagnemitePal, 0x1250},
		{gFollowerMonPic0082_MagnetonPal, 0x1251},
		{gFollowerMonPic0083_FarfetchdPal, 0x1252},
		{gFollowerMonPic0084_DoduoPal, 0x1253},
		{gFollowerMonPic0085_DodrioPal, 0x1254},
		{gFollowerMonPic0086_SeelPal, 0x1255},
		{gFollowerMonPic0087_DewgongPal, 0x1256},
		{gFollowerMonPic0088_GrimerPal, 0x1257},
		{gFollowerMonPic0089_MukPal, 0x1258},
		{gFollowerMonPic0090_ShellderPal, 0x1259},
		{gFollowerMonPic0091_CloysterPal, 0x125A},
		{gFollowerMonPic0092_GastlyPal, 0x125B},
		{gFollowerMonPic0093_HaunterPal, 0x125C},
		{gFollowerMonPic0094_GengarPal, 0x125D},
		{gFollowerMonPic0095_OnixPal, 0x125E},
		{gFollowerMonPic0096_DrowzeePal, 0x125F},
		{gFollowerMonPic0097_HypnoPal, 0x1260},
		{gFollowerMonPic0098_KrabbyPal, 0x1261},
		{gFollowerMonPic0099_KinglerPal, 0x1262},
		{gFollowerMonPic0100_VoltorbPal, 0x1263},
		{gFollowerMonPic0101_ElectrodePal, 0x1264},
		{gFollowerMonPic0102_ExeggcutePal, 0x1265},
		{gFollowerMonPic0103_ExeggutorPal, 0x1266},
		{gFollowerMonPic0104_CubonePal, 0x1267},
		{gFollowerMonPic0105_MarowakPal, 0x1268},
		{gFollowerMonPic0106_HitmonleePal, 0x1269},
		{gFollowerMonPic0107_HitmonchanPal, 0x126A},
		{gFollowerMonPic0108_LickitungPal, 0x126B},
		{gFollowerMonPic0109_KoffingPal, 0x126C},
		{gFollowerMonPic0110_WeezingPal, 0x126D},
		{gFollowerMonPic0111_RhyhornPal, 0x126E},
		{gFollowerMonPic0112_RhydonPal, 0x126F},
		{gFollowerMonPic0113_ChanseyPal, 0x1270},
		{gFollowerMonPic0114_TangelaPal, 0x1271},
		{gFollowerMonPic0115_KangaskhanPal, 0x1272},
		{gFollowerMonPic0116_HorseaPal, 0x1273},
		{gFollowerMonPic0117_SeadraPal, 0x1274},
		{gFollowerMonPic0118_GoldeenPal, 0x1275},
		{gFollowerMonPic0119_SeakingPal, 0x1276},
		{gFollowerMonPic0120_StaryuPal, 0x1277},
		{gFollowerMonPic0121_StarmiePal, 0x1278},
		{gFollowerMonPic0122_MrMimePal, 0x1279},
		{gFollowerMonPic0123_ScytherPal, 0x127A},
		{gFollowerMonPic0124_JynxPal, 0x127B},
		{gFollowerMonPic0125_ElectabuzzPal, 0x127C},
		{gFollowerMonPic0126_MagmarPal, 0x127D},
		{gFollowerMonPic0127_PinsirPal, 0x127E},
		{gFollowerMonPic0128_TaurosPal, 0x127F},
		{gFollowerMonPic0129_MagikarpPal, 0x1280},
		{gFollowerMonPic0130_GyaradosPal, 0x1281},
		{gFollowerMonPic0131_LaprasPal, 0x1282},
		{gFollowerMonPic0132_DittoPal, 0x1283},
		{gFollowerMonPic0133_EeveePal, 0x1284},
		{gFollowerMonPic0134_VaporeonPal, 0x1285},
		{gFollowerMonPic0135_JolteonPal, 0x1286},
		{gFollowerMonPic0136_FlareonPal, 0x1287},
		{gFollowerMonPic0137_PorygonPal, 0x1288},
		{gFollowerMonPic0138_OmanytePal, 0x1289},
		{gFollowerMonPic0139_OmastarPal, 0x128A},
		{gFollowerMonPic0140_KabutoPal, 0x128B},
		{gFollowerMonPic0141_KabutopsPal, 0x128C},
		{gFollowerMonPic0142_AerodactylPal, 0x128D},
		{gFollowerMonPic0143_SnorlaxPal, 0x128E},
		{gFollowerMonPic0144_ArticunoPal, 0x128F},
		{gFollowerMonPic0145_ZapdosPal, 0x1290},
		{gFollowerMonPic0146_MoltresPal, 0x1291},
		{gFollowerMonPic0147_DratiniPal, 0x1292},
		{gFollowerMonPic0148_DragonairPal, 0x1293},
		{gFollowerMonPic0149_DragonitePal, 0x1294},
		{gFollowerMonPic0150_MewtwoPal, 0x1295},
		{gFollowerMonPic0151_MewPal, 0x1296},
	};
	static const struct SpritePalette gObjectEventSpritePalettes13[] = 	
	{
		{gFollowerMonPic2001_BulbasaurShinyPal, 0x1300},
		{gFollowerMonPic2002_IvysaurShinyPal, 0x1301},
		{gFollowerMonPic2003_VenusaurShinyPal, 0x1302},
		{gFollowerMonPic2004_CharmanderShinyPal, 0x1303},
		{gFollowerMonPic2005_CharmeleonShinyPal, 0x1304},
		{gFollowerMonPic2006_CharizardShinyPal, 0x1305},
		{gFollowerMonPic2007_SquirtleShinyPal, 0x1306},
		{gFollowerMonPic2008_WartortleShinyPal, 0x1307},
		{gFollowerMonPic2009_BlastoiseShinyPal, 0x1308},
		{gFollowerMonPic2010_CaterpieShinyPal, 0x1309},
		{gFollowerMonPic2011_MetapodShinyPal, 0x130A},
		{gFollowerMonPic2012_ButterfreeShinyPal, 0x130B},
		{gFollowerMonPic2013_WeedleShinyPal, 0x130C},
		{gFollowerMonPic2014_KakunaShinyPal, 0x130D},
		{gFollowerMonPic2015_BeedrillShinyPal, 0x130E},
		{gFollowerMonPic2016_PidgeyShinyPal, 0x130F},
		{gFollowerMonPic2017_PidgeottoShinyPal, 0x1310},
		{gFollowerMonPic2018_PidgeotShinyPal, 0x1311},
		{gFollowerMonPic2019_RattataShinyPal, 0x1312},
		{gFollowerMonPic2020_RaticateShinyPal, 0x1313},
		{gFollowerMonPic2021_SpearowShinyPal, 0x1314},
		{gFollowerMonPic2022_FearowShinyPal, 0x1315},
		{gFollowerMonPic2023_EkansShinyPal, 0x1316},
		{gFollowerMonPic2024_ArbokShinyPal, 0x1317},
		{gFollowerMonPic2025_PikachuShinyPal, 0x1318},
		{gFollowerMonPic2026_RaichuShinyPal, 0x1319},
		{gFollowerMonPic2027_SandshrewShinyPal, 0x131A},
		{gFollowerMonPic2028_SandslashShinyPal, 0x131B},
		{gFollowerMonPic2029_NidoranFShinyPal, 0x131C},
		{gFollowerMonPic2030_NidorinaShinyPal, 0x131D},
		{gFollowerMonPic2031_NidoqueenShinyPal, 0x131E},
		{gFollowerMonPic2032_NidoranMShinyPal, 0x131F},
		{gFollowerMonPic2033_NidorinoShinyPal, 0x1320},
		{gFollowerMonPic2034_NidokingShinyPal, 0x1321},
		{gFollowerMonPic2035_ClefairyShinyPal, 0x1322},
		{gFollowerMonPic2036_ClefableShinyPal, 0x1323},
		{gFollowerMonPic2037_VulpixShinyPal, 0x1324},
		{gFollowerMonPic2038_NinetalesShinyPal, 0x1325},
		{gFollowerMonPic2039_JigglypuffShinyPal, 0x1326},
		{gFollowerMonPic2040_WigglytuffShinyPal, 0x1327},
		{gFollowerMonPic2041_ZubatShinyPal, 0x1328},
		{gFollowerMonPic2042_GolbatShinyPal, 0x1329},
		{gFollowerMonPic2043_OddishShinyPal, 0x132A},
		{gFollowerMonPic2044_GloomShinyPal, 0x132B},
		{gFollowerMonPic2045_VileplumeShinyPal, 0x132C},
		{gFollowerMonPic2046_ParasShinyPal, 0x132D},
		{gFollowerMonPic2047_ParasectShinyPal, 0x132E},
		{gFollowerMonPic2048_VenonatShinyPal, 0x132F},
		{gFollowerMonPic2049_VenomothShinyPal, 0x1330},
		{gFollowerMonPic2050_DiglettShinyPal, 0x1331},
		{gFollowerMonPic2051_DugtrioShinyPal, 0x1332},
		{gFollowerMonPic2052_MeowthShinyPal, 0x1333},
		{gFollowerMonPic2053_PersianShinyPal, 0x1334},
		{gFollowerMonPic2054_PsyduckShinyPal, 0x1335},
		{gFollowerMonPic2055_GolduckShinyPal, 0x1336},
		{gFollowerMonPic2056_MankeyShinyPal, 0x1337},
		{gFollowerMonPic2057_PrimeapeShinyPal, 0x1338},
		{gFollowerMonPic2058_GrowlitheShinyPal, 0x1339},
		{gFollowerMonPic2059_ArcanineShinyPal, 0x133A},
		{gFollowerMonPic2060_PoliwagShinyPal, 0x133B},
		{gFollowerMonPic2061_PoliwhirlShinyPal, 0x133C},
		{gFollowerMonPic2062_PoliwrathShinyPal, 0x133D},
		{gFollowerMonPic2063_AbraShinyPal, 0x133E},
		{gFollowerMonPic2064_KadabraShinyPal, 0x133F},
		{gFollowerMonPic2065_AlakazamShinyPal, 0x1340},
		{gFollowerMonPic2066_MachopShinyPal, 0x1341},
		{gFollowerMonPic2067_MachokeShinyPal, 0x1342},
		{gFollowerMonPic2068_MachampShinyPal, 0x1343},
		{gFollowerMonPic2069_BellsproutShinyPal, 0x1344},
		{gFollowerMonPic2070_WeepinbellShinyPal, 0x1345},
		{gFollowerMonPic2071_VictreebelShinyPal, 0x1346},
		{gFollowerMonPic2072_TentacoolShinyPal, 0x1347},
		{gFollowerMonPic2073_TentacruelShinyPal, 0x1348},
		{gFollowerMonPic2074_GeodudeShinyPal, 0x1349},
		{gFollowerMonPic2075_GravelerShinyPal, 0x134A},
		{gFollowerMonPic2076_GolemShinyPal, 0x134B},
		{gFollowerMonPic2077_PonytaShinyPal, 0x134C},
		{gFollowerMonPic2078_RapidashShinyPal, 0x134D},
		{gFollowerMonPic2079_SlowpokeShinyPal, 0x134E},
		{gFollowerMonPic2080_SlowbroShinyPal, 0x134F},
		{gFollowerMonPic2081_MagnemiteShinyPal, 0x1350},
		{gFollowerMonPic2082_MagnetonShinyPal, 0x1351},
		{gFollowerMonPic2083_FarfetchdShinyPal, 0x1352},
		{gFollowerMonPic2084_DoduoShinyPal, 0x1353},
		{gFollowerMonPic2085_DodrioShinyPal, 0x1354},
		{gFollowerMonPic2086_SeelShinyPal, 0x1355},
		{gFollowerMonPic2087_DewgongShinyPal, 0x1356},
		{gFollowerMonPic2088_GrimerShinyPal, 0x1357},
		{gFollowerMonPic2089_MukShinyPal, 0x1358},
		{gFollowerMonPic2090_ShellderShinyPal, 0x1359},
		{gFollowerMonPic2091_CloysterShinyPal, 0x135A},
		{gFollowerMonPic2092_GastlyShinyPal, 0x135B},
		{gFollowerMonPic2093_HaunterShinyPal, 0x135C},
		{gFollowerMonPic2094_GengarShinyPal, 0x135D},
		{gFollowerMonPic2095_OnixShinyPal, 0x135E},
		{gFollowerMonPic2096_DrowzeeShinyPal, 0x135F},
		{gFollowerMonPic2097_HypnoShinyPal, 0x1360},
		{gFollowerMonPic2098_KrabbyShinyPal, 0x1361},
		{gFollowerMonPic2099_KinglerShinyPal, 0x1362},
		{gFollowerMonPic2100_VoltorbShinyPal, 0x1363},
		{gFollowerMonPic2101_ElectrodeShinyPal, 0x1364},
		{gFollowerMonPic2102_ExeggcuteShinyPal, 0x1365},
		{gFollowerMonPic2103_ExeggutorShinyPal, 0x1366},
		{gFollowerMonPic2104_CuboneShinyPal, 0x1367},
		{gFollowerMonPic2105_MarowakShinyPal, 0x1368},
		{gFollowerMonPic2106_HitmonleeShinyPal, 0x1369},
		{gFollowerMonPic2107_HitmonchanShinyPal, 0x136A},
		{gFollowerMonPic2108_LickitungShinyPal, 0x136B},
		{gFollowerMonPic2109_KoffingShinyPal, 0x136C},
		{gFollowerMonPic2110_WeezingShinyPal, 0x136D},
		{gFollowerMonPic2111_RhyhornShinyPal, 0x136E},
		{gFollowerMonPic2112_RhydonShinyPal, 0x136F},
		{gFollowerMonPic2113_ChanseyShinyPal, 0x1370},
		{gFollowerMonPic2114_TangelaShinyPal, 0x1371},
		{gFollowerMonPic2115_KangaskhanShinyPal, 0x1372},
		{gFollowerMonPic2116_HorseaShinyPal, 0x1373},
		{gFollowerMonPic2117_SeadraShinyPal, 0x1374},
		{gFollowerMonPic2118_GoldeenShinyPal, 0x1375},
		{gFollowerMonPic2119_SeakingShinyPal, 0x1376},
		{gFollowerMonPic2120_StaryuShinyPal, 0x1377},
		{gFollowerMonPic2121_StarmieShinyPal, 0x1378},
		{gFollowerMonPic2122_MrMimeShinyPal, 0x1379},
		{gFollowerMonPic2123_ScytherShinyPal, 0x137A},
		{gFollowerMonPic2124_JynxShinyPal, 0x137B},
		{gFollowerMonPic2125_ElectabuzzShinyPal, 0x137C},
		{gFollowerMonPic2126_MagmarShinyPal, 0x137D},
		{gFollowerMonPic2127_PinsirShinyPal, 0x137E},
		{gFollowerMonPic2128_TaurosShinyPal, 0x137F},
		{gFollowerMonPic2129_MagikarpShinyPal, 0x1380},
		{gFollowerMonPic2130_GyaradosShinyPal, 0x1381},
		{gFollowerMonPic2131_LaprasShinyPal, 0x1382},
		{gFollowerMonPic2132_DittoShinyPal, 0x1383},
		{gFollowerMonPic2133_EeveeShinyPal, 0x1384},
		{gFollowerMonPic2134_VaporeonShinyPal, 0x1385},
		{gFollowerMonPic2135_JolteonShinyPal, 0x1386},
		{gFollowerMonPic2136_FlareonShinyPal, 0x1387},
		{gFollowerMonPic2137_PorygonShinyPal, 0x1388},
		{gFollowerMonPic2138_OmanyteShinyPal, 0x1389},
		{gFollowerMonPic2139_OmastarShinyPal, 0x138A},
		{gFollowerMonPic2140_KabutoShinyPal, 0x138B},
		{gFollowerMonPic2141_KabutopsShinyPal, 0x138C},
		{gFollowerMonPic2142_AerodactylShinyPal, 0x138D},
		{gFollowerMonPic2143_SnorlaxShinyPal, 0x138E},
		{gFollowerMonPic2144_ArticunoShinyPal, 0x138F},
		{gFollowerMonPic2145_ZapdosShinyPal, 0x1390},
		{gFollowerMonPic2146_MoltresShinyPal, 0x1391},
		{gFollowerMonPic2147_DratiniShinyPal, 0x1392},
		{gFollowerMonPic2148_DragonairShinyPal, 0x1393},
		{gFollowerMonPic2149_DragoniteShinyPal, 0x1394},
		{gFollowerMonPic2150_MewtwoShinyPal, 0x1395},
		{gFollowerMonPic2151_MewShinyPal, 0x1396},

	};
	
	const struct SpritePalette* const gObjectEventSpritePalettesSwitcher[255] =
	{
		[0x11] = gObjectEventSpritePalettes11,
		[0x12] = gObjectEventSpritePalettes12,
		[0x13] = gObjectEventSpritePalettes13,
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
