#pragma once
#include "Struct.h"
#include "Inventory.h"
#include "Monster.h"
#include "Merchant.h"
#include "LuckyBox.h"
#include "FileSave.h"
#include <wchar.h>
#include <locale.h>

// ���� ����
void SelectAnimal(Player* player);
// ���� ���
void PrintStatus(const Player* player);
void UpdateExpAndLevel(Player* player, const int exp);
// �κ� �ʱ�ȭ
void InitInven(Player* player);
// �ൿ ����
void SelectAction(Player* player, Monster* monster, Merchant* merchant);
// ����
void Battle(Player* player, Monster* monster);
// ��� ���� ����
Item EquipItem(Player* player, const int item_idx);
void UneqiupItem(Player* player);
// ������ �Ǹ�
void SellItem(Player* player);

// �Է¹��� ����
void flushInputBuffer();
// ���ѵ� �ð��� ��Ȯ�� ��ų���� �Է��ؾ� �ߵ�
bool SkillNameInput(const wchar_t* skillName, int timeLimitSec);
// �ƽ�Ű �ڵ忡 ���� ȭ��ǥ ���
const wchar_t* ArrowName(int code);
// ���ѵ� �ð��� ��Ȯ�� Ŀ�ǵ带 �Է��ؾ� �ߵ�
bool SkillArrowCommandInput(const int* expectedCommand, int length, int timeLimitMs);
// ���ѵ� �ð��� �����ϰ� �־����� Ű �Է�
bool SkillRandomInput(int pressCount, int timeLimitSeconds);

void PrintSkill(Player* player);
void UseSkill(Player* player, int* realDmg_PtoM, const int selNum);