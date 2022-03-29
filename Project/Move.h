#pragma once
#include "TypeFactory.h"
#include "MoveType.h"
#include "AdditionalEffect.h"
#include <Mof.h>
#include <string>

// �킴
class CMove
{
private:
	std::string m_Name;
	std::vector<CTypeBase*> m_Type; // �^�C�v
	MoveType m_MoveType;			// �킴�敪
	int m_Power;					// �З�
	int m_HitRate;					// ������
	int m_PowerPoint;				// PP
	std::vector<AdditionalEffect> m_Effect; // �ǉ�����

public:
	CMove();
	~CMove();

	bool Load(std::string name);
};

