#pragma once
#include "Label.h"
#include "Button.h"

class CMenuItemFactory
{
private:
	CMenuItemFactory() {

	}
public:
	static CMenuItemFactory& GetInstance() {
		static CMenuItemFactory obj;
		return obj;
	}

	CMenuItemBase* CreateMenuItem(ItemType type) {
		switch (type)
		{
		case ITEMTYPE_LABEL:
			return new CLabel();
		case ITEMTYPE_BUTTON:
			return new CButton();
		default:
			break;
		}
		return nullptr;
	}
};