#pragma once
#include "CCuadrado.h"
#include "CTriangulo.h"
#include <vector>
using namespace std;
using namespace System;
class CManejador
{
private:
	vector <CFigura*> vecfig;
public:
	CManejador();
	void Insertar(char letra);
	void Dibujar();
	void Mover();
	void Borrar();
	void Colision();
	void Cambiar_Relleno();
};
CManejador::CManejador() {}
void CManejador::Insertar(char letra)
{
	Random f;
	if (letra == 'C')
	{
		int tipo = f.Next(1, 3);
		if (tipo == 1)//vertical verde
			vecfig.push_back(new CCuadrado(f.Next(1, 70), f.Next(1, 18), 0, 1, tipo, f.Next(2, 5)));
		if (tipo == 2)//vertical amarillo
			vecfig.push_back(new CCuadrado(f.Next(1, 70), f.Next(1, 18), 1, 0, tipo, f.Next(2, 5)));
	}
	if (letra == 'T')
		vecfig.push_back(new CTriangulo(f.Next(1, 70), f.Next(8, 18), f.Next(-1, 2), f.Next(-1, 2), f.Next(2, 5), f.Next('A', 'Z' + 1)));
}
void CManejador::Dibujar()
{
	for (int i = 0; i < vecfig.size(); i++)   vecfig[i]->Dibujar();
}
void CManejador::Mover()
{
	for (int i = 0; i < vecfig.size(); i++)   vecfig[i]->Mover();
}
void CManejador::Borrar()
{
	for (int i = 0; i < vecfig.size(); i++)   vecfig[i]->Borrar();
}
void CManejador::Colision()

{
	if (vecfig.size() > 2)//existen elementos antes de ver colision
	{
		for (int i = 0; i < vecfig.size() - 1; i++)
			for (int j = i + 1; j < vecfig.size(); j++)
				if (vecfig[i]->GetForma() == 1 && vecfig[j]->GetForma() == 2)
				{	//algoritmo de colision
					int x1 = vecfig[i]->GetX(); int y1 = vecfig[i]->GetY();
					int x2 = vecfig[j]->GetX();	int y2 = vecfig[j]->GetY();
					int lado1 = vecfig[i]->GetLado();
					int lado2 = vecfig[j]->GetLado();
					if (!(x1 + lado1<x2 || y1 + lado1<y2 ||
						  x1>x2 + lado2 || y1>y2 + lado2))
					{
						vecfig[i]->CambiaDx(); vecfig[i]->CambiaDy();
						vecfig[j]->CambiaDx(); vecfig[j]->CambiaDy();
					}
				}
	}
}
void CManejador::Cambiar_Relleno()
{
	for (int i = 0; i < vecfig.size(); i++)    vecfig[i]->CambiaRelleno();
}
