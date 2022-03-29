#include "SceneBattle.h"

CSceneBattle::CSceneBattle() :
	m_MyMonster(),
	m_WildMonster(),
	m_SelectMonster(0),
	m_Texture(),
	m_BackTexture() {

}

void CSceneBattle::Initialize() {
	m_Texture.Load("Monster/Pokemon.png");
	m_BackTexture.Load("Monster/Pokemon Back.png");

	CMonsterData data = CMonsterDataList::GetInstance().GetRandomMonster();
	m_WildMonster.Initialize(data, &m_Texture, &m_BackTexture);
	m_WildMonster.SetPosition(false);
	for (int i = 0; i < 3; i++)
	{
		m_MyMonster.push_back(CMonster());
		CMonsterData data = CMonsterDataList::GetInstance().GetRandomMonster();
		m_MyMonster[i].Initialize(data, &m_Texture, &m_BackTexture);
		m_MyMonster[i].SetPosition(true);
	}
	InitializeMenu();
}

void CSceneBattle::InitializeMenu() {
	m_ModeMenu.Initialize();
}

void CSceneBattle::Update() {

}

void CSceneBattle::UpdateDebug() {

}

void CSceneBattle::Render() {
	m_WildMonster.Render();
	m_MyMonster[m_SelectMonster].Render();
	RenderHPGage(CVector2(454, 50), m_WildMonster.GetHpPercent(), m_WildMonster.GetName(), m_WildMonster.GetLevel());
	RenderHPGage(CVector2(384, 288), m_MyMonster[m_SelectMonster].GetHpPercent(), m_MyMonster[m_SelectMonster].GetName(), m_MyMonster[m_SelectMonster].GetLevel());
	RenderMessage();
	m_ModeMenu.Render();
}

void CSceneBattle::RenderHPGage(CVector2 pos, float per, std::string name, int level) {
	CGraphicsUtilities::RenderFillRect(pos.x, pos.y, pos.x + 250, pos.y + 80, MOF_XRGB(0, 0, 0));
	CGraphicsUtilities::RenderFillRect(pos.x + 3, pos.y + 3, pos.x + 247, pos.y + 77, MOF_XRGB(200, 200, 200));
	CGraphicsUtilities::RenderFillRect(pos.x + 20, pos.y + 40, pos.x + 230, pos.y + 60, MOF_XRGB(0, 0, 0));
	CGraphicsUtilities::RenderFillRect(pos.x + 21, pos.y + 41, pos.x + 229, pos.y + 59, MOF_XRGB(0, 100, 0));
	CGraphicsUtilities::RenderFillRect(pos.x + 21, pos.y + 41, pos.x + 229 * per, pos.y + 59, MOF_XRGB(0, 255, 0));

	CFont font;
	font.SetSize(25);
	std::string text = name + " : Lv" + std::to_string(level);
	font.RenderString(pos.x + 5, pos.y + 5, MOF_COLOR_BLACK, text.c_str());
}

void CSceneBattle::RenderMessage() {
	float w = g_pGraphics->GetTargetWidth();
	float h = g_pGraphics->GetTargetHeight();
	CGraphicsUtilities::RenderFillRect(0, 480, w, h, MOF_XRGB(0, 0, 0));
	CGraphicsUtilities::RenderFillRect(0, 500, w, h, MOF_XRGB(200, 200, 200));

}

void CSceneBattle::RenderDebug() {

}

void CSceneBattle::Release() {
	m_Texture.Release();
	m_BackTexture.Release();
	m_ModeMenu.Release();
}