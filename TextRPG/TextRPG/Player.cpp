#include "Player.h"
#include "Inventory.h"
#include "Monster.h"

void SelectAnimal(Player* player)
{
	Animal sel_ani;
	while (1)
	{
		printf("1. 강아지  2. 고양이  3. 토끼  4. 거북이  5. 쿼카\n");
		printf("나는 뭐야?? ");

		bool isCorrect = true;
		scanf_s("%d", &sel_ani);
		system("cls");

		switch (sel_ani)
		{
		case Dog:
		{
			printf("난 강아지구나.\n\n");
			player->info.name = "강아지";
			player->info.maxHp = 100;
			player->info.hp = player->info.maxHp;
			player->info.atk = 10;
			player->maxMp = 50;
			player->mp = player->maxMp;
			player->criRate = 0.2f;
			player->criMulti = 1.5f;
			break;
		}
		case Cat:
		{
			printf("난 고양이구나.\n\n");
			player->info.name = "고양이";
			player->info.maxHp = 80;
			player->info.hp = player->info.maxHp;
			player->info.atk = 12;
			player->maxMp = 50;
			player->mp = player->maxMp;
			player->criRate = 0.2f;
			player->criMulti = 1.8f;
			break;
		}
		case Rabbit:
		{
			printf("난 토끼구나.\n\n");
			player->info.name = "토끼";
			player->info.maxHp = 80;
			player->info.hp = player->info.maxHp;
			player->info.atk = 10;
			player->maxMp = 50;
			player->mp = player->maxMp;
			player->criRate = 0.3f;
			player->criMulti = 1.5f;
			break;
		}
		case Turtle:
		{
			printf("난 거북이구나.\n\n");
			player->info.name = "거북이";
			player->info.maxHp = 150;
			player->info.hp = player->info.maxHp;
			player->info.atk = 5;
			player->maxMp = 50;
			player->mp = player->maxMp;
			player->criRate = 0.2f;
			player->criMulti = 1.5f;
			break;
		}
		case Quokka:
		{
			printf("난 쿼카구나.\n\n");
			player->info.name = "쿼카";
			player->info.maxHp = 80;
			player->info.hp = player->info.maxHp;
			player->info.atk = 10;
			player->maxMp = 80;
			player->mp = player->maxMp;
			player->criRate = 0.2f;
			player->criMulti = 1.5f;
			break;
		}
		default:
		{
			printf("내가 누군지 모르겠는걸..\n\n");
			isCorrect = false;
			break;
		}
		}

		if (isCorrect)
			break;
	}
}

void PrintStatus(const Player* player)
{
	std::cout << "=== 플레이어 상태 ===\n";
	std::cout << "이름: " << player->info.name << "\n";
	std::cout << "레벨: " << playerLevel << "\n";
	std::cout << "HP: " << player->info.hp << "/" << player->info.maxHp << "\n";
	std::cout << "공격력: " << player->info.atk << "\n";
	std::cout << "MP: " << player->mp << "/" << player->maxMp << "\n";
	std::cout << "치명타 확률: " << player->criRate << "\n";
	std::cout << "치명타 배율: " << player->criMulti << "\n";
	std::cout << "현재 경험치: " << player->exp << "\n";
	PrintInven(player);
	
}

void InitInven(Player* player)
{
	for (int i = 0; i < EQUIPITEM_NUM; ++i)
		player->EquipItem[i] = MakeEmptyItem();

	for (int i = 0; i < CONSUMEITEM_NUM; ++i)
		player->ConsumeItem[i] = MakeEmptyItem();
}

void SelectAction(Player* player, Monster* monster)
{
	while (1)
	{
		printf("무슨 행동을 할까??\n");
		printf("1. 탑을 오른다    2. 상태를 확인한다    3. 다시 잠에 든다\n");

		int select;
		bool isCorrect = true;
		scanf_s("%d", &select);

		system("cls");
		switch (select)
		{
		case 1:
		{
			floorNum++;
			printf("%d층에 도착했다.\n", floorNum);

			int random = rand() % 100;

			if (random < 80)
			{
				int arr_size = sizeof(monsterNames) / sizeof(std::string);
				std::string monsterName = PickRandomName(monsterNames, arr_size);
				*monster = CreateMonster(monsterName);
				printf("몬스터와 마주쳤다! 전투 시작!\n\n");
				Battle(player, monster);
				// TODO: 전투 함수 호출
			}
			else if (random < 95)
			{
				printf("수상한 상인을 만났다.\n\n");
				// TODO: 상인 상호작용 함수 호출
			}
			else
			{
				printf("보물상자를 발견했다!\n\n");
				// TODO: 보상 함수 호출
			}
			break;
		}
		case 2:
		{
			PrintStatus(player);
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			printf("다시 잠에 빠져든다...\n");
			printf("Game Over!\n");
			exit(0);
		}
		default:
		{
			printf("이해할 수 없는 행동이야.\n\n");
			isCorrect = false;
			break;
		}
		}

		if (isCorrect)
			break;
	}
}

void Battle(Player* player, Monster* monster)
{
	while (1)
	{
		PrintStatus(monster);
		printf("\n\n\n");
		PrintStatus(player);

		int act_sel, realDmg_PtoM = 0, realDmg_MtoP = 0;
		bool isCorrect = true;
		printf("\n1. 공격  2. 스킬  3. 아이템\n");
		printf("행동 선택 : ");
		scanf_s("%d", &act_sel);

		system("cls");
		switch (act_sel)
		{
		case 1:
		{
			// 최종데미지 계산 로직 실행 후 몬스터 hp - 최종데미지
			printf("공격!!\n");
			realDmg_PtoM = player->info.atk;
			monster->info.hp -= realDmg_PtoM;
			break;
		}
		case 2:
		{
			printf("스킬 사용!\n");
			// 보유 스킬 출력 후 선택 구현
			break;
		}
		case 3:
		{
			printf("아이템 사용!\n");
			// 보유 아이템 출력 후 선택 구현
			break;
		}
		default:
		{
			printf("이상한 행동은 안돼.\n");
			isCorrect = false;
			break;
		}
		}

		// 올바른 입력 시 입력에 따른 결과와 최종 데미지 합산하여 준 피해와 받은 피해 출력.
		if (isCorrect)
		{
			// 몬스터의 최종 데미지 계산 후 플레이어 hp - 최종데미지
			realDmg_MtoP = monster->info.atk;
			player->info.hp -= realDmg_MtoP;
			printf_s("%s에게 %d 데미지를 주었습니다!!\n", monster->info.name.c_str(), realDmg_PtoM);
			printf_s("%s는 %d 피해를 입었습니다!!\n\n", player->info.name.c_str(), realDmg_MtoP);
		}

		// 몬스터 사망 시 전리품 획득과 전투 종료
		if (monster->info.hp <= 0)
		{
			printf("%s를 처치했다!!\n", monster->info.name.c_str());

			const Item* dropItem = RollDrop(monster->dropTable);
			if (!dropItem)
				printf("아이템이 드랍되지 않았습니다..\n");
			else
				printf("%s를 획득했습니다!!", dropItem->name.c_str());

			PutInven(player, dropItem);
			// 전리품 획득 문구 출력 후 전리품 획득 구현
			Sleep(2000);
			system("cls");
			break;
		}

		// 플레이어 사망 시 게임 오버
		if (player->info.hp <= 0)
		{
			printf("%s는 쓰러졌다...\n", player->info.name.c_str());
			exit(0);
		}
	}

}