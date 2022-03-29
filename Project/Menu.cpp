#include "Menu.h"

CMenu::CMenu() :
	m_MStatus(),
	m_pSubMenu(),
	m_pItem(),
	m_StartPos(0, 0),
	m_EndPos(0, 0),
	m_Scroll(0, 0) {

}

CMenu::~CMenu() {

}

void CMenu::Initialize(MenuStatus ms, ItemStatus* is, int itemcnt, CMenu* submenu) {
	m_MStatus = ms;
	m_StartPos = CVector2(0, 0);
	m_EndPos = CVector2(0, 0);

	PackPosition(m_MStatus.Type);

	if (m_MStatus.SubMenuCount <= 0 && m_pSubMenu.size() > 0)
	{
		m_pSubMenu.clear();
	}
	if (m_MStatus.SubMenuCount > 0 && submenu)
	{
		m_pSubMenu.clear();
		for (int i = 0; i < m_MStatus.SubMenuCount; i++)
		{
			m_pSubMenu.push_back(&submenu[i]);
			m_StartPos.x = min(m_StartPos.x, m_pSubMenu[i]->GetMenuStatus().Pos.x - ms.EdgeSpaceSize - ms.EdgeLineSize);
			m_StartPos.y = min(m_StartPos.y, m_pSubMenu[i]->GetMenuStatus().Pos.y - ms.EdgeSpaceSize - ms.EdgeLineSize);
			m_EndPos.x = max(m_EndPos.x, m_pSubMenu[i]->GetMenuStatus().Pos.x + m_pSubMenu[i]->GetMenuStatus().Size.x + ms.EdgeSpaceSize + ms.EdgeLineSize);
			m_EndPos.y = max(m_EndPos.y, m_pSubMenu[i]->GetMenuStatus().Pos.y + m_pSubMenu[i]->GetMenuStatus().Size.y + ms.EdgeSpaceSize + ms.EdgeLineSize);
		}
	}

	m_pItem.clear();
	for (int i = 0; i < itemcnt; i++)
	{
		m_pItem.push_back(CMenuItemFactory::GetInstance().CreateMenuItem(is[i].ItemType));
		m_StartPos.x = min(m_StartPos.x, is[i].Pos.x - ms.EdgeSpaceSize);
		m_StartPos.y = min(m_StartPos.y, is[i].Pos.y - ms.EdgeSpaceSize);
		m_EndPos.x = max(m_EndPos.x, is[i].Pos.x + is[i].Size.x + ms.EdgeSpaceSize + ms.EdgeLineSize);
		m_EndPos.y = max(m_EndPos.y, is[i].Pos.y + is[i].Size.y + ms.EdgeSpaceSize + ms.EdgeLineSize);
		m_pItem[i]->Initialize(is[i]);
	}

	m_EndPos.x = max(m_EndPos.x, ms.Size.x);
	m_EndPos.y = max(m_EndPos.y, ms.Size.y);

	m_RenderTarget.Release();
	if (m_RenderTarget.CreateTarget(g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(),
		PIXELFORMAT_R8G8B8A8_UNORM, BUFFERACCESS_GPUREADWRITE))
	{
		MOF_PRINTLOG("TT");
	}
}

void CMenu::Initialize(MenuStatus ms, std::vector<ItemStatus> is, CMenu* submenu) {
	m_MStatus = ms;
	m_StartPos = CVector2(0, 0);
	m_EndPos = CVector2(0, 0);

	PackPosition(m_MStatus.Type);

	if (m_MStatus.SubMenuCount <= 0 && m_pSubMenu.size() > 0)
	{
		m_pSubMenu.clear();
	}
	if (m_MStatus.SubMenuCount > 0 && submenu)
	{
		m_pSubMenu.clear();
		for (int i = 0; i < m_MStatus.SubMenuCount; i++)
		{
			m_pSubMenu.push_back(&submenu[i]);
			m_StartPos.x = min(m_StartPos.x, m_pSubMenu[i]->GetMenuStatus().Pos.x - ms.EdgeSpaceSize - ms.EdgeLineSize);
			m_StartPos.y = min(m_StartPos.y, m_pSubMenu[i]->GetMenuStatus().Pos.y - ms.EdgeSpaceSize - ms.EdgeLineSize);
			m_EndPos.x = max(m_EndPos.x, m_pSubMenu[i]->GetMenuStatus().Pos.x + m_pSubMenu[i]->GetMenuStatus().Size.x + ms.EdgeSpaceSize + ms.EdgeLineSize);
			m_EndPos.y = max(m_EndPos.y, m_pSubMenu[i]->GetMenuStatus().Pos.y + m_pSubMenu[i]->GetMenuStatus().Size.y + ms.EdgeSpaceSize + ms.EdgeLineSize);
		}
	}

	m_pItem.clear();
	for (int i = 0; i < is.size(); i++)
	{
		m_pItem.push_back(CMenuItemFactory::GetInstance().CreateMenuItem(is[i].ItemType));
		m_StartPos.x = min(m_StartPos.x, is[i].Pos.x - ms.EdgeSpaceSize);
		m_StartPos.y = min(m_StartPos.y, is[i].Pos.y - ms.EdgeSpaceSize);
		m_EndPos.x = max(m_EndPos.x, is[i].Pos.x + is[i].Size.x + ms.EdgeSpaceSize + ms.EdgeLineSize);
		m_EndPos.y = max(m_EndPos.y, is[i].Pos.y + is[i].Size.y + ms.EdgeSpaceSize + ms.EdgeLineSize);
		m_pItem[i]->Initialize(is[i]);
	}

	m_EndPos.x = max(m_EndPos.x, ms.Size.x);
	m_EndPos.y = max(m_EndPos.y, ms.Size.y);

	m_RenderTarget.Release();
	if (m_RenderTarget.CreateTarget(g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(),
		PIXELFORMAT_R8G8B8A8_UNORM, BUFFERACCESS_GPUREADWRITE))
	{
		MOF_PRINTLOG("TT");
	}
}

void CMenu::PackPosition(int type) {
	switch (type)
	{
	case 0:
		// 中央
		m_MStatus.Pos.x = (g_pGraphics->GetTargetWidth() - m_MStatus.Size.x) / 2;
		m_MStatus.Pos.y = (g_pGraphics->GetTargetHeight() - m_MStatus.Size.y) / 2;
		break;
	case 1:
		// 左上
		m_MStatus.Pos.x = m_MStatus.Pos.x;
		m_MStatus.Pos.y = m_MStatus.Pos.y;
		break;
	case 2:
		// 右上
		m_MStatus.Pos.x = g_pGraphics->GetTargetWidth() - m_MStatus.Size.x - m_MStatus.Pos.x;
		m_MStatus.Pos.y = m_MStatus.Pos.y;
		break;
	case 3:
		m_MStatus.Pos.x = m_MStatus.Pos.x;
		m_MStatus.Pos.y = g_pGraphics->GetTargetHeight() - m_MStatus.Size.y - m_MStatus.Pos.y;
		// 左下
		break;
	case 4:
		// 右下
		m_MStatus.Pos.x = g_pGraphics->GetTargetWidth() - m_MStatus.Size.x - m_MStatus.Pos.x;
		m_MStatus.Pos.y = g_pGraphics->GetTargetHeight() - m_MStatus.Size.y - m_MStatus.Pos.y;
		break;
	default:
		break;
	}
}

void CMenu::Update() {
	for (int i = 0; i < m_pSubMenu.size(); i++)
	{
		m_pSubMenu[i]->Update();
	}
	for (int i = 0; i < m_pItem.size(); i++)
	{
		m_pItem[i]->Update(false);
	}
}

void CMenu::SelectButton(int sno) {
	int no = 0;
	for (int i = 0; i < m_pSubMenu.size(); i++)
	{
		no += m_pSubMenu[i]->GetRangeNo();
		if (no > sno)
		{
			m_pSubMenu[i]->SelectButton(no - sno - m_pSubMenu[i]->GetRangeNo());
			return;
		}
	}
	if (sno < no + m_pItem.size())
	{
		m_pItem[sno - no]->Update(true);
	}
}

int CMenu::Collision(CVector2 vec) {
	if (!GetEdgeRect().CollisionPoint(vec))
	{
		return -1;
	}
	if (m_MStatus.bScroll)
	{
		float hoil = g_pInput->GetMouseWheelMove();
		if (hoil != 0)
		{
			m_Scroll.y -= hoil * 0.2f;
		}
		if (m_Scroll.y < m_StartPos.y)
		{
			m_Scroll.y = m_StartPos.y;
		}
		else if (m_Scroll.y > m_EndPos.y - m_MStatus.Size.y)
		{
			m_Scroll.y = m_EndPos.y - m_MStatus.Size.y;
		}
	}
	vec -= m_MStatus.Pos - m_Scroll;
	int no = 0;
	int cnt = 0;

	for (int i = 0; i < m_pSubMenu.size(); i++)
	{
		no = m_pSubMenu[i]->Collision(vec);
		if (no != -1)
		{
			return cnt + no;
		}
		else
		{
			cnt += m_pSubMenu[i]->GetRangeNo();
		}
	}
	for (int i = 0; i < m_pItem.size(); i++)
	{
		if (m_pItem[i]->Collision(vec))
		{
			m_pItem[i]->Update(true);
			return cnt + i;
		}
	}
	return -1;
}

void CMenu::ChangeText(int i, std::string tex) {
	m_pItem[i]->ChangeText(tex);
}

void CMenu::UpdateStatus(ItemStatus* is, int itemcnt, int startno, CMenu* submenu) {
	if (submenu != NULL)
	{
		for (int i = 0; i < m_MStatus.SubMenuCount; i++)
		{
			m_pSubMenu[i] = &submenu[i];
		}
	}
	for (int i = startno; i < itemcnt; i++)
	{
		m_pItem[i]->Initialize(is[i]);
	}
}

void CMenu::UpdateStatus(std::vector<ItemStatus> is, int startno, CMenu* submenu) {
	if (submenu != NULL)
	{
		for (int i = 0; i < m_MStatus.SubMenuCount; i++)
		{
			m_pSubMenu[i] = &submenu[i];
		}
	}
	for (int i = startno; i < is.size(); i++)
	{
		m_pItem[i]->Initialize(is[i]);
	}
}

// 構造を後で治す
void CMenu::Render() {
	MakeRender();
	RenderMakedRect();
	RenderGraphic();
}

void CMenu::MakeRender() {
	for (int i = 0; i < m_pSubMenu.size(); i++)
	{
		m_pSubMenu[i]->MakeRender();
	}
	//画像を描画対象にする
	LPRenderTarget old = g_pGraphics->GetRenderTarget();
	LPDepthTarget oldd = g_pGraphics->GetDepthTarget();
	g_pGraphics->SetRenderTarget(m_RenderTarget.GetRenderTarget(), g_pGraphics->GetDepthTarget());
	//画面のクリア
	g_pGraphics->ClearTarget(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0);

	for (int i = 0; i < m_pItem.size(); i++)
	{
		m_pItem[i]->Render(-m_Scroll);
	}
	for (int i = 0; i < m_pSubMenu.size(); i++)
	{
		m_pSubMenu[i]->RenderMakedRect();
		m_pSubMenu[i]->RenderGraphic();
	}
	//描画対象を元に戻す
	g_pGraphics->SetRenderTarget(old, oldd);
}

void CMenu::RenderMakedRect() {
	CGraphicsUtilities::RenderFillRect(GetRect(), m_MStatus.EdgeLineColor);
	CGraphicsUtilities::RenderFillRect(GetEdgeRect(), m_MStatus.SurfaceColor);
}

void CMenu::RenderGraphic() {
	CRectangle rec(m_MStatus.EdgeLineSize, m_MStatus.EdgeLineSize, m_MStatus.Size.x - m_MStatus.EdgeLineSize, m_MStatus.Size.y - m_MStatus.EdgeLineSize);
	m_RenderTarget.Render(m_MStatus.Pos.x + m_MStatus.EdgeLineSize, m_MStatus.Pos.y + m_MStatus.EdgeLineSize, rec);
}

void CMenu::Release() {
	m_RenderTarget.Release();
	for (int i = 0; i < m_pSubMenu.size(); i++)
	{
		m_pSubMenu[i]->Release();
	}
	for (int i = 0; i < m_pItem.size(); i++)
	{
		if (m_pItem[i])
		{
			delete m_pItem[i];
			m_pItem[i] = NULL;
		}
	}
}

int CMenu::GetRangeNo() {
	int cnt = 0;
	for (int i = 0; i < m_pSubMenu.size(); i++)
	{
		cnt += m_pSubMenu[i]->GetRangeNo();
	}
	for (int i = 0; i < m_pItem.size(); i++)
	{
		if (m_pItem[i]->GetStatus().bClick)
		{
			cnt++;
		}
	}
	return cnt;
}

bool CMenu::IsSubMenuNo(int sno, int mno) {
	int no = sno;
	for (int i = 0; i < m_pSubMenu.size(); i++)
	{
		if (mno == i)
		{
			if (0 <= no && no < (int)m_pSubMenu[i]->GetRangeNo())
			{
				return true;
			}
		}
		else
		{
			no -= m_pSubMenu[i]->GetRangeNo();
		}
	}
	return false;
}

int CMenu::ChangeMainMenuNo(const int& sno) {
	int no = sno;
	for (int i = 0; i < m_pSubMenu.size(); i++)
	{
		no -= m_pSubMenu[i]->GetRangeNo();
	}
	if (0 <= no)
	{
		return no;
	}
	return -1;
}

int CMenu::ChangeSubMenuNo(const int& sno, const int& menuno) {
	int no = sno;
	for (int i = 0; i < m_pSubMenu.size(); i++)
	{
		if (i == menuno)
		{
			no = m_pSubMenu[menuno]->ChangeMainMenuNo(no);
			int rno = m_pSubMenu[menuno]->GetRangeNo();
			if (0 <= no && no < rno)
			{
				return no;
			}
		}
		no -= m_pSubMenu[i]->GetRangeNo();
	}
	return -1;
}