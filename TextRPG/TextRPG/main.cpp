#include <stdio.h>

void InitPlayerStatus(unsigned int* hp, unsigned int* mp, unsigned int* atk, int animal_type)
{
	switch (animal_type)
	{
	case 1:
		*hp = 100;
		*mp = 100;
		*atk = 10;
		break;
	case 2:
		*hp = 80;
		*mp = 100;
		*atk = 12;
		break;
	case 3:
		*hp = 60;
		*mp = 100;
		*atk = 12;
		break;
	case 4:
		*hp = 150;
		*mp = 80;
		*atk = 10;
		break;
	case 5:
		*hp = 100;
		*mp = 150;
		*atk = 5;
		break;
	}
}

int main()
{
	unsigned int ani_sel;
	unsigned int player_hp;
	unsigned int player_mp;
	unsigned int player_atk;

	bool isSelect = false;
	printf("============================================================\n");
	printf("============���� ���忡 ���� ���� ȯ���մϴ�!=================\n");
	printf("============================================================\n\n");
	
	// ĳ���� ����
	while (!isSelect)
	{
		printf("�÷��� �ϰ��� �ϴ� ������ ����ּ���!\n");
		printf("1. ������\t2.�����\t3.�䳢\t4.�ź���\t5.��ī\n");
		printf("����� ������?? ");

		scanf_s("%u", &ani_sel);

		switch (ani_sel)
		{
		case 1:
			printf("������ ����!\n\n");
			isSelect = true;
			break;
		case 2:
			printf("����� ����!\n\n");
			isSelect = true;
			break;
		case 3:
			printf("�䳢 ����!\n\n");
			isSelect = true;
			break;
		case 4:
			printf("�ź��� ����!\n\n");
			isSelect = true;
			break;
		case 5:
			printf("��ī ����!\n\n");
			isSelect = true;
			break;
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �������ּ���!\n\n");
			break;
		}

	}

	InitPlayerStatus(&player_hp, &player_mp, &player_atk, ani_sel);

	while (1)
	{
		int select;
		printf("�ϰ��� �ϴ� �۾��� �����ϼ���!\n");
		printf("1.����\t2.����\t3.���� Ȯ��\n\n");
		scanf_s("%d", &select);
	}



	return 0;
}