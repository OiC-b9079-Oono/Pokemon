#pragma once
#include "MenuItemStatus.h"

class CMenuItemBase
{
protected:
	ItemStatus  m_Status;
	bool		m_bSelect;
public:
	CMenuItemBase();
	virtual ~CMenuItemBase();
	virtual void Initialize(const ItemStatus& status);
	virtual void ChangeText(const std::string& tex);
	virtual void Update(const bool& select);
	virtual bool Collision(const CVector2& pos);
	virtual void Render(const CVector2& pos = CVector2(0, 0));
	virtual void Release();
	ItemStatus GetStatus() { return m_Status; };
	ItemType   GetItemType() { return m_Status.ItemType; }
	CRectangle GetRect(const CVector2& pos = CVector2(0, 0)) {
		return CRectangle(m_Status.Pos.x + pos.x, m_Status.Pos.y + pos.y, m_Status.Pos.x + m_Status.Size.x + pos.x, m_Status.Pos.y + m_Status.Size.y + pos.y);
	}
	CRectangle GetEdgeRect(const CVector2& pos = CVector2(0, 0)) {
		return CRectangle(m_Status.Pos.x + pos.x + m_Status.EdgeSize, m_Status.Pos.y + pos.y + m_Status.EdgeSize, m_Status.Pos.x + m_Status.Size.x + pos.x - m_Status.EdgeSize, m_Status.Pos.y + m_Status.Size.y + pos.y - m_Status.EdgeSize);
	}
};

