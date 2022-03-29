#pragma once
#include "MonsterDataList.h"

class CMonster
{
private:
	CMonsterData m_Data;
	int		m_Level;					// レベル

	int m_HP;

	int		m_SelectMove;		// 選択中のわざ
	bool	m_bMainPosition;

	Status m_EffortValue;		// 個体値
	Status m_IndividualValue;	// 努力値

	CTexture* m_Texture;
	CTexture* m_BackTexture;

	std::vector<CMove>	m_RememberedMove; // 覚えているわざ
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