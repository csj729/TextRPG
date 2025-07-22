#include "Inventory.h"

Item MakeEmptyItem() {
	return { L"", 0, 0, 0, 0, 0, 0, 0.0f, 0.0f , ITEM_NONE};
}

void PrintInven(const Player* player)
{
	wprintf(L"현재 인벤토리 : ");
	if (wcscmp(player->ItemList[0].name, L"") == 0)
		wprintf(L"인벤토리 비어있음!!\n");

	else
	{
		for (int i = 0; (wcscmp(player->ItemList[i].name, L"") != 0) && i < INVENTORY_SIZE; i++)
			wprintf(L"%d. %s ", i+1, player->ItemList[i].name);

		wprintf(L"\n");
	}
}

void PrintEquip(const Player* player)
{
	wprintf(L"\n현재 장착된 장비\n");
	wprintf(L"===================\n");
	for (int i = 0; i < EQUIPITEM_NUM; i++)
	{
		if (i == ITEM_EQUIPWEAPON)
		{
			if (wcscmp(player->EquipList[i].name, L"") == 0)
				wprintf(L"무기 장착 X\n");
			else
				wprintf(L"무기 %s\n", player->EquipList[i].name);
		}
		else if (i == ITEM_EQUIPBODY)
		{
			if (wcscmp(player->EquipList[i].name, L"") == 0)
				wprintf(L"몸통 장착 X\n");
			else
				wprintf(L"몸통 %s\n", player->EquipList[i].name);
		}
		else if (i == ITEM_EQUIPHEAD)
		{
			if (wcscmp(player->EquipList[i].name, L"") == 0)
				wprintf(L"머리 장착 X\n");
			else
				wprintf(L"머리 %s\n", player->EquipList[i].name);
		}
		else if (i == ITEM_EQUIPGLOVES)
		{
			if (wcscmp(player->EquipList[i].name, L"") == 0)
				wprintf(L"장갑 장착 X\n");
			else
				wprintf(L"장갑 %s\n", player->EquipList[i].name);
		}
		else if (i == ITEM_EQUIPLEG)
		{
			if (wcscmp(player->EquipList[i].name, L"") == 0)
				wprintf(L"다리 장착 X\n");
			else
				wprintf(L"다리 %s\n", player->EquipList[i].name);
		}
		else
		{
			wprintf(L"장착 장비 출력 오류오류오류오류!!!!!!!!!!!!\n\n\n");
		}

	}
}
void PutInven(Player* player, const Item* item)
{
	if (!item)
		wprintf(L"넣을 아이템이 없습니다!\n");

	else if (wcscmp(player->ItemList[INVENTORY_SIZE - 1].name, L"") != 0)
	{
		wprintf(L"소지품이 가득찼습니다!!\n");
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

// 빈 인덱스를 제거하고 앞으로 정렬
void CompactItemList(Player* player) {
	int insertPos = 0;

	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (IsValidItem(&player->ItemList[i])) {
			if (i != insertPos) {
				// 유효한 아이템을 앞으로 이동
				player->ItemList[insertPos] = player->ItemList[i];
				// 원래 위치 초기화
				player->ItemList[i] = MakeEmptyItem();
			}
			insertPos++;
		}
	}

	// 나머지 뒷부분 초기화
	for (int i = insertPos; i < INVENTORY_SIZE; i++) {
		player->ItemList[i] = MakeEmptyItem();
	}
}