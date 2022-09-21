#pragma once
#include "CFigura.h"
class CCuadrado: public CFigura
{
private:
	int tipo;
	int relleno;
public:
	//constructor
	CCuadrado();
	CCuadrado(int px, int py, int pdx, int pdy, int ptipo, int plado);
	//acciones o metodos propios
	void Dibujar();
	//metodos de acceso
	void cambiaDx();
	void cambiaDy();
	void cambiaRelleno();

};
//constructor
CCuadrado::CCuadrado(){}
CCuadrado::CCuadrado(int px, int py, int pdx, int pdy, int ptipo, int plado):CFigura(px,py,pdx,pdy,plado)
{
	tipo = ptipo;
	relleno = 1; 
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
				if (i == 1 || i == lado || j == 1 || j == lado) { cout << "*"; }
				else { cout << " "; }
			py++;
		}
	}
}
//metodos de acceso
void CCuadrado::cambiaDx() 
{ 
	dx = dx * -1;
}
void CCuadrado::cambiaDy()
{ 
	dy = dy * -1;
}
void CCuadrado::cambiaRelleno()
{ 
	if (relleno == 1)relleno = 0;
	else relleno = 1;
}
