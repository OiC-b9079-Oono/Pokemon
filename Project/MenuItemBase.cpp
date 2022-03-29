#include "MenuItemBase.h"

CMenuItemBase::CMenuItemBase() :
	m_bSelect(false) {

}

CMenuItemBase::~CMenuItemBase() {

}

void CMenuItemBase::Initialize(const ItemStatus& status) {
	m_Status = status;
}

void CMenuItemBase::ChangeText(const std::string& tex) {
	m_Status.Text = tex;
}

void CMenuItemBase::Update(const bool& select) {
	m_bSelect = select;
}

bool CMenuItemBase::Collision(const CVector2& pos) {
	return GetRect().CollisionPoint(pos);
}

void CMenuItemBase::Render(const CVector2& pos) {
}

void CMenuItemBase::Release() {
}