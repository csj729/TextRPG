#include "Struct.h"
#include "Player.h"
#include "Monster.h"
#include "Merchant.h"

int floorNum = 0;
StoreTable storeTable[STORETABLE_MAXNUM];

int main()
{
	srand(unsigned(time(NULL)));
	Player player;
	Monster monster;
	Merchant merchant;


	printf("잠에서 깬다..\n");
	SelectAnimal(&player);
	InitInven(&player);
	InitStoreTable(storeTable);

	while (1)
	{
		SelectAction(&player, &monster, &merchant);
	}
	return 0;
}

