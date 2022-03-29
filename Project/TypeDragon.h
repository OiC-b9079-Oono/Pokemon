#pragma once
#include "TypeBase.h"

class CTypeDragon : public CTypeBase
{
public:
	float GetCompatibility(TypeNo attack_type) {
		switch (attack_type)
		{
		case TYPE2_FIRE:
			return 0.5f;
		case TYPE3_WATER:
			return 0.5f;
		case TYPE4_GRASS:
			return 0.5f;
		case TYPE5_ELECTRIC:
			return 0.5f;
		case TYPE6_ICE:
			return 2.0f;
		case TYPE15_DRAGON:
			return 2.0f;
		case TYPE18_FAIRY:
			return 2.0f;
		default:
			break;
		}
		return 1.0f;
	}

	TypeNo GetTypeNo() {
		return TypeNo::TYPE15_DRAGON;
	}
};

