#include "Inventory.h"

Inven MakeEmptyItem() {
	return { "", 0, 0, 0, 0, 0, 0.0f, 0.0f , ITEM_NONE};
}

void PrintInven(const Player* player)
{
	std::cout << "���� ��� : ";
	if (player->EquipItem[0].name == "")
		std::cout << "��� ����\n";
	else 
	{
		for (int i = 0; player->EquipItem[i].name != ""; i++)
		{
			std::cout << player->EquipItem[i].name << " ";
		}
		std::cout << "\n";
	}

	std::cout << "���� �Һ� ������ : ";
	if (player->ConsumeItem[0].name == "")
		std::cout << "�Һ� ������ ����\n";
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
		printf("���� �������� �����ϴ�!\n");

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
					printf("����ǰ�� ����á���ϴ�!\n");
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
					printf("����ǰ�� ����á���ϴ�!\n");
			}
		}

		else
			printf("������ Ÿ���� ���ǵ��� �ʾҽ��ϴ�!\n");
	}
	
}