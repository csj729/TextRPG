#include "Merchant.h"

void InitStoreTable(StoreTable* storeTable)
{
	// ���� ǰ�� ���̺�
	storeTable[0] = { { "HP����", 0, 50, 0, 0, 0, 50, 0.0f, 0.0f, ITEM_CONSUME }, 50 };
	storeTable[1] = { { "MP����", 0, 0, 0, 50, 0, 50, 0.0f, 0.0f, ITEM_CONSUME }, 50 };
	storeTable[2] = { { "AD����", 0, 0, 0, 0, 20, 50, 0.0f, 0.0f, ITEM_CONSUME }, 50 };
	storeTable[3] = { { "ġ��Ÿ Ȯ�� ����", 0, 0, 0, 0, 0, 50, 0.2f, 0.0f, ITEM_CONSUME }, 50 };
	storeTable[4] = { { "ġ��Ÿ ���� ����", 0, 0, 0, 0, 0, 50, 0.0f, 0.2f, ITEM_CONSUME }, 50 };

}

void InitMerchant(Merchant* merchant, StoreTable* storeTable)
{

	for (int i = 0; i < STORETABLE_MAXNUM; i++)
		merchant->storeTable[i].item = MakeEmptyItem();

	for (int i = 0; i < merchant->productNum; i++)
	{
		int randomNum = rand() % STORETABLE_MAXNUM;
		merchant->storeTable[i] = storeTable[randomNum];
	}
}

void SelectProduct(const Merchant* merchant, Player* player)
{
	printf("�ƹ��ų� ��󺸶�.\n");
	for (int i = 0; i < merchant->productNum; i++)
	{	
		printf("%d. %s (%dGold)  ", i + 1, merchant->storeTable[i].item.name.c_str(), merchant->storeTable[i].price);
	}
	printf("\n");

	while (1)
	{
		int selNum;
		printf("���� ������? (��ǰ ��ȣ �Է�, 0 �Է� �� �ڷΰ���) ");
		scanf_s("%d", &selNum);

		if (selNum == 0)
			break;

		else if (selNum < 1 || selNum > merchant->productNum)
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n\n");

		else
		{
			if (merchant->storeTable[selNum - 1].price > player->info.gold)
			{
				printf("�������� �����մϴ�.. %dGold �ۿ� ���׿�.\n", player->info.gold);
			}

			else
			{
 				if (player->ItemList[INVENTORY_SIZE - 1].name != "")
					printf("�κ��丮�� ����á���ϴ�!\n");

				else 
				{
					player->info.gold -= merchant->storeTable[selNum - 1].price;
					PutInven(player, &merchant->storeTable[selNum - 1].item);
					printf("%s ���� �Ϸ�!\n", merchant->storeTable[selNum - 1].item.name.c_str());
				}
			}
		}
	}

	system("cls");
}