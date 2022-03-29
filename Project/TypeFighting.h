#pragma once
#include "TypeBase.h"

class CTypeFighting : public CTypeBase
{
public:
	float GetCompatibility(TypeNo attack_type) {
		switch (attack_type)
		{
		case TYPE10_FLYING:
			return 2.0f;
		case TYPE11_PSYCHIC:
			return 2.0f;
		case TYPE12_BUG:
			return 0.5f;
		case TYPE13_ROCK:
			return 0.5f;
		case TYPE16_DARK:
			return 0.5f;
		case TYPE18_FAIRY:
			return 2.0f;
		default:
			break;
		}
		return 1.0f;
	}

	TypeNo GetTypeNo() {
		return TypeNo::TYPE7_FIGHTING;
	}
};

