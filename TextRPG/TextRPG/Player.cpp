#include "Player.h"
#include "Inventory.h"
#include "Monster.h"

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
	std::cout << "����: " << playerLevel << "\n";
	std::cout << "HP: " << player->info.hp << "/" << player->info.maxHp << "\n";
	std::cout << "���ݷ�: " << player->info.atk << "\n";
	std::cout << "MP: " << player->mp << "/" << player->maxMp << "\n";
	std::cout << "ġ��Ÿ Ȯ��: " << player->criRate << "\n";
	std::cout << "ġ��Ÿ ����: " << player->criMulti << "\n";
	std::cout << "���� ����ġ: " << player->exp << "\n";
	PrintInven(player);
	
}

void InitInven(Player* player)
{
	for (int i = 0; i < EQUIPITEM_NUM; ++i)
		player->EquipItem[i] = MakeEmptyItem();

	for (int i = 0; i < CONSUMEITEM_NUM; ++i)
		player->ConsumeItem[i] = MakeEmptyItem();
}

void SelectAction(Player* player, Monster* monster)
{
	while (1)
	{
		printf("���� �ൿ�� �ұ�??\n");
		printf("1. ž�� ������    2. ���¸� Ȯ���Ѵ�    3. �ٽ� �ῡ ���\n");

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

			if (random < 80)
			{
				int arr_size = sizeof(monsterNames) / sizeof(std::string);
				std::string monsterName = PickRandomName(monsterNames, arr_size);
				*monster = CreateMonster(monsterName);
				printf("���Ϳ� �����ƴ�! ���� ����!\n\n");
				Battle(player, monster);
				// TODO: ���� �Լ� ȣ��
			}
			else if (random < 95)
			{
				printf("������ ������ ������.\n\n");
				// TODO: ���� ��ȣ�ۿ� �Լ� ȣ��
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

		// �ùٸ� �Է� �� �Է¿� ���� ����� ���� ������ �ջ��Ͽ� �� ���ؿ� ���� ���� ���.
		if (isCorrect)
		{
			// ������ ���� ������ ��� �� �÷��̾� hp - ����������
			realDmg_MtoP = monster->info.atk;
			player->info.hp -= realDmg_MtoP;
			printf_s("%s���� %d �������� �־����ϴ�!!\n", monster->info.name.c_str(), realDmg_PtoM);
			printf_s("%s�� %d ���ظ� �Ծ����ϴ�!!\n\n", player->info.name.c_str(), realDmg_MtoP);
		}

		// ���� ��� �� ����ǰ ȹ��� ���� ����
		if (monster->info.hp <= 0)
		{
			printf("%s�� óġ�ߴ�!!\n", monster->info.name.c_str());

			const Item* dropItem = RollDrop(monster->dropTable);
			if (!dropItem)
				printf("�������� ������� �ʾҽ��ϴ�..\n");
			else
				printf("%s�� ȹ���߽��ϴ�!!", dropItem->name.c_str());

			PutInven(player, dropItem);
			// ����ǰ ȹ�� ���� ��� �� ����ǰ ȹ�� ����
			Sleep(2000);
			system("cls");
			break;
		}

		// �÷��̾� ��� �� ���� ����
		if (player->info.hp <= 0)
		{
			printf("%s�� ��������...\n", player->info.name.c_str());
			exit(0);
		}
	}

}