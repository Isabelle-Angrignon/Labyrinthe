#include "Evenements.h"
#include <algorithm>

void CEvenements::AjouterEvenement(int delais, ACTION_EVENEMENT action)
{	
	m_Evenements.push_back(CEvenement(delais+m_Temps, action));
}

void CEvenements::ExecuterEvenements()
{	
	auto i = std::find_if(m_Evenements.begin(), m_Evenements.end(), [&](CEvenement e){return e.GetDelais() == m_Temps; });
	
	while ((i != m_Evenements.end()))
	{
		i->GetAction()();
		m_Evenements.erase(i);	
		i = std::find_if(m_Evenements.begin(), m_Evenements.end(), [&](CEvenement e){return e.GetDelais() == m_Temps; });
	}

	++m_Temps;
}
  