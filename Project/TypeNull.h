#pragma once
#include "TypeBase.h"

class CTypeNull : public CTypeBase
{
public:
	TypeNo GetTypeNo() {
		return TypeNo::TYPE1_NORMAL;
	}
};

