#pragma once
#include "Item.h"


class CContenuCase
{
	char m_carac;
	CItem * m_pItem;

public:
	static enum e_CaractereAAfficher{ MUR_A = '#', LIBRE_A = '.', ENTRE_A = 'A', SORTIE_A = 'S', ITEM_A = 'I' };
	CContenuCase(e_CaractereAAfficher c) :m_carac(c){}
	CContenuCase(CItem * pItem) :m_pItem(pItem), m_carac(ITEM_A) {}
	void SetContenueCase(CItem *pItem){ m_carac = ITEM_A; m_pItem = pItem; }
	friend std::ostream& operator<<(std::ostream &os, const CContenuCase& c){ return os << c.GetCarac(); }

	CItem * GetItem() const{ return m_pItem; }

	bool operator==(const CContenuCase& c) const { return m_carac == c.GetCarac(); }
	bool operator!=(const CContenuCase& c) const { return !(*this == c); }
	
	
	CContenuCase& operator=(const CContenuCase& c);
	void Swap(CContenuCase& c);
	CContenuCase(const CContenuCase& c);

	char GetCarac() const{ return m_carac; }
	CContenuCase() :m_carac(MUR_A), m_pItem(nullptr) {};	
	~CContenuCase(){ if (m_pItem)delete m_pItem; };
};
