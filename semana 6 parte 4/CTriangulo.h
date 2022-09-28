#pragma once
#include "CFigura.h"
#include <iostream>
using namespace std;
using namespace System;
class CTriangulo :public CFigura
{
private:
	char car; // caracter para pintar el  triangulo
public:
	//constructura o destructor
	CTriangulo();
	CTriangulo(int _x, int _y, int _dx, int _dy, int _lado, char _car);
	//acciones o metodos propios
	void Dibujar();
};
CTriangulo::CTriangulo() {};
CTriangulo::CTriangulo(int _x, int _y, int _dx, int _dy, int _lado, char _car) :CFigura(_x, _y, _dx, _dy, _lado)
{
	car = _car;
	forma = 2;
}
void CTriangulo::Dibujar()
{
	int _x = x, _y = y;
	Console::ForegroundColor = ConsoleColor::Red;
	for (int fila = 1; fila <= lado; fila++)
	{
		Console::SetCursorPosition(_x, _y);
		for (int col = 1; col <= fila; col++)
			cout << car;
		_y++;
	}
}