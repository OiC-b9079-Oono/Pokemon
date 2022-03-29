#pragma once
#include "TypeBase.h"

class CTypeFlying : public CTypeBase
{
public:
	float GetCompatibility(TypeNo attack_type) {
		switch (attack_type)
		{
		case TYPE4_GRASS:
			return 0.5f;
		case TYPE5_ELECTRIC:
			return 2.0f;
		case TYPE6_ICE:
			return 2.0f;
		case TYPE7_FIGHTING:
			return 0.5f;
		case TYPE9_GROUND:
			return 0.0f;
		case TYPE12_BUG:
			return 0.5f;
		case TYPE13_ROCK:
			return 2.0f;
		default:
			break;
		}
		return 1.0f;
	}

	TypeNo GetTypeNo() {
		return TypeNo::TYPE10_FLYING;
	}
};

