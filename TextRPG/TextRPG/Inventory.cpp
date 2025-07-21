#include "Inventory.h"

Inven MakeEmptyItem() {
	return { "", 0, 0, 0, 0, 0, 0.0f, 0.0f , ITEM_NONE};
}

void PrintInven(const Player* player)
{
	std::cout << "���� �κ��丮 : ";
	if (player->ItemList[0].name == "")
		printf("�κ��丮 �������!!\n");

	else
	{
		for (int i = 0; player->ItemList[i].name != ""; i++)
			printf("%d. %s ", i+1, player->ItemList[i].name.c_str());

		printf("\n");
	}
}

void PrintEquip(const Player* player)
{
	printf("\n���� ������ ���\n");
	printf("===================\n");
	for (int i = 0; i < EQUIPITEM_NUM; i++)
	{
		if (i == ITEM_EQUIPWEAPON)
		{
			if (player->EquipList[i].name == "")
				printf("���� ���� X\n");
			else
				printf("���� %s\n", player->EquipList[i].name.c_str());
		}
		else if (i == ITEM_EQUIPBODY)
		{
			if (player->EquipList[i].name == "")
				printf("���� ���� X\n");
			else
				printf("���� %s\n", player->EquipList[i].name.c_str());
		}
		else if (i == ITEM_EQUIPHEAD)
		{
			if (player->EquipList[i].name == "")
				printf("�Ӹ� ���� X\n");
			else
				printf("�Ӹ� %s\n", player->EquipList[i].name.c_str());
		}
		else if (i == ITEM_EQUIPGLOVES)
		{
			if (player->EquipList[i].name == "")
				printf("�尩 ���� X\n");
			else
				printf("�尩 %s\n", player->EquipList[i].name.c_str());
		}
		else if (i == ITEM_EQUIPLEG)
		{
			if (player->EquipList[i].name == "")
				printf("�ٸ� ���� X\n");
			else
				printf("�ٸ� %s\n", player->EquipList[i].name.c_str());
		}
		else
		{
			printf("���� ��� ��� ����������������!!!!!!!!!!!!\n\n\n");
		}

	}
}
void PutInven(Player* player, const Item* item)
{
	if (!item)
		printf("���� �������� �����ϴ�!\n");

	else if (player->ItemList[INVENTORY_SIZE - 1].name != "")
	{
		printf("����ǰ�� ����á���ϴ�!!\n");
		return;
	}
	else
	{
		for (int i = 0; i < INVENTORY_SIZE; i++)
		{	
			if (player->ItemList[i].name == "")
			{
				player->ItemList[i] = *item;
				break;
			}

		}

	}
	
}

int IsValidItem(Item* item) {
	return item->name != "";
}

// �� �ε����� �����ϰ� ������ ����
void CompactItemList(Player* player) {
	int insertPos = 0;

	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (IsValidItem(&player->ItemList[i])) {
			if (i != insertPos) {
				// ��ȿ�� �������� ������ �̵�
				player->ItemList[insertPos] = player->ItemList[i];
				// ���� ��ġ �ʱ�ȭ
				player->ItemList[i] = MakeEmptyItem();
			}
			insertPos++;
		}
	}

	// ������ �޺κ� �ʱ�ȭ
	for (int i = insertPos; i < INVENTORY_SIZE; i++) {
		player->ItemList[i] = MakeEmptyItem();
	}
}