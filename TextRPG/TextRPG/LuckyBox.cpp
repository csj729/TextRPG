#include "LuckyBox.h"
#define BOX_GOLD 250

void OpenBox(Player* player)
{
	int roll = rand() % 100;

	if (roll < 70)
	{
		// 돈 획득
		printf("%dGold가 나왔다!!!\n", BOX_GOLD);
		player->info.gold += BOX_GOLD;
	}
	else if (roll < 90)
	{
		// 장비 획득, 쓸만한 세트아이템 나오게
		Item NewItem;
		printf("%s가 나왔다!!!\n", NewItem.name);
		PutInven(player, &NewItem);
	}
	else
	{
		// 버프 획득, 공, 체, 마 버프가 있고 각각 3중첩까지 가능한 형태로 구현
		int buffRoll = rand() % 100;
		if (buffRoll < 40)
		{
			printf("거북이 여신의 축복이 내려왔습니다! 체력이 증가합니다.\n");
		}

		else if (buffRoll < 80)
		{
			printf("쿼카 여신의 축복이 내려왔습니다! 마나가 증가합니다.\n");
		}

		else
		{
			printf("호랑이 여신의 축복이 내려왔습니다! 공격력이 증가합니다.\n");
		}
	}

	system("pause");
}