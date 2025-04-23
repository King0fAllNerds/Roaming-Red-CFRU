#pragma once

#include "../global.h"

/**
 * \file character_customization.h
 * \brief Contains functions relating to replacing the overworld sprite, the trainer
 *		  sprite, and the backsprite of the player character.
 */

//Exported Types
typedef const struct EventObjectGraphicsInfo* NPCPtr;

//Exported Functions
u16 GetEventObjectGraphicsId(struct EventObject* eventObj);
u16 GetBackspriteId(void);
void LoadTrainerBackPal(u16 trainerPicId, u8 paletteNum);
const u8* GetTrainerSpritePal(u16 trainerPicId);
bool8 IsPaletteTagAffectedByCharacterCustomization(u16 tag);
u8 GetOutfitStyleByTrainerPic(u16 trainerPicId);
void ChangeTrainerPicPal(u16 paletteOffset, u8 outfitStyle);
void ChangeEventObjPal(u16 paletteOffset, u16 palTag);
void TryModifyMugshotTrainerPicPal(u16 trainerPicId, u8 index);

//Hooked In Functions
NPCPtr GetEventObjectGraphicsInfo(u16 graphicsId);
u16 GetPlayerAvatarGraphicsIdByStateIdAndGender(u8 state, u8 gender);
u16 GetPlayerAvatarGraphicsIdByStateId(u8 state);
u8 PlayerGenderToFrontTrainerPicId(u8 gender, bool8 modify);
void PlayerHandleDrawTrainerPic(void);
void PlayerHandleTrainerSlide(void);
void TryUpdateTrainerPicPalTrainerCard(u16 trainerPicId, u16 palOffset);

#ifdef PALETTE_SWAPPER
extern const struct SpritePalette* const gObjectEventSpritePalettesSwitcher[255];
#endif
#define gObjectEventPallete_1 ((void*)0x0835B968)
#define gObjectEventPallete_2 ((void*)0x0835E968)
#define gObjectEventPallete_3 ((void*)0x0835E988)
#define gObjectEventPallete_4 ((void*)0x0836D828)
#define gObjectEventPallete_5 ((void*)0x0836D848)
#define gObjectEventPallete_6 ((void*)0x0836D868)
#define gObjectEventPallete_7 ((void*)0x0836D888)
#define gObjectEventPallete_8 ((void*)0x0836D8A8)
#define gObjectEventPallete_9 ((void*)0x0836D8C8)
#define gObjectEventPallete_10 ((void*)0x0836D8E8)
#define gObjectEventPallete_11 ((void*)0x0836D908)
#define gObjectEventPallete_12 ((void*)0x08398008)
#define gObjectEventPallete_13 ((void*)0x08398028)
#define gObjectEventPallete_14 ((void*)0x0835B968)
#define gObjectEventPallete_15 ((void*)0x0835E968)
#define gObjectEventPallete_16 ((void*)0x08394EA8)
#define gObjectEventPallete_17 ((void*)0x08395AE8)
#define gObjectEventPallete_18 ((void*)0x083952C8)
#define gObjectEventPallete_19 ((void*)0x08F1FD48)
#define gObjectEventPallete_20 ((void*)0x08F1FD68)
#define gObjectEventPallete_21 ((void*)0x08F1FD88)
#define gObjectEventPallete_22 ((void*)0x08F1FDA8)
#define gObjectEventPallete_23 ((void*)0x08F1FDC8)
#define gObjectEventPallete_24 ((void*)0x08F1FDE8)
#define gObjectEventPallete_25 ((void*)0x08F1FE08)
#define gObjectEventPallete_26 ((void*)0x08F1FE28)
#define gObjectEventPallete_27 ((void*)0x08F1A324)
#define gObjectEventPallete_28 ((void*)0x08F1A344)
#define gObjectEventPallete_29 ((void*)0x08F1A364)
#define gObjectEventPallete_30 ((void*)0x08F1A384)
#define gObjectEventPallete_31 ((void*)0x08F1A3A4)
#define gObjectEventPallete_32 ((void*)0x08F1A3C4)
#define gObjectEventPallete_33 ((void*)0x08F1A3E4)
#define gObjectEventPallete_34 ((void*)0x08F1A404)
#define gObjectEventPallete_35 ((void*)0x08F1A424)
#define gObjectEventPallete_36 ((void*)0x08F1A444)
#define gObjectEventPallete_37 ((void*)0x08F1A464)
#define gObjectEventPallete_38 ((void*)0x08F1A484)
#define gObjectEventPallete_39 ((void*)0x08F1A4A4)
#define gObjectEventPallete_40 ((void*)0x08F1A4C4)
#define gObjectEventPallete_41 ((void*)0x08F1A4E4)
#define gObjectEventPallete_42 ((void*)0x08F1A504)
#define gObjectEventPallete_43 ((void*)0x08F1AA28)
#define gObjectEventPallete_44 ((void*)0x08F1AA48)
#define gObjectEventPallete_45 ((void*)0x08F1AA68)
#define gObjectEventPallete_46 ((void*)0x08F1AA88)
#define gObjectEventPallete_47 ((void*)0x08F1AAA8)
#define gObjectEventPallete_48 ((void*)0x08F1AAC8)
#define gObjectEventPallete_49 ((void*)0x08F1AAE8)
#define gObjectEventPallete_50 ((void*)0x08F1AB08)
#define gObjectEventPallete_51 ((void*)0x08F1AB28)
#define gObjectEventPallete_52 ((void*)0x08F1AB48)
#define gObjectEventPallete_53 ((void*)0x08F1AB68)
#define gObjectEventPallete_54 ((void*)0x08F1AB88)
#define gObjectEventPallete_55 ((void*)0x08F1ABA8)
#define gObjectEventPallete_56 ((void*)0x08F1ABC8)
#define gObjectEventPallete_57 ((void*)0x08F1ABE8)
#define gObjectEventPallete_58 ((void*)0x08F1AC08)
#define gObjectEventPallete_59 ((void*)0x08F1AC28)
#define gObjectEventPallete_60 ((void*)0x08F1AC48)
#define gObjectEventPallete_61 ((void*)0x08F1AC68)
#define gObjectEventPallete_62 ((void*)0x08F1AC88)
#define gObjectEventPallete_63 ((void*)0x08F1ACA8)
#define gObjectEventPallete_64 ((void*)0x08F1ACC8)
#define gObjectEventPallete_65 ((void*)0x08F24964)
#define gObjectEventPallete_66 ((void*)0x08F24984)
#define gObjectEventPallete_67 ((void*)0x08F249A4)
#define gObjectEventPallete_68 ((void*)0x08F249C4)
#define gObjectEventPallete_69 ((void*)0x08F249E4)
#define gObjectEventPallete_70 ((void*)0x08F24A04)
#define gObjectEventPallete_71 ((void*)0x08F24A24)
#define gObjectEventPallete_72 ((void*)0x08F24A44)
#define gObjectEventPallete_73 ((void*)0x08F24A64)
#define gObjectEventPallete_74 ((void*)0x08F24A84)
#define gObjectEventPallete_75 ((void*)0x08F24B28)

// Gen 1
extern const u16 gFollowerMonPic0001_BulbasaurPal[255];
extern const u16 gFollowerMonPic2000_BulbasaurShinyPal[255];
extern const u16 gFollowerMonPic0002_IvysaurPal[255];
extern const u16 gFollowerMonPic0003_VenusaurPal[255];
extern const u16 gFollowerMonPic0004_CharmanderPal[255];
extern const u16 gFollowerMonPic0005_CharmeleonPal[255];
extern const u16 gFollowerMonPic0006_CharizardPal[255];
extern const u16 gFollowerMonPic0007_SquirtlePal[255];
extern const u16 gFollowerMonPic0008_WartortlePal[255];
extern const u16 gFollowerMonPic0009_BlastoisePal[255];
// Gen 2
extern const u16 gFollowerMonPic0152_ChikoritaPal[255];
extern const u16 gFollowerMonPic0153_BayleefPal[255];
extern const u16 gFollowerMonPic0154_MeganiumPal[255];
extern const u16 gFollowerMonPic0155_CyndaquilPal[255];
extern const u16 gFollowerMonPic0156_QuilavaPal[255];
extern const u16 gFollowerMonPic0157_TyphlosionPal[255];
extern const u16 gFollowerMonPic0158_TotodilePal[255];
extern const u16 gFollowerMonPic0159_CroconawPal[255];
extern const u16 gFollowerMonPic0160_FeraligatrPal[255];
//Gen 3
extern const u16 gFollowerMonPic0252_TreeckoPal[255];
extern const u16 gFollowerMonPic0253_GrovylePal[255];
extern const u16 gFollowerMonPic0254_SceptilePal[255];
extern const u16 gFollowerMonPic0255_TorchicPal[255];
extern const u16 gFollowerMonPic0256_CombuskenPal[255];
extern const u16 gFollowerMonPic0257_BlazikenPal[255];
extern const u16 gFollowerMonPic0258_MudkipPal[255];
extern const u16 gFollowerMonPic0259_MarshtompPal[255];
extern const u16 gFollowerMonPic0260_SwampertPal[255];
//Gen 4
extern const u16 gFollowerMonPic0387_TurtwigPal[255];
extern const u16 gFollowerMonPic0388_GrotlePal[255];
extern const u16 gFollowerMonPic0389_TorterraPal[255];
extern const u16 gFollowerMonPic0390_ChimcharPal[255];
extern const u16 gFollowerMonPic0391_MonfernoPal[255];
extern const u16 gFollowerMonPic0392_InfernapePal[255];
extern const u16 gFollowerMonPic0393_PiplupPal[255];
extern const u16 gFollowerMonPic0394_PrinplupPal[255];
extern const u16 gFollowerMonPic0395_EmpoleonPal[255];
//Gen 5
extern const u16 gFollowerMonPic0495_SnivyPal[255];
extern const u16 gFollowerMonPic0496_ServinePal[255];
extern const u16 gFollowerMonPic0497_SerperiorPal[255];
extern const u16 gFollowerMonPic0498_TepigPal[255];
extern const u16 gFollowerMonPic0499_PignitePal[255];
extern const u16 gFollowerMonPic0500_EmboarPal[255];
extern const u16 gFollowerMonPic0501_OshawottPal[255];
extern const u16 gFollowerMonPic0502_DewottPal[255];
extern const u16 gFollowerMonPic0503_SamurottPal[255];
// Gen 6
extern const u16 gFollowerMonPic0650_ChespinPal[255];
extern const u16 gFollowerMonPic0651_QuilladinPal[255];
extern const u16 gFollowerMonPic0652_ChesnaughtPal[255];
extern const u16 gFollowerMonPic0653_FennekinPal[255];
extern const u16 gFollowerMonPic0654_BraixenPal[255];
extern const u16 gFollowerMonPic0655_DelphoxPal[255];
extern const u16 gFollowerMonPic0656_FroakiePal[255];
extern const u16 gFollowerMonPic0657_FrogadierPal[255];
extern const u16 gFollowerMonPic0658_GreninjaPal[255];
// Gen 7
extern const u16 gFollowerMonPic0722_RowletPal[255];
extern const u16 gFollowerMonPic0723_DartrixPal[255];
extern const u16 gFollowerMonPic0724_DecidueyePal[255];
extern const u16 gFollowerMonPic0725_LittenPal[255];
extern const u16 gFollowerMonPic0726_TorracatPal[255];
extern const u16 gFollowerMonPic0727_IncineroarPal[255];
extern const u16 gFollowerMonPic0728_PopplioPal[255];
extern const u16 gFollowerMonPic0729_BrionnePal[255];
extern const u16 gFollowerMonPic0730_PrimarinaPal[255];
// Gen 8
extern const u16 gFollowerMonPic0810_GrookeyPal[255];
extern const u16 gFollowerMonPic0811_ThwackeyPal[255];
extern const u16 gFollowerMonPic0812_RillaboomPal[255];
extern const u16 gFollowerMonPic0813_ScorbunnyPal[255];
extern const u16 gFollowerMonPic0814_RabootPal[255];
extern const u16 gFollowerMonPic0815_CinderacePal[255];
extern const u16 gFollowerMonPic0816_SobblePal[255];
extern const u16 gFollowerMonPic0817_DrizzilePal[255];
extern const u16 gFollowerMonPic0818_InteleonPal[255];
// Gen 9
extern const u16 gFollowerMonPic0906_SprigatitoPal[255];
extern const u16 gFollowerMonPic0907_FloragatoPal[255];
extern const u16 gFollowerMonPic0908_MeowscaradaPal[255];
extern const u16 gFollowerMonPic0909_FuecocoPal[255];
extern const u16 gFollowerMonPic0910_CrocalorPal[255];
extern const u16 gFollowerMonPic0911_SkeledirgePal[255];
extern const u16 gFollowerMonPic0912_QuaxlyPal[255];
extern const u16 gFollowerMonPic0913_QuaxwellPal[255];
extern const u16 gFollowerMonPic0914_QuaquavalPal[255];
