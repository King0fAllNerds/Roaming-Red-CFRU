#include "defines.h"
#include "../include/follower_mon.h"
#include "../include/follower_mon_sprites.h"
#include "../include/pokemon.h"
#include "../include/new/follow_me.h"
#include "../include/global.fieldmap.h"
#include "../include/event_object_movement.h"
#include "../include/script_menu.h"
#include "../include/new_menu_helpers.h"
#include "../include/script.h"


extern u8 SparkleTiles[];
extern u16 SparklePal[];

static void SpriteCB_Sparkle(struct Sprite *sprite);

static const struct OamData sSparkleOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_SQUARE,
    .x = 0,
    .matrixNum = 0,
    .size = ST_OAM_SIZE_2,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSparkleAnim0[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_FRAME(80, 5),
    ANIMCMD_END,
};

static const union AffineAnimCmd sSparkleAffineAnim0[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(4, 4, 8, 30),
    AFFINEANIMCMD_END,
};

static const union AnimCmd *const sSparkleAnimTable[] =
{
    sSparkleAnim0,
};

static const union AffineAnimCmd *const sSparkleAffineAnimTable[] =
{
    sSparkleAffineAnim0,
};

static struct SpriteSheet sSparkleTileData =
{
    .data = SparkleTiles,
    .size = (192 * 32) / 2,
    .tag = 12,
};

static struct SpritePalette sSparklePalData =
{
    .data = SparklePal,
    .tag = 12,
};

static struct SpriteTemplate sSparkleTemplate =
{
    .tileTag = 12,
    .paletteTag = 12,
    .oam = &sSparkleOamData,
    .anims = sSparkleAnimTable,
    .images = NULL,
    .affineAnims = sSparkleAffineAnimTable,
    .callback = SpriteCB_Sparkle,
};

static void SpriteCB_Sparkle(struct Sprite *sprite)
{
    if (sprite->data[0] == 30)
        DestroySprite(sprite);
    else
        sprite->data[0]++;
}

void CreateSparkleSprite(void)
{
    if (FlagGet(FLAG_FOLLOWER_POKEMON) && gFollowerState.inProgress)
    {
        struct Sprite *followerSprite = &gSprites[gEventObjects[gFollowerState.objId].spriteId];
        s16 posX = followerSprite->pos1.x - 16;
        s16 posY = followerSprite->pos1.y - 10;
        u8 spriteId;

        LoadSpriteSheet(&sSparkleTileData);
        LoadSpritePalette(&sSparklePalData);
        spriteId = CreateSprite(&sSparkleTemplate, posX, posY, 0);

        gSprites[spriteId].data[0] = 0;
        gSprites[spriteId].centerToCornerVecX = 0;
        gSprites[spriteId].centerToCornerVecY = 0;
        gSprites[spriteId].coordOffsetEnabled = TRUE;
    }
}

u16 GetFollowerMonSprite(void)
{
    u8 slotId = 7;
    u16 species;

    for (u8 i = 0; i < gPlayerPartyCount; ++i)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, NULL)
         && GetMonData(&gPlayerParty[i], MON_DATA_HP, NULL) > 0)
        {
            slotId = i;
            break;
        }
    }

    if (slotId == 7)
        return 0;

    struct Pokemon* mon = &gPlayerParty[slotId];
    species = GetMonData(mon, MON_DATA_SPECIES, NULL);

    if (IsMonShiny(mon))
        return gFollowerMonShinySpriteIdTable[species]; // Shiny sprite offset
    else
        return gFollowerMonSpriteIdTable[species];
}

void CreateFollowerMonObject(void)
{
    u16 sprite = GetFollowerMonSprite();
    if (sprite == 0)  // If there is no valid Pokémon, do not create the follower
        return;
    struct EventObject *playerObj = &gEventObjects[gPlayerAvatar->eventObjectId];
 
         s16 posX = playerObj->currentCoords.x - 7;
         s16 posY = playerObj->currentCoords.y - 7;
     
         // Adjusts follower position based on player direction
         switch (playerObj->facingDirection)
    {
        case DIR_SOUTH: posY -= 1; break;
         case DIR_NORTH: posY += 1; break;
         case DIR_WEST:  posX += 1; break;
         case DIR_EAST:  posX -= 1; break;
     }
 
     // Check if follower already exists before creating a new one
     for (u8 i = 0; i < MAP_OBJECTS_COUNT; i++)
     {
         if (gEventObjects[i].localId == 30 && gEventObjects[i].active)
             return;  // There is already a follower, so don't create another one
    }

    struct EventObjectTemplate followerObj =
    {
        .localId = 30,
        .graphicsIdLowerByte = sprite & 0xFF,
        .graphicsIdUpperByte = sprite >> 8,
        .x = posX,
        .y = posY,
        .elevation = 3,
        .movementType = 1,
        .movementRangeX = 0,
        .movementRangeY = 0,
        .trainerType = 0,
        .trainerRange_berryTreeId = 0,
    };

    SpawnSpecialEventObject(&followerObj);
}

void FollowerMonFacePlayer(void)
{
    u8 dir;

    switch (gEventObjects[gPlayerAvatar->eventObjectId].facingDirection)
    {
        case DIR_SOUTH:
            dir = DIR_NORTH;
            break;
        case DIR_NORTH:
            dir = DIR_SOUTH;
            break;
        case DIR_WEST:
            dir = DIR_EAST;
            break;
        case DIR_EAST:
            dir = DIR_WEST;
            break;
        case DIR_SOUTHWEST:
            dir = DIR_SOUTHEAST;
            break;
        case DIR_SOUTHEAST:
            dir = DIR_SOUTHWEST;
            break;
        case DIR_NORTHWEST:
            dir = DIR_NORTHEAST;
            break;
        case DIR_NORTHEAST:
            dir = DIR_NORTHWEST;
            break;
        default:
            dir = DIR_NORTH;
            break;
    }

    EventObjectTurn(&gEventObjects[gFollowerState.objId], dir);
}

void TurnFollowerMonToPlayer(void)
{
    u8 dir = gEventObjects[gPlayerAvatar->eventObjectId].facingDirection;
    EventObjectTurn(&gEventObjects[gFollowerState.objId], dir);
}

void ShowFollowerMon(void)
{
    if (FlagGet(FLAG_FOLLOWER_POKEMON) && gFollowerState.inProgress)
        gEventObjects[gFollowerState.objId].invisible = FALSE;
}
extern void Task_ScriptShowMonPic(u8 taskId);
#define gMonPaletteTable (*((struct CompressedSpritePalette**) 0x8000130))
#define gMonShinyPaletteTable (*((struct CompressedSpritePalette**) 0x8000134))

struct CompressedSpritePalette * GetSpritePalToUse(bool8 isShiny)
{
    if(isShiny)
        return gMonShinyPaletteTable;
    else
        return gMonPaletteTable;
}

u8 CreateMonSprite_MysteryGift(u16 species, s16 x, s16 y)
{
    struct Pokemon* mon = &gPlayerParty[0];
    u32 personality = 0xFFFFFFFF;
    u32 otId = T1_READ_32(gSaveBlock2->playerTrainerId);
    u16 isShiny = IsMonShiny(mon);
    const struct CompressedSpritePalette * spritePal = GetSpritePalToUse(isShiny);
    u16 spriteId = CreateMonPicSprite_HandleDeoxys(species, otId, personality, 1, x, y, 0, spritePal[species].tag);
    LoadCompressedSpritePalette(&spritePal[species]);
    if(spriteId != 0xFFFF)
    {
        gSprites[spriteId].oam.paletteNum = IndexOfSpritePaletteTag(spritePal[species].tag);
    }
    if (spriteId == 0xFFFF)
        return MAX_SPRITES;
    else
        return spriteId;
}

bool8 ScriptMenu_ShowMysteryPokemonPic(u16 species, u8 x, u8 y)
{
    u8 spriteId;
    u8 taskId;
    if (FindTaskIdByFunc(Task_ScriptShowMonPic) != 0xFF)
        return FALSE;
    spriteId = CreateMonSprite_MysteryGift(species, 8 * x + 40, 8 * y + 40);
    taskId = CreateTask(Task_ScriptShowMonPic, 80);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = species;
    gTasks[taskId].data[2] = spriteId;
    gSprites[spriteId].callback = SpriteCallbackDummy;
    gSprites[spriteId].oam.priority = 0;
    SetStandardWindowBorderStyle(gTasks[taskId].data[5], TRUE);
    ScheduleBgCopyTilemapToVram(0);
    return TRUE;
}

bool8 ShowMysteryGiftMon()
{
    u16 species = VarGet(0x4004);
    u8 x = 0x1A;
    u8 y = 0x2;

    ScriptMenu_ShowMysteryPokemonPic(species, x, y);
    return FALSE;
}
#define tState        data[0]
#define tSpecies      data[1]
#define tSpriteId     data[2]
#define tWindowId     data[5]
void Remove_PokemonPic(void)
{
    u8 taskId = FindTaskIdByFunc(Task_ScriptShowMonPic);
    
    if (taskId != 0xFF)
    {
        u8 spriteId = gTasks[taskId].tSpriteId;

        if (spriteId < MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[spriteId];

            FreeSpriteOamMatrix(sprite);
            DestroySprite(sprite);
            FreeSpriteTiles(sprite);
            FreeSpritePalette(sprite);
        }
        DestroyTask(taskId);
    }
}