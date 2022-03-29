#pragma once
#include "TypeNo.h"

class CTypeBase
{
public:
	// 攻撃してきたタイプに応じた倍率を返却
	virtual float GetCompatibility(TypeNo attack_type) {
		return 1.0f;
	}

	// 自分のタイプを返却
	virtual TypeNo GetTypeNo() {
		return TypeNo::TYPE1_NORMAL;
	}
};

