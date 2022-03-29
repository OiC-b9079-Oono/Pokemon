#pragma once
#include "TypeBase.h"

class CTypeGround : public CTypeBase
{
public:
	float GetCompatibility(TypeNo attack_type) {
		switch (attack_type)
		{
		case TYPE3_WATER:
			return 2.0f;
		case TYPE4_GRASS:
			return 2.0f;
		case TYPE5_ELECTRIC:
			return 0.0f;
		case TYPE6_ICE:
			return 2.0f;
		case TYPE8_POISON:
			return 0.5f;
		case TYPE13_ROCK:
			return 0.5f;
		default:
			break;
		}
		return 1.0f;
	}

	TypeNo GetTypeNo() {
		return TypeNo::TYPE9_GROUND;
	}
};

