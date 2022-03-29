#pragma once
#include "MenuItemFactory.h"
#include "MenuStatus.h"

class CMenu
{
protected:
	MenuStatus						m_MStatus;
	std::vector<CMenu*>				m_pSubMenu;
	std::vector<CMenuItemBase*>		m_pItem;

	CVector2 m_StartPos;
	CVector2 m_EndPos;
	CVector2 m_Scroll;
	CTexture m_RenderTarget;


	CRectangle GetEdgeRect()
	{
		return CRectangle(m_MStatus.Pos.x + m_MStatus.EdgeLineSize, m_MStatus.Pos.y + m_MStatus.EdgeLineSize, m_MStatus.Pos.x + m_MStatus.Size.x - m_MStatus.EdgeLineSize, m_MStatus.Pos.y + m_MStatus.Size.y - m_MStatus.EdgeLineSize);
	}

	void PackPosition(int type);
	void RenderMakedRect();
	void MakeRender();
	void RenderGraphic();

public:
	CMenu();
	~CMenu();

	void Initialize(MenuStatus ms, ItemStatus* is, int itemcnt, CMenu* submenu = NULL);
	void Initialize(MenuStatus ms, std::vector<ItemStatus> is, CMenu* submenu = NULL);
	void Update();
	void UpdateStatus(ItemStatus* is, int itemcnt,int startno, CMenu* submenu = NULL);
	void UpdateStatus(std::vector<ItemStatus> is, int startno, CMenu* submenu = NULL);
	void SelectButton(int i);
	int  Collision(CVector2 vec);
	void ChangeText(int i, std::string tex);
	void Render();
	void Release();

	bool IsSubMenuNo(int sno, int mno);

	int ChangeMainMenuNo(const int& sno);
	int ChangeSubMenuNo(const int& sno, const int& menuno);

	CRectangle GetRect()
	{
		return CRectangle(m_MStatus.Pos.x, m_MStatus.Pos.y, m_MStatus.Pos.x + m_MStatus.Size.x, m_MStatus.Pos.y + m_MStatus.Size.y);
	}
	MenuStatus	GetMenuStatus() { return m_MStatus; }

	int GetRangeNo();
	int GetSubMenuGetRange(int mno) { return m_pSubMenu[mno]->GetRangeNo(); }
	CMenu* GetSubMenu(int menuno) { return m_pSubMenu[menuno]; }
};

