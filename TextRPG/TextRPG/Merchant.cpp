#include "Merchant.h"

void InitStoreTable(StoreTable* storeTable)
{
	// 상점 품목 테이블
	storeTable[0] = { { L"HP포션", 0, 50, 0, 0, 0, 50, 0.0f, 0.0f, ITEM_CONSUME }, 50 };
	storeTable[1] = { { L"MP포션", 0, 0, 0, 50, 0, 50, 0.0f, 0.0f, ITEM_CONSUME }, 50 };
	storeTable[2] = { { L"AD포션", 0, 0, 0, 0, 20, 50, 0.0f, 0.0f, ITEM_CONSUME }, 50 };
	storeTable[3] = { { L"치명타 확률 포션", 0, 0, 0, 0, 0, 50, 0.2f, 0.0f, ITEM_CONSUME }, 50 };
	storeTable[4] = { { L"치명타 배율 포션", 0, 0, 0, 0, 0, 50, 0.0f, 0.2f, ITEM_CONSUME }, 50 };

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
		wprintf(L"아무거나 골라보라구.\n");
		for (int i = 0; i < merchant->productNum; i++)
		{
			wprintf(L"%d. %s (%dGold)  ", i + 1, merchant->storeTable[i].item.name, merchant->storeTable[i].price);
		}
		wprintf(L"\n나의 소지금 : %dGold\n\n", player->info.gold);

		int selNum;
		wprintf(L"나의 선택은? (상품 번호 입력, 0 입력 시 뒤로가기) ");
		scanf_s("%d", &selNum);

		if (selNum == 0)
			break;

		else if (selNum < 1 || selNum > merchant->productNum)
			wprintf(L"잘못된 입력입니다. 다시 입력해주세요.\n\n");

		else
		{
			if (merchant->storeTable[selNum - 1].price > player->info.gold)
			{
				wprintf(L"소지금이 부족합니다.. %dGold 밖에 없네요.\n", player->info.gold);
			}

			else
			{
 				if (wcscmp(player->ItemList[INVENTORY_SIZE - 1].name, L"") != 0)
					wprintf(L"인벤토리가 가득찼습니다!\n");

				else 
				{
					player->info.gold -= merchant->storeTable[selNum - 1].price;
					PutInven(player, &merchant->storeTable[selNum - 1].item);
					wprintf(L"%s 구입 완료!\n", merchant->storeTable[selNum - 1].item.name);
				}
			}
		}
		Sleep(1000);
	}

	system("cls");
}