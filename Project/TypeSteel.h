#pragma once
#include "TypeBase.h"

class CTypeSteel : public CTypeBase
{
public:
	float GetCompatibility(TypeNo attack_type) {
		switch (attack_type)
		{
		case TYPE1_NORMAL:
			return 0.5f;
		case TYPE2_FIRE:
			return 2.0f;
		case TYPE4_GRASS:
			return 0.5f;
		case TYPE6_ICE:
			return 0.5f;
		case TYPE7_FIGHTING:
			return 2.0f;
		case TYPE8_POISON:
			return 0.0f;
		case TYPE9_GROUND:
			return 2.0f;
		case TYPE10_FLYING:
			return 0.5f;
		case TYPE11_PSYCHIC:
			return 0.5f;
		case TYPE12_BUG:
			return 0.5f;
		case TYPE13_ROCK:
			return 0.5f;
		case TYPE15_DRAGON:
			return 0.5f;
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
		return TypeNo::TYPE17_STEEL;
	}
};