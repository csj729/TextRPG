#include "Player.h"
#include "Inventory.h"
#include "Monster.h"
#include "Merchant.h"

void SelectAnimal(Player* player)
{
	Animal sel_ani;
	while (1)
	{
		printf("1. ������  2. �����  3. �䳢  4. �ź���  5. ��ī\n");
		printf("���� ����?? ");

		bool isCorrect = true;
		scanf_s("%d", &sel_ani);
		system("cls");

		switch (sel_ani)
		{
		case Dog:
		{
			printf("�� ����������.\n\n");
			player->info.name = "������";
			player->info.maxHp = 100;
			player->info.hp = player->info.maxHp;
			player->info.atk = 10;
			player->maxMp = 50;
			player->mp = player->maxMp;
			player->criRate = 0.2f;
			player->criMulti = 1.5f;
			break;
		}
		case Cat:
		{
			printf("�� ����̱���.\n\n");
			player->info.name = "�����";
			player->info.maxHp = 80;
			player->info.hp = player->info.maxHp;
			player->info.atk = 12;
			player->maxMp = 50;
			player->mp = player->maxMp;
			player->criRate = 0.2f;
			player->criMulti = 1.8f;
			break;
		}
		case Rabbit:
		{
			printf("�� �䳢����.\n\n");
			player->info.name = "�䳢";
			player->info.maxHp = 80;
			player->info.hp = player->info.maxHp;
			player->info.atk = 10;
			player->maxMp = 50;
			player->mp = player->maxMp;
			player->criRate = 0.3f;
			player->criMulti = 1.5f;
			break;
		}
		case Turtle:
		{
			printf("�� �ź��̱���.\n\n");
			player->info.name = "�ź���";
			player->info.maxHp = 150;
			player->info.hp = player->info.maxHp;
			player->info.atk = 5;
			player->maxMp = 50;
			player->mp = player->maxMp;
			player->criRate = 0.2f;
			player->criMulti = 1.5f;
			break;
		}
		case Quokka:
		{
			printf("�� ��ī����.\n\n");
			player->info.name = "��ī";
			player->info.maxHp = 80;
			player->info.hp = player->info.maxHp;
			player->info.atk = 10;
			player->maxMp = 80;
			player->mp = player->maxMp;
			player->criRate = 0.2f;
			player->criMulti = 1.5f;
			break;
		}
		default:
		{
			printf("���� ������ �𸣰ڴ°�..\n\n");
			isCorrect = false;
			break;
		}
		}

		if (isCorrect)
			break;
	}
}

void PrintStatus(const Player* player)
{
	std::cout << "=== �÷��̾� ���� ===\n";
	std::cout << "�̸�: " << player->info.name << "\n";
	std::cout << "����: " << player->level << "\n";
	std::cout << "HP: " << player->info.hp << "/" << player->info.maxHp << "\n";
	std::cout << "���ݷ�: " << player->info.atk << "\n";
	std::cout << "MP: " << player->mp << "/" << player->maxMp << "\n";
	std::cout << "ġ��Ÿ Ȯ��: " << player->criRate << "\n";
	std::cout << "ġ��Ÿ ����: " << player->criMulti << "\n";
	std::cout << "���� ����ġ: " << player->info.exp << "/" << player->maxExp << "\n";
	std::cout << "���� ���� ���: " << player->info.gold << "Gold" << "\n";
	PrintEquip(player);
	printf("\n");
	PrintInven(player);
	
}

void UpdateExpAndLevel(Player* player, const int exp)
{
	if (player->maxExp <= player->info.exp + exp)
	{
		player->info.exp = player->info.exp + exp - player->maxExp;
		player->level++;
		player->maxExp = BASE_EXP * player->level;
	}

	else
	{
		player->info.exp += exp;
	}
}
void InitInven(Player* player)
{
	for (int i = 0; i < EQUIPITEM_NUM; ++i)
		player->EquipList[i] = MakeEmptyItem();

	for (int i = 0; i < INVENTORY_SIZE; ++i)
		player->ItemList[i] = MakeEmptyItem();
}

void SelectAction(Player* player, Monster* monster, Merchant* merchant)
{
	while (1)
	{
		printf("���� �ൿ�� �ұ�??\n");
		printf("1. ž�� ������    2. ���¸� Ȯ���Ѵ�    3. ��� �����Ѵ�    4. �ٽ� �ῡ ���\n");

		int select;
		bool isCorrect = true;
		scanf_s("%d", &select);

		system("cls");
		switch (select)
		{
		case 1:
		{
			floorNum++;
			printf("%d���� �����ߴ�.\n", floorNum);

			int random = rand() % 100;

			if (random < 70)
			{
				int arr_size = sizeof(monsterNames) / sizeof(std::string);
				std::string monsterName = PickRandomName(monsterNames, arr_size);
				*monster = CreateMonster(monsterName);
				printf("���Ϳ� �����ƴ�! ���� ����!\n\n");
				Battle(player, monster);
			}
			else if (random < 95)
			{
				printf("������ ������ ������.\n\n");
				InitMerchant(merchant, storeTable);
				SelectProduct(merchant, player);
			}
			else
			{
				printf("�������ڸ� �߰��ߴ�!\n\n");
				// TODO: ���� �Լ� ȣ��
			}
			break;
		}
		case 2:
		{
			PrintStatus(player);
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			while (1)
			{
				system("cls");
				printf("��� ��������! �� �����ұ�?\n");
				PrintInven(player);

				printf("�κ��丮�� ��ȣ�� �Է��ϼ��� (1~%d����, ������� 0) : ", INVENTORY_SIZE);
				int sel_idx;
				scanf_s("%d", &sel_idx);

				if (sel_idx == 0)
				{
					system("cls");
					break;
				}

				else if (sel_idx < 0 || sel_idx > 10)
					printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���!\n");

				else if ( player->ItemList[sel_idx - 1].itemType > ITEM_EQUIPLEG)
					printf("��� �������� �ƴմϴ�. �ٽ� �������ּ���!\n");

				else
					printf("%s�� �����߽��ϴ�!\n", EquipItem(player, sel_idx).name.c_str());

				system("pause");
			}
			break;
		}
		case 4:
		{
			printf("�ٽ� �ῡ �������...\n");
			printf("Game Over!\n");
			exit(0);
		}
		default:
		{
			printf("������ �� ���� �ൿ�̾�.\n\n");
			isCorrect = false;
			break;
		}
		}

		if (isCorrect)
			break;
	}
}

void Battle(Player* player, Monster* monster)
{
	while (1)
	{
		PrintStatus(monster);
		printf("\n\n\n");
		PrintStatus(player);
		

		int act_sel, realDmg_PtoM = 0, realDmg_MtoP = 0;
		bool isCorrect = true;
		printf("\n1. ����  2. ��ų  3. ������\n");
		printf("�ൿ ���� : ");
		scanf_s("%d", &act_sel);

		system("cls");
		switch (act_sel)
		{
		case 1:
		{
			// ���������� ��� ���� ���� �� ���� hp - ����������
			printf("����!!\n");
			realDmg_PtoM = player->info.atk;
			monster->info.hp -= realDmg_PtoM;
			break;
		}
		case 2:
		{
			printf("��ų ���!\n");
			// ���� ��ų ��� �� ���� ����
			break;
		}
		case 3:
		{
			printf("������ ���!\n");
			// ���� ������ ��� �� ���� ����
			break;
		}
		default:
		{
			printf("�̻��� �ൿ�� �ȵ�.\n");
			isCorrect = false;
			break;
		}
		}

		printf_s("%s���� %d �������� �־����ϴ�!!\n", monster->info.name.c_str(), realDmg_PtoM);
		// ���� ��� �� ����ǰ ȹ��� ���� ����
		if (monster->info.hp <= 0)
		{
			printf("%s�� óġ�ߴ�!!\n", monster->info.name.c_str());
			printf("%d�� ����ġ�� �����!!\n", monster->info.exp);
			printf("%d�� Gold�� �����!!\n", monster->info.gold);

			UpdateExpAndLevel(player, monster->info.exp);
			player->info.gold += monster->info.gold;
			const Item* dropItem = RollDrop(monster->dropTable);
			if (!dropItem)
				printf("�������� ������� �ʾҽ��ϴ�..\n\n");
			else
				printf("%s�� ȹ���߽��ϴ�!!\n\n", dropItem->name.c_str());

			PutInven(player, dropItem);
			// ����ǰ ȹ�� ���� ��� �� ����ǰ ȹ�� ����
			break;
		}

		// �ùٸ� �Է� �� �Է¿� ���� ����� ���� ������ �ջ��Ͽ� �� ���ؿ� ���� ���� ���.
		if (isCorrect)
		{
			// ������ ���� ������ ��� �� �÷��̾� hp - ����������
			realDmg_MtoP = monster->info.atk;
			player->info.hp -= realDmg_MtoP;
			printf_s("%s�� %d ���ظ� �Ծ����ϴ�!!\n\n", player->info.name.c_str(), realDmg_MtoP);
		}

		// �÷��̾� ��� �� ���� ����
		if (player->info.hp <= 0)
		{
			printf("%s�� ��������...\n", player->info.name.c_str());
			exit(0);
		}

		Sleep(2000);
		system("cls");
	}

}

Item EquipItem(Player* player, const int item_idx)
{
	Item NewItem = player->ItemList[item_idx - 1];
	if (NewItem.itemType == ITEM_EQUIPWEAPON)
	{
		// ���� ������ �̹� ������ ��� ����
		if (player->EquipList[ITEM_EQUIPWEAPON].name != "")
		{
			// ������ ������ ��� ���ȸ�ŭ ����
			player->info.maxHp -= player->EquipList[ITEM_EQUIPWEAPON].maxHp;
			player->info.hp -= player->EquipList[ITEM_EQUIPWEAPON].hp;
			player->maxMp -= player->EquipList[ITEM_EQUIPWEAPON].maxMp;
			player->mp -= player->EquipList[ITEM_EQUIPWEAPON].mp;
			player->info.atk -= player->EquipList[ITEM_EQUIPWEAPON].atk;
			player->criRate -= player->EquipList[ITEM_EQUIPWEAPON].criRate;
			player->criMulti -= player->EquipList[ITEM_EQUIPWEAPON].criMulti;
			
			// ���ο� ��� ���ȸ�ŭ ���� �� ���� ��� �κ��丮�� �ٽ� ����
			player->info.maxHp += NewItem.maxHp;
			player->info.hp += NewItem.hp;
			player->maxMp += NewItem.maxMp;
			player->mp += NewItem.mp;
			player->info.atk += NewItem.atk;
			player->criRate += NewItem.criRate;
			player->criMulti += NewItem.criMulti;
			player->ItemList[item_idx - 1] = player->EquipList[ITEM_EQUIPWEAPON];
			return player->EquipList[ITEM_EQUIPWEAPON] = NewItem;
		}

		player->info.maxHp += NewItem.maxHp;
		player->info.hp += NewItem.hp;
		player->maxMp += NewItem.maxMp;
		player->mp += NewItem.mp;
		player->info.atk += NewItem.atk;
		player->criRate += NewItem.criRate;
		player->criMulti += NewItem.criMulti;
		player->ItemList[item_idx - 1] = MakeEmptyItem();
		return player->EquipList[ITEM_EQUIPWEAPON] = NewItem;
	}
	else if (NewItem.itemType == ITEM_EQUIPBODY)
	{
		if (player->EquipList[ITEM_EQUIPBODY].name != "")
		{
			player->info.maxHp -= player->EquipList[ITEM_EQUIPBODY].maxHp;
			player->info.hp -= player->EquipList[ITEM_EQUIPBODY].hp;
			player->maxMp -= player->EquipList[ITEM_EQUIPBODY].maxMp;
			player->mp -= player->EquipList[ITEM_EQUIPBODY].mp;
			player->info.atk -= player->EquipList[ITEM_EQUIPBODY].atk;
			player->criRate -= player->EquipList[ITEM_EQUIPBODY].criRate;
			player->criMulti -= player->EquipList[ITEM_EQUIPBODY].criMulti;

			player->info.maxHp += NewItem.maxHp;
			player->info.hp += NewItem.hp;
			player->maxMp += NewItem.maxMp;
			player->mp += NewItem.mp;
			player->info.atk += NewItem.atk;
			player->criRate += NewItem.criRate;
			player->criMulti += NewItem.criMulti;
			player->ItemList[item_idx - 1] = player->EquipList[ITEM_EQUIPBODY];
			return player->EquipList[ITEM_EQUIPBODY] = NewItem;
		}

		player->info.maxHp += NewItem.maxHp;
		player->info.hp += NewItem.hp;
		player->maxMp += NewItem.maxMp;
		player->mp += NewItem.mp;
		player->info.atk += NewItem.atk;
		player->criRate += NewItem.criRate;
		player->criMulti += NewItem.criMulti;
		player->ItemList[item_idx - 1] = MakeEmptyItem();
		return player->EquipList[ITEM_EQUIPBODY] = NewItem;
	}
	else if (NewItem.itemType == ITEM_EQUIPHEAD)
	{
		if (player->EquipList[ITEM_EQUIPHEAD].name != "")
		{
			player->info.maxHp -= player->EquipList[ITEM_EQUIPHEAD].maxHp;
			player->info.hp -= player->EquipList[ITEM_EQUIPHEAD].hp;
			player->maxMp -= player->EquipList[ITEM_EQUIPHEAD].maxMp;
			player->mp -= player->EquipList[ITEM_EQUIPHEAD].mp;
			player->info.atk -= player->EquipList[ITEM_EQUIPHEAD].atk;
			player->criRate -= player->EquipList[ITEM_EQUIPHEAD].criRate;
			player->criMulti -= player->EquipList[ITEM_EQUIPHEAD].criMulti;
			
			player->info.maxHp += NewItem.maxHp;
			player->info.hp += NewItem.hp;
			player->maxMp += NewItem.maxMp;
			player->mp += NewItem.mp;
			player->info.atk += NewItem.atk;
			player->criRate += NewItem.criRate;
			player->criMulti += NewItem.criMulti;
			player->ItemList[item_idx - 1] = player->EquipList[ITEM_EQUIPHEAD];
			return player->EquipList[ITEM_EQUIPHEAD] = NewItem;
		}
		player->info.maxHp += NewItem.maxHp;
		player->info.hp += NewItem.hp;
		player->maxMp += NewItem.maxMp;
		player->mp += NewItem.mp;
		player->info.atk += NewItem.atk;
		player->criRate += NewItem.criRate;
		player->criMulti += NewItem.criMulti;
		player->ItemList[item_idx - 1] = MakeEmptyItem();
		return player->EquipList[ITEM_EQUIPHEAD] = NewItem;
	}
	else if (NewItem.itemType == ITEM_EQUIPGLOVES)
	{
		if (player->EquipList[ITEM_EQUIPGLOVES].name != "")
		{
			player->info.maxHp -= player->EquipList[ITEM_EQUIPGLOVES].maxHp;
			player->info.hp -= player->EquipList[ITEM_EQUIPGLOVES].hp;
			player->maxMp -= player->EquipList[ITEM_EQUIPGLOVES].maxMp;
			player->mp -= player->EquipList[ITEM_EQUIPGLOVES].mp;
			player->info.atk -= player->EquipList[ITEM_EQUIPGLOVES].atk;
			player->criRate -= player->EquipList[ITEM_EQUIPGLOVES].criRate;
			player->criMulti -= player->EquipList[ITEM_EQUIPGLOVES].criMulti;
			
			player->info.maxHp += NewItem.maxHp;
			player->info.hp += NewItem.hp;
			player->maxMp += NewItem.maxMp;
			player->mp += NewItem.mp;
			player->info.atk += NewItem.atk;
			player->criRate += NewItem.criRate;
			player->criMulti += NewItem.criMulti;
			player->ItemList[item_idx - 1] = player->EquipList[ITEM_EQUIPGLOVES];
			return player->EquipList[ITEM_EQUIPGLOVES] = NewItem;
		}
		player->info.maxHp += NewItem.maxHp;
		player->info.hp += NewItem.hp;
		player->maxMp += NewItem.maxMp;
		player->mp += NewItem.mp;
		player->info.atk += NewItem.atk;
		player->criRate += NewItem.criRate;
		player->criMulti += NewItem.criMulti;
		player->ItemList[item_idx - 1] = MakeEmptyItem();
		return player->EquipList[ITEM_EQUIPGLOVES] = NewItem;
	}
	else if (NewItem.itemType == ITEM_EQUIPLEG)
	{
		if (player->EquipList[ITEM_EQUIPLEG].name != "")
		{
			player->info.maxHp -= player->EquipList[ITEM_EQUIPLEG].maxHp;
			player->info.hp -= player->EquipList[ITEM_EQUIPLEG].hp;
			player->maxMp -= player->EquipList[ITEM_EQUIPLEG].maxMp;
			player->mp -= player->EquipList[ITEM_EQUIPLEG].mp;
			player->info.atk -= player->EquipList[ITEM_EQUIPLEG].atk;
			player->criRate -= player->EquipList[ITEM_EQUIPLEG].criRate;
			player->criMulti -= player->EquipList[ITEM_EQUIPLEG].criMulti;
			
			player->info.maxHp += NewItem.maxHp;
			player->info.hp += NewItem.hp;
			player->maxMp += NewItem.maxMp;
			player->mp += NewItem.mp;
			player->info.atk += NewItem.atk;
			player->criRate += NewItem.criRate;
			player->criMulti += NewItem.criMulti;
			player->ItemList[item_idx - 1] = player->EquipList[ITEM_EQUIPLEG];
			return player->EquipList[ITEM_EQUIPLEG] = NewItem;
		}
		player->info.maxHp += NewItem.maxHp;
		player->info.hp += NewItem.hp;
		player->maxMp += NewItem.maxMp;
		player->mp += NewItem.mp;
		player->info.atk += NewItem.atk;
		player->criRate += NewItem.criRate;
		player->criMulti += NewItem.criMulti;
		player->ItemList[item_idx - 1] = MakeEmptyItem();
		return player->EquipList[ITEM_EQUIPLEG] = NewItem;
	}
	else
	{
		printf("��� ���� ����������������!!!! NewItem �Լ� Ȯ��\n");
		Item dummy = { 0 };
		return dummy;
	}
}

void UneqiupItem(Player* player)
{

}