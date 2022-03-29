#pragma once
#include "TypeBase.h"

class CTypeRock : public CTypeBase
{
public:
	float GetCompatibility(TypeNo attack_type) {
		switch (attack_type)
		{
		case TYPE1_NORMAL:
			return 0.5f;
		case TYPE2_FIRE:
			return 0.5f;
		case TYPE3_WATER:
			return 2.0f;
		case TYPE4_GRASS:
			return 2.0f;
		case TYPE7_FIGHTING:
			return 2.0f;
		case TYPE8_POISON:
			return 0.5f;
		case TYPE9_GROUND:
			return 2.0f;
		case TYPE10_FLYING:
			return 0.5f;
		case TYPE17_STEEL:
			return 2.0f;
		default:
			break;
		}
		return 1.0f;
	}

	TypeNo GetTypeNo() {
		return TypeNo::TYPE13_ROCK;
	}
};