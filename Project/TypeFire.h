#pragma once
#include "TypeBase.h"

class CTypeFire : public CTypeBase
{
public:
	float GetCompatibility(TypeNo attack_type) {
		switch (attack_type)
		{
		case TYPE2_FIRE:
			return 0.5f;
		case TYPE3_WATER:
			return 2.0f;
		case TYPE4_GRASS:
			return 0.5f;
		case TYPE6_ICE:
			return 0.5f;
		case TYPE9_GROUND:
			return 2.0f;
		case TYPE12_BUG:
			return 0.5f;
		case TYPE13_ROCK:
			return 2.0f;
		case TYPE17_STEEL:
			return 0.5f;
		case TYPE18_FAIRY:
			return 0.5f;
		default:
			break;
		}
		return 1.0f;
	}

	TypeNo GetTypeNo() {
		return TypeNo::TYPE2_FIRE;
	}
};
