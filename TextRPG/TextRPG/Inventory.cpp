#include "Inventory.h"

Inven MakeEmptyItem() {
	return { "", 0, 0, 0, 0, 0, 0.0f, 0.0f };
}

void PrintInven(const Player* player)
{
	std::cout << "���� ��� : ";
	if (player->Gearitem[0].name == "")
		std::cout << "��� ����\n";
	else 
	{
		for (int i = 0; player->Gearitem[i].name != ""; i++)
		{
			std::cout << player->Gearitem[i].name << " ";
		}
		std::cout << "\n";
	}

	std::cout << "���� �Һ� ������ : ";
	if (player->Useitem[0].name == "")
		std::cout << "�Һ� ������ ����\n";
	else
	{
		for (int i = 0; player->Useitem[i].name != ""; i++)
		{
			std::cout << player->Useitem[i].name << " ";
		}
		std::cout << "\n";
	}
}

