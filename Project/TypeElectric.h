#pragma once
#include "TypeBase.h"

class CTypeElectric : public CTypeBase
{
public:
	float GetCompatibility(TypeNo attack_type) {
		switch (attack_type)
		{
		case TYPE5_ELECTRIC:
			return 0.5f;
		case TYPE9_GROUND:
			return 2.0f;
		case TYPE10_FLYING:
			return 0.5f;
		case TYPE17_STEEL:
			return 0.5f;
		default:
			break;
		}
		return 1.0f;
	}

	TypeNo GetTypeNo() {
		return TypeNo::TYPE5_ELECTRIC;
	}
};

