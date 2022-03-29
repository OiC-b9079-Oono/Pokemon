#include "Move.h"

CMove::CMove() :
	m_Name(),
	m_Type(),
	m_MoveType(MoveType::MOVETYPE0_STATUS),
	m_Power(0),
	m_HitRate(0),
	m_PowerPoint(0),
	m_Effect() {
}

CMove::~CMove() {

}

bool CMove::Load(std::string name) {
	FILE* fp = fopen(name.c_str(), "rb");
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

	// キャラクターのHP
	m_Name = pstr;
	pstr = strtok(NULL, ",");

	int typecnt = atoi(pstr);
	pstr = strtok(NULL, ",");

	CTypeFactory factory;
	for (int i = 0; i < typecnt; i++)
	{
		int typeno = atoi(pstr);
		m_Type.push_back(factory.CreateType(typeno));
		pstr = strtok(NULL, ",");
	}

	m_MoveType = (MoveType)atoi(pstr);
	pstr = strtok(NULL, ",");

	m_Power = atoi(pstr);
	pstr = strtok(NULL, ",");

	m_HitRate = atoi(pstr);
	pstr = strtok(NULL, ",");

	m_PowerPoint = atoi(pstr);
	pstr = strtok(NULL, ",");

	int effectcnt = atoi(pstr);
	pstr = strtok(NULL, ",");

	for (int i = 0; i < effectcnt; i++)
	{

	}

	fclose(fp);
	free(pBuffer);

	return true;
}