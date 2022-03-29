#pragma once
#include "TypeBase.h"

class TypeFairy : public CTypeBase
{
public:
	float GetCompatibility(TypeNo attack_type) {
		switch (attack_type)
		{
		case TYPE7_FIGHTING:
			return 0.5f;
		case TYPE8_POISON:
			return 2.0f;
		case TYPE12_BUG:
			return 0.5f;
		case TYPE15_DRAGON:
			return 0.0f;
		case TYPE16_DARK:
			return 0.5f;
		case TYPE17_STEEL:
			return 2.0f;
		default:
			break;
		}
		return 1.0f;
	}

	TypeNo GetTypeNo() {
		return TypeNo::TYPE18_FAIRY;
	}
};