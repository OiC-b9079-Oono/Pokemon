#include "MoveList.h"

bool CMoveList::Load() {

	CUtilities::SetCurrentDirectory("Move");
	FILE* fp = fopen("MoveList.txt", "rb");
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

	// わざの総数
	int movecnt = atoi(pstr);
	pstr = strtok(NULL, ",\r\n");

	for (int i = 0; i < movecnt; i++)
	{
		m_MoveArray.push_back(CMove());
		std::string pass = pstr;
		pass = pass + ".txt";
		pstr = strtok(NULL, ",\r\n");
		m_MoveArray[i].Load(pass);
	}

	fclose(fp);
	free(pBuffer);
	CUtilities::SetCurrentDirectory("..");
	return true;
}