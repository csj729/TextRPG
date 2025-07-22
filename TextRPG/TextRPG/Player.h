#pragma once
#include "Struct.h"
#include "Inventory.h"
#include "Monster.h"
#include "Merchant.h"
#include "LuckyBox.h"
#include "FileSave.h"
#include <wchar.h>
#include <locale.h>

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
// 장비 장착 해제
Item EquipItem(Player* player, const int item_idx);
void UneqiupItem(Player* player);
// 아이템 판매
void SellItem(Player* player);

// 입력버퍼 비우기
void flushInputBuffer();
// 제한된 시간에 정확한 스킬명을 입력해야 발동
bool SkillNameInput(const wchar_t* skillName, int timeLimitSec);
// 아스키 코드에 따라 화살표 출력
const wchar_t* ArrowName(int code);
// 제한된 시간에 정확한 커맨드를 입력해야 발동
bool SkillArrowCommandInput(const int* expectedCommand, int length, int timeLimitMs);
// 제한된 시간에 랜덤하게 주어지는 키 입력
bool SkillRandomInput(int pressCount, int timeLimitSeconds);

void PrintSkill(Player* player);
void UseSkill(Player* player, int* realDmg_PtoM, const int selNum);