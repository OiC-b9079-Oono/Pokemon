#pragma once
#include "MonsterData.h"

class CMonsterDataList
{
	std::vector<CMonsterData> m_MonsterArray;
	CMonsterDataList() :
		m_MonsterArray() {
		Load();
	}
public:
	static CMonsterDataList& GetInstance()
	{
		static CMonsterDataList obj;
		return obj;
	}
	bool Load();
	CMonsterData GetMonster(int move_no) { return m_MonsterArray[move_no];	}
	CMonsterData GetRandomMonster() {
		int no = rand() % m_MonsterArray.size();
		return m_MonsterArray[no]; 
	}
	void Release();
};

