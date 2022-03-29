#include "MonsterData.h"

CMonsterData::CMonsterData() :
	m_No(0),
	m_BaseStatus(),
	m_Type(),
	m_RememberMove() {

}

bool CMonsterData::Load(std::string name) {
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

	m_No = atoi(pstr);
	pstr = strtok(NULL, ",");

	// キャラクターのHP
	m_RaceName = pstr;
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

	m_BaseStatus.HP = (MoveType)atoi(pstr);
	pstr = strtok(NULL, ",");

	m_BaseStatus.Attack = (MoveType)atoi(pstr);
	pstr = strtok(NULL, ",");

	m_BaseStatus.Block = (MoveType)atoi(pstr);
	pstr = strtok(NULL, ",");

	m_BaseStatus.Charge = (MoveType)atoi(pstr);
	pstr = strtok(NULL, ",");

	m_BaseStatus.Defense = (MoveType)atoi(pstr);
	pstr = strtok(NULL, ",");

	m_BaseStatus.Speed = (MoveType)atoi(pstr);
	pstr = strtok(NULL, ",");

	int movecnt = atoi(pstr);
	pstr = strtok(NULL, ",");

	for (int i = 0; i < movecnt; i++)
	{

	}

	fclose(fp);
	free(pBuffer);

	return true;
}

void CMonsterData::Release() {
	for (int i = 0; i < m_Type.size(); i++)
	{
		delete m_Type[i];
		m_Type[i] = NULL;
	}
}