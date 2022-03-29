#pragma once
#include "Status.h"
#include "TypeFactory.h"
#include "MoveList.h"
#include <Mof.h>

class CMonsterData
{
private:
	int		m_No;					// 図鑑No 画像の取得に使用
	std::string	m_RaceName;			// 種族名
	Status m_BaseStatus;			// 種族値
	std::vector<CTypeBase*> m_Type;
	std::vector<CMove>	m_RememberMove; // 覚えられるわざ

public:
	CMonsterData();
	bool Load(std::string name);
	void Release();


	int GetNo() { return m_No; }
	std::string GetName() { return m_RaceName; }
	Status GetStatus() { return m_BaseStatus; }
};

