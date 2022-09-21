#pragma once
#include "iostream"
using namespace std;
using namespace System;
class CCuadrado
{
private:
	int x, y;
	int dx, dy;
	int tipo;
	int relleno;
	int lado;
public:
	//constructor
	CCuadrado();
	CCuadrado(int px, int py, int pdx, int pdy, int ptipo, int plado);
	//acciones o metodos propios
	void Dibujar();
	void Mover();
	void Borrar();
	//metodos de acceso
	void SetDX(int pdx);
	void SetDY(int pdy);
	void SetRelleno(int prelleno);
	int getDx();
	int getDy();
	int getRelleno();
};
//constructor
CCuadrado::CCuadrado(){}
CCuadrado::CCuadrado(int px, int py, int pdx, int pdy, int ptipo, int plado)
{
	x = px; y = py;
	dx = pdx; dy = pdy;
	tipo = ptipo;
	relleno = 1; lado = plado;
}
//acciones o metodos propios
void CCuadrado::Dibujar()
{
	if (tipo == 1)
		Console::ForegroundColor = ConsoleColor::Green;
	else
		Console::ForegroundColor = ConsoleColor::Yellow;
	if (relleno == 1) //prendido
	{
		int px = x, py = y;
		for (int i = 1; i <= lado; i++)
		{
			Console::SetCursorPosition(px, py);
			for (int j = 1; j <= lado; j++)
				cout << "*";
			py++;
		}
	}
	else//apagado relleno 0
	{
		for (int i = 1; i <= lado; i++)
		{
			int px = x, py = y;
			Console::SetCursorPosition(px, py);
			for (int j = 1; j <= lado; j++)
				if (i == 1 || i == lado || j == 1 || j == lado)
					cout << "*";
				else
					cout << " ";
			py++;
		}
	}
}
void CCuadrado::Mover()
{
	if (x + dx < 0 || x + dx + lado >70) dx =dx *-1;
	if (y + dy <= 0 || y + dy + lado >18) dy = dy * -1;
	x += dx; y += dy;
}
void CCuadrado::Borrar()
{
	int px = x, py = y;
	for (int i = 1; i <= lado; i++)
	{
		Console::SetCursorPosition(px, py);
		for (int j = 1; j <= lado; j++)
			cout << " ";
		py++;
	}
}
//metodos de acceso
void CCuadrado::SetDX(int pdx) { dx = pdx; }
void CCuadrado::SetDY(int pdy) { dy = pdy; }
void CCuadrado::SetRelleno(int prelleno) { relleno = prelleno; }
int CCuadrado::getDx() { return dx; }
int CCuadrado::getDy() { return dy; }
int CCuadrado::getRelleno() { return relleno;}