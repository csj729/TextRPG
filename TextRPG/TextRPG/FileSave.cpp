#include "FileSave.h"


void CreateData(Player* pinfo)
{
	FILE* pFile = NULL;

	fopen_s(&pFile, "SaveData.KGA", "wb");

	if (pFile != NULL)
	{
		fwrite(pinfo, sizeof(Player), 1, pFile);

		int iData = fclose(pFile);
		if (iData != 0)
		{
			//�ݱ� ����
			printf("���� �Ҹ� ���� \n");
		}
	}

	printf("================\n");
	printf("ĳ���� ���� ����!\n");
	printf("================\n");
}

void LoadData(Player* pinfo)
{
	FILE* pFile = NULL;

	fopen_s(&pFile, "SaveData.KGA", "rb");

	if (pFile != NULL)
	{
		// ������ player ������ ����
		memset(pinfo, 0, sizeof(Player));

		fread(pinfo, sizeof(Player), 1, pFile);

		int iData = fclose(pFile);
		if (iData != 0)
		{
			//�ݱ� ����
			printf("���� �Ҹ� ���� \n");
		}
	}

	printf("================\n");
	printf("ĳ���� �ε� ����!\n");
	printf("================\n");
}