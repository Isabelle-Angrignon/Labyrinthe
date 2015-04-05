#pragma once

class CPos
{
public:
	int x, y;
	
	CPos() throw() : x{ }, y{ } {  }
	CPos(const int _x, const int _y) throw() : x{ _x }, y{ _y } {  }
	~CPos() = default; 
	
	bool operator==(const CPos &p) const throw()
	{
		return x == p.x && y == p.y;
	}
	bool operator!=(const CPos &p) const throw()
	{
		return !(*this == p);
	}
	bool operator<(const CPos &p) const throw()
	{
		bool plusPetit = false;
		if (y < p.y)
			plusPetit = true;
		else if (y == p.y)
		{
			if (x < p.x)
				plusPetit = true;
		}
		return plusPetit;
	}
};
