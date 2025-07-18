#include "Monster.h"

void PrintStatus(const Monster* monster)
{
	std::cout << "=== 몬스터 상태 ===\n";
	std::cout << "이름: " << monster->name << "\n";
	std::cout << "HP: " << monster->hp << "/" << monster->maxHp << "\n";
	std::cout << "공격력: " << monster->atk << "\n";
}

Monster CreateMonster(const std::string name)
{
	Monster monster;

	if (name == "트롤")
	{
		monster.name = name;
		monster.maxHp = 60;
		monster.hp = monster.maxHp;
		monster.atk = 12;
	}
	else if (name == "오크")
	{
		monster.name = name;
		monster.maxHp = 50;
		monster.hp = monster.maxHp;
		monster.atk = 10;
	}
	else if (name == "고블린")
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