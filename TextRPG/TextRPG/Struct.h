#pragma once
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <wchar.h>


#define MAX_NAME_LEN 128
#define EQUIPITEM_NUM 5
#define CONSUMEITEM_NUM 3
#define INVENTORY_SIZE 10
#define DROPTABLE_NUM 3
#define STORETABLE_MAXNUM 5
#define BASE_EXP 30
#define BASIC_GOLD 500
#define SKILL_SLOTNUM 3

extern int floorNum;

typedef enum ItemType
{
    ITEM_EQUIPWEAPON,
    ITEM_EQUIPHEAD,
    ITEM_EQUIPBODY,
    ITEM_EQUIPGLOVES,
    ITEM_EQUIPLEG,
    ITEM_NONE,
    ITEM_CONSUME,
} ItemType;

typedef enum Animal
{
    Dog = 1,
    Cat,
    Rabbit,
    Turtle,
    Quokka
} Animal;

typedef enum Buff
{
    ATK,
    MAXHP,
    MAXMP,
    CRIRATE,
    CRIMULTI
} Buff;

typedef struct BasicInfo
{
    wchar_t name[MAX_NAME_LEN];
    int maxHp;
    int hp;
    int atk;
    int exp = 0;
    int gold = 100;
} BasicInfo;

typedef struct Item
{
    wchar_t name[MAX_NAME_LEN];
    int maxHp;
    int hp;
    int maxMp;
    int mp;
    int atk;
    int gold;
    float criRate;
    float criMulti;
    ItemType itemType;
} Item;

typedef struct Skill
{
    wchar_t name[MAX_NAME_LEN];
    int atk;
} Skill;

typedef struct DropTable
{
    Item item;
    int dropRate;
    int minCount;
    int maxCount;
} DropTable;

typedef struct StoreTable
{
    Item item;
    int price;
} StoreTable;

extern StoreTable storeTable[STORETABLE_MAXNUM];

typedef struct Monster
{
    BasicInfo info;
    DropTable dropTable[DROPTABLE_NUM];
} Monster;

typedef struct Player
{
    BasicInfo info;
    Item EquipList[EQUIPITEM_NUM];
    Item ItemList[INVENTORY_SIZE];
    Skill SkillList[SKILL_SLOTNUM];
    int level = 1;
    int maxMp;
    int mp;
    int maxExp = BASE_EXP;
    float criRate;
    float criMulti;
} Player;

typedef struct Merchant
{
    int productNum = 3;
    StoreTable storeTable[STORETABLE_MAXNUM];
} Merchant;