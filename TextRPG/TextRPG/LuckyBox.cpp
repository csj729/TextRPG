#include "LuckyBox.h"
#define BOX_GOLD 250

void OpenBox(Player* player)
{
	int roll = rand() % 100;

	if (roll < 70)
	{
		// �� ȹ��
		printf("%dGold�� ���Դ�!!!\n", BOX_GOLD);
		player->info.gold += BOX_GOLD;
	}
	else if (roll < 90)
	{
		// ��� ȹ��, ������ ��Ʈ������ ������
		Item NewItem;
		printf("%s�� ���Դ�!!!\n", NewItem.name);
		PutInven(player, &NewItem);
	}
	else
	{
		// ���� ȹ��, ��, ü, �� ������ �ְ� ���� 3��ø���� ������ ���·� ����
		int buffRoll = rand() % 100;
		if (buffRoll < 40)
		{
			printf("�ź��� ������ �ູ�� �����Խ��ϴ�! ü���� �����մϴ�.\n");
		}

		else if (buffRoll < 80)
		{
			printf("��ī ������ �ູ�� �����Խ��ϴ�! ������ �����մϴ�.\n");
		}

		else
		{
			printf("ȣ���� ������ �ູ�� �����Խ��ϴ�! ���ݷ��� �����մϴ�.\n");
		}
	}

	system("pause");
}