#pragma once
#include "Struct.h"
#include "Player.h"
#include "Inventory.h"
const std::string monsterNames[3] = { "트롤", "오크", "고블린" };
const Item TrollDropTable[3] =
{
	{"트롤의 몽둥이", 50, 0, 0, 0, 10, 0.0f, 0.0f},
	{"트롤 갑옷", 50, 0, 0, 0, 5, 0.0f, 0.0f},
	{"생명력 포션", 0, 50, 0, 0, 0, 0.0f, 0.0f}
};

const Item OrcDropTable[3] =
{
	{"오크의 도끼", 0, 0, 0, 0, 30, 0.2f, 0.3f},
	{"오크 갑옷", 20, 0, 0, 0, 10, 0.0f, 0.0f},
	{"공격력 포션", 0, 0, 0, 0, 30, 0.0f, 0.0f}
};

const Item GoblinDropTable[3] =
{
	{"고블린의 지팡이", 0, 0, 20, 0, 10, 0.1f, 0.1f},
	{"고블린 로브", 0, 0, 30, 0, 10, 0.1f, 0.1f},
	{"마나 포션", 0, 0, 0, 50, 0, 0.0f, 0.0f}
};
// 상태 출력
void PrintStatus(const Monster* monster);

// 몬스터 생성
Monster CreateMonster(const std::string name);

std::string PickRandomName(const std::string monsterName[], int size);