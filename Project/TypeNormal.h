#pragma once
#include "TypeBase.h"

class CTypeNormal : public CTypeBase
{
public:
	float GetCompatibility(TypeNo attack_type) {
		switch (attack_type)
		{
		case TYPE10_FLYING:
			return 2.0f;
		case TYPE14_GHOST:
			return 0.0f;
		default:
			break;
		}
		return 1.0f;
	}

	TypeNo GetTypeNo() {
		return TypeNo::TYPE1_NORMAL;
	}
};

