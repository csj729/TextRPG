#pragma once
#include "Struct.h"
#include "Player.h"
#include "Monster.h"

Inven MakeEmptyItem();
void PrintInven(const Player* player);
void PrintEquip(const Player* player);
void PutInven(Player* player, const Item* item);
