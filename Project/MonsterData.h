#pragma once
#include "Status.h"
#include "TypeFactory.h"
#include "MoveList.h"
#include <Mof.h>

class CMonsterData
{
private:
	int		m_No;					// �}��No �摜�̎擾�Ɏg�p
	std::string	m_RaceName;			// �푰��
	Status m_BaseStatus;			// �푰�l
	std::vector<CTypeBase*> m_Type;
	std::vector<CMove>	m_RememberMove; // �o������킴

public:
	CMonsterData();
	bool Load(std::string name);
	void Release();


	int GetNo() { return m_No; }
	std::string GetName() { return m_RaceName; }
	Status GetStatus() { return m_BaseStatus; }
};

