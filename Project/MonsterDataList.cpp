#include "MonsterDataList.h"

bool CMonsterDataList::Load() {

	CUtilities::SetCurrentDirectory("Monster");
	FILE* fp = fopen("MonsterList.txt", "rb");
	if (!fp) { return false; }

	fseek(fp, 0, SEEK_END);
	long fSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	//ファイルサイズ分だけのメモリを確保する
	char* pBuffer = (char*)malloc(fSize + 1);
	//ファイルを全てバッファに読み込む
	fSize = fread(pBuffer, 1, fSize, fp);
	pBuffer[fSize] = '\0';
	char* pstr;

	pstr = strtok(pBuffer, ",");

	// キャラクターの総数
	int monstercnt = atoi(pstr);
	pstr = strtok(NULL, ",\r\n");

	std::vector<std::string> pass;

	for (int i = 0; i < monstercnt; i++)
	{
		pass.push_back(pstr);
		pstr = strtok(NULL, ",\r\n");
	}

	fclose(fp);
	free(pBuffer);

	for (int i = 0; i < monstercnt; i++)
	{
		m_MonsterArray.push_back(CMonsterData());
		pass[i] = pass[i] + ".txt";
		m_MonsterArray[i].Load(pass[i]);
	}

	
	CUtilities::SetCurrentDirectory("..");
	return true;
}

void CMonsterDataList::Release() {
	for (int i = 0; i < m_MonsterArray.size(); i++)
	{
		m_MonsterArray[i].Release();
	}
}