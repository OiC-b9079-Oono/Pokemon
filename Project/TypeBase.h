#pragma once
#include "TypeNo.h"

class CTypeBase
{
public:
	// �U�����Ă����^�C�v�ɉ������{����ԋp
	virtual float GetCompatibility(TypeNo attack_type) {
		return 1.0f;
	}

	// �����̃^�C�v��ԋp
	virtual TypeNo GetTypeNo() {
		return TypeNo::TYPE1_NORMAL;
	}
};

