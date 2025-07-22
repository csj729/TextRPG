#include "Inventory.h"

Item MakeEmptyItem() {
	return { L"", 0, 0, 0, 0, 0, 0, 0.0f, 0.0f , ITEM_NONE};
}

void PrintInven(const Player* player)
{
	wprintf(L"���� �κ��丮 : ");
	if (wcscmp(player->ItemList[0].name, L"") == 0)
		wprintf(L"�κ��丮 �������!!\n");

	else
	{
		for (int i = 0; (wcscmp(player->ItemList[i].name, L"") != 0) && i < INVENTORY_SIZE; i++)
			wprintf(L"%d. %s ", i+1, player->ItemList[i].name);

		wprintf(L"\n");
	}
}

void PrintEquip(const Player* player)
{
	wprintf(L"\n���� ������ ���\n");
	wprintf(L"===================\n");
	for (int i = 0; i < EQUIPITEM_NUM; i++)
	{
		if (i == ITEM_EQUIPWEAPON)
		{
			if (wcscmp(player->EquipList[i].name, L"") == 0)
				wprintf(L"���� ���� X\n");
			else
				wprintf(L"���� %s\n", player->EquipList[i].name);
		}
		else if (i == ITEM_EQUIPBODY)
		{
			if (wcscmp(player->EquipList[i].name, L"") == 0)
				wprintf(L"���� ���� X\n");
			else
				wprintf(L"���� %s\n", player->EquipList[i].name);
		}
		else if (i == ITEM_EQUIPHEAD)
		{
			if (wcscmp(player->EquipList[i].name, L"") == 0)
				wprintf(L"�Ӹ� ���� X\n");
			else
				wprintf(L"�Ӹ� %s\n", player->EquipList[i].name);
		}
		else if (i == ITEM_EQUIPGLOVES)
		{
			if (wcscmp(player->EquipList[i].name, L"") == 0)
				wprintf(L"�尩 ���� X\n");
			else
				wprintf(L"�尩 %s\n", player->EquipList[i].name);
		}
		else if (i == ITEM_EQUIPLEG)
		{
			if (wcscmp(player->EquipList[i].name, L"") == 0)
				wprintf(L"�ٸ� ���� X\n");
			else
				wprintf(L"�ٸ� %s\n", player->EquipList[i].name);
		}
		else
		{
			wprintf(L"���� ��� ��� ����������������!!!!!!!!!!!!\n\n\n");
		}

	}
}
void PutInven(Player* player, const Item* item)
{
	if (!item)
		wprintf(L"���� �������� �����ϴ�!\n");

	else if (wcscmp(player->ItemList[INVENTORY_SIZE - 1].name, L"") != 0)
	{
		wprintf(L"����ǰ�� ����á���ϴ�!!\n");
		return;
	}
	else
	{
		for (int i = 0; i < INVENTORY_SIZE; i++)
		{	
			if (wcscmp(player->ItemList[i].name, L"") == 0)
			{
				player->ItemList[i] = *item;
				break;
			}

		}

	}
	
}

int IsValidItem(Item* item) {
	return wcscmp(item->name, L"") != 0;
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