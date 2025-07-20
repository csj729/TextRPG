#pragma once
#include "Struct.h"
#include "Monster.h"

// 동물 선택
void SelectAnimal(Player* player);
// 상태 출력
void PrintStatus(const Player* player);
void UpdateExpAndLevel(Player* player, const int exp);
// 인벤 초기화
void InitInven(Player* player);
// 행동 선택
void SelectAction(Player* player, Monster* monster, Merchant* merchant);
// 전투
void Battle(Player* player, Monster* monster);
// 상태 업데이트
Item EquipItem(Player* player, const int item_idx);
void UneqiupItem(Player* player);