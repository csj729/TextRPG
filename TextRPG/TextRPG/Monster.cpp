#include "Monster.h"

void PrintStatus(const Monster* monster)
{
	std::cout << "=== 몬스터 상태 ===\n";
	std::cout << "이름: " << monster->info.name << "\n";
	std::cout << "HP: " << monster->info.hp << "/" << monster->info.maxHp << "\n";
	std::cout << "공격력: " << monster->info.atk << "\n";
}

Monster CreateMonster(const std::string name)
{
	Monster monster;

	if (name == "트롤")
	{
		monster.info.name = name;
		monster.info.maxHp = 60;
		monster.info.hp = monster.info.maxHp;
		monster.info.atk = 12;
		monster.dropTable[0] = { { "트롤의 몽둥이", 50, 0, 0, 0, 10, 0.0f, 0.0f, ITEM_EQUIP }, 20, 1, 1 };
		monster.dropTable[1] = { { "트롤 갑옷", 50, 0, 0, 0, 5, 0.0f, 0.0f, ITEM_EQUIP } , 20, 1, 1 };
		monster.dropTable[2] = { { "생명력 포션", 0, 50, 0, 0, 0, 0.0f, 0.0f, ITEM_CONSUME }, 50, 1, 2 };
	}
	else if (name == "오크")
	{
		monster.info.name = name;
		monster.info.maxHp = 50;
		monster.info.hp = monster.info.maxHp;
		monster.info.atk = 10;
		monster.dropTable[0] = { { "오크의 도끼", 0, 0, 0, 0, 30, 0.2f, 0.3f, ITEM_EQUIP }, 20, 1, 1 };
		monster.dropTable[1] = { { "오크 갑옷", 20, 0, 0, 0, 10, 0.0f, 0.0f, ITEM_EQUIP }, 20 , 1, 1 };
		monster.dropTable[2] = { { "공격력 포션", 0, 0, 0, 0, 30, 0.0f, 0.0f, ITEM_CONSUME }, 50, 1, 1 };

	}
	else if (name == "고블린")
	{
		monster.info.name = name;
		monster.info.maxHp = 30;
		monster.info.hp = monster.info.maxHp;
		monster.info.atk = 5;
		monster.dropTable[0] = { { "고블린의 지팡이", 0, 0, 20, 0, 10, 0.1f, 0.1f, ITEM_EQUIP }, 20, 1, 1 };
		monster.dropTable[1] = { { "고블린 로브", 0, 0, 30, 0, 10, 0.1f, 0.1f, ITEM_EQUIP}, 20, 1, 1 };
		monster.dropTable[2] = { { "마나 포션", 0, 0, 0, 50, 0, 0.0f, 0.0f, ITEM_CONSUME }, 50, 1, 1 };
	}

	return monster;
}

std::string PickRandomName(const std::string monsterName[], int size)
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

	return NULL; // 아무것도 안 떨어짐
}