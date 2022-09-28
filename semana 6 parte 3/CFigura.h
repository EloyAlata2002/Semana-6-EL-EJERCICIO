#pragma once
#include <iostream>
using namespace std;
using namespace System;
class CFigura
{
protected:
	int x, y, dx, dy, lado;
public:
	CFigura();
	CFigura(int _x, int _y, int _dx, int _dy, int _lado);
	void Mover();
	void Borrar();
	virtual void Dibujar() {};
	virtual void CambiaDx() {};
	virtual void CambiaDy() {};
	virtual void CambiaRelleno() {};
};
CFigura::CFigura() {}
CFigura::CFigura(int _x, int _y, int _dx, int _dy, int _lado)
{
	x = _x; y = _y; dx = _dx; dy = _dy; lado = _lado;
}
void CFigura::Mover()
{
	if (x + dx < 0 || x + dx + lado > 79)dx = dx * -1;
	x += dx;
	if (y + dy < 0 || y + dy + lado > 24)dy = dy * -1;
	y += dy;
}
void CFigura::Borrar()
{
	int _x = x, _y = y;
	for (int i = 1; i <= lado; i++)
	{
		Console::SetCursorPosition(_x, _y);
		for (int j = 1; j <= lado; j++)
			cout << ' ';
		_y++;
	}
}