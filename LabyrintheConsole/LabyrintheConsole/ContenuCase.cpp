#include "ContenuCase.h"


CContenuCase::CContenuCase(const CContenuCase& c)
{
	m_carac = c.GetCarac();
	if (c.GetItem())
		m_pItem = new CItem(*c.GetItem());
	else
		m_pItem = nullptr;
}

void CContenuCase::Swap(CContenuCase& c)
{
	using std::swap;
	swap(m_carac, c.m_carac);
	swap(m_pItem, c.m_pItem);
}

CContenuCase& CContenuCase::operator=(const CContenuCase& c)
{
	CContenuCase{ c }.Swap(*this);
	return *this;
}
