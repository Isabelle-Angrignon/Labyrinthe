#pragma once
#include <Windows.h>
class Commande
{
public:
	// Constructeur 
	Commande(int vkKey) :m_Key{ vkKey }{}
	bool operator==(const Commande &c){ return GetKey() == c.GetKey(); }
	bool operator!=(const Commande &c){ return !Commande::operator==(c); }
	int GetKey()const { return m_Key; }
	~Commande() = default;
private:
	Commande() = delete;
	int m_Key;
};

