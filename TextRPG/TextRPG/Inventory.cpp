#include "Inventory.h"

Inven MakeEmptyItem() {
	return { "", 0, 0, 0, 0, 0, 0.0f, 0.0f , ITEM_NONE};
}

void PrintInven(const Player* player)
{
	std::cout << "현재 장비 : ";
	if (player->EquipItem[0].name == "")
		std::cout << "장비 없음\n";
	else 
	{
		for (int i = 0; player->EquipItem[i].name != ""; i++)
		{
			std::cout << player->EquipItem[i].name << " ";
		}
		std::cout << "\n";
	}

	std::cout << "현재 소비 아이템 : ";
	if (player->ConsumeItem[0].name == "")
		std::cout << "소비 아이템 없음\n";
	else
	{
		for (int i = 0; player->ConsumeItem[i].name != ""; i++)
		{
			std::cout << player->ConsumeItem[i].name << " ";
		}
		std::cout << "\n";
	}
}

void PutInven(Player* player, const Item* item)
{
	if (!item)
		printf("넣을 아이템이 없습니다!\n");

	else
	{
		if (item->itemType == ITEM_CONSUME)
		{
			for (int i = 0; i < CONSUMEITEM_NUM; i++)
			{
				if (player->ConsumeItem[i].name == "")
				{
					player->ConsumeItem[i] = *item;
					break;
				}

				if (i == CONSUMEITEM_NUM - 1)
					printf("소지품이 가득찼습니다!\n");
			}
			
		}

		else if (item->itemType == ITEM_EQUIP)
		{
			for (int i = 0; i < EQUIPITEM_NUM; i++)
			{
				if (player->EquipItem[i].name == "")
				{
					player->EquipItem[i] = *item;
					break;
				}

				if (i == EQUIPITEM_NUM - 1)
					printf("소지품이 가득찼습니다!\n");
			}
		}

		else
			printf("아이템 타입이 정의되지 않았습니다!\n");
	}
	
}