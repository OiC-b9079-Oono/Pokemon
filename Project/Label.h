#pragma once
#include "MenuItemBase.h"

class CLabel : public CMenuItemBase
{
private:
public:
	CLabel();
	~CLabel();

	void Render(const CVector2& pos = CVector2(0, 0));
};