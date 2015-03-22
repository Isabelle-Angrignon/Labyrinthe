#include "Partie.h"
#include "Pos.h"

CPartie::CPartie(std::string filePath) :m_Lab(filePath)
{
	m_Personnage = new CPersonnage(m_Lab.GetDebut(),&m_Lab);
}
void CPartie::JouerUnePartie()
{
	afficher();
	
}

void CPartie::afficher()
{
	using namespace std;
	vector<pair<Pos, CLabyrinthe::disponibiliteCase>> CaseVisible = m_Lab.LireCasesVisibles(m_Personnage->GetPosition(), m_Personnage->GetVision());
	int ParcourirCaseVisible = 0;
	for (int i = 0; i < 120; ++i)
		cout << endl;
	for (int i = 0; i < m_Lab.GetHauteur(); ++i)
	{
		for (int j = 0; j < m_Lab.GetLargeur(); ++j)
		{
			if (i == CaseVisible[ParcourirCaseVisible].first.x && j == CaseVisible[ParcourirCaseVisible].first.y)
			{
				if (m_Personnage->GetPosition().x == i && m_Personnage->GetPosition().y)
					std::cout << m_Personnage->m_avatar;
				else
					std::cout << CaseVisible[ParcourirCaseVisible].second;
				if (ParcourirCaseVisible + 1 < CaseVisible.size())
					++ParcourirCaseVisible;
			}
			else
				std::cout << ' ';
		}
		cout << endl;
	}
}

CPartie::~CPartie()
{
}

int CPartie::LireTouche()
{
	// -32767 == touche appuyé ! 
	while (true)
	{
		short VirtualKey;
		VirtualKey = GetAsyncKeyState(VK_UP);
		if (VirtualKey == -32767) return VK_UP;
		VirtualKey = GetAsyncKeyState(VK_RIGHT);
		if (VirtualKey == -32767) return VK_RIGHT;
		VirtualKey = GetAsyncKeyState(VK_DOWN);
		if (VirtualKey == -32767) return VK_DOWN;
		VirtualKey = GetAsyncKeyState(VK_LEFT);
		if (VirtualKey == -32767) return VK_LEFT;
		VirtualKey = GetAsyncKeyState(VK_ESCAPE);
		if (VirtualKey == -32767) return VK_ESCAPE;
		Sleep(10);
	}
}