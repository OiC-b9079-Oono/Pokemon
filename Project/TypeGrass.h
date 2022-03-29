#pragma once
#include "TypeBase.h"

class CTypeGrass : public CTypeBase
{
public:
	float GetCompatibility(TypeNo attack_type) {
		switch (attack_type)
		{
		case TYPE2_FIRE:
			return 2.0f;
		case TYPE3_WATER:
			return 0.5f;
		case TYPE4_GRASS:
			return 0.5f;
		case TYPE5_ELECTRIC:
			return 0.5f;
		case TYPE6_ICE:
			return 2.0f;
		case TYPE8_POISON:
			return 2.0f;
		case TYPE9_GROUND:
			return 0.5f;
		case TYPE10_FLYING:
			return 2.0f;
		case TYPE12_BUG:
			return 2.0f;
		default:
			break;
		}
		return 1.0f;
	}

	TypeNo GetTypeNo() {
		return TypeNo::TYPE4_GRASS;
	}
};

