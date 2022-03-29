#pragma once
#include "TypeBase.h"

class CTypeWater : public CTypeBase
{
public:
	float GetCompatibility(TypeNo attack_type) {
		switch (attack_type)
		{
		case TYPE2_FIRE:
			return 0.5f;
		case TYPE3_WATER:
			return 0.5f;
		case TYPE4_GRASS:
			return 2.0f;
		case TYPE5_ELECTRIC:
			return 2.0f;
		case TYPE6_ICE:
			return 0.5f;
		case TYPE17_STEEL:
			return 0.5f;
		default:
			break;
		}
		return 1.0f;
	}

	TypeNo GetTypeNo() {
		return TypeNo::TYPE3_WATER;
	}
};
