#include "Monster.h"

CMonster::CMonster() :
	m_Level(0),
	m_HP(0),
	m_SelectMove(0),
	m_bMainPosition(false),
	m_EffortValue(),
	m_IndividualValue(),
	m_Texture(),
	m_BackTexture(),
	m_RememberedMove() {
}

CMonster::~CMonster() {

}

bool CMonster::Load() {
	return true;
}

void CMonster::Initialize(CMonsterData data, CTexture* tex, CTexture* back) {
	m_Data = data;
	m_Level = rand() % 100 + 1;
	m_HP = GetRealStatus(0);
	m_Texture = tex;
	m_BackTexture = back;
}

void CMonster::Update() {

}

void CMonster::Render() {
	float w = g_pGraphics->GetTargetWidth();
	float h = g_pGraphics->GetTargetHeight();
	int x = (m_Data.GetNo() - 1 ) % 31;
	int y = (m_Data.GetNo() - 1 ) / 31;
	float size = 96;
	CRectangle rec(size * x, size * y, size * (x + 1), size * (y + 1));
	if (m_bMainPosition)
	{
		float mainsize = 384;
		m_BackTexture->RenderScale(0, h - mainsize - 256, mainsize / size, rec);
	}
	else
	{
		float backsize = 256;
		m_Texture->RenderScale(w - backsize - 64, 0, backsize / size, rec);
	}
}

void CMonster::Release() {

}

int CMonster::GetRealStatus(int no) {
	switch (no)
	{
	case 0:
		return ((m_Data.GetStatus().HP * 2 + m_EffortValue.HP + m_IndividualValue.HP / 4) * m_Level / 100) + 10 + m_Level;
	case 1:
		return ((m_Data.GetStatus().Attack * 2 + m_EffortValue.Attack + m_IndividualValue.Attack / 4) * m_Level / 100) + 5;
	case 2:
		return ((m_Data.GetStatus().Block * 2 + m_EffortValue.Block + m_IndividualValue.Block / 4) * m_Level / 100) + 5;
	case 3:
		return ((m_Data.GetStatus().Charge * 2 + m_EffortValue.Charge + m_IndividualValue.Charge / 4) * m_Level / 100) + 5;
	case 4:
		return ((m_Data.GetStatus().Defense * 2 + m_EffortValue.Defense + m_IndividualValue.Defense / 4) * m_Level / 100) + 5;
	case 5:
		return ((m_Data.GetStatus().Speed * 2 + m_EffortValue.Speed + m_IndividualValue.Speed / 4) * m_Level / 100) + 5;
	default:
		break;
	}
	return 0;
}