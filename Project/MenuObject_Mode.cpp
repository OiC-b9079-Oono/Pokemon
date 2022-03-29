#include "MenuObject_Mode.h"

CMenuObject_Mode::CMenuObject_Mode() :
	m_SelectNo(0) {
}

void CMenuObject_Mode::Initialize() {
	m_MStatus.Size = CVector2(320, 210);
	m_MStatus.Pos = CVector2(640, 525);
	m_MStatus.Type = 1;
	m_MStatus.EdgeLineColor = MOF_COLOR_BLACK;
	m_MStatus.SurfaceColor = MOF_XRGB(230, 230, 230);

	m_MenuItemStatus[0].ItemType = ItemType::ITEMTYPE_BUTTON;
	m_MenuItemStatus[0].Size = CVector2(110, 60);
	m_MenuItemStatus[0].Pos = CVector2(30, 30);
	m_MenuItemStatus[0].Text = "‚½‚½‚©‚¤";
	m_MenuItemStatus[0].EdgeSize = 3;
	m_MenuItemStatus[0].TextColor = MOF_COLOR_BLACK;
	m_MenuItemStatus[0].SurfaceColor = MOF_COLOR_WHITE;
	m_MenuItemStatus[0].EdgeColor = MOF_COLOR_BLACK;

	m_MenuItemStatus[1].ItemType = ItemType::ITEMTYPE_BUTTON;
	m_MenuItemStatus[1].Size = CVector2(110, 60);
	m_MenuItemStatus[1].Pos = CVector2(180, 30);
	m_MenuItemStatus[1].Text = "ƒ|ƒPƒ‚ƒ“";
	m_MenuItemStatus[1].EdgeSize = 3;
	m_MenuItemStatus[1].TextColor = MOF_COLOR_BLACK;
	m_MenuItemStatus[1].SurfaceColor = MOF_COLOR_WHITE;
	m_MenuItemStatus[1].EdgeColor = MOF_COLOR_BLACK;

	m_MenuItemStatus[2].ItemType = ItemType::ITEMTYPE_BUTTON;
	m_MenuItemStatus[2].Size = CVector2(110, 60);
	m_MenuItemStatus[2].Pos = CVector2(30, 120);
	m_MenuItemStatus[2].Text = "‚Ç‚¤‚®";
	m_MenuItemStatus[2].EdgeSize = 3;
	m_MenuItemStatus[2].TextColor = MOF_COLOR_BLACK;
	m_MenuItemStatus[2].SurfaceColor = MOF_COLOR_WHITE;
	m_MenuItemStatus[2].EdgeColor = MOF_COLOR_BLACK;

	m_MenuItemStatus[3].ItemType = ItemType::ITEMTYPE_BUTTON;
	m_MenuItemStatus[3].Size = CVector2(110, 60);
	m_MenuItemStatus[3].Pos = CVector2(180, 120);
	m_MenuItemStatus[3].Text = "‚É‚°‚é";
	m_MenuItemStatus[3].EdgeSize = 3;
	m_MenuItemStatus[3].TextColor = MOF_COLOR_BLACK;
	m_MenuItemStatus[3].SurfaceColor = MOF_COLOR_WHITE;
	m_MenuItemStatus[3].EdgeColor = MOF_COLOR_BLACK;

	CMenu::Initialize(m_MStatus, m_MenuItemStatus, m_ItemCount);
}

void CMenuObject_Mode::Update() {
	Vector2 mpos;
	g_pInput->GetMousePos(mpos);

	UpdateMenuMouse(mpos);
	UpdateMenu();
}

void CMenuObject_Mode::UpdateMenu() {
	CInputManager::GetInstance().SelectVertical(0, m_SelectNo, 3, 0);
	SelectButton(m_SelectNo);
	if (CInputManager::GetInstance().GetPush(0, 1) || CInputManager::GetInstance().GetPush(0, 8))
	{

	}
}

void CMenuObject_Mode::UpdateMenuMouse(Vector2 vec) {
	CMenu::Update();
	int no = Collision(vec);
	if (no == -1) { return; }
	m_SelectNo = no;
	if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON))
	{

	}
}