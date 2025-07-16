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
	printf("============동물 농장에 오신 것을 환영합니다!=================\n");
	printf("============================================================\n\n");
	
	// 캐릭터 선택
	while (!isSelect)
	{
		printf("플레이 하고자 하는 동물을 골라주세요!\n");
		printf("1. 강아지\t2.고양이\t3.토끼\t4.거북이\t5.쿼카\n");
		printf("당신의 선택은?? ");

		scanf_s("%u", &ani_sel);

		switch (ani_sel)
		{
		case 1:
			printf("강아지 선택!\n\n");
			isSelect = true;
			break;
		case 2:
			printf("고양이 선택!\n\n");
			isSelect = true;
			break;
		case 3:
			printf("토끼 선택!\n\n");
			isSelect = true;
			break;
		case 4:
			printf("거북이 선택!\n\n");
			isSelect = true;
			break;
		case 5:
			printf("쿼카 선택!\n\n");
			isSelect = true;
			break;
		default:
			printf("잘못된 입력입니다. 다시 선택해주세요!\n\n");
			break;
		}

	}

	InitPlayerStatus(&player_hp, &player_mp, &player_atk, ani_sel);

	while (1)
	{
		int select;
		printf("하고자 하는 작업을 선택하세요!\n");
		printf("1.던전\t2.마을\t3.상태 확인\n\n");
		scanf_s("%d", &select);
	}



	return 0;
}