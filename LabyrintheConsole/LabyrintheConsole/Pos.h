#pragma once
struct Pos
{
	int x, y;
	Pos(int _x, int _y) : x{ _x }, y{ _y }{}
	Pos() : x{}, y{}{}
};