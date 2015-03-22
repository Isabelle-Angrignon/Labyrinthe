#pragma once
#include <Windows.h>
class Commande
{
public:
	// Constructeur 
	Commande(int vkKey) :m_Key{ vkKey }{}
	bool operator==(const Commande &c) const { return GetKey() == c.GetKey(); }
	bool operator!=(const Commande &c) const{ return !Commande::operator==(c); }
	int GetKey()const { return m_Key; }
	Commande() :m_Key{ VK_ESCAPE }{}
	~Commande() = default;
private:
	int m_Key;
};

