#pragma once
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <windows.h>

#define GEARITEM_NUM 6
#define USEITEM_NUM 3
extern int floorNum;
extern int playerLevel;

enum Animal
{
	Dog = 1,
	Cat,
	Rabbit,
	Turtle,
	Quokka
};

typedef struct BasicInfo
{
	std::string name;
	int maxHp;
	int hp;
	int atk;
} Monster;

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
} Gear, Consume, Item;

struct Player
{
	BasicInfo info;
	Inven Gearitem[GEARITEM_NUM];
	Inven Useitem[USEITEM_NUM];
	int level;
	int maxMp;
	int mp;
	float criRate;
	float criMulti;
	int exp = 0;
};