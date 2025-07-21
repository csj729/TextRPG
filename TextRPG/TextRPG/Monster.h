#pragma once
#include "Struct.h"
#include "Player.h"
#include "Inventory.h"
const std::string monsterNames[3] = { "트롤", "오크", "고블린" };

// 상태 출력
void PrintStatus(const Monster* monster);

// 몬스터 생성
Monster CreateMonster(const std::string name);
std::string PickRandomName(const std::string monsterName[], int size);

// 드랍아이템 랜덤으로 픽
const Item* RollDrop(const DropTable* table);