#pragma once
#include "CFigura.h"
#include <iostream>
using namespace std;
using namespace System;
class CCuadrado :public CFigura
{
private:
	int tipo;  // 1 seran verde verticales
			   // 2 amarillos horizontales
	int relleno;
public:
	//constructura o destructor
	CCuadrado();
	CCuadrado(int _x, int _y, int _dx, int _dy, int _tipo, int _lado);
	//acciones o metodos propios
	void Dibujar();
	void CambiaRelleno();
};
CCuadrado::CCuadrado() {};
CCuadrado::CCuadrado(int _x, int _y, int _dx, int _dy, int _tipo, int _lado) :CFigura(_x, _y, _dx, _dy, _lado)
{
	tipo = _tipo;
	relleno = 1;
	forma = 1;
}
void CCuadrado::Dibujar()
{
	if (tipo == 1)
		Console::ForegroundColor = ConsoleColor::Green;
	else
		Console::ForegroundColor = ConsoleColor::Yellow;
	if (relleno == 1) //prendido
	{
		int _x = x, _y = y;
		for (int fila = 1; fila <= lado; fila++)
		{
			Console::SetCursorPosition(_x, _y);
			for (int col = 1; col <= lado; col++)
				cout << '*';
			_y++;
		}
	}
	else //apagado relleno 0
	{
		int _x = x, _y = y;
		for (int fila = 1; fila <= lado; fila++)
		{
			Console::SetCursorPosition(_x, _y);
			for (int col = 1; col <= lado; col++)
				if (fila == 1 || fila == lado || col == 1 || col == lado)
					cout << '*';
				else cout << ' ';
			_y++;
		}
	}
}
void CCuadrado::CambiaRelleno()
{
	if (relleno == 1) relleno = 0;
	else relleno = 1;
}