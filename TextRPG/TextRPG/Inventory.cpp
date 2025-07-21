#include "Inventory.h"

Inven MakeEmptyItem() {
	return { "", 0, 0, 0, 0, 0, 0.0f, 0.0f , ITEM_NONE};
}

void PrintInven(const Player* player)
{
	std::cout << "현재 인벤토리 : ";
	if (player->ItemList[0].name == "")
		printf("인벤토리 비어있음!!\n");

	else
	{
		for (int i = 0; player->ItemList[i].name != ""; i++)
			printf("%d. %s ", i+1, player->ItemList[i].name.c_str());

		printf("\n");
	}
}

void PrintEquip(const Player* player)
{
	printf("\n현재 장착된 장비\n");
	printf("===================\n");
	for (int i = 0; i < EQUIPITEM_NUM; i++)
	{
		if (i == ITEM_EQUIPWEAPON)
		{
			if (player->EquipList[i].name == "")
				printf("무기 장착 X\n");
			else
				printf("무기 %s\n", player->EquipList[i].name.c_str());
		}
		else if (i == ITEM_EQUIPBODY)
		{
			if (player->EquipList[i].name == "")
				printf("몸통 장착 X\n");
			else
				printf("몸통 %s\n", player->EquipList[i].name.c_str());
		}
		else if (i == ITEM_EQUIPHEAD)
		{
			if (player->EquipList[i].name == "")
				printf("머리 장착 X\n");
			else
				printf("머리 %s\n", player->EquipList[i].name.c_str());
		}
		else if (i == ITEM_EQUIPGLOVES)
		{
			if (player->EquipList[i].name == "")
				printf("장갑 장착 X\n");
			else
				printf("장갑 %s\n", player->EquipList[i].name.c_str());
		}
		else if (i == ITEM_EQUIPLEG)
		{
			if (player->EquipList[i].name == "")
				printf("다리 장착 X\n");
			else
				printf("다리 %s\n", player->EquipList[i].name.c_str());
		}
		else
		{
			printf("장착 장비 출력 오류오류오류오류!!!!!!!!!!!!\n\n\n");
		}

	}
}
void PutInven(Player* player, const Item* item)
{
	if (!item)
		printf("넣을 아이템이 없습니다!\n");

	else if (player->ItemList[INVENTORY_SIZE - 1].name != "")
	{
		printf("소지품이 가득찼습니다!!\n");
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