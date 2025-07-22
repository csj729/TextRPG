#pragma once
#include "Struct.h"
#include "Player.h"
#include "Monster.h"

Item MakeEmptyItem();
void PrintInven(const Player* player);
void PrintEquip(const Player* player);
void PutInven(Player* player, const Item* item);
int IsValidItem(Item* item);
void CompactItemList(Player* player);