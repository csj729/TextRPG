#pragma once
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <windows.h>

#define EQUIPITEM_NUM 6
#define CONSUMEITEM_NUM 3
#define DROPTABLE_NUM 3
extern int floorNum;
extern int playerLevel;

enum ItemType 
{
	ITEM_NONE = 1 << 0,
	ITEM_CONSUME = 1 << 1,
	ITEM_EQUIP = 1 << 2,
	ITEM_QUEST = 1 << 3,
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

struct Monster
{
	BasicInfo info;
	DropTable dropTable[DROPTABLE_NUM];
};


struct Player
{
	BasicInfo info;
	Inven EquipItem[EQUIPITEM_NUM];
	Inven ConsumeItem[CONSUMEITEM_NUM];
	int level;
	int maxMp;
	int mp;
	float criRate;
	float criMulti;
	int exp = 0;
};