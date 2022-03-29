#pragma once
#include "TypeBase.h"

class CTypeIce : public CTypeBase
{
public:
	float GetCompatibility(TypeNo attack_type) {
		switch (attack_type)
		{
		case TYPE2_FIRE:
			return 2.0f;
		case TYPE6_ICE:
			return 0.5f;
		case TYPE7_FIGHTING:
			return 2.0f;
		case TYPE13_ROCK:
			return 2.0f;
		case TYPE17_STEEL:
			return 2.0f;
		default:
			break;
		}
		return 1.0f;
	}

	TypeNo GetTypeNo() {
		return TypeNo::TYPE6_ICE;
	}
};

