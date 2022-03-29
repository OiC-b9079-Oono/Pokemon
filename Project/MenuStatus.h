#pragma once
#include <Mof.h>

typedef struct tag_MenuStatus {
	int			Type;
	CVector2	Pos;
	CVector2	Size;
	bool		bScroll;
	bool		bSelectVertical;
	int			SubMenuCount;
	int			EdgeLineSize;
	int			EdgeSpaceSize;
	MofU32			SurfaceColor;
	MofU32			EdgeLineColor;

	tag_MenuStatus() {
		Type = 0;
		Pos = CVector2(0, 0);
		Size = CVector2(0, 0);
		SubMenuCount = 0;
		bScroll = true;
		bSelectVertical = true;
		EdgeLineSize = 3;
		EdgeSpaceSize = 3;
		SurfaceColor = MOF_ARGB(255, 30, 30, 30);
		EdgeLineColor = MOF_ARGB(255, 50, 50, 200);
	}
}MenuStatus;