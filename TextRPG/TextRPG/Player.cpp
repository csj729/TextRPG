#include "Player.h"

#define COMMAND_LENGTH 4
#define TIME_LIMIT_MS 5000  // 5초
#define MAX_INPUT 50

// 방향키 코드
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77

void SelectAnimal(Player* player)
{
	Animal sel_ani;
	while (1)
	{
		wprintf(L"1. 강아지  2. 고양이  3. 토끼  4. 거북이  5. 쿼카\n");
		wprintf(L"나는 뭐야?? ");

		bool isCorrect = true;
		wscanf_s(L"%d", &sel_ani);
		system("cls");

		switch (sel_ani)
		{
		case Dog:
		{
			wprintf(L"난 강아지구나.\n\n");
			wprintf(L"      / \\__\n");
			wprintf(L"    (    @\\___\n");
			wprintf(L"    /         O\n");
			wprintf(L"   /   (_____/\n");
			wprintf(L"  /_____/ U\n\n");
			wcscpy_s(player->info.name, L"강아지");
			player->info.maxHp = 100;
			player->info.hp = player->info.maxHp;
			player->info.atk = 10;
			player->maxMp = 50;
			player->mp = player->maxMp;
			player->criRate = 0.2f;
			player->criMulti = 1.5f;
			player->SkillList[0] = { L"꼬리흔들기", 50 };
			player->SkillList[1] = { L"멍멍펀치", 50 };
			player->SkillList[2] = { L"뼈다귀투척", 50 };
			break;
		}
		case Cat:
		{
			wprintf(L"난 고양이구나.\n\n");
			wprintf(L" /\\_/\\\n");
			wprintf(L"( o.o )\n");
			wprintf(L" > ^ <\n");
			wcscpy_s(player->info.name, L"고양이");
			player->info.maxHp = 80;
			player->info.hp = player->info.maxHp;
			player->info.atk = 12;
			player->maxMp = 50;
			player->mp = player->maxMp;
			player->criRate = 0.2f;
			player->criMulti = 1.8f;
			player->SkillList[0] = { L"발톱할퀴기", 50 };
			player->SkillList[1] = { L"냥냥펀치", 50 };
			player->SkillList[2] = { L"야옹찌르기", 50 };
			break;
		}
		case Rabbit:
		{
			wprintf(L"난 토끼구나.\n\n");
			wprintf(L"  (\\_/)\n");
			wprintf(L"  ( -_-)\n");
			wprintf(L" / >     \n");
			wprintf(L"/     \\\n");
			wprintf(L"(       )\n");
			wprintf(L" ^^   ^^   \n\n");
			wcscpy_s(player->info.name, L"토끼");
			player->info.maxHp = 80;
			player->info.hp = player->info.maxHp;
			player->info.atk = 10;
			player->maxMp = 50;
			player->mp = player->maxMp;
			player->criRate = 0.3f;
			player->criMulti = 1.5f;
			player->SkillList[0] = { L"당근화살", 50 };
			player->SkillList[1] = { L"깡총발차기", 50 };
			player->SkillList[2] = { L"당근발차기", 50 };
			break;
		}
		case Turtle:
		{

			wprintf(L"난 거북이구나.\n\n");
			wprintf(L"       _____     \n");
			wprintf(L"     /       \\   \n");
			wprintf(L" ___|  o   o  |___\n");
			wprintf(L"/     \\  ∇  /     \\\n");
			wprintf(L"\\_____/-----\\_____/\n");
			wprintf(L"   _|         |_   \n");
			wprintf(L"  / |         | \\  \n");
			wprintf(L" /_/|         |\\_\\ \n");
			wprintf(L"   /_/     \\_\\     \n\n");
			wcscpy_s(player->info.name, L"거북이");
			player->info.maxHp = 150;
			player->info.hp = player->info.maxHp;
			player->info.atk = 5;
			player->maxMp = 50;
			player->mp = player->maxMp;
			player->criRate = 0.2f;
			player->criMulti = 1.5f;
			player->SkillList[0] = { L"몸통박치기", 50 };
			player->SkillList[1] = { L"거북충돌", 50 };
			player->SkillList[2] = { L"등껍질투척", 50 };
			break;
		}
		case Quokka:
		{
			wprintf(L"난 쿼카구나.\n\n");
			wprintf(L"  (\\__/)\n");
			wprintf(L"  ( oㅅo)\n");
			wprintf(L"  / 　 づ\n\n");
			wcscpy_s(player->info.name, L"쿼카");
			player->info.maxHp = 80;
			player->info.hp = player->info.maxHp;
			player->info.atk = 10;
			player->maxMp = 80;
			player->mp = player->maxMp;
			player->criRate = 0.2f;
			player->criMulti = 1.5f;
			player->SkillList[0] = { L"파이어볼", 50 };
			player->SkillList[1] = { L"미소레이저", 50 };
			player->SkillList[2] = { L"아이스볼트", 50 };
			break;
		}
		default:
		{
			wprintf(L"내가 누군지 모르겠는걸..\n\n");
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
	wprintf(L"=== 플레이어 상태 ===\n");
	wprintf(L"이름: %ls\n", player->info.name);
	wprintf(L"레벨: %d\n", player->level);
	wprintf(L"HP: %d/%d\n", player->info.hp, player->info.maxHp);
	wprintf(L"공격력: %d\n", player->info.atk);
	wprintf(L"MP: %d/%d\n", player->mp, player->maxMp);
	wprintf(L"치명타 확률: %.2f\n", player->criRate);
	wprintf(L"치명타 배율: %.2f\n", player->criMulti);
	wprintf(L"현재 경험치: %d/%d\n", player->info.exp, player->maxExp);
	wprintf(L"현재 소지 골드: %dGold\n", player->info.gold);

	PrintEquip(player);     // 장비 출력 함수
	wprintf(L"\n");
	PrintInven(player);     // 인벤토리 출력 함수
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
		system("cls");
		wprintf(L"무슨 행동을 할까??\n");
		wprintf(L"1. 탑을 오른다    2. 상태를 확인한다    3. 장비를 장착한다   4. 장비를 해제한다    5. 저장    6. 불러오기    7. 종료\n");

		int select;
		bool isCorrect = true;
		scanf_s("%d", &select);

		system("cls");
		switch (select)
		{
		case 1:
		{
			floorNum++;
			wprintf(L"%d층에 도착했다.\n", floorNum);

			int random = rand() % 100;

			if (random < 70)
			{
				int arr_size = sizeof(monsterNames) / sizeof(wchar_t*);
				const wchar_t* monsterName = PickRandomName(monsterNames, arr_size);
				*monster = CreateMonster(monsterName);
				wprintf(L"몬스터와 마주쳤다! 전투 시작!\n\n");
				Battle(player, monster);
			}
			else if (random < 95)
			{
				while (1)
				{
					wprintf(L"수상한 상인을 만났다.\n");
					wprintf(L"1.구매    2.판매    3.무시하기\n");

					int selNum;
					scanf_s("%d", &selNum);
					system("cls");

					if (selNum == 1)
					{
						InitMerchant(merchant, storeTable);
						SelectProduct(merchant, player);
					}
					else if (selNum == 2)
					{
						SellItem(player);
					}
					else if (selNum == 3)
						break;
				}
				
				wprintf(L"상인을 무시한다. 왠지 뒤에서 중얼거리는 듯하다.\n");
				Sleep(2000);
				break;
				
			}
			else
			{
				wprintf(L"보물상자를 발견했다!\n\n");
				OpenBox(player);
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
				wprintf(L"장비를 장착하자! 뭘 장착할까?\n");
				PrintStatus(player);

				wprintf(L"인벤토리의 번호를 입력하세요 (1~%d까지, 나가기는 0) : ", INVENTORY_SIZE);
				int sel_idx;
				scanf_s("%d", &sel_idx);

				if (sel_idx == 0)
				{
					system("cls");
					break;
				}

				else if (sel_idx < 0 || sel_idx > 10)
					wprintf(L"잘못된 입력입니다. 다시 입력해주세요!\n");

				else if ( player->ItemList[sel_idx - 1].itemType > ITEM_EQUIPLEG)
					wprintf(L"장비 아이템이 아닙니다. 다시 선택해주세요!\n");

				else
				{
					wprintf(L"%s를 장착했습니다!\n", EquipItem(player, sel_idx).name);
					CompactItemList(player);
				}

				Sleep(1000);
			}
			break;
		}
		case 4:
		{
			PrintStatus(player);
			wprintf(L"어느 장비를 해제하겠습니까? (해제하고자 하는 부위명 입력, 나가기는 취소 입력)\n");
			UneqiupItem(player);
			break;
		}
		case 5:
		{
			CreateData(player);
			Sleep(1000);
			break;
		}
		case 6:
		{
			LoadData(player);
			Sleep(1000);
			break;
		}
		case 7:
		{
			wprintf(L"다시 잠에 빠져든다...\n");
			wprintf(L"Game Over!\n");
			exit(0);
		}
		default:
		{
			wprintf(L"이해할 수 없는 행동이야.\n\n");
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
		wprintf(L"\n\n");
		PrintStatus(player);
		

		int act_sel, realDmg_PtoM = 0, realDmg_MtoP = 0;
		bool isCorrect = true;
		wprintf(L"\n1.공격   2.스킬   3.아이템\n");
		wprintf(L"행동 선택 : ");
		scanf_s("%d", &act_sel);

		system("cls");
		switch (act_sel)
		{
		case 1:
		{
			// 최종데미지 계산 로직 실행 후 몬스터 hp - 최종데미지
			wprintf(L"공격!!\n");
			realDmg_PtoM = player->info.atk;
			monster->info.hp -= realDmg_PtoM;
			break;
		}
		case 2:
		{
			int selNum;
			wprintf(L"스킬 사용!!\n");
			PrintSkill(player);
			wprintf(L"스킬을 선택해야해 : ");
			scanf_s("%d", &selNum);

			UseSkill(player, &realDmg_PtoM, selNum);
			monster->info.hp -= realDmg_PtoM;
			// 보유 스킬 출력 후 선택 구현
			break;
		}
		case 3:
		{
			wprintf(L"아이템 사용!\n");
			// 보유 아이템 출력 후 선택 구현
			break;
		}
		default:
		{
			wprintf(L"이상한 행동은 안돼.\n");
			isCorrect = false;
			break;
		}
		}

		wprintf_s(L"%s에게 %d 데미지를 주었습니다!!\n", monster->info.name, realDmg_PtoM);
		// 몬스터 사망 시 전리품 획득과 전투 종료
		if (monster->info.hp <= 0)
		{
			wprintf(L"%s를 처치했다!!\n", monster->info.name);
			wprintf(L"%d의 경험치를 얻었다!!\n", monster->info.exp);
			wprintf(L"%d의 Gold를 얻었다!!\n", monster->info.gold);

			UpdateExpAndLevel(player, monster->info.exp);
			player->info.gold += monster->info.gold;
			const Item* dropItem = RollDrop(monster->dropTable);
			if (!dropItem)
				wprintf(L"아이템이 드랍되지 않았습니다..\n\n");
			else
				wprintf(L"%s를 획득했습니다!!\n\n", dropItem->name);

			PutInven(player, dropItem);
			Sleep(2000);
			system("cls");
			// 전리품 획득 문구 출력 후 전리품 획득 구현
			break;
		}

		// 올바른 입력 시 입력에 따른 결과와 최종 데미지 합산하여 준 피해와 받은 피해 출력.
		if (isCorrect)
		{
			// 몬스터의 최종 데미지 계산 후 플레이어 hp - 최종데미지
			realDmg_MtoP = monster->info.atk;
			player->info.hp -= realDmg_MtoP;
			wprintf_s(L"%s는 %d 피해를 입었습니다!!\n\n", player->info.name, realDmg_MtoP);
		}

		// 플레이어 사망 시 게임 오버
		if (player->info.hp <= 0)
		{
			wprintf(L"%s는 쓰러졌다...\n", player->info.name);
			exit(0);
		}

		Sleep(1000);
		system("cls");
	}

}

Item EquipItem(Player* player, const int item_idx)
{
	Item NewItem = player->ItemList[item_idx - 1];
	if (NewItem.itemType == ITEM_EQUIPWEAPON)
	{
		// 동일 부위에 이미 장착된 장비 존재
		if (wcscmp(player->EquipList[ITEM_EQUIPWEAPON].name, L"") != 0)
		{
			// 기존에 장착된 장비 스탯만큼 감소
			player->info.maxHp -= player->EquipList[ITEM_EQUIPWEAPON].maxHp;
			player->info.hp -= player->EquipList[ITEM_EQUIPWEAPON].hp;
			player->maxMp -= player->EquipList[ITEM_EQUIPWEAPON].maxMp;
			player->mp -= player->EquipList[ITEM_EQUIPWEAPON].mp;
			player->info.atk -= player->EquipList[ITEM_EQUIPWEAPON].atk;
			player->criRate -= player->EquipList[ITEM_EQUIPWEAPON].criRate;
			player->criMulti -= player->EquipList[ITEM_EQUIPWEAPON].criMulti;
			
			// 새로운 장비 스탯만큼 증가 후 기존 장비 인벤토리에 다시 저장
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

		else
		{
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
	}
	else if (NewItem.itemType == ITEM_EQUIPBODY)
	{
		if (wcscmp(player->EquipList[ITEM_EQUIPBODY].name, L"") != 0)
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

		else 
		{
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
	}
	else if (NewItem.itemType == ITEM_EQUIPHEAD)
	{
		if (wcscmp(player->EquipList[ITEM_EQUIPHEAD].name, L"") != 0)
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
		else
		{
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
	}
	else if (NewItem.itemType == ITEM_EQUIPGLOVES)
	{
		if (wcscmp(player->EquipList[ITEM_EQUIPGLOVES].name, L"") != 0)
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
		else
		{
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
	}
	else if (NewItem.itemType == ITEM_EQUIPLEG)
	{
		if (wcscmp(player->EquipList[ITEM_EQUIPLEG].name, L"") != 0)
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
		else
		{
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
	}
	else
	{
		wprintf(L"장비 장착 오류오류오류오류!!!! NewItem 함수 확인\n");
		Item dummy = { 0 };
		return dummy;
	}
}

void UneqiupItem(Player* player)
{
	wchar_t selEquip[20];
	wscanf_s(L"%ws", selEquip, (unsigned)sizeof(selEquip));

	if (wcscmp(selEquip, L"무기") == 0)
	{
		player->info.maxHp -= player->EquipList[ITEM_EQUIPWEAPON].maxHp;
		player->info.hp -= player->EquipList[ITEM_EQUIPWEAPON].hp;
		player->maxMp -= player->EquipList[ITEM_EQUIPWEAPON].maxMp;
		player->mp -= player->EquipList[ITEM_EQUIPWEAPON].mp;
		player->info.atk -= player->EquipList[ITEM_EQUIPWEAPON].atk;
		player->criRate -= player->EquipList[ITEM_EQUIPWEAPON].criRate;
		player->criMulti -= player->EquipList[ITEM_EQUIPWEAPON].criMulti;

		PutInven(player, &player->EquipList[ITEM_EQUIPWEAPON]);
		player->EquipList[ITEM_EQUIPWEAPON] = MakeEmptyItem();
		wprintf(L"무기를 해제했습니다!\n");
	}

	else if (wcscmp(selEquip, L"몸통") == 0)
	{
		player->info.maxHp -= player->EquipList[ITEM_EQUIPBODY].maxHp;
		player->info.hp -= player->EquipList[ITEM_EQUIPBODY].hp;
		player->maxMp -= player->EquipList[ITEM_EQUIPBODY].maxMp;
		player->mp -= player->EquipList[ITEM_EQUIPBODY].mp;
		player->info.atk -= player->EquipList[ITEM_EQUIPBODY].atk;
		player->criRate -= player->EquipList[ITEM_EQUIPBODY].criRate;
		player->criMulti -= player->EquipList[ITEM_EQUIPBODY].criMulti;

		PutInven(player, &player->EquipList[ITEM_EQUIPBODY]);
		player->EquipList[ITEM_EQUIPBODY] = MakeEmptyItem();
		wprintf(L"몸통을 해제했습니다!\n");
	}

	else if (wcscmp(selEquip, L"장갑") == 0)
	{
		player->info.maxHp -= player->EquipList[ITEM_EQUIPGLOVES].maxHp;
		player->info.hp -= player->EquipList[ITEM_EQUIPGLOVES].hp;
		player->maxMp -= player->EquipList[ITEM_EQUIPGLOVES].maxMp;
		player->mp -= player->EquipList[ITEM_EQUIPGLOVES].mp;
		player->info.atk -= player->EquipList[ITEM_EQUIPGLOVES].atk;
		player->criRate -= player->EquipList[ITEM_EQUIPGLOVES].criRate;
		player->criMulti -= player->EquipList[ITEM_EQUIPGLOVES].criMulti;

		PutInven(player, &player->EquipList[ITEM_EQUIPGLOVES]);
		player->EquipList[ITEM_EQUIPGLOVES] = MakeEmptyItem();
		wprintf(L"장갑을 해제했습니다!\n");
	}

	else if (wcscmp(selEquip, L"다리") == 0)
	{
		player->info.maxHp -= player->EquipList[ITEM_EQUIPLEG].maxHp;
		player->info.hp -= player->EquipList[ITEM_EQUIPLEG].hp;
		player->maxMp -= player->EquipList[ITEM_EQUIPLEG].maxMp;
		player->mp -= player->EquipList[ITEM_EQUIPLEG].mp;
		player->info.atk -= player->EquipList[ITEM_EQUIPLEG].atk;
		player->criRate -= player->EquipList[ITEM_EQUIPLEG].criRate;
		player->criMulti -= player->EquipList[ITEM_EQUIPLEG].criMulti;

		PutInven(player, &player->EquipList[ITEM_EQUIPLEG]);
		player->EquipList[ITEM_EQUIPLEG] = MakeEmptyItem();
		wprintf(L"다리를 해제했습니다!\n");
	}

	else if (wcscmp(selEquip, L"머리") == 0)
	{
		player->info.maxHp -= player->EquipList[ITEM_EQUIPHEAD].maxHp;
		player->info.hp -= player->EquipList[ITEM_EQUIPHEAD].hp;
		player->maxMp -= player->EquipList[ITEM_EQUIPHEAD].maxMp;
		player->mp -= player->EquipList[ITEM_EQUIPHEAD].mp;
		player->info.atk -= player->EquipList[ITEM_EQUIPHEAD].atk;
		player->criRate -= player->EquipList[ITEM_EQUIPHEAD].criRate;
		player->criMulti -= player->EquipList[ITEM_EQUIPHEAD].criMulti;

		PutInven(player, &player->EquipList[ITEM_EQUIPHEAD]);
		player->EquipList[ITEM_EQUIPHEAD] = MakeEmptyItem();
		wprintf(L"머리를 해제했습니다!\n");
	}

	else if (wcscmp(selEquip, L"취소") == 0)
	{
		system("cls");
		return;
	}

	else
	{
		wprintf(L"잘못된 입력입니다!\n");
	}
	Sleep(1000);
	system("cls");
}

void SellItem(Player* player)
{
	while (wcscmp(player->ItemList[0].name, L"") != 0)
	{
		system("cls");
		int selNum;
		PrintInven(player);
		wprintf(L"판매할 아이템을 골라야 해! (0은 나가기)\n");
		scanf_s("%d", &selNum);

		if (selNum == 0)
		{
			system("cls");
			return;
		}

		player->info.gold += player->ItemList[selNum - 1].gold / 10;
		wprintf(L"%dGold 획득!\n", player->ItemList[selNum - 1].gold / 10);
		player->ItemList[selNum - 1] = MakeEmptyItem();
		CompactItemList(player);
		Sleep(1000);

	}

	wprintf(L"판매할 아이템이 없어..\n");
	Sleep(1000);
	system("cls");
	// 추후 판매 가능한 최대 횟수를 정하고 최대 횟수에 다다르면 바로 나가기 
}

void flushInputBuffer()
{
	while (_kbhit()) _getwch();
}

bool SkillNameInput(const wchar_t* skillName, int timeLimitSec) {
	setlocale(LC_ALL, "");  // 한글 입력/출력 설정

	wchar_t input[MAX_INPUT] = { 0 };
	int idx = 0;
	int lastDisplayed = -1;

	time_t start = time(NULL);
	time_t current;

	wprintf(L"스킬명을 %d초 안에 정확히 입력하세요: %ls\n", timeLimitSec, skillName);
	wprintf(L"> ");
	fflush(stdout);

	while (1) {
		current = time(NULL);
		int elapsed = (int)(current - start);
		int timeLeft = timeLimitSec - elapsed;

		if (timeLeft != lastDisplayed) {
			lastDisplayed = timeLeft;
			wprintf(L"\r> %ls   [남은 시간: %2d초]   ", input, timeLeft);
			fflush(stdout);
		}

		if (elapsed >= timeLimitSec) {
			break;
		}

		if (_kbhit()) {
			wchar_t ch = _getwch();

			if (ch == L'\r') {
				break;
			}
			else if (ch == L'\b') {
				if (idx > 0) {
					idx--;
					input[idx] = L'\0';
				}
			}
			else if (iswprint(ch) && idx < MAX_INPUT - 1) {
				input[idx++] = ch;
				input[idx] = L'\0';
			}
		}

		Sleep(10);
	}

	wprintf(L"\n");

	if (wcslen(input) == 0) {
		wprintf(L"[시간 초과!] 스킬 실패!\n");
		return false;
	}

	if (wcscmp(input, skillName) == 0) {
		wprintf(L"정확하게 입력했습니다! 스킬 발동!\n");
		return true;
	}
	else {
		wprintf(L"잘못된 입력입니다. 스킬 실패!\n");
		return false;
	}
}

bool SkillRandomInput(int pressCount, int timeLimitSeconds)
{
	wchar_t targets[10];

	wprintf(L"%d초 안에 다음 버튼들을 순서대로 누르세요:\n", timeLimitSeconds);

	for (int i = 0; i < pressCount; ++i)
	{
		targets[i] = L'A' + rand() % 26;
		wprintf(L"%c ", targets[i]);
	}
	wprintf(L"\n");

	clock_t start = clock();

	for (int i = 0; i < pressCount; ++i)
	{
		wchar_t input;
		wprintf(L"%d번째 버튼 입력: ", i + 1);

		// 공백 문자 무시하고 한 문자 입력 (Enter 필요 없음)
		do {
			input = _getwch();
		} while (iswspace(input));  // wide 문자 공백 체크

		if (input != targets[i])
		{
			wprintf(L"\n잘못된 버튼! 스킬 실패!\n");
			return 0;
		}

		clock_t now = clock();
		double elapsed = (double)(now - start) / CLOCKS_PER_SEC;
		if (elapsed > timeLimitSeconds)
		{
			wprintf(L"\n시간 초과! (%.2f초)\n", elapsed);
			return 0;
		}

		wprintf(L"%c\n", input); // 입력 확인 출력
	}

	wprintf(L"성공! 스킬 발동!\n");
	return 1;
}

const wchar_t* ArrowName(int code) {
	switch (code) {
	case ARROW_UP: return L"↑";
	case ARROW_DOWN: return L"↓";
	case ARROW_LEFT: return L"←";
	case ARROW_RIGHT: return L"→";
	default: return L"?";
	}
}

bool SkillArrowCommandInput(const int* expectedCommand, int length, int timeLimitMs)
{
	wprintf(L">> 정해진 방향키를 %d초 내에 순서대로 입력하세요!\n", timeLimitMs / 1000);
	wprintf(L">> 입력할 순서: ");
	for (int i = 0; i < length; ++i)
		wprintf(L"%s ", ArrowName(expectedCommand[i]));
	wprintf(L"\n\n");

	DWORD startTime = GetTickCount64();

	for (int i = 0; i < length; ++i)
	{
		while (!_kbhit())
		{
			if (GetTickCount64() - startTime > (DWORD)timeLimitMs)
			{
				wprintf(L"\n[실패] 시간 초과!\n");
				return false;
			}
		}

		int ch = _getch();
		if (ch == 0 || ch == 224)
		{
			int arrow = _getch();

			if (arrow != expectedCommand[i])
			{
				wprintf(L"[실패] 잘못된 방향 입력 (%s)\n", ArrowName(arrow));
				return false;
			}
			else
			{
				wprintf(L"[성공] 입력: %s\n", ArrowName(arrow));
			}
		}
		else
		{
			wprintf(L"[실패] 방향키가 아닙니다.\n");
			return false;
		}
	}

	wprintf(L"\n[성공] 스킬 발동!\n");
	return true;
}

void PrintSkill(Player* player)
{
	for (int i = 0; i < SKILL_SLOTNUM; i++)
		wprintf(L"%d.%s   ", i + 1, player->SkillList[i].name);

	wprintf(L"\n");
}

void UseSkill(Player* player, int* realDmg_PtoM, const int selNum)
{
	if (selNum == 1)
	{
		if (SkillNameInput(player->SkillList[selNum - 1].name, 4))
			*realDmg_PtoM += player->SkillList[selNum - 1].atk;
	}

	else if (selNum == 2)
	{
		if (SkillRandomInput(4, 4))
			*realDmg_PtoM += player->SkillList[selNum - 1].atk;
	}
	
	else if (selNum == 3)
	{
		int skillCombo[] = { ARROW_LEFT, ARROW_DOWN, ARROW_RIGHT, ARROW_DOWN };
		if (SkillArrowCommandInput( skillCombo, 4, TIME_LIMIT_MS))
			*realDmg_PtoM += player->SkillList[selNum - 1].atk;
	}

	else
	{
		wprintf(L"잘못된 입력! 다시 입력하세요.\n");
	}
}