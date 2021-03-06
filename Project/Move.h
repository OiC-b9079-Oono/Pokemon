#pragma once
#include "TypeFactory.h"
#include "MoveType.h"
#include "AdditionalEffect.h"
#include <Mof.h>
#include <string>

// わざ
class CMove
{
private:
	std::string m_Name;
	std::vector<CTypeBase*> m_Type; // タイプ
	MoveType m_MoveType;			// わざ区分
	int m_Power;					// 威力
	int m_HitRate;					// 命中率
	int m_PowerPoint;				// PP
	std::vector<AdditionalEffect> m_Effect; // 追加効果

public:
	CMove();
	~CMove();

	bool Load(std::string name);
};

