#pragma once
#include "Struct.h"
#include "Player.h"
#include "Inventory.h"
const std::string monsterNames[3] = { "Ʈ��", "��ũ", "���" };

// ���� ���
void PrintStatus(const Monster* monster);

// ���� ����
Monster CreateMonster(const std::string name);
std::string PickRandomName(const std::string monsterName[], int size);

// ��������� �������� ��
const Item* RollDrop(const DropTable* table);