#pragma once
#include "Struct.h"
#include "Monster.h"


// ���� ����
void SelectAnimal(Player* player);
// ���� ���
void PrintStatus(const Player* player);
// �κ� �ʱ�ȭ
void InitInven(const Player* player);
// �ൿ ����
void SelectAction(Player* player, Monster* monster);
// ����
void Battle(Player* player, Monster* monster);