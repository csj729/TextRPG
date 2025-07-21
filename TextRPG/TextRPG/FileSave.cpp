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
			//닫기 실패
			printf("파일 소멸 실패 \n");
		}
	}

	printf("================\n");
	printf("캐릭터 저장 성공!\n");
	printf("================\n");
}

void LoadData(Player* pinfo)
{
	FILE* pFile = NULL;

	fopen_s(&pFile, "SaveData.KGA", "rb");

	if (pFile != NULL)
	{
		// 기존에 player 데이터 삭제
		memset(pinfo, 0, sizeof(Player));

		fread(pinfo, sizeof(Player), 1, pFile);

		int iData = fclose(pFile);
		if (iData != 0)
		{
			//닫기 실패
			printf("파일 소멸 실패 \n");
		}
	}

	printf("================\n");
	printf("캐릭터 로드 성공!\n");
	printf("================\n");
}