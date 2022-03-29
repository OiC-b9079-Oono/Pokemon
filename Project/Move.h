#pragma once
#include "TypeFactory.h"
#include "MoveType.h"
#include "AdditionalEffect.h"
#include <Mof.h>
#include <string>

// ‚í‚´
class CMove
{
private:
	std::string m_Name;
	std::vector<CTypeBase*> m_Type; // ƒ^ƒCƒv
	MoveType m_MoveType;			// ‚í‚´‹æ•ª
	int m_Power;					// ˆÐ—Í
	int m_HitRate;					// –½’†—¦
	int m_PowerPoint;				// PP
	std::vector<AdditionalEffect> m_Effect; // ’Ç‰ÁŒø‰Ê

public:
	CMove();
	~CMove();

	bool Load(std::string name);
};

