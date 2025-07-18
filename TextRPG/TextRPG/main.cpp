#include "Struct.h"
#include "Player.h"
#include "Monster.h"

int floorNum = 0;
int playerLevel = 1;

int main()
{
	srand(unsigned(time(NULL)));
	Player player;
	Monster monster;

	printf("잠에서 깬다..\n");
	SelectAnimal(&player);
	// PrintStatus(&player);

	while (1)
	{
		SelectAction(&player, &monster);
	}
	return 0;
}

