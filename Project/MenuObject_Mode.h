#pragma once
#include "Menu.h"
#include "CInputManager.h"

class CMenuObject_Mode : public CMenu
{
private:
	int m_SelectNo;

	static const int m_ItemCount = 4;
	ItemStatus m_MenuItemStatus[m_ItemCount];

	void UpdateMenu();
	void UpdateMenuMouse(Vector2 vec);
public:
	CMenuObject_Mode();

	void Initialize(void);
	void Update(void);
};

