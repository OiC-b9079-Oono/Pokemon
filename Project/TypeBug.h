#pragma once
#include "TypeBase.h"

class CTypeBug : public CTypeBase
{
public:
	float GetCompatibility(TypeNo attack_type) {
		switch (attack_type)
		{
		case TYPE2_FIRE:
			return 2.0f;
		case TYPE4_GRASS:
			return 0.5f;
		case TYPE7_FIGHTING:
			return 0.5f;
		case TYPE9_GROUND:
			return 0.5f;
		case TYPE10_FLYING:
			return 2.0f;
		case TYPE13_ROCK:
			return 2.0f;
		default:
			break;
		}
		return 1.0f;
	}

	TypeNo GetTypeNo() {
		return TypeNo::TYPE12_BUG;
	}
};

