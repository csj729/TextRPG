#pragma once
#include "Struct.h"
#include "Monster.h"

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