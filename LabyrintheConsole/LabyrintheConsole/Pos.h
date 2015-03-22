#pragma once
class Pos
{
public:
	int x, y;
	
	Pos() throw() : x{ }, y{ } {  }
	Pos(const int _x, const int _y) throw() : x{ _x }, y{ _y } {  }
	~Pos() = default; 
	
	bool operator==(const Pos &p) const throw()
	{
		return x == p.x && y == p.y;
	}
	bool operator!=(const Pos &p) const throw()
	{
		return !(*this == p);
	}
};
