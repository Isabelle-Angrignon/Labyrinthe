#pragma once

#include <functional>

typedef std::function<void ()> ACTION_EVENEMENT;
typedef std::pair<int, ACTION_EVENEMENT > INFO_EVENEMENT;


class CEvenement
{
private:
		
	int m_Delais;
	ACTION_EVENEMENT m_Action;

public:
	CEvenement(int d, ACTION_EVENEMENT a)
		:m_Delais(d), m_Action(a)  { }

	CEvenement() = delete;
	~CEvenement() = default;

	const int  GetDelais() { return m_Delais; };
	const ACTION_EVENEMENT  GetAction() { return m_Action; };
};

