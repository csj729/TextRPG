#pragma once
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <windows.h>

#define EQUIPITEM_NUM 5
#define CONSUMEITEM_NUM 3
#define INVENTORY_SIZE 10
#define DROPTABLE_NUM 3
#define STORETABLE_MAXNUM 5
#define BASE_EXP 30
#define BASIC_GOLD 500
extern int floorNum;

// 0~4까지 장착가능 장비, 장비 종류와 인덱스는 서로 일대일 대응으로 고정 ex) 0번 = 무기, 1번 = 머리
enum ItemType
{
	ITEM_EQUIPWEAPON,
	ITEM_EQUIPHEAD,
	ITEM_EQUIPBODY,
	ITEM_EQUIPGLOVES,
	ITEM_EQUIPLEG,
	ITEM_NONE,
	ITEM_CONSUME,
	ITEM_QUEST
};

enum Animal
{
	Dog = 1,
	Cat,
	Rabbit,
	Turtle,
	Quokka
};

struct BasicInfo
{
	std::string name;
	int maxHp;
	int hp;
	int atk;
	int exp = 0;
	int gold = 100;
};

typedef struct Inven
{
	std::string name;
	int maxHp;
	int hp;
	int maxMp;
	int mp;
	int atk;
	float criRate;
	float criMulti;
	ItemType itemType;

} Item;

struct DropTable
{
	Item item;
	int dropRate;
	int minCount;
	int maxCount;
};

struct StoreTable
{
	Item item;
	int price = 0;
};

extern StoreTable storeTable[STORETABLE_MAXNUM];

struct Monster
{
	BasicInfo info;
	DropTable dropTable[DROPTABLE_NUM];	
};


struct Player
{
	BasicInfo info;
	Item EquipList[EQUIPITEM_NUM];
	Item ItemList[INVENTORY_SIZE];
	int level = 1;
	int maxMp;
	int mp;
	int maxExp = BASE_EXP;
	float criRate;
	float criMulti;
};

struct Merchant
{
	int productNum = 3;
	StoreTable storeTable[STORETABLE_MAXNUM];
};