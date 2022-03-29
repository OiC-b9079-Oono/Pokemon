#pragma once
#include "Move.h"

class CMoveList
{
private:
	std::vector<CMove> m_MoveArray;
	CMoveList() :
		m_MoveArray() {
		Load();
	}
public:
	static CMoveList& GetInstance()
	{
		static CMoveList obj;
		return obj;
	}
	bool Load();
	CMove GetMove(int move_no) { return m_MoveArray[move_no]; }
};

