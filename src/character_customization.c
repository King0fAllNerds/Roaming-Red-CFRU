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
extern const struct EventObjectGraphicsInfo gFollowerMonGfxTable2[];
extern const struct EventObjectGraphicsInfo gFollowerMonGfxTable3[];

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
    &gFollowerMonGfxTable0[151], // Chikorita
    &gFollowerMonGfxTable0[152], // Bayleef
    &gFollowerMonGfxTable0[153], // Meganium
    &gFollowerMonGfxTable0[154], // Cyndaquil
    &gFollowerMonGfxTable0[155], // Quilava
    &gFollowerMonGfxTable0[156], // Typhlosion
    &gFollowerMonGfxTable0[157], // Totodile
    &gFollowerMonGfxTable0[158], // Croconaw
    &gFollowerMonGfxTable0[159], // Feraligatr
    &gFollowerMonGfxTable0[160], // Sentret
    &gFollowerMonGfxTable0[161], // Furret
    &gFollowerMonGfxTable0[162], // Hoothoot
    &gFollowerMonGfxTable0[163], // Noctowl
    &gFollowerMonGfxTable0[164], // Ledyba
    &gFollowerMonGfxTable0[165], // Ledian
    &gFollowerMonGfxTable0[166], // Spinarak
    &gFollowerMonGfxTable0[167], // Ariados
    &gFollowerMonGfxTable0[168], // Crobat
    &gFollowerMonGfxTable0[169], // Chinchou
    &gFollowerMonGfxTable0[170], // Lanturn
    &gFollowerMonGfxTable0[171], // Pichu
    &gFollowerMonGfxTable0[172], // Cleffa
    &gFollowerMonGfxTable0[173], // Igglybuff
    &gFollowerMonGfxTable0[174], // Togepi
    &gFollowerMonGfxTable0[175], // Togetic
    &gFollowerMonGfxTable0[176], // Natu
    &gFollowerMonGfxTable0[177], // Xatu
    &gFollowerMonGfxTable0[178], // Mareep
    &gFollowerMonGfxTable0[179], // Flaaffy
    &gFollowerMonGfxTable0[180], // Ampharos
    &gFollowerMonGfxTable0[181], // Bellossom
    &gFollowerMonGfxTable0[182], // Marill
    &gFollowerMonGfxTable0[183], // Azumarill
    &gFollowerMonGfxTable0[184], // Sudowoodo
    &gFollowerMonGfxTable0[185], // Politoed
    &gFollowerMonGfxTable0[186], // Hoppip
    &gFollowerMonGfxTable0[187], // Skiploom
    &gFollowerMonGfxTable0[188], // Jumpluff
    &gFollowerMonGfxTable0[189], // Aipom
    &gFollowerMonGfxTable0[190], // Sunkern
    &gFollowerMonGfxTable0[191], // Sunflora
    &gFollowerMonGfxTable0[192], // Yanma
    &gFollowerMonGfxTable0[193], // Wooper
    &gFollowerMonGfxTable0[194], // Quagsire
    &gFollowerMonGfxTable0[195], // Espeon
    &gFollowerMonGfxTable0[196], // Umbreon
    &gFollowerMonGfxTable0[197], // Murkrow
    &gFollowerMonGfxTable0[198], // Slowking
    &gFollowerMonGfxTable0[199], // Misdreavus
    &gFollowerMonGfxTable0[200], // Unown
    &gFollowerMonGfxTable0[201], // Wobbuffet
    &gFollowerMonGfxTable0[202], // Girafarig
    &gFollowerMonGfxTable0[203], // Pineco
    &gFollowerMonGfxTable0[204], // Forretress
    &gFollowerMonGfxTable0[205], // Dunsparce
    &gFollowerMonGfxTable0[206], // Gligar
    &gFollowerMonGfxTable0[207], // Steelix
    &gFollowerMonGfxTable0[208], // Snubbull
    &gFollowerMonGfxTable0[209], // Granbull
    &gFollowerMonGfxTable0[210], // Qwilfish
    &gFollowerMonGfxTable0[211], // Scizor
    &gFollowerMonGfxTable0[212], // Shuckle
    &gFollowerMonGfxTable0[213], // Heracross
    &gFollowerMonGfxTable0[214], // Sneasel
    &gFollowerMonGfxTable0[215], // Teddiursa
    &gFollowerMonGfxTable0[216], // Ursaring
    &gFollowerMonGfxTable0[217], // Slugma
    &gFollowerMonGfxTable0[218], // Magcargo
    &gFollowerMonGfxTable0[219], // Swinub
    &gFollowerMonGfxTable0[220], // Piloswine
    &gFollowerMonGfxTable0[221], // Corsola
    &gFollowerMonGfxTable0[222], // Remoraid
    &gFollowerMonGfxTable0[223], // Octillery
    &gFollowerMonGfxTable0[224], // Delibird
    &gFollowerMonGfxTable0[225], // Mantine
    &gFollowerMonGfxTable0[226], // Skarmory
    &gFollowerMonGfxTable0[227], // Houndour
    &gFollowerMonGfxTable0[228], // Houndoom
    &gFollowerMonGfxTable0[229], // Kingdra
    &gFollowerMonGfxTable0[230], // Phanpy
    &gFollowerMonGfxTable0[231], // Donphan
    &gFollowerMonGfxTable0[232], // Porygon2
    &gFollowerMonGfxTable0[233], // Stantler
    &gFollowerMonGfxTable0[234], // Smeargle
    &gFollowerMonGfxTable0[235], // Tyrogue
    &gFollowerMonGfxTable0[236], // Hitmontop
    &gFollowerMonGfxTable0[237], // Smoochum
    &gFollowerMonGfxTable0[238], // Elekid
    &gFollowerMonGfxTable0[239], // Magby
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
    &gFollowerMonGfxTable1[151], // ChikoritaShiny
    &gFollowerMonGfxTable1[152], // BayleefShiny
    &gFollowerMonGfxTable1[153], // MeganiumShiny
    &gFollowerMonGfxTable1[154], // CyndaquilShiny
    &gFollowerMonGfxTable1[155], // QuilavaShiny
    &gFollowerMonGfxTable1[156], // TyphlosionShiny
    &gFollowerMonGfxTable1[157], // TotodileShiny
    &gFollowerMonGfxTable1[158], // CroconawShiny
    &gFollowerMonGfxTable1[159], // FeraligatrShiny
    &gFollowerMonGfxTable1[160], // SentretShiny
    &gFollowerMonGfxTable1[161], // FurretShiny
    &gFollowerMonGfxTable1[162], // HoothootShiny
    &gFollowerMonGfxTable1[163], // NoctowlShiny
    &gFollowerMonGfxTable1[164], // LedybaShiny
    &gFollowerMonGfxTable1[165], // LedianShiny
    &gFollowerMonGfxTable1[166], // SpinarakShiny
    &gFollowerMonGfxTable1[167], // AriadosShiny
    &gFollowerMonGfxTable1[168], // CrobatShiny
    &gFollowerMonGfxTable1[169], // ChinchouShiny
    &gFollowerMonGfxTable1[170], // LanturnShiny
    &gFollowerMonGfxTable1[171], // PichuShiny
    &gFollowerMonGfxTable1[172], // CleffaShiny
    &gFollowerMonGfxTable1[173], // IgglybuffShiny
    &gFollowerMonGfxTable1[174], // TogepiShiny
    &gFollowerMonGfxTable1[175], // TogeticShiny
    &gFollowerMonGfxTable1[176], // NatuShiny
    &gFollowerMonGfxTable1[177], // XatuShiny
    &gFollowerMonGfxTable1[178], // MareepShiny
    &gFollowerMonGfxTable1[179], // FlaaffyShiny
    &gFollowerMonGfxTable1[180], // AmpharosShiny
    &gFollowerMonGfxTable1[181], // BellossomShiny
    &gFollowerMonGfxTable1[182], // MarillShiny
    &gFollowerMonGfxTable1[183], // AzumarillShiny
    &gFollowerMonGfxTable1[184], // SudowoodoShiny
    &gFollowerMonGfxTable1[185], // PolitoedShiny
    &gFollowerMonGfxTable1[186], // HoppipShiny
    &gFollowerMonGfxTable1[187], // SkiploomShiny
    &gFollowerMonGfxTable1[188], // JumpluffShiny
    &gFollowerMonGfxTable1[189], // AipomShiny
    &gFollowerMonGfxTable1[190], // SunkernShiny
    &gFollowerMonGfxTable1[191], // SunfloraShiny
    &gFollowerMonGfxTable1[192], // YanmaShiny
    &gFollowerMonGfxTable1[193], // WooperShiny
    &gFollowerMonGfxTable1[194], // QuagsireShiny
    &gFollowerMonGfxTable1[195], // EspeonShiny
    &gFollowerMonGfxTable1[196], // UmbreonShiny
    &gFollowerMonGfxTable1[197], // MurkrowShiny
    &gFollowerMonGfxTable1[198], // SlowkingShiny
    &gFollowerMonGfxTable1[199], // MisdreavusShiny
    &gFollowerMonGfxTable1[200], // UnownShiny
    &gFollowerMonGfxTable1[201], // WobbuffetShiny
    &gFollowerMonGfxTable1[202], // GirafarigShiny
    &gFollowerMonGfxTable1[203], // PinecoShiny
    &gFollowerMonGfxTable1[204], // ForretressShiny
    &gFollowerMonGfxTable1[205], // DunsparceShiny
    &gFollowerMonGfxTable1[206], // GligarShiny
    &gFollowerMonGfxTable1[207], // SteelixShiny
    &gFollowerMonGfxTable1[208], // SnubbullShiny
    &gFollowerMonGfxTable1[209], // GranbullShiny
    &gFollowerMonGfxTable1[210], // QwilfishShiny
    &gFollowerMonGfxTable1[211], // ScizorShiny
    &gFollowerMonGfxTable1[212], // ShuckleShiny
    &gFollowerMonGfxTable1[213], // HeracrossShiny
    &gFollowerMonGfxTable1[214], // SneaselShiny
    &gFollowerMonGfxTable1[215], // TeddiursaShiny
    &gFollowerMonGfxTable1[216], // UrsaringShiny
    &gFollowerMonGfxTable1[217], // SlugmaShiny
    &gFollowerMonGfxTable1[218], // MagcargoShiny
    &gFollowerMonGfxTable1[219], // SwinubShiny
    &gFollowerMonGfxTable1[220], // PiloswineShiny
    &gFollowerMonGfxTable1[221], // CorsolaShiny
    &gFollowerMonGfxTable1[222], // RemoraidShiny
    &gFollowerMonGfxTable1[223], // OctilleryShiny
    &gFollowerMonGfxTable1[224], // DelibirdShiny
    &gFollowerMonGfxTable1[225], // MantineShiny
    &gFollowerMonGfxTable1[226], // SkarmoryShiny
    &gFollowerMonGfxTable1[227], // HoundourShiny
    &gFollowerMonGfxTable1[228], // HoundoomShiny
    &gFollowerMonGfxTable1[229], // KingdraShiny
    &gFollowerMonGfxTable1[230], // PhanpyShiny
    &gFollowerMonGfxTable1[231], // DonphanShiny
    &gFollowerMonGfxTable1[232], // Porygon2Shiny
    &gFollowerMonGfxTable1[233], // StantlerShiny
    &gFollowerMonGfxTable1[234], // SmeargleShiny
    &gFollowerMonGfxTable1[235], // TyrogueShiny
    &gFollowerMonGfxTable1[236], // HitmontopShiny
    &gFollowerMonGfxTable1[237], // SmoochumShiny
    &gFollowerMonGfxTable1[238], // ElekidShiny
    &gFollowerMonGfxTable1[239], // MagbyShiny
};
static NPCPtr sOverworldTable4[] =
{
	&gFollowerMonGfxTable2[0], // Miltank
    &gFollowerMonGfxTable2[1], // Blissey
    &gFollowerMonGfxTable2[2], // Raikou
    &gFollowerMonGfxTable2[3], // Entei
    &gFollowerMonGfxTable2[4], // Suicune
    &gFollowerMonGfxTable2[5], // Larvitar
    &gFollowerMonGfxTable2[6], // Pupitar
    &gFollowerMonGfxTable2[7], // Tyranitar
    &gFollowerMonGfxTable2[8], // Lugia
    &gFollowerMonGfxTable2[9], // Ho-Oh
    &gFollowerMonGfxTable2[10], // Celebi
	&gFollowerMonGfxTable2[11],  // Treecko
	&gFollowerMonGfxTable2[12],  // Grovyle
	&gFollowerMonGfxTable2[13],  // Sceptile
	&gFollowerMonGfxTable2[14],  // Torchic
	&gFollowerMonGfxTable2[15],  // Combusken
	&gFollowerMonGfxTable2[16],  // Blaziken
	&gFollowerMonGfxTable2[17],  // Mudkip
	&gFollowerMonGfxTable2[18],  // Marshtomp
	&gFollowerMonGfxTable2[19],  // Swampert
	&gFollowerMonGfxTable2[20],  // Poochyena
	&gFollowerMonGfxTable2[21],  // Mightyena
	&gFollowerMonGfxTable2[22],  // Zigzagoon
	&gFollowerMonGfxTable2[23],  // Linoone
	&gFollowerMonGfxTable2[24],  // Wurmple
	&gFollowerMonGfxTable2[25],  // Silcoon
	&gFollowerMonGfxTable2[26],  // Beautifly
	&gFollowerMonGfxTable2[27],  // Cascoon
	&gFollowerMonGfxTable2[28],  // Dustox
	&gFollowerMonGfxTable2[29],  // Lotad
	&gFollowerMonGfxTable2[30],  // Lombre
	&gFollowerMonGfxTable2[31],  // Ludicolo
	&gFollowerMonGfxTable2[32],  // Seedot
	&gFollowerMonGfxTable2[33],  // Nuzleaf
	&gFollowerMonGfxTable2[34],  // Shiftry
	&gFollowerMonGfxTable2[35],  // Nincada
	&gFollowerMonGfxTable2[36],  // Ninjask
	&gFollowerMonGfxTable2[37],  // Shedinja
	&gFollowerMonGfxTable2[38],  // Taillow
	&gFollowerMonGfxTable2[39],  // Swellow
	&gFollowerMonGfxTable2[40],  // Shroomish
	&gFollowerMonGfxTable2[41],  // Breloom
	&gFollowerMonGfxTable2[42],  // Spinda
	&gFollowerMonGfxTable2[43],  // Wingull
	&gFollowerMonGfxTable2[44],  // Pelipper
	&gFollowerMonGfxTable2[45],  // Surskit
	&gFollowerMonGfxTable2[46],  // Masquerain
	&gFollowerMonGfxTable2[47],  // Wailmer
	&gFollowerMonGfxTable2[48],  // Wailord
	&gFollowerMonGfxTable2[49],  // Skitty
	&gFollowerMonGfxTable2[50],  // Delcatty
	&gFollowerMonGfxTable2[51],  // Kecleon
	&gFollowerMonGfxTable2[52],  // Baltoy
	&gFollowerMonGfxTable2[53],  // Claydol
	&gFollowerMonGfxTable2[54],  // Nosepass
	&gFollowerMonGfxTable2[55],  // Torkoal
	&gFollowerMonGfxTable2[56],  // Sableye
	&gFollowerMonGfxTable2[57],  // Barboach
	&gFollowerMonGfxTable2[58],  // Whiscash
	&gFollowerMonGfxTable2[59],  // Luvdisc
	&gFollowerMonGfxTable2[60],  // Corphish
	&gFollowerMonGfxTable2[61],  // Crawdaunt
	&gFollowerMonGfxTable2[62],  // Feebas
	&gFollowerMonGfxTable2[63],  // Milotic
	&gFollowerMonGfxTable2[64],  // Carvanha
	&gFollowerMonGfxTable2[65],  // Sharpedo
	&gFollowerMonGfxTable2[66],  // Trapinch
	&gFollowerMonGfxTable2[67],  // Vibrava
	&gFollowerMonGfxTable2[68],  // Flygon
	&gFollowerMonGfxTable2[69],  // Makuhita
	&gFollowerMonGfxTable2[70],  // Hariyama
	&gFollowerMonGfxTable2[71],  // Electrike
	&gFollowerMonGfxTable2[72],  // Manectric
	&gFollowerMonGfxTable2[73],  // Numel
	&gFollowerMonGfxTable2[74],  // Camerupt
	&gFollowerMonGfxTable2[75],  // Spheal
	&gFollowerMonGfxTable2[76],  // Sealeo
	&gFollowerMonGfxTable2[77],  // Walrein
	&gFollowerMonGfxTable2[78],  // Cacnea
	&gFollowerMonGfxTable2[79],  // Cacturne
	&gFollowerMonGfxTable2[80],  // Snorunt
	&gFollowerMonGfxTable2[81],  // Glalie
	&gFollowerMonGfxTable2[82],  // Lunatone
	&gFollowerMonGfxTable2[83],  // Solrock
	&gFollowerMonGfxTable2[84],  // Azurill
	&gFollowerMonGfxTable2[85],  // Spoink
	&gFollowerMonGfxTable2[86],  // Grumpig
	&gFollowerMonGfxTable2[87],  // Plusle
	&gFollowerMonGfxTable2[88],  // Minun
	&gFollowerMonGfxTable2[89],  // Mawile
	&gFollowerMonGfxTable2[90],  // Meditite
	&gFollowerMonGfxTable2[91],  // Medicham
	&gFollowerMonGfxTable2[92],  // Swablu
	&gFollowerMonGfxTable2[93],  // Altaria
	&gFollowerMonGfxTable2[94],  // Wynaut
	&gFollowerMonGfxTable2[95],  // Duskull
	&gFollowerMonGfxTable2[96],  // Dusclops
	&gFollowerMonGfxTable2[97],  // Roselia
	&gFollowerMonGfxTable2[98],  // Slakoth
	&gFollowerMonGfxTable2[99],  // Vigoroth
	&gFollowerMonGfxTable2[100], // Slaking
	&gFollowerMonGfxTable2[101], // Gulpin
	&gFollowerMonGfxTable2[102], // Swalot
	&gFollowerMonGfxTable2[103], // Tropius
	&gFollowerMonGfxTable2[104], // Whismur
	&gFollowerMonGfxTable2[105], // Loudred
	&gFollowerMonGfxTable2[106], // Exploud
	&gFollowerMonGfxTable2[107], // Clamperl
	&gFollowerMonGfxTable2[108], // Huntail
	&gFollowerMonGfxTable2[109], // Gorebyss
	&gFollowerMonGfxTable2[110], // Absol
	&gFollowerMonGfxTable2[111], // Shuppet
	&gFollowerMonGfxTable2[112], // Banette
	&gFollowerMonGfxTable2[113], // Seviper
	&gFollowerMonGfxTable2[114], // Zangoose
	&gFollowerMonGfxTable2[115], // Relicanth
	&gFollowerMonGfxTable2[116], // Aron
	&gFollowerMonGfxTable2[117], // Lairon
	&gFollowerMonGfxTable2[118], // Aggron
	&gFollowerMonGfxTable2[119], // Castform
	&gFollowerMonGfxTable2[120], // Volbeat
	&gFollowerMonGfxTable2[121], // Illumise
	&gFollowerMonGfxTable2[122], // Lileep
	&gFollowerMonGfxTable2[123], // Cradily
	&gFollowerMonGfxTable2[124], // Anorith
	&gFollowerMonGfxTable2[125], // Armaldo
	&gFollowerMonGfxTable2[126], // Ralts
	&gFollowerMonGfxTable2[127], // Kirlia
	&gFollowerMonGfxTable2[128], // Gardevoir
	&gFollowerMonGfxTable2[129], // Bagon
	&gFollowerMonGfxTable2[130], // Shelgon
	&gFollowerMonGfxTable2[131], // Salamence
	&gFollowerMonGfxTable2[132], // Beldum
	&gFollowerMonGfxTable2[133], // Metang
	&gFollowerMonGfxTable2[134], // Metagross
	&gFollowerMonGfxTable2[135], // Regirock
	&gFollowerMonGfxTable2[136], // Regice
	&gFollowerMonGfxTable2[137], // Registeel
	&gFollowerMonGfxTable2[138], // Kyogre
	&gFollowerMonGfxTable2[139], // Groudon
	&gFollowerMonGfxTable2[140], // Rayquaza
	&gFollowerMonGfxTable2[141], // Latias
	&gFollowerMonGfxTable2[142], // Latios
	&gFollowerMonGfxTable2[143], // Jirachi
	&gFollowerMonGfxTable2[144], // Deoxys
	&gFollowerMonGfxTable2[145], // Chimecho


};
static NPCPtr sOverworldTable5[] =
{
    &gFollowerMonGfxTable3[0], // MiltankShiny
    &gFollowerMonGfxTable3[1], // BlisseyShiny
    &gFollowerMonGfxTable3[2], // RaikouShiny
    &gFollowerMonGfxTable3[3], // EnteiShiny
    &gFollowerMonGfxTable3[4], // SuicuneShiny
    &gFollowerMonGfxTable3[5], // LarvitarShiny
    &gFollowerMonGfxTable3[6], // PupitarShiny
    &gFollowerMonGfxTable3[7], // TyranitarShiny
    &gFollowerMonGfxTable3[8], // LugiaShiny
    &gFollowerMonGfxTable3[9], // Ho-OhShiny
    &gFollowerMonGfxTable3[10], // CelebiShiny
	&gFollowerMonGfxTable3[11],  // TreeckoShiny
    &gFollowerMonGfxTable3[12],  // GrovyleShiny
    &gFollowerMonGfxTable3[13],  // SceptileShiny
    &gFollowerMonGfxTable3[14],  // TorchicShiny
    &gFollowerMonGfxTable3[15],  // CombuskenShiny
    &gFollowerMonGfxTable3[16],  // BlazikenShiny
    &gFollowerMonGfxTable3[17],  // MudkipShiny
    &gFollowerMonGfxTable3[18],  // MarshtompShiny
    &gFollowerMonGfxTable3[19],  // SwampertShiny
    &gFollowerMonGfxTable3[20],  // PoochyenaShiny
    &gFollowerMonGfxTable3[21],  // MightyenaShiny
    &gFollowerMonGfxTable3[22],  // ZigzagoonShiny
    &gFollowerMonGfxTable3[23],  // LinooneShiny
    &gFollowerMonGfxTable3[24],  // WurmpleShiny
    &gFollowerMonGfxTable3[25],  // SilcoonShiny
    &gFollowerMonGfxTable3[26],  // BeautiflyShiny
    &gFollowerMonGfxTable3[27],  // CascoonShiny
    &gFollowerMonGfxTable3[28],  // DustoxShiny
    &gFollowerMonGfxTable3[29],  // LotadShiny
    &gFollowerMonGfxTable3[30],  // LombreShiny
    &gFollowerMonGfxTable3[31],  // LudicoloShiny
    &gFollowerMonGfxTable3[32],  // SeedotShiny
    &gFollowerMonGfxTable3[33],  // NuzleafShiny
    &gFollowerMonGfxTable3[34],  // ShiftryShiny
    &gFollowerMonGfxTable3[35],  // NincadaShiny
    &gFollowerMonGfxTable3[36],  // NinjaskShiny
    &gFollowerMonGfxTable3[37],  // ShedinjaShiny
    &gFollowerMonGfxTable3[38],  // TaillowShiny
    &gFollowerMonGfxTable3[39],  // SwellowShiny
    &gFollowerMonGfxTable3[40],  // ShroomishShiny
    &gFollowerMonGfxTable3[41],  // BreloomShiny
    &gFollowerMonGfxTable3[42],  // SpindaShiny
    &gFollowerMonGfxTable3[43],  // WingullShiny
    &gFollowerMonGfxTable3[44],  // PelipperShiny
    &gFollowerMonGfxTable3[45],  // SurskitShiny
    &gFollowerMonGfxTable3[46],  // MasquerainShiny
    &gFollowerMonGfxTable3[47],  // WailmerShiny
    &gFollowerMonGfxTable3[48],  // WailordShiny
    &gFollowerMonGfxTable3[49],  // SkittyShiny
    &gFollowerMonGfxTable3[50],  // DelcattyShiny
    &gFollowerMonGfxTable3[51],  // KecleonShiny
    &gFollowerMonGfxTable3[52],  // BaltoyShiny
    &gFollowerMonGfxTable3[53],  // ClaydolShiny
    &gFollowerMonGfxTable3[54],  // NosepassShiny
    &gFollowerMonGfxTable3[55],  // TorkoalShiny
    &gFollowerMonGfxTable3[56],  // SableyeShiny
    &gFollowerMonGfxTable3[57],  // BarboachShiny
    &gFollowerMonGfxTable3[58],  // WhiscashShiny
    &gFollowerMonGfxTable3[59],  // LuvdiscShiny
    &gFollowerMonGfxTable3[60],  // CorphishShiny
    &gFollowerMonGfxTable3[61],  // CrawdauntShiny
    &gFollowerMonGfxTable3[62],  // FeebasShiny
    &gFollowerMonGfxTable3[63],  // MiloticShiny
    &gFollowerMonGfxTable3[64],  // CarvanhaShiny
    &gFollowerMonGfxTable3[65],  // SharpedoShiny
    &gFollowerMonGfxTable3[66],  // TrapinchShiny
    &gFollowerMonGfxTable3[67],  // VibravaShiny
    &gFollowerMonGfxTable3[68],  // FlygonShiny
    &gFollowerMonGfxTable3[69],  // MakuhitaShiny
    &gFollowerMonGfxTable3[70],  // HariyamaShiny
    &gFollowerMonGfxTable3[71],  // ElectrikeShiny
    &gFollowerMonGfxTable3[72],  // ManectricShiny
    &gFollowerMonGfxTable3[73],  // NumelShiny
    &gFollowerMonGfxTable3[74],  // CameruptShiny
    &gFollowerMonGfxTable3[75],  // SphealShiny
    &gFollowerMonGfxTable3[76],  // SealeoShiny
    &gFollowerMonGfxTable3[77],  // WalreinShiny
    &gFollowerMonGfxTable3[78],  // CacneaShiny
    &gFollowerMonGfxTable3[79],  // CacturneShiny
    &gFollowerMonGfxTable3[80],  // SnoruntShiny
    &gFollowerMonGfxTable3[81],  // GlalieShiny
    &gFollowerMonGfxTable3[82],  // LunatoneShiny
    &gFollowerMonGfxTable3[83],  // SolrockShiny
    &gFollowerMonGfxTable3[84],  // AzurillShiny
    &gFollowerMonGfxTable3[85],  // SpoinkShiny
    &gFollowerMonGfxTable3[86],  // GrumpigShiny
    &gFollowerMonGfxTable3[87],  // PlusleShiny
    &gFollowerMonGfxTable3[88],  // MinunShiny
    &gFollowerMonGfxTable3[89],  // MawileShiny
    &gFollowerMonGfxTable3[90],  // MedititeShiny
    &gFollowerMonGfxTable3[91],  // MedichamShiny
    &gFollowerMonGfxTable3[92],  // SwabluShiny
    &gFollowerMonGfxTable3[93],  // AltariaShiny
    &gFollowerMonGfxTable3[94],  // WynautShiny
    &gFollowerMonGfxTable3[95],  // DuskullShiny
    &gFollowerMonGfxTable3[96],  // DusclopsShiny
    &gFollowerMonGfxTable3[97],  // RoseliaShiny
    &gFollowerMonGfxTable3[98],  // SlakothShiny
    &gFollowerMonGfxTable3[99],  // VigorothShiny
    &gFollowerMonGfxTable3[100], // SlakingShiny
    &gFollowerMonGfxTable3[101], // GulpinShiny
    &gFollowerMonGfxTable3[102], // SwalotShiny
    &gFollowerMonGfxTable3[103], // TropiusShiny
    &gFollowerMonGfxTable3[104], // WhismurShiny
    &gFollowerMonGfxTable3[105], // LoudredShiny
    &gFollowerMonGfxTable3[106], // ExploudShiny
    &gFollowerMonGfxTable3[107], // ClamperlShiny
    &gFollowerMonGfxTable3[108], // HuntailShiny
    &gFollowerMonGfxTable3[109], // GorebyssShiny
    &gFollowerMonGfxTable3[110], // AbsolShiny
    &gFollowerMonGfxTable3[111], // ShuppetShiny
    &gFollowerMonGfxTable3[112], // BanetteShiny
    &gFollowerMonGfxTable3[113], // SeviperShiny
    &gFollowerMonGfxTable3[114], // ZangooseShiny
    &gFollowerMonGfxTable3[115], // RelicanthShiny
    &gFollowerMonGfxTable3[116], // AronShiny
    &gFollowerMonGfxTable3[117], // LaironShiny
    &gFollowerMonGfxTable3[118], // AggronShiny
    &gFollowerMonGfxTable3[119], // CastformShiny
    &gFollowerMonGfxTable3[120], // VolbeatShiny
    &gFollowerMonGfxTable3[121], // IllumiseShiny
    &gFollowerMonGfxTable3[122], // LileepShiny
    &gFollowerMonGfxTable3[123], // CradilyShiny
    &gFollowerMonGfxTable3[124], // AnorithShiny
    &gFollowerMonGfxTable3[125], // ArmaldoShiny
    &gFollowerMonGfxTable3[126], // RaltsShiny
    &gFollowerMonGfxTable3[127], // KirliaShiny
    &gFollowerMonGfxTable3[128], // GardevoirShiny
    &gFollowerMonGfxTable3[129], // BagonShiny
    &gFollowerMonGfxTable3[130], // ShelgonShiny
    &gFollowerMonGfxTable3[131], // SalamenceShiny
    &gFollowerMonGfxTable3[132], // BeldumShiny
    &gFollowerMonGfxTable3[133], // MetangShiny
    &gFollowerMonGfxTable3[134], // MetagrossShiny
    &gFollowerMonGfxTable3[135], // RegirockShiny
    &gFollowerMonGfxTable3[136], // RegiceShiny
    &gFollowerMonGfxTable3[137], // RegisteelShiny
    &gFollowerMonGfxTable3[138], // KyogreShiny
    &gFollowerMonGfxTable3[139], // GroudonShiny
    &gFollowerMonGfxTable3[140], // RayquazaShiny
    &gFollowerMonGfxTable3[141], // LatiasShiny
    &gFollowerMonGfxTable3[142], // LatiosShiny
    &gFollowerMonGfxTable3[143], // JirachiShiny
    &gFollowerMonGfxTable3[144], // DeoxysShiny
    &gFollowerMonGfxTable3[145], // ChimechoShiny
};
	// create 255 OW tables
	const struct EventObjectGraphicsInfo** const gOverworldTableSwitcher[255] =
	{
		(NPCPtr*) 0x839FDB0,
		sOverworldTable2,
		sOverworldTable3,
		sOverworldTable4,
		sOverworldTable5,
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
        {gFollowerMonPic0152_ChikoritaPal, 0x1297},
        {gFollowerMonPic0153_BayleefPal,  0x1298},
        {gFollowerMonPic0154_MeganiumPal, 0x1299},
        {gFollowerMonPic0155_CyndaquilPal, 0x129A},
        {gFollowerMonPic0156_QuilavaPal,  0x129B},
        {gFollowerMonPic0157_TyphlosionPal, 0x129C},
        {gFollowerMonPic0158_TotodilePal, 0x129D},
        {gFollowerMonPic0159_CroconawPal, 0x129E},
        {gFollowerMonPic0160_FeraligatrPal, 0x129F},
        {gFollowerMonPic0161_SentretPal,  0x12A0},
        {gFollowerMonPic0162_FurretPal,   0x12A1},
        {gFollowerMonPic0163_HoothootPal, 0x12A2},
        {gFollowerMonPic0164_NoctowlPal,  0x12A3},
        {gFollowerMonPic0165_LedybaPal,   0x12A4},
        {gFollowerMonPic0166_LedianPal,   0x12A5},
        {gFollowerMonPic0167_SpinarakPal, 0x12A6},
        {gFollowerMonPic0168_AriadosPal,  0x12A7},
        {gFollowerMonPic0169_CrobatPal,   0x12A8},
        {gFollowerMonPic0170_ChinchouPal, 0x12A9},
        {gFollowerMonPic0171_LanturnPal,  0x12AA},
        {gFollowerMonPic0172_PichuPal,    0x12AB},
        {gFollowerMonPic0173_CleffaPal,   0x12AC},
        {gFollowerMonPic0174_IgglybuffPal, 0x12AD},
        {gFollowerMonPic0175_TogepiPal,   0x12AE},
        {gFollowerMonPic0176_TogeticPal,  0x12AF},
        {gFollowerMonPic0177_NatuPal,     0x12B0},
        {gFollowerMonPic0178_XatuPal,     0x12B1},
        {gFollowerMonPic0179_MareepPal,   0x12B2},
        {gFollowerMonPic0180_FlaaffyPal,  0x12B3},
        {gFollowerMonPic0181_AmpharosPal, 0x12B4},
        {gFollowerMonPic0182_BellossomPal, 0x12B5},
        {gFollowerMonPic0183_MarillPal,   0x12B6},
        {gFollowerMonPic0184_AzumarillPal, 0x12B7},
        {gFollowerMonPic0185_SudowoodoPal, 0x12B8},
        {gFollowerMonPic0186_PolitoedPal, 0x12B9},
        {gFollowerMonPic0187_HoppipPal,   0x12BA},
        {gFollowerMonPic0188_SkiploomPal, 0x12BB},
        {gFollowerMonPic0189_JumpluffPal, 0x12BC},
        {gFollowerMonPic0190_AipomPal,    0x12BD},
        {gFollowerMonPic0191_SunkernPal,  0x12BE},
        {gFollowerMonPic0192_SunfloraPal, 0x12BF},
        {gFollowerMonPic0193_YanmaPal,    0x12C0},
        {gFollowerMonPic0194_WooperPal,   0x12C1},
        {gFollowerMonPic0195_QuagsirePal, 0x12C2},
        {gFollowerMonPic0196_EspeonPal,   0x12C3},
        {gFollowerMonPic0197_UmbreonPal,  0x12C4},
        {gFollowerMonPic0198_MurkrowPal,  0x12C5},
        {gFollowerMonPic0199_SlowkingPal, 0x12C6},
        {gFollowerMonPic0200_MisdreavusPal, 0x12C7},
        {gFollowerMonPic0201_UnownPal,    0x12C8},
        {gFollowerMonPic0202_WobbuffetPal, 0x12C9},
        {gFollowerMonPic0203_GirafarigPal, 0x12CA},
        {gFollowerMonPic0204_PinecoPal,   0x12CB},
        {gFollowerMonPic0205_ForretressPal, 0x12CC},
        {gFollowerMonPic0206_DunsparcePal, 0x12CD},
        {gFollowerMonPic0207_GligarPal,   0x12CE},
        {gFollowerMonPic0208_SteelixPal,  0x12CF},
        {gFollowerMonPic0209_SnubbullPal, 0x12D0},
        {gFollowerMonPic0210_GranbullPal, 0x12D1},
        {gFollowerMonPic0211_QwilfishPal, 0x12D2},
        {gFollowerMonPic0212_ScizorPal,   0x12D3},
        {gFollowerMonPic0213_ShucklePal,  0x12D4},
        {gFollowerMonPic0214_HeracrossPal, 0x12D5},
        {gFollowerMonPic0215_SneaselPal,  0x12D6},
        {gFollowerMonPic0216_TeddiursaPal, 0x12D7},
        {gFollowerMonPic0217_UrsaringPal, 0x12D8},
        {gFollowerMonPic0218_SlugmaPal,   0x12D9},
        {gFollowerMonPic0219_MagcargoPal, 0x12DA},
        {gFollowerMonPic0220_SwinubPal,   0x12DB},
        {gFollowerMonPic0221_PiloswinePal, 0x12DC},
        {gFollowerMonPic0222_CorsolaPal,  0x12DD},
        {gFollowerMonPic0223_RemoraidPal, 0x12DE},
        {gFollowerMonPic0224_OctilleryPal, 0x12DF},
        {gFollowerMonPic0225_DelibirdPal, 0x12E0},
        {gFollowerMonPic0226_MantinePal,  0x12E1},
        {gFollowerMonPic0227_SkarmoryPal, 0x12E2},
        {gFollowerMonPic0228_HoundourPal, 0x12E3},
        {gFollowerMonPic0229_HoundoomPal, 0x12E4},
        {gFollowerMonPic0230_KingdraPal,  0x12E5},
        {gFollowerMonPic0231_PhanpyPal,   0x12E6},
        {gFollowerMonPic0232_DonphanPal,  0x12E7},
        {gFollowerMonPic0233_Porygon2Pal, 0x12E8},
        {gFollowerMonPic0234_StantlerPal, 0x12E9},
        {gFollowerMonPic0235_SmearglePal, 0x12EA},
        {gFollowerMonPic0236_TyroguePal,  0x12EB},
        {gFollowerMonPic0237_HitmontopPal, 0x12EC},
        {gFollowerMonPic0238_SmoochumPal, 0x12ED},
        {gFollowerMonPic0239_ElekidPal,   0x12EE},
        {gFollowerMonPic0240_MagbyPal,    0x12EF},
        {gFollowerMonPic0241_MiltankPal,  0x12F0},
        {gFollowerMonPic0242_BlisseyPal,  0x12F1},
        {gFollowerMonPic0243_RaikouPal,   0x12F2},
        {gFollowerMonPic0244_EnteiPal,    0x12F3},
        {gFollowerMonPic0245_SuicunePal,  0x12F4},
        {gFollowerMonPic0246_LarvitarPal, 0x12F5},
        {gFollowerMonPic0247_PupitarPal,  0x12F6},
        {gFollowerMonPic0248_TyranitarPal, 0x12F7},
        {gFollowerMonPic0249_LugiaPal,    0x12F8},
        {gFollowerMonPic0250_HoOhPal,     0x12F9},
        {gFollowerMonPic0251_CelebiPal,   0x12FA},
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
        {gFollowerMonPic2152_ChikoritaShinyPal, 0x1397},
        {gFollowerMonPic2153_BayleefShinyPal,  0x1398},
        {gFollowerMonPic2154_MeganiumShinyPal, 0x1399},
        {gFollowerMonPic2155_CyndaquilShinyPal, 0x139A},
        {gFollowerMonPic2156_QuilavaShinyPal,  0x139B},
        {gFollowerMonPic2157_TyphlosionShinyPal, 0x139C},
        {gFollowerMonPic2158_TotodileShinyPal, 0x139D},
        {gFollowerMonPic2159_CroconawShinyPal, 0x139E},
        {gFollowerMonPic2160_FeraligatrShinyPal, 0x139F},
        {gFollowerMonPic2161_SentretShinyPal,  0x13A0},
        {gFollowerMonPic2162_FurretShinyPal,   0x13A1},
        {gFollowerMonPic2163_HoothootShinyPal, 0x13A2},
        {gFollowerMonPic2164_NoctowlShinyPal,  0x13A3},
        {gFollowerMonPic2165_LedybaShinyPal,   0x13A4},
        {gFollowerMonPic2166_LedianShinyPal,   0x13A5},
        {gFollowerMonPic2167_SpinarakShinyPal, 0x13A6},
        {gFollowerMonPic2168_AriadosShinyPal,  0x13A7},
        {gFollowerMonPic2169_CrobatShinyPal,   0x13A8},
        {gFollowerMonPic2170_ChinchouShinyPal, 0x13A9},
        {gFollowerMonPic2171_LanturnShinyPal,  0x13AA},
        {gFollowerMonPic2172_PichuShinyPal,    0x13AB},
        {gFollowerMonPic2173_CleffaShinyPal,   0x13AC},
        {gFollowerMonPic2174_IgglybuffShinyPal, 0x13AD},
        {gFollowerMonPic2175_TogepiShinyPal,   0x13AE},
        {gFollowerMonPic2176_TogeticShinyPal,  0x13AF},
        {gFollowerMonPic2177_NatuShinyPal,     0x13B0},
        {gFollowerMonPic2178_XatuShinyPal,     0x13B1},
        {gFollowerMonPic2179_MareepShinyPal,   0x13B2},
        {gFollowerMonPic2180_FlaaffyShinyPal,  0x13B3},
        {gFollowerMonPic2181_AmpharosShinyPal, 0x13B4},
        {gFollowerMonPic2182_BellossomShinyPal, 0x13B5},
        {gFollowerMonPic2183_MarillShinyPal,   0x13B6},
        {gFollowerMonPic2184_AzumarillShinyPal, 0x13B7},
        {gFollowerMonPic2185_SudowoodoShinyPal, 0x13B8},
        {gFollowerMonPic2186_PolitoedShinyPal, 0x13B9},
        {gFollowerMonPic2187_HoppipShinyPal,   0x13BA},
        {gFollowerMonPic2188_SkiploomShinyPal, 0x13BB},
        {gFollowerMonPic2189_JumpluffShinyPal, 0x13BC},
        {gFollowerMonPic2190_AipomShinyPal,    0x13BD},
        {gFollowerMonPic2191_SunkernShinyPal,  0x13BE},
        {gFollowerMonPic2192_SunfloraShinyPal, 0x13BF},
        {gFollowerMonPic2193_YanmaShinyPal,    0x13C0},
        {gFollowerMonPic2194_WooperShinyPal,   0x13C1},
        {gFollowerMonPic2195_QuagsireShinyPal, 0x13C2},
        {gFollowerMonPic2196_EspeonShinyPal,   0x13C3},
        {gFollowerMonPic2197_UmbreonShinyPal,  0x13C4},
        {gFollowerMonPic2198_MurkrowShinyPal,  0x13C5},
        {gFollowerMonPic2199_SlowkingShinyPal, 0x13C6},
        {gFollowerMonPic2200_MisdreavusShinyPal, 0x13C7},
        {gFollowerMonPic2201_UnownShinyPal,    0x13C8},
        {gFollowerMonPic2202_WobbuffetShinyPal, 0x13C9},
        {gFollowerMonPic2203_GirafarigShinyPal, 0x13CA},
        {gFollowerMonPic2204_PinecoShinyPal,   0x13CB},
        {gFollowerMonPic2205_ForretressShinyPal, 0x13CC},
        {gFollowerMonPic2206_DunsparceShinyPal, 0x13CD},
        {gFollowerMonPic2207_GligarShinyPal,   0x13CE},
        {gFollowerMonPic2208_SteelixShinyPal,  0x13CF},
        {gFollowerMonPic2209_SnubbullShinyPal, 0x13D0},
        {gFollowerMonPic2210_GranbullShinyPal, 0x13D1},
        {gFollowerMonPic2211_QwilfishShinyPal, 0x13D2},
        {gFollowerMonPic2212_ScizorShinyPal,   0x13D3},
        {gFollowerMonPic2213_ShuckleShinyPal,  0x13D4},
        {gFollowerMonPic2214_HeracrossShinyPal, 0x13D5},
        {gFollowerMonPic2215_SneaselShinyPal,  0x13D6},
        {gFollowerMonPic2216_TeddiursaShinyPal, 0x13D7},
        {gFollowerMonPic2217_UrsaringShinyPal, 0x13D8},
        {gFollowerMonPic2218_SlugmaShinyPal,   0x13D9},
        {gFollowerMonPic2219_MagcargoShinyPal, 0x13DA},
        {gFollowerMonPic2220_SwinubShinyPal,   0x13DB},
        {gFollowerMonPic2221_PiloswineShinyPal, 0x13DC},
        {gFollowerMonPic2222_CorsolaShinyPal,  0x13DD},
        {gFollowerMonPic2223_RemoraidShinyPal, 0x13DE},
        {gFollowerMonPic2224_OctilleryShinyPal, 0x13DF},
        {gFollowerMonPic2225_DelibirdShinyPal, 0x13E0},
        {gFollowerMonPic2226_MantineShinyPal,  0x13E1},
        {gFollowerMonPic2227_SkarmoryShinyPal, 0x13E2},
        {gFollowerMonPic2228_HoundourShinyPal, 0x13E3},
        {gFollowerMonPic2229_HoundoomShinyPal, 0x13E4},
        {gFollowerMonPic2230_KingdraShinyPal,  0x13E5},
        {gFollowerMonPic2231_PhanpyShinyPal,   0x13E6},
        {gFollowerMonPic2232_DonphanShinyPal,  0x13E7},
        {gFollowerMonPic2233_Porygon2ShinyPal, 0x13E8},
        {gFollowerMonPic2234_StantlerShinyPal, 0x13E9},
        {gFollowerMonPic2235_SmeargleShinyPal, 0x13EA},
        {gFollowerMonPic2236_TyrogueShinyPal,  0x13EB},
        {gFollowerMonPic2237_HitmontopShinyPal, 0x13EC},
        {gFollowerMonPic2238_SmoochumShinyPal, 0x13ED},
        {gFollowerMonPic2239_ElekidShinyPal,   0x13EE},
        {gFollowerMonPic2240_MagbyShinyPal,    0x13EF},
        {gFollowerMonPic2241_MiltankShinyPal,  0x13F0},
        {gFollowerMonPic2242_BlisseyShinyPal,  0x13F1},
        {gFollowerMonPic2243_RaikouShinyPal,   0x13F2},
        {gFollowerMonPic2244_EnteiShinyPal,    0x13F3},
        {gFollowerMonPic2245_SuicuneShinyPal,  0x13F4},
        {gFollowerMonPic2246_LarvitarShinyPal, 0x13F5},
        {gFollowerMonPic2247_PupitarShinyPal,  0x13F6},
        {gFollowerMonPic2248_TyranitarShinyPal, 0x13F7},
        {gFollowerMonPic2249_LugiaShinyPal,    0x13F8},
        {gFollowerMonPic2250_HoOhShinyPal,     0x13F9},
        {gFollowerMonPic2251_CelebiShinyPal,   0x13FA},

	};

	static const struct SpritePalette gObjectEventSpritePalettes14[] = 	
	{
		{gFollowerMonPic0277_TreeckoPal,  0x1400},
		{gFollowerMonPic0278_GrovylePal,  0x1401},
		{gFollowerMonPic0279_SceptilePal, 0x1402},
		{gFollowerMonPic0280_TorchicPal,  0x1403},
		{gFollowerMonPic0281_CombuskenPal, 0x1404},
		{gFollowerMonPic0282_BlazikenPal, 0x1405},
		{gFollowerMonPic0283_MudkipPal,   0x1406},
		{gFollowerMonPic0284_MarshtompPal, 0x1407},
		{gFollowerMonPic0285_SwampertPal, 0x1408},
		{gFollowerMonPic0286_PoochyenaPal, 0x1409},
		{gFollowerMonPic0287_MightyenaPal, 0x140A},
		{gFollowerMonPic0288_ZigzagoonPal, 0x140B},
		{gFollowerMonPic0289_LinoonePal,  0x140C},
		{gFollowerMonPic0290_WurmplePal,  0x140D},
		{gFollowerMonPic0291_SilcoonPal,  0x140E},
		{gFollowerMonPic0292_BeautiflyPal, 0x140F},
		{gFollowerMonPic0293_CascoonPal,  0x1410},
		{gFollowerMonPic0294_DustoxPal,   0x1411},
		{gFollowerMonPic0295_LotadPal,    0x1412},
		{gFollowerMonPic0296_LombrePal,   0x1413},
		{gFollowerMonPic0297_LudicoloPal, 0x1414},
		{gFollowerMonPic0298_SeedotPal,   0x1415},
		{gFollowerMonPic0299_NuzleafPal,  0x1416},
		{gFollowerMonPic0300_ShiftryPal,  0x1417},
		{gFollowerMonPic0301_NincadaPal,  0x1418},
		{gFollowerMonPic0302_NinjaskPal,  0x1419},
		{gFollowerMonPic0303_ShedinjaPal, 0x141A},
		{gFollowerMonPic0304_TaillowPal,  0x141B},
		{gFollowerMonPic0305_SwellowPal,  0x141C},
		{gFollowerMonPic0306_ShroomishPal, 0x141D},
		{gFollowerMonPic0307_BreloomPal,  0x141E},
		{gFollowerMonPic0308_SpindaPal,   0x141F},
		{gFollowerMonPic0309_WingullPal,  0x1420},
		{gFollowerMonPic0310_PelipperPal, 0x1421},
		{gFollowerMonPic0311_SurskitPal,  0x1422},
		{gFollowerMonPic0312_MasquerainPal, 0x1423},
		{gFollowerMonPic0313_WailmerPal,  0x1424},
		{gFollowerMonPic0314_WailordPal,  0x1425},
		{gFollowerMonPic0315_SkittyPal,   0x1426},
		{gFollowerMonPic0316_DelcattyPal, 0x1427},
		{gFollowerMonPic0317_KecleonPal,  0x1428},
		{gFollowerMonPic0318_BaltoyPal,   0x1429},
		{gFollowerMonPic0319_ClaydolPal,  0x142A},
		{gFollowerMonPic0320_NosepassPal, 0x142B},
		{gFollowerMonPic0321_TorkoalPal,  0x142C},
		{gFollowerMonPic0322_SableyePal,  0x142D},
		{gFollowerMonPic0323_BarboachPal, 0x142E},
		{gFollowerMonPic0324_WhiscashPal, 0x142F},
		{gFollowerMonPic0325_LuvdiscPal,  0x1430},
		{gFollowerMonPic0326_CorphishPal, 0x1431},
		{gFollowerMonPic0327_CrawdauntPal, 0x1432},
		{gFollowerMonPic0328_FeebasPal,   0x1433},
		{gFollowerMonPic0329_MiloticPal,  0x1434},
		{gFollowerMonPic0330_CarvanhaPal, 0x1435},
		{gFollowerMonPic0331_SharpedoPal, 0x1436},
		{gFollowerMonPic0332_TrapinchPal, 0x1437},
		{gFollowerMonPic0333_VibravaPal,  0x1438},
		{gFollowerMonPic0334_FlygonPal,   0x1439},
		{gFollowerMonPic0335_MakuhitaPal, 0x143A},
		{gFollowerMonPic0336_HariyamaPal, 0x143B},
		{gFollowerMonPic0337_ElectrikePal, 0x143C},
		{gFollowerMonPic0338_ManectricPal, 0x143D},
		{gFollowerMonPic0339_NumelPal,    0x143E},
		{gFollowerMonPic0340_CameruptPal, 0x143F},
		{gFollowerMonPic0341_SphealPal,   0x1440},
		{gFollowerMonPic0342_SealeoPal,   0x1441},
		{gFollowerMonPic0343_WalreinPal,  0x1442},
		{gFollowerMonPic0344_CacneaPal,   0x1443},
		{gFollowerMonPic0345_CacturnePal, 0x1444},
		{gFollowerMonPic0346_SnoruntPal,  0x1445},
		{gFollowerMonPic0347_GlaliePal,   0x1446},
		{gFollowerMonPic0348_LunatonePal, 0x1447},
		{gFollowerMonPic0349_SolrockPal,  0x1448},
		{gFollowerMonPic0350_AzurillPal,  0x1449},
		{gFollowerMonPic0351_SpoinkPal,   0x144A},
		{gFollowerMonPic0352_GrumpigPal,  0x144B},
		{gFollowerMonPic0353_PluslePal,   0x144C},
		{gFollowerMonPic0354_MinunPal,    0x144D},
		{gFollowerMonPic0355_MawilePal,   0x144E},
		{gFollowerMonPic0356_MedititePal, 0x144F},
		{gFollowerMonPic0357_MedichamPal, 0x1450},
		{gFollowerMonPic0358_SwabluPal,   0x1451},
		{gFollowerMonPic0359_AltariaPal,  0x1452},
		{gFollowerMonPic0360_WynautPal,   0x1453},
		{gFollowerMonPic0361_DuskullPal,  0x1454},
		{gFollowerMonPic0362_DusclopsPal, 0x1455},
		{gFollowerMonPic0363_RoseliaPal,  0x1456},
		{gFollowerMonPic0364_SlakothPal,  0x1457},
		{gFollowerMonPic0365_VigorothPal, 0x1458},
		{gFollowerMonPic0366_SlakingPal,  0x1459},
		{gFollowerMonPic0367_GulpinPal,   0x145A},
		{gFollowerMonPic0368_SwalotPal,   0x145B},
		{gFollowerMonPic0369_TropiusPal,  0x145C},
		{gFollowerMonPic0370_WhismurPal,  0x145D},
		{gFollowerMonPic0371_LoudredPal,  0x145E},
		{gFollowerMonPic0372_ExploudPal,  0x145F},
		{gFollowerMonPic0373_ClamperlPal, 0x1460},
		{gFollowerMonPic0374_HuntailPal,  0x1461},
		{gFollowerMonPic0375_GorebyssPal, 0x1462},
		{gFollowerMonPic0376_AbsolPal,    0x1463},
		{gFollowerMonPic0377_ShuppetPal,  0x1464},
		{gFollowerMonPic0378_BanettePal,  0x1465},
		{gFollowerMonPic0379_SeviperPal,  0x1466},
		{gFollowerMonPic0380_ZangoosePal, 0x1467},
		{gFollowerMonPic0381_RelicanthPal, 0x1468},
		{gFollowerMonPic0382_AronPal,     0x1469},
		{gFollowerMonPic0383_LaironPal,   0x146A},
		{gFollowerMonPic0384_AggronPal,   0x146B},
		{gFollowerMonPic0385_CastformPal, 0x146C},
		{gFollowerMonPic0386_VolbeatPal,  0x146D},
		{gFollowerMonPic0387_IllumisePal, 0x146E},
		{gFollowerMonPic0388_LileepPal,   0x146F},
		{gFollowerMonPic0389_CradilyPal,  0x1470},
		{gFollowerMonPic0390_AnorithPal,  0x1471},
		{gFollowerMonPic0391_ArmaldoPal,  0x1472},
		{gFollowerMonPic0392_RaltsPal,    0x1473},
		{gFollowerMonPic0393_KirliaPal,   0x1474},
		{gFollowerMonPic0394_GardevoirPal, 0x1475},
		{gFollowerMonPic0395_BagonPal,    0x1476},
		{gFollowerMonPic0396_ShelgonPal,  0x1477},
		{gFollowerMonPic0397_SalamencePal, 0x1478},
		{gFollowerMonPic0398_BeldumPal,   0x1479},
		{gFollowerMonPic0399_MetangPal,   0x147A},
		{gFollowerMonPic0400_MetagrossPal, 0x147B},
		{gFollowerMonPic0401_RegirockPal, 0x147C},
		{gFollowerMonPic0402_RegicePal,   0x147D},
		{gFollowerMonPic0403_RegisteelPal, 0x147E},
		{gFollowerMonPic0404_KyogrePal,   0x147F},
		{gFollowerMonPic0405_GroudonPal,  0x1480},
		{gFollowerMonPic0406_RayquazaPal, 0x1481},
		{gFollowerMonPic0407_LatiasPal,   0x1482},
		{gFollowerMonPic0408_LatiosPal,   0x1483},
		{gFollowerMonPic0409_JirachiPal,  0x1484},
		{gFollowerMonPic0410_DeoxysPal,   0x1485},
		{gFollowerMonPic0411_ChimechoPal, 0x1486},

	};

	static const struct SpritePalette gObjectEventSpritePalettes15[] = 	
	{
    {gFollowerMonPic2277_TreeckoShinyPal,  0x1500},
    {gFollowerMonPic2278_GrovyleShinyPal,  0x1501},
    {gFollowerMonPic2279_SceptileShinyPal, 0x1502},
    {gFollowerMonPic2280_TorchicShinyPal,  0x1503},
    {gFollowerMonPic2281_CombuskenShinyPal, 0x1504},
    {gFollowerMonPic2282_BlazikenShinyPal, 0x1505},
    {gFollowerMonPic2283_MudkipShinyPal,   0x1506},
    {gFollowerMonPic2284_MarshtompShinyPal, 0x1507},
    {gFollowerMonPic2285_SwampertShinyPal, 0x1508},
    {gFollowerMonPic2286_PoochyenaShinyPal, 0x1509},
    {gFollowerMonPic2287_MightyenaShinyPal, 0x150A},
    {gFollowerMonPic2288_ZigzagoonShinyPal, 0x150B},
    {gFollowerMonPic2289_LinooneShinyPal,  0x150C},
    {gFollowerMonPic2290_WurmpleShinyPal,  0x150D},
    {gFollowerMonPic2291_SilcoonShinyPal,  0x150E},
    {gFollowerMonPic2292_BeautiflyShinyPal, 0x150F},
    {gFollowerMonPic2293_CascoonShinyPal,  0x1510},
    {gFollowerMonPic2294_DustoxShinyPal,   0x1511},
    {gFollowerMonPic2295_LotadShinyPal,    0x1512},
    {gFollowerMonPic2296_LombreShinyPal,   0x1513},
    {gFollowerMonPic2297_LudicoloShinyPal, 0x1514},
    {gFollowerMonPic2298_SeedotShinyPal,   0x1515},
    {gFollowerMonPic2299_NuzleafShinyPal,  0x1516},
    {gFollowerMonPic2300_ShiftryShinyPal,  0x1517},
    {gFollowerMonPic2301_NincadaShinyPal,  0x1518},
    {gFollowerMonPic2302_NinjaskShinyPal,  0x1519},
    {gFollowerMonPic2303_ShedinjaShinyPal, 0x151A},
    {gFollowerMonPic2304_TaillowShinyPal,  0x151B},
    {gFollowerMonPic2305_SwellowShinyPal,  0x151C},
    {gFollowerMonPic2306_ShroomishShinyPal, 0x151D},
    {gFollowerMonPic2307_BreloomShinyPal,  0x151E},
    {gFollowerMonPic2308_SpindaShinyPal,   0x151F},
    {gFollowerMonPic2309_WingullShinyPal,  0x1520},
    {gFollowerMonPic2310_PelipperShinyPal, 0x1521},
    {gFollowerMonPic2311_SurskitShinyPal,  0x1522},
    {gFollowerMonPic2312_MasquerainShinyPal, 0x1523},
    {gFollowerMonPic2313_WailmerShinyPal,  0x1524},
    {gFollowerMonPic2314_WailordShinyPal,  0x1525},
    {gFollowerMonPic2315_SkittyShinyPal,   0x1526},
    {gFollowerMonPic2316_DelcattyShinyPal, 0x1527},
    {gFollowerMonPic2317_KecleonShinyPal,  0x1528},
    {gFollowerMonPic2318_BaltoyShinyPal,   0x1529},
    {gFollowerMonPic2319_ClaydolShinyPal,  0x152A},
    {gFollowerMonPic2320_NosepassShinyPal, 0x152B},
    {gFollowerMonPic2321_TorkoalShinyPal,  0x152C},
    {gFollowerMonPic2322_SableyeShinyPal,  0x152D},
    {gFollowerMonPic2323_BarboachShinyPal, 0x152E},
    {gFollowerMonPic2324_WhiscashShinyPal, 0x152F},
    {gFollowerMonPic2325_LuvdiscShinyPal,  0x1530},
    {gFollowerMonPic2326_CorphishShinyPal, 0x1531},
    {gFollowerMonPic2327_CrawdauntShinyPal, 0x1532},
    {gFollowerMonPic2328_FeebasShinyPal,   0x1533},
    {gFollowerMonPic2329_MiloticShinyPal,  0x1534},
    {gFollowerMonPic2330_CarvanhaShinyPal, 0x1535},
    {gFollowerMonPic2331_SharpedoShinyPal, 0x1536},
    {gFollowerMonPic2332_TrapinchShinyPal, 0x1537},
    {gFollowerMonPic2333_VibravaShinyPal,  0x1538},
    {gFollowerMonPic2334_FlygonShinyPal,   0x1539},
    {gFollowerMonPic2335_MakuhitaShinyPal, 0x153A},
    {gFollowerMonPic2336_HariyamaShinyPal, 0x153B},
    {gFollowerMonPic2337_ElectrikeShinyPal, 0x153C},
    {gFollowerMonPic2338_ManectricShinyPal, 0x153D},
    {gFollowerMonPic2339_NumelShinyPal,    0x153E},
    {gFollowerMonPic2340_CameruptShinyPal, 0x153F},
    {gFollowerMonPic2341_SphealShinyPal,   0x1540},
    {gFollowerMonPic2342_SealeoShinyPal,   0x1541},
    {gFollowerMonPic2343_WalreinShinyPal,  0x1542},
    {gFollowerMonPic2344_CacneaShinyPal,   0x1543},
    {gFollowerMonPic2345_CacturneShinyPal, 0x1544},
    {gFollowerMonPic2346_SnoruntShinyPal,  0x1545},
    {gFollowerMonPic2347_GlalieShinyPal,   0x1546},
    {gFollowerMonPic2348_LunatoneShinyPal, 0x1547},
    {gFollowerMonPic2349_SolrockShinyPal,  0x1548},
    {gFollowerMonPic2350_AzurillShinyPal,  0x1549},
    {gFollowerMonPic2351_SpoinkShinyPal,   0x154A},
    {gFollowerMonPic2352_GrumpigShinyPal,  0x154B},
    {gFollowerMonPic2353_PlusleShinyPal,   0x154C},
    {gFollowerMonPic2354_MinunShinyPal,    0x154D},
    {gFollowerMonPic2355_MawileShinyPal,   0x154E},
    {gFollowerMonPic2356_MedititeShinyPal, 0x154F},
    {gFollowerMonPic2357_MedichamShinyPal, 0x1550},
    {gFollowerMonPic2358_SwabluShinyPal,   0x1551},
    {gFollowerMonPic2359_AltariaShinyPal,  0x1552},
    {gFollowerMonPic2360_WynautShinyPal,   0x1553},
    {gFollowerMonPic2361_DuskullShinyPal,  0x1554},
    {gFollowerMonPic2362_DusclopsShinyPal, 0x1555},
    {gFollowerMonPic2363_RoseliaShinyPal,  0x1556},
    {gFollowerMonPic2364_SlakothShinyPal,  0x1557},
    {gFollowerMonPic2365_VigorothShinyPal, 0x1558},
    {gFollowerMonPic2366_SlakingShinyPal,  0x1559},
    {gFollowerMonPic2367_GulpinShinyPal,   0x155A},
    {gFollowerMonPic2368_SwalotShinyPal,   0x155B},
    {gFollowerMonPic2369_TropiusShinyPal,  0x155C},
    {gFollowerMonPic2370_WhismurShinyPal,  0x155D},
    {gFollowerMonPic2371_LoudredShinyPal,  0x155E},
    {gFollowerMonPic2372_ExploudShinyPal,  0x155F},
    {gFollowerMonPic2373_ClamperlShinyPal, 0x1560},
    {gFollowerMonPic2374_HuntailShinyPal,  0x1561},
    {gFollowerMonPic2375_GorebyssShinyPal, 0x1562},
    {gFollowerMonPic2376_AbsolShinyPal,    0x1563},
    {gFollowerMonPic2377_ShuppetShinyPal,  0x1564},
    {gFollowerMonPic2378_BanetteShinyPal,  0x1565},
    {gFollowerMonPic2379_SeviperShinyPal,  0x1566},
    {gFollowerMonPic2380_ZangooseShinyPal, 0x1567},
    {gFollowerMonPic2381_RelicanthShinyPal, 0x1568},
    {gFollowerMonPic2382_AronShinyPal,     0x1569},
    {gFollowerMonPic2383_LaironShinyPal,   0x156A},
    {gFollowerMonPic2384_AggronShinyPal,   0x156B},
    {gFollowerMonPic2385_CastformShinyPal, 0x156C},
    {gFollowerMonPic2386_VolbeatShinyPal,  0x156D},
    {gFollowerMonPic2387_IllumiseShinyPal, 0x156E},
    {gFollowerMonPic2388_LileepShinyPal,   0x156F},
    {gFollowerMonPic2389_CradilyShinyPal,  0x1570},
    {gFollowerMonPic2390_AnorithShinyPal,  0x1571},
    {gFollowerMonPic2391_ArmaldoShinyPal,  0x1572},
    {gFollowerMonPic2392_RaltsShinyPal,    0x1573},
    {gFollowerMonPic2393_KirliaShinyPal,   0x1574},
    {gFollowerMonPic2394_GardevoirShinyPal, 0x1575},
    {gFollowerMonPic2395_BagonShinyPal,    0x1576},
    {gFollowerMonPic2396_ShelgonShinyPal,  0x1577},
    {gFollowerMonPic2397_SalamenceShinyPal, 0x1578},
    {gFollowerMonPic2398_BeldumShinyPal,   0x1579},
    {gFollowerMonPic2399_MetangShinyPal,   0x157A},
    {gFollowerMonPic2400_MetagrossShinyPal, 0x157B},
    {gFollowerMonPic2401_RegirockShinyPal, 0x157C},
    {gFollowerMonPic2402_RegiceShinyPal,   0x157D},
    {gFollowerMonPic2403_RegisteelShinyPal, 0x157E},
    {gFollowerMonPic2404_KyogreShinyPal,   0x157F},
    {gFollowerMonPic2405_GroudonShinyPal,  0x1580},
    {gFollowerMonPic2406_RayquazaShinyPal, 0x1581},
    {gFollowerMonPic2407_LatiasShinyPal,   0x1582},
    {gFollowerMonPic2408_LatiosShinyPal,   0x1583},
    {gFollowerMonPic2409_JirachiShinyPal,  0x1584},
    {gFollowerMonPic2410_DeoxysShinyPal,   0x1585},
    {gFollowerMonPic2411_ChimechoShinyPal, 0x1586},
	};


	const struct SpritePalette* const gObjectEventSpritePalettesSwitcher[255] =
	{
		[0x11] = gObjectEventSpritePalettes11,
		[0x12] = gObjectEventSpritePalettes12,
		[0x13] = gObjectEventSpritePalettes13,
		[0x14] = gObjectEventSpritePalettes14,
		[0x15] = gObjectEventSpritePalettes15,
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
