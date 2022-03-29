#pragma once
#include "MonsterDataList.h"

class CMonster
{
private:
	CMonsterData m_Data;
	int		m_Level;					// ���x��

	int m_HP;

	int		m_SelectMove;		// �I�𒆂̂킴
	bool	m_bMainPosition;

	Status m_EffortValue;		// �̒l
	Status m_IndividualValue;	// �w�͒l

	CTexture* m_Texture;
	CTexture* m_BackTexture;

	std::vector<CMove>	m_RememberedMove; // �o���Ă���킴
public:
	CMonster();
	~CMonster();
	bool Load();
	void SetPosition(bool pos) { m_bMainPosition = pos; }
	void Initialize(CMonsterData data, CTexture* tex, CTexture* back);
	void Update();
	void Render();
	void Release();

	std::string GetName() { return m_Data.GetName(); }
	float GetHpPercent() { return m_HP / GetRealStatus(0); }
	int GetRealStatus(int no);
	int GetLevel() { return m_Level; }
};