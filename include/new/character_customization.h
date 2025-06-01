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
extern const u16 gFollowerMonPic0002_IvysaurPal[255];
extern const u16 gFollowerMonPic0003_VenusaurPal[255];
extern const u16 gFollowerMonPic0004_CharmanderPal[255];
extern const u16 gFollowerMonPic0005_CharmeleonPal[255];
extern const u16 gFollowerMonPic0006_CharizardPal[255];
extern const u16 gFollowerMonPic0007_SquirtlePal[255];
extern const u16 gFollowerMonPic0008_WartortlePal[255];
extern const u16 gFollowerMonPic0009_BlastoisePal[255];
extern const u16 gFollowerMonPic0010_CaterpiePal[255];
extern const u16 gFollowerMonPic0011_MetapodPal[255];
extern const u16 gFollowerMonPic0012_ButterfreePal[255];
extern const u16 gFollowerMonPic0013_WeedlePal[255];
extern const u16 gFollowerMonPic0014_KakunaPal[255];
extern const u16 gFollowerMonPic0015_BeedrillPal[255];
extern const u16 gFollowerMonPic0016_PidgeyPal[255];
extern const u16 gFollowerMonPic0017_PidgeottoPal[255];
extern const u16 gFollowerMonPic0018_PidgeotPal[255];
extern const u16 gFollowerMonPic0019_RattataPal[255];
extern const u16 gFollowerMonPic0020_RaticatePal[255];
extern const u16 gFollowerMonPic0021_SpearowPal[255];
extern const u16 gFollowerMonPic0022_FearowPal[255];
extern const u16 gFollowerMonPic0023_EkansPal[255];
extern const u16 gFollowerMonPic0024_ArbokPal[255];
extern const u16 gFollowerMonPic0025_PikachuPal[255];
extern const u16 gFollowerMonPic0026_RaichuPal[255];
extern const u16 gFollowerMonPic0027_SandshrewPal[255];
extern const u16 gFollowerMonPic0028_SandslashPal[255];
extern const u16 gFollowerMonPic0029_NidoranFPal[255];
extern const u16 gFollowerMonPic0030_NidorinaPal[255];
extern const u16 gFollowerMonPic0031_NidoqueenPal[255];
extern const u16 gFollowerMonPic0032_NidoranMPal[255];
extern const u16 gFollowerMonPic0033_NidorinoPal[255];
extern const u16 gFollowerMonPic0034_NidokingPal[255];
extern const u16 gFollowerMonPic0035_ClefairyPal[255];
extern const u16 gFollowerMonPic0036_ClefablePal[255];
extern const u16 gFollowerMonPic0037_VulpixPal[255];
extern const u16 gFollowerMonPic0038_NinetalesPal[255];
extern const u16 gFollowerMonPic0039_JigglypuffPal[255];
extern const u16 gFollowerMonPic0040_WigglytuffPal[255];
extern const u16 gFollowerMonPic0041_ZubatPal[255];
extern const u16 gFollowerMonPic0042_GolbatPal[255];
extern const u16 gFollowerMonPic0043_OddishPal[255];
extern const u16 gFollowerMonPic0044_GloomPal[255];
extern const u16 gFollowerMonPic0045_VileplumePal[255];
extern const u16 gFollowerMonPic0046_ParasPal[255];
extern const u16 gFollowerMonPic0047_ParasectPal[255];
extern const u16 gFollowerMonPic0048_VenonatPal[255];
extern const u16 gFollowerMonPic0049_VenomothPal[255];
extern const u16 gFollowerMonPic0050_DiglettPal[255];
extern const u16 gFollowerMonPic0051_DugtrioPal[255];
extern const u16 gFollowerMonPic0052_MeowthPal[255];
extern const u16 gFollowerMonPic0053_PersianPal[255];
extern const u16 gFollowerMonPic0054_PsyduckPal[255];
extern const u16 gFollowerMonPic0055_GolduckPal[255];
extern const u16 gFollowerMonPic0056_MankeyPal[255];
extern const u16 gFollowerMonPic0057_PrimeapePal[255];
extern const u16 gFollowerMonPic0058_GrowlithePal[255];
extern const u16 gFollowerMonPic0059_ArcaninePal[255];
extern const u16 gFollowerMonPic0060_PoliwagPal[255];
extern const u16 gFollowerMonPic0061_PoliwhirlPal[255];
extern const u16 gFollowerMonPic0062_PoliwrathPal[255];
extern const u16 gFollowerMonPic0063_AbraPal[255];
extern const u16 gFollowerMonPic0064_KadabraPal[255];
extern const u16 gFollowerMonPic0065_AlakazamPal[255];
extern const u16 gFollowerMonPic0066_MachopPal[255];
extern const u16 gFollowerMonPic0067_MachokePal[255];
extern const u16 gFollowerMonPic0068_MachampPal[255];
extern const u16 gFollowerMonPic0069_BellsproutPal[255];
extern const u16 gFollowerMonPic0070_WeepinbellPal[255];
extern const u16 gFollowerMonPic0071_VictreebelPal[255];
extern const u16 gFollowerMonPic0072_TentacoolPal[255];
extern const u16 gFollowerMonPic0073_TentacruelPal[255];
extern const u16 gFollowerMonPic0074_GeodudePal[255];
extern const u16 gFollowerMonPic0075_GravelerPal[255];
extern const u16 gFollowerMonPic0076_GolemPal[255];
extern const u16 gFollowerMonPic0077_PonytaPal[255];
extern const u16 gFollowerMonPic0078_RapidashPal[255];
extern const u16 gFollowerMonPic0079_SlowpokePal[255];
extern const u16 gFollowerMonPic0080_SlowbroPal[255];
extern const u16 gFollowerMonPic0081_MagnemitePal[255];
extern const u16 gFollowerMonPic0082_MagnetonPal[255];
extern const u16 gFollowerMonPic0083_FarfetchdPal[255];
extern const u16 gFollowerMonPic0084_DoduoPal[255];
extern const u16 gFollowerMonPic0085_DodrioPal[255];
extern const u16 gFollowerMonPic0086_SeelPal[255];
extern const u16 gFollowerMonPic0087_DewgongPal[255];
extern const u16 gFollowerMonPic0088_GrimerPal[255];
extern const u16 gFollowerMonPic0089_MukPal[255];
extern const u16 gFollowerMonPic0090_ShellderPal[255];
extern const u16 gFollowerMonPic0091_CloysterPal[255];
extern const u16 gFollowerMonPic0092_GastlyPal[255];
extern const u16 gFollowerMonPic0093_HaunterPal[255];
extern const u16 gFollowerMonPic0094_GengarPal[255];
extern const u16 gFollowerMonPic0095_OnixPal[255];
extern const u16 gFollowerMonPic0096_DrowzeePal[255];
extern const u16 gFollowerMonPic0097_HypnoPal[255];
extern const u16 gFollowerMonPic0098_KrabbyPal[255];
extern const u16 gFollowerMonPic0099_KinglerPal[255];
extern const u16 gFollowerMonPic0100_VoltorbPal[255];
extern const u16 gFollowerMonPic0101_ElectrodePal[255];
extern const u16 gFollowerMonPic0102_ExeggcutePal[255];
extern const u16 gFollowerMonPic0103_ExeggutorPal[255];
extern const u16 gFollowerMonPic0104_CubonePal[255];
extern const u16 gFollowerMonPic0105_MarowakPal[255];
extern const u16 gFollowerMonPic0106_HitmonleePal[255];
extern const u16 gFollowerMonPic0107_HitmonchanPal[255];
extern const u16 gFollowerMonPic0108_LickitungPal[255];
extern const u16 gFollowerMonPic0109_KoffingPal[255];
extern const u16 gFollowerMonPic0110_WeezingPal[255];
extern const u16 gFollowerMonPic0111_RhyhornPal[255];
extern const u16 gFollowerMonPic0112_RhydonPal[255];
extern const u16 gFollowerMonPic0113_ChanseyPal[255];
extern const u16 gFollowerMonPic0114_TangelaPal[255];
extern const u16 gFollowerMonPic0115_KangaskhanPal[255];
extern const u16 gFollowerMonPic0116_HorseaPal[255];
extern const u16 gFollowerMonPic0117_SeadraPal[255];
extern const u16 gFollowerMonPic0118_GoldeenPal[255];
extern const u16 gFollowerMonPic0119_SeakingPal[255];
extern const u16 gFollowerMonPic0120_StaryuPal[255];
extern const u16 gFollowerMonPic0121_StarmiePal[255];
extern const u16 gFollowerMonPic0122_MrMimePal[255];
extern const u16 gFollowerMonPic0123_ScytherPal[255];
extern const u16 gFollowerMonPic0124_JynxPal[255];
extern const u16 gFollowerMonPic0125_ElectabuzzPal[255];
extern const u16 gFollowerMonPic0126_MagmarPal[255];
extern const u16 gFollowerMonPic0127_PinsirPal[255];
extern const u16 gFollowerMonPic0128_TaurosPal[255];
extern const u16 gFollowerMonPic0129_MagikarpPal[255];
extern const u16 gFollowerMonPic0130_GyaradosPal[255];
extern const u16 gFollowerMonPic0131_LaprasPal[255];
extern const u16 gFollowerMonPic0132_DittoPal[255];
extern const u16 gFollowerMonPic0133_EeveePal[255];
extern const u16 gFollowerMonPic0134_VaporeonPal[255];
extern const u16 gFollowerMonPic0135_JolteonPal[255];
extern const u16 gFollowerMonPic0136_FlareonPal[255];
extern const u16 gFollowerMonPic0137_PorygonPal[255];
extern const u16 gFollowerMonPic0138_OmanytePal[255];
extern const u16 gFollowerMonPic0139_OmastarPal[255];
extern const u16 gFollowerMonPic0140_KabutoPal[255];
extern const u16 gFollowerMonPic0141_KabutopsPal[255];
extern const u16 gFollowerMonPic0142_AerodactylPal[255];
extern const u16 gFollowerMonPic0143_SnorlaxPal[255];
extern const u16 gFollowerMonPic0144_ArticunoPal[255];
extern const u16 gFollowerMonPic0145_ZapdosPal[255];
extern const u16 gFollowerMonPic0146_MoltresPal[255];
extern const u16 gFollowerMonPic0147_DratiniPal[255];
extern const u16 gFollowerMonPic0148_DragonairPal[255];
extern const u16 gFollowerMonPic0149_DragonitePal[255];
extern const u16 gFollowerMonPic0150_MewtwoPal[255];
extern const u16 gFollowerMonPic0151_MewPal[255];


//Shiny
extern const u16 gFollowerMonPic2001_BulbasaurShinyPal[255];
extern const u16 gFollowerMonPic2002_IvysaurShinyPal[255];
extern const u16 gFollowerMonPic2003_VenusaurShinyPal[255];
extern const u16 gFollowerMonPic2004_CharmanderShinyPal[255];
extern const u16 gFollowerMonPic2005_CharmeleonShinyPal[255];
extern const u16 gFollowerMonPic2006_CharizardShinyPal[255];
extern const u16 gFollowerMonPic2007_SquirtleShinyPal[255];
extern const u16 gFollowerMonPic2008_WartortleShinyPal[255];
extern const u16 gFollowerMonPic2009_BlastoiseShinyPal[255];
extern const u16 gFollowerMonPic2010_CaterpieShinyPal[255];
extern const u16 gFollowerMonPic2011_MetapodShinyPal[255];
extern const u16 gFollowerMonPic2012_ButterfreeShinyPal[255];
extern const u16 gFollowerMonPic2013_WeedleShinyPal[255];
extern const u16 gFollowerMonPic2014_KakunaShinyPal[255];
extern const u16 gFollowerMonPic2015_BeedrillShinyPal[255];
extern const u16 gFollowerMonPic2016_PidgeyShinyPal[255];
extern const u16 gFollowerMonPic2017_PidgeottoShinyPal[255];
extern const u16 gFollowerMonPic2018_PidgeotShinyPal[255];
extern const u16 gFollowerMonPic2019_RattataShinyPal[255];
extern const u16 gFollowerMonPic2020_RaticateShinyPal[255];
extern const u16 gFollowerMonPic2021_SpearowShinyPal[255];
extern const u16 gFollowerMonPic2022_FearowShinyPal[255];
extern const u16 gFollowerMonPic2023_EkansShinyPal[255];
extern const u16 gFollowerMonPic2024_ArbokShinyPal[255];
extern const u16 gFollowerMonPic2025_PikachuShinyPal[255];
extern const u16 gFollowerMonPic2026_RaichuShinyPal[255];
extern const u16 gFollowerMonPic2027_SandshrewShinyPal[255];
extern const u16 gFollowerMonPic2028_SandslashShinyPal[255];
extern const u16 gFollowerMonPic2029_NidoranFShinyPal[255];
extern const u16 gFollowerMonPic2030_NidorinaShinyPal[255];
extern const u16 gFollowerMonPic2031_NidoqueenShinyPal[255];
extern const u16 gFollowerMonPic2032_NidoranMShinyPal[255];
extern const u16 gFollowerMonPic2033_NidorinoShinyPal[255];
extern const u16 gFollowerMonPic2034_NidokingShinyPal[255];
extern const u16 gFollowerMonPic2035_ClefairyShinyPal[255];
extern const u16 gFollowerMonPic2036_ClefableShinyPal[255];
extern const u16 gFollowerMonPic2037_VulpixShinyPal[255];
extern const u16 gFollowerMonPic2038_NinetalesShinyPal[255];
extern const u16 gFollowerMonPic2039_JigglypuffShinyPal[255];
extern const u16 gFollowerMonPic2040_WigglytuffShinyPal[255];
extern const u16 gFollowerMonPic2041_ZubatShinyPal[255];
extern const u16 gFollowerMonPic2042_GolbatShinyPal[255];
extern const u16 gFollowerMonPic2043_OddishShinyPal[255];
extern const u16 gFollowerMonPic2044_GloomShinyPal[255];
extern const u16 gFollowerMonPic2045_VileplumeShinyPal[255];
extern const u16 gFollowerMonPic2046_ParasShinyPal[255];
extern const u16 gFollowerMonPic2047_ParasectShinyPal[255];
extern const u16 gFollowerMonPic2048_VenonatShinyPal[255];
extern const u16 gFollowerMonPic2049_VenomothShinyPal[255];
extern const u16 gFollowerMonPic2050_DiglettShinyPal[255];
extern const u16 gFollowerMonPic2051_DugtrioShinyPal[255];
extern const u16 gFollowerMonPic2052_MeowthShinyPal[255];
extern const u16 gFollowerMonPic2053_PersianShinyPal[255];
extern const u16 gFollowerMonPic2054_PsyduckShinyPal[255];
extern const u16 gFollowerMonPic2055_GolduckShinyPal[255];
extern const u16 gFollowerMonPic2056_MankeyShinyPal[255];
extern const u16 gFollowerMonPic2057_PrimeapeShinyPal[255];
extern const u16 gFollowerMonPic2058_GrowlitheShinyPal[255];
extern const u16 gFollowerMonPic2059_ArcanineShinyPal[255];
extern const u16 gFollowerMonPic2060_PoliwagShinyPal[255];
extern const u16 gFollowerMonPic2061_PoliwhirlShinyPal[255];
extern const u16 gFollowerMonPic2062_PoliwrathShinyPal[255];
extern const u16 gFollowerMonPic2063_AbraShinyPal[255];
extern const u16 gFollowerMonPic2064_KadabraShinyPal[255];
extern const u16 gFollowerMonPic2065_AlakazamShinyPal[255];
extern const u16 gFollowerMonPic2066_MachopShinyPal[255];
extern const u16 gFollowerMonPic2067_MachokeShinyPal[255];
extern const u16 gFollowerMonPic2068_MachampShinyPal[255];
extern const u16 gFollowerMonPic2069_BellsproutShinyPal[255];
extern const u16 gFollowerMonPic2070_WeepinbellShinyPal[255];
extern const u16 gFollowerMonPic2071_VictreebelShinyPal[255];
extern const u16 gFollowerMonPic2072_TentacoolShinyPal[255];
extern const u16 gFollowerMonPic2073_TentacruelShinyPal[255];
extern const u16 gFollowerMonPic2074_GeodudeShinyPal[255];
extern const u16 gFollowerMonPic2075_GravelerShinyPal[255];
extern const u16 gFollowerMonPic2076_GolemShinyPal[255];
extern const u16 gFollowerMonPic2077_PonytaShinyPal[255];
extern const u16 gFollowerMonPic2078_RapidashShinyPal[255];
extern const u16 gFollowerMonPic2079_SlowpokeShinyPal[255];
extern const u16 gFollowerMonPic2080_SlowbroShinyPal[255];
extern const u16 gFollowerMonPic2081_MagnemiteShinyPal[255];
extern const u16 gFollowerMonPic2082_MagnetonShinyPal[255];
extern const u16 gFollowerMonPic2083_FarfetchdShinyPal[255];
extern const u16 gFollowerMonPic2084_DoduoShinyPal[255];
extern const u16 gFollowerMonPic2085_DodrioShinyPal[255];
extern const u16 gFollowerMonPic2086_SeelShinyPal[255];
extern const u16 gFollowerMonPic2087_DewgongShinyPal[255];
extern const u16 gFollowerMonPic2088_GrimerShinyPal[255];
extern const u16 gFollowerMonPic2089_MukShinyPal[255];
extern const u16 gFollowerMonPic2090_ShellderShinyPal[255];
extern const u16 gFollowerMonPic2091_CloysterShinyPal[255];
extern const u16 gFollowerMonPic2092_GastlyShinyPal[255];
extern const u16 gFollowerMonPic2093_HaunterShinyPal[255];
extern const u16 gFollowerMonPic2094_GengarShinyPal[255];
extern const u16 gFollowerMonPic2095_OnixShinyPal[255];
extern const u16 gFollowerMonPic2096_DrowzeeShinyPal[255];
extern const u16 gFollowerMonPic2097_HypnoShinyPal[255];
extern const u16 gFollowerMonPic2098_KrabbyShinyPal[255];
extern const u16 gFollowerMonPic2099_KinglerShinyPal[255];
extern const u16 gFollowerMonPic2100_VoltorbShinyPal[255];
extern const u16 gFollowerMonPic2101_ElectrodeShinyPal[255];
extern const u16 gFollowerMonPic2102_ExeggcuteShinyPal[255];
extern const u16 gFollowerMonPic2103_ExeggutorShinyPal[255];
extern const u16 gFollowerMonPic2104_CuboneShinyPal[255];
extern const u16 gFollowerMonPic2105_MarowakShinyPal[255];
extern const u16 gFollowerMonPic2106_HitmonleeShinyPal[255];
extern const u16 gFollowerMonPic2107_HitmonchanShinyPal[255];
extern const u16 gFollowerMonPic2108_LickitungShinyPal[255];
extern const u16 gFollowerMonPic2109_KoffingShinyPal[255];
extern const u16 gFollowerMonPic2110_WeezingShinyPal[255];
extern const u16 gFollowerMonPic2111_RhyhornShinyPal[255];
extern const u16 gFollowerMonPic2112_RhydonShinyPal[255];
extern const u16 gFollowerMonPic2113_ChanseyShinyPal[255];
extern const u16 gFollowerMonPic2114_TangelaShinyPal[255];
extern const u16 gFollowerMonPic2115_KangaskhanShinyPal[255];
extern const u16 gFollowerMonPic2116_HorseaShinyPal[255];
extern const u16 gFollowerMonPic2117_SeadraShinyPal[255];
extern const u16 gFollowerMonPic2118_GoldeenShinyPal[255];
extern const u16 gFollowerMonPic2119_SeakingShinyPal[255];
extern const u16 gFollowerMonPic2120_StaryuShinyPal[255];
extern const u16 gFollowerMonPic2121_StarmieShinyPal[255];
extern const u16 gFollowerMonPic2122_MrMimeShinyPal[255];
extern const u16 gFollowerMonPic2123_ScytherShinyPal[255];
extern const u16 gFollowerMonPic2124_JynxShinyPal[255];
extern const u16 gFollowerMonPic2125_ElectabuzzShinyPal[255];
extern const u16 gFollowerMonPic2126_MagmarShinyPal[255];
extern const u16 gFollowerMonPic2127_PinsirShinyPal[255];
extern const u16 gFollowerMonPic2128_TaurosShinyPal[255];
extern const u16 gFollowerMonPic2129_MagikarpShinyPal[255];
extern const u16 gFollowerMonPic2130_GyaradosShinyPal[255];
extern const u16 gFollowerMonPic2131_LaprasShinyPal[255];
extern const u16 gFollowerMonPic2132_DittoShinyPal[255];
extern const u16 gFollowerMonPic2133_EeveeShinyPal[255];
extern const u16 gFollowerMonPic2134_VaporeonShinyPal[255];
extern const u16 gFollowerMonPic2135_JolteonShinyPal[255];
extern const u16 gFollowerMonPic2136_FlareonShinyPal[255];
extern const u16 gFollowerMonPic2137_PorygonShinyPal[255];
extern const u16 gFollowerMonPic2138_OmanyteShinyPal[255];
extern const u16 gFollowerMonPic2139_OmastarShinyPal[255];
extern const u16 gFollowerMonPic2140_KabutoShinyPal[255];
extern const u16 gFollowerMonPic2141_KabutopsShinyPal[255];
extern const u16 gFollowerMonPic2142_AerodactylShinyPal[255];
extern const u16 gFollowerMonPic2143_SnorlaxShinyPal[255];
extern const u16 gFollowerMonPic2144_ArticunoShinyPal[255];
extern const u16 gFollowerMonPic2145_ZapdosShinyPal[255];
extern const u16 gFollowerMonPic2146_MoltresShinyPal[255];
extern const u16 gFollowerMonPic2147_DratiniShinyPal[255];
extern const u16 gFollowerMonPic2148_DragonairShinyPal[255];
extern const u16 gFollowerMonPic2149_DragoniteShinyPal[255];
extern const u16 gFollowerMonPic2150_MewtwoShinyPal[255];
extern const u16 gFollowerMonPic2151_MewShinyPal[255];


