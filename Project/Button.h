#pragma once
#include "MenuItemBase.h"

class CButton : public CMenuItemBase
{
private:

public:
	CButton();
	~CButton();

	bool Collision(const CVector2& pos);
	void Render(const CVector2& pos = CVector2(0, 0));
};