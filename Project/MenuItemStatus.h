#pragma once
#include <Mof.h>
#include "ItemType.h"

typedef struct tag_ItemStatus {
	ItemType		ItemType;
	CVector2		Pos;
	CVector2		Size;
	std::string		Text;
	int				Justified;
	bool			bClick;
	float			EdgeSize;

	MofU32			TextColor;
	MofU32			SurfaceColor;
	MofU32			EdgeColor;
	MofU32			SelectTextColor;
	MofU32			SelectSurfaceColor;
	MofU32			SelectEdgeColor;
	MofU32			NoClickTextColor;
	MofU32			NoClickSurfaceColor;
	MofU32			NoClickEdgeColor;

	tag_ItemStatus() :
		ItemType(ItemType::ITEMTYPE_LABEL),
		Pos(0, 0),
		Size(0, 0),
		Text(""),
		Justified(0),
		bClick(true),
		EdgeSize(0),
		TextColor(MOF_ARGB(255, 255, 255, 255)),
		SurfaceColor(MOF_ARGB(0, 0, 0, 0)),
		EdgeColor(MOF_ARGB(0, 255, 255, 255)),
		SelectTextColor(MOF_ARGB(255, 255, 255, 255)),
		SelectSurfaceColor(MOF_ARGB(255, 0, 0, 0)),
		SelectEdgeColor(MOF_ARGB(255, 255, 50, 50)),
		NoClickTextColor(MOF_ARGB(255, 200, 200, 200)),
		NoClickSurfaceColor(MOF_ARGB(255, 0, 0, 0)),
		NoClickEdgeColor(MOF_ARGB(255, 200, 200, 200)) {
	}
}ItemStatus;