#include "Merchant.h"

void InitStoreTable(StoreTable* storeTable)
{
	// ���� ǰ�� ���̺�
	storeTable[0] = { { L"HP����", 0, 50, 0, 0, 0, 50, 0.0f, 0.0f, ITEM_CONSUME }, 50 };
	storeTable[1] = { { L"MP����", 0, 0, 0, 50, 0, 50, 0.0f, 0.0f, ITEM_CONSUME }, 50 };
	storeTable[2] = { { L"AD����", 0, 0, 0, 0, 20, 50, 0.0f, 0.0f, ITEM_CONSUME }, 50 };
	storeTable[3] = { { L"ġ��Ÿ Ȯ�� ����", 0, 0, 0, 0, 0, 50, 0.2f, 0.0f, ITEM_CONSUME }, 50 };
	storeTable[4] = { { L"ġ��Ÿ ���� ����", 0, 0, 0, 0, 0, 50, 0.0f, 0.2f, ITEM_CONSUME }, 50 };

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
	while (1)
	{
		system("cls");
		wprintf(L"�ƹ��ų� ��󺸶�.\n");
		for (int i = 0; i < merchant->productNum; i++)
		{
			wprintf(L"%d. %s (%dGold)  ", i + 1, merchant->storeTable[i].item.name, merchant->storeTable[i].price);
		}
		wprintf(L"\n���� ������ : %dGold\n\n", player->info.gold);

		int selNum;
		wprintf(L"���� ������? (��ǰ ��ȣ �Է�, 0 �Է� �� �ڷΰ���) ");
		scanf_s("%d", &selNum);

		if (selNum == 0)
			break;

		else if (selNum < 1 || selNum > merchant->productNum)
			wprintf(L"�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n\n");

		else
		{
			if (merchant->storeTable[selNum - 1].price > player->info.gold)
			{
				wprintf(L"�������� �����մϴ�.. %dGold �ۿ� ���׿�.\n", player->info.gold);
			}

			else
			{
 				if (wcscmp(player->ItemList[INVENTORY_SIZE - 1].name, L"") != 0)
					wprintf(L"�κ��丮�� ����á���ϴ�!\n");

				else 
				{
					player->info.gold -= merchant->storeTable[selNum - 1].price;
					PutInven(player, &merchant->storeTable[selNum - 1].item);
					wprintf(L"%s ���� �Ϸ�!\n", merchant->storeTable[selNum - 1].item.name);
				}
			}
		}
		Sleep(1000);
	}

	system("cls");
}