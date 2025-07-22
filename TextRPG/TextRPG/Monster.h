#pragma once
#include "Struct.h"
#include "Player.h"
#include "Inventory.h"
static const wchar_t* monsterNames[3] = { L"Ʈ��", L"��ũ", L"���" };

// ���� ���
void PrintStatus(const Monster* monster);

// ���� ����
Monster CreateMonster(const wchar_t* name);
const wchar_t* PickRandomName(const wchar_t* monsterName[], int size);

// ��������� �������� ��
const Item* RollDrop(const DropTable* table);