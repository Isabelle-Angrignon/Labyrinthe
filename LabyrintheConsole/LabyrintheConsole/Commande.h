#pragma once
#include <Windows.h>
class CCommande
{
public:
	 
	CCommande(int vkKey) :m_Key{ vkKey }{}
	bool operator==(const CCommande &c) const { return GetKey() == c.GetKey(); }
	bool operator!=(const CCommande &c) const{ return !CCommande::operator==(c); }
	int GetKey()const { return m_Key; }
	CCommande() :m_Key{ VK_ESCAPE }{}
	~CCommande() = default;

private:
	int m_Key;
};

