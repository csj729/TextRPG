#include "Monster.h"

void PrintStatus(const Monster* monster)
{
	std::cout << "=== ���� ���� ===\n";
	std::cout << "�̸�: " << monster->name << "\n";
	std::cout << "HP: " << monster->hp << "/" << monster->maxHp << "\n";
	std::cout << "���ݷ�: " << monster->atk << "\n";
}

Monster CreateMonster(const std::string name)
{
	Monster monster;

	if (name == "Ʈ��")
	{
		monster.name = name;
		monster.maxHp = 60;
		monster.hp = monster.maxHp;
		monster.atk = 12;
	}
	else if (name == "��ũ")
	{
		monster.name = name;
		monster.maxHp = 50;
		monster.hp = monster.maxHp;
		monster.atk = 10;
	}
	else if (name == "���")
	{
		monster.name = name;
		monster.maxHp = 30;
		monster.hp = monster.maxHp;
		monster.atk = 5;
	}

	return monster;
}

std::string PickRandomName(const std::string monsterName[], int size)
{
	int pickNum = rand() % size;
	return monsterName[pickNum];
}