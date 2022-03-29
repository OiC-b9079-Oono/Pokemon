#pragma once
#include "SceneBase.h"
#include "Monster.h"
#include "Menu.h"

#include "MenuObject_Mode.h"

class CSceneBattle : public CSceneBase
{
private:
	std::vector<CMonster> m_MyMonster;
	CMonster m_WildMonster;

	int m_SelectMonster;

	CTexture m_Texture;
	CTexture m_BackTexture;

	CMenuObject_Mode m_ModeMenu;

	void InitializeMenu();


	void RenderHPGage(CVector2 pos, float per, std::string name, int level);
	void RenderMessage();
public:
	CSceneBattle();
	void Initialize(void);
	void Update(void);
	void UpdateDebug(void);
	void Render(void);
	void RenderDebug(void);
	void Release(void);
};

