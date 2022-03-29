#pragma once
#include "TypeBase.h"

class CTypePoison : public CTypeBase
{
public:
	float GetCompatibility(TypeNo attack_type) {
		switch (attack_type)
		{
		case TYPE4_GRASS:
			return 0.5f;
		case TYPE7_FIGHTING:
			return 0.5f;
		case TYPE8_POISON:
			return 0.5f;
		case TYPE9_GROUND:
			return 2.0f;
		case TYPE11_PSYCHIC:
			return 2.0f;
		case TYPE12_BUG:
			return 0.5f;
		case TYPE18_FAIRY:
			return 0.5f;
		default:
			break;
		}
		return 1.0f;
	}

	TypeNo GetTypeNo() {
		return TypeNo::TYPE8_POISON;
	}
};

