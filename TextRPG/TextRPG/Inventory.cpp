#include "Inventory.h"

Inven MakeEmptyItem() {
	return { "", 0, 0, 0, 0, 0, 0.0f, 0.0f };
}

void PrintInven(const Player* player)
{
	std::cout << "현재 장비 : ";
	if (player->Gearitem[0].name == "")
		std::cout << "장비 없음\n";
	else 
	{
		for (int i = 0; player->Gearitem[i].name != ""; i++)
		{
			std::cout << player->Gearitem[i].name << " ";
		}
		std::cout << "\n";
	}

	std::cout << "현재 소비 아이템 : ";
	if (player->Useitem[0].name == "")
		std::cout << "소비 아이템 없음\n";
	else
	{
		for (int i = 0; player->Useitem[i].name != ""; i++)
		{
			std::cout << player->Useitem[i].name << " ";
		}
		std::cout << "\n";
	}
}

