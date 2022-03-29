#pragma once
#include "TypeBase.h"

class CTypeDark : public CTypeBase
{
public:
	float GetCompatibility(TypeNo attack_type) {
		switch (attack_type)
		{
		case TYPE7_FIGHTING:
			return 2.0f;
		case TYPE11_PSYCHIC:
			return 0.0f;
		case TYPE12_BUG:
			return 2.0f;
		case TYPE14_GHOST:
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
		return TypeNo::TYPE16_DARK;
	}
};

