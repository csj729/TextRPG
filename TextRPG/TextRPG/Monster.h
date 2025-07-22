#pragma once
#include "Struct.h"
#include "Player.h"
#include "Inventory.h"
static const wchar_t* monsterNames[3] = { L"트롤", L"오크", L"고블린" };

// 상태 출력
void PrintStatus(const Monster* monster);

// 몬스터 생성
Monster CreateMonster(const wchar_t* name);
const wchar_t* PickRandomName(const wchar_t* monsterName[], int size);

// 드랍아이템 랜덤으로 픽
const Item* RollDrop(const DropTable* table);