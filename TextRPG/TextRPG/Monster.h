#pragma once
#include "Struct.h"
#include "Player.h"
#include "Inventory.h"
const std::string monsterNames[3] = { "Ʈ��", "��ũ", "���" };
const Item TrollDropTable[3] =
{
	{"Ʈ���� ������", 50, 0, 0, 0, 10, 0.0f, 0.0f},
	{"Ʈ�� ����", 50, 0, 0, 0, 5, 0.0f, 0.0f},
	{"����� ����", 0, 50, 0, 0, 0, 0.0f, 0.0f}
};

const Item OrcDropTable[3] =
{
	{"��ũ�� ����", 0, 0, 0, 0, 30, 0.2f, 0.3f},
	{"��ũ ����", 20, 0, 0, 0, 10, 0.0f, 0.0f},
	{"���ݷ� ����", 0, 0, 0, 0, 30, 0.0f, 0.0f}
};

const Item GoblinDropTable[3] =
{
	{"����� ������", 0, 0, 20, 0, 10, 0.1f, 0.1f},
	{"��� �κ�", 0, 0, 30, 0, 10, 0.1f, 0.1f},
	{"���� ����", 0, 0, 0, 50, 0, 0.0f, 0.0f}
};
// ���� ���
void PrintStatus(const Monster* monster);

// ���� ����
Monster CreateMonster(const std::string name);

std::string PickRandomName(const std::string monsterName[], int size);