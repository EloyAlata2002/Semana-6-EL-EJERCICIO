#pragma once
#include "CFigura.h"
class CTriangulo : public CFigura
{
private:
	char car;
public:
	//constructor
	CTriangulo();
	CTriangulo(int px, int py, int pdx, int pdy,int plado,int pcar);
	//acciones o metodos propios
	void Dibujar();
};
//constructor
CTriangulo::CTriangulo() {}
CTriangulo::CTriangulo(int px, int py, int pdx, int pdy, int plado,int pcar) :CFigura(px, py, pdx, pdy, plado)
{
	car = pcar;
}
//acciones o metodos propios
void CTriangulo::Dibujar()
{
		int px = x, py = y;
		Console::ForegroundColor=ConsoleColor::Red;
		for (int i = 1; i <= lado; i++)
		{
			Console::SetCursorPosition(px, py);
			for (int j = 1; j <= i; j++)
				cout << car;
			py++;
		}
}
