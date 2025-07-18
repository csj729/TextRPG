#pragma once
#include "Struct.h"
#include "Monster.h"


// 동물 선택
void SelectAnimal(Player* player);
// 상태 출력
void PrintStatus(const Player* player);
// 인벤 초기화
void InitInven(const Player* player);
// 행동 선택
void SelectAction(Player* player, Monster* monster);
// 전투
void Battle(Player* player, Monster* monster);