#include "Monster.h"

void PrintStatus(const Monster* monster)
{
	wprintf(L"=== ���� ���� ===\n");
	wprintf(L"�̸�: %ls\n", monster->info.name);
	wprintf(L"HP: %d/%d\n", monster->info.hp, monster->info.maxHp);
	wprintf(L"���ݷ�: %d\n", monster->info.atk);
}

Monster CreateMonster(const wchar_t* name)
{
	Monster monster = {0};

	if (wcscmp(name, L"Ʈ��") == 0 )
	{
		wcscpy_s(monster.info.name, L"Ʈ��");
		monster.info.maxHp = 30;
		monster.info.hp = monster.info.maxHp;
		monster.info.atk = 6;
		monster.info.exp = 30;
		monster.info.gold = 50;
		monster.dropTable[0] = { { L"Ʈ���� ������", 50, 50, 0, 0, 10, 100, 0.0f, 0.0f, ITEM_EQUIPWEAPON }, 50, 1, 1 };
		monster.dropTable[1] = { { L"Ʈ�� ����", 50, 50, 0, 0, 5, 100,0.0f, 0.0f, ITEM_EQUIPBODY } , 50, 1, 1 };
		monster.dropTable[2] = { { L"����� ����", 0, 50, 0, 0, 0, 50, 0.0f, 0.0f, ITEM_CONSUME }, 0, 1, 2 };
	}
	else if (wcscmp(name, L"��ũ") == 0)
	{
		wcscpy_s(monster.info.name, L"��ũ");
		monster.info.maxHp = 25;
		monster.info.hp = monster.info.maxHp;
		monster.info.atk = 5;
		monster.info.exp = 20;
		monster.info.gold = 40;
		monster.dropTable[0] = { { L"��ũ�� ����", 0, 0, 0, 0, 30, 100, 0.2f, 0.3f, ITEM_EQUIPWEAPON }, 50, 1, 1 };
		monster.dropTable[1] = { { L"��ũ ����", 20, 20, 0, 0, 10, 100, 0.0f, 0.0f, ITEM_EQUIPBODY }, 50 , 1, 1 };
		monster.dropTable[2] = { { L"���ݷ� ����", 0, 0, 0, 0, 30, 50, 0.0f, 0.0f, ITEM_CONSUME }, 0, 1, 1 };

	}
	else if (wcscmp(name, L"���") == 0)
	{
		wcscpy_s(monster.info.name, L"���");
		monster.info.maxHp = 20;
		monster.info.hp = monster.info.maxHp;
		monster.info.atk = 3;
		monster.info.exp = 10;
		monster.info.gold = 30;
		monster.dropTable[0] = { { L"����� ������", 0, 0, 20, 20, 10, 100, 0.1f, 0.1f, ITEM_EQUIPWEAPON }, 50, 1, 1 };
		monster.dropTable[1] = { { L"��� �κ�", 0, 0, 30, 30, 10, 100, 0.1f, 0.1f, ITEM_EQUIPBODY}, 50, 1, 1 };
		monster.dropTable[2] = { { L"���� ����", 0, 0, 0, 50, 0, 50, 0.0f, 0.0f, ITEM_CONSUME }, 0, 1, 1 };
	}

	return monster;
}

const wchar_t* PickRandomName(const wchar_t* monsterName[], int size)
{
	int pickNum = rand() % size;
	return monsterName[pickNum];
}

const Item* RollDrop(const DropTable* table)
{
	int roll = rand() % 100;

	for (int i = 0; i < DROPTABLE_NUM; ++i) {
		if (roll <= table[i].dropRate) {
			return &table[i].item;
		}
		roll -= table[i].dropRate;
	}

	return NULL; // �ƹ��͵� �� ������
}