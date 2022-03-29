#include "Button.h"

CButton::CButton() {
}

CButton::~CButton() {

}

bool CButton::Collision(const CVector2& pos) {
	return (m_Status.bClick) ? GetRect().CollisionPoint(pos) : false;
}

void CButton::Render(const CVector2& pos) {
	if (m_Status.bClick)
	{
		if (m_bSelect)
		{
			CGraphicsUtilities::RenderFillRect(GetRect(pos), m_Status.SelectEdgeColor);
			CGraphicsUtilities::RenderFillRect(GetEdgeRect(pos), m_Status.SelectSurfaceColor);
		}
		else
		{
			CGraphicsUtilities::RenderFillRect(GetRect(pos), m_Status.EdgeColor);
			CGraphicsUtilities::RenderFillRect(GetEdgeRect(pos), m_Status.SurfaceColor);
		}
	}
	else
	{
		CGraphicsUtilities::RenderFillRect(GetRect(pos), m_Status.NoClickEdgeColor);
		CGraphicsUtilities::RenderFillRect(GetEdgeRect(pos), m_Status.NoClickSurfaceColor);
	}

	CRectangle trec;
	CGraphicsUtilities::CalculateStringRect(0, 0, m_Status.Text.c_str(), trec);

	float x = (m_Status.Pos.x + m_Status.Size.x / 2) - trec.GetWidth() / 2;
	float y = (m_Status.Pos.y + m_Status.Size.y / 2) - trec.GetHeight() / 2;

	CGraphicsUtilities::RenderString(x + pos.x, y + pos.y, (m_Status.bClick) ? m_Status.TextColor : m_Status.NoClickTextColor, m_Status.Text.c_str());
}