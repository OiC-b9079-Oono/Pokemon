#include "Label.h"

CLabel::CLabel() {
	m_Status.bClick = false;
}

CLabel::~CLabel() {

}

void CLabel::Render(const CVector2& pos) {
	if (m_Status.SurfaceColor != 0)
		CGraphicsUtilities::RenderFillRect(GetRect(), m_Status.SurfaceColor);
	if (m_Status.EdgeColor != 0)
		CGraphicsUtilities::RenderRect(GetRect(), m_Status.EdgeColor);

	CRectangle trec;
	CGraphicsUtilities::CalculateStringRect(0, 0, m_Status.Text.c_str(), trec);

	float x = 0;
	float y = m_Status.Pos.y + m_Status.Size.y / 2 - trec.GetHeight() / 2;

	switch (m_Status.Justified)
	{
	case 0:
		x = m_Status.Pos.x + m_Status.Size.x / 2 - trec.GetWidth() / 2;
		break;
	case 1:
		x = m_Status.Pos.x;
		break;
	case 2:
		x = m_Status.Pos.x + m_Status.Size.x - trec.GetWidth();
		break;
	default:
		break;
	}

	CGraphicsUtilities::RenderString(x, y, m_Status.TextColor, m_Status.Text.c_str());
}