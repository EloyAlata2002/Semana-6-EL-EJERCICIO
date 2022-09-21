#pragma once
#include "CCuadrado.h"
#include <vector>
class CManejador
{
private:
	vector <CCuadrado> veccua;
public:
	CManejador();
	void Insertar();
	void Dibujar();
	void Mover();
	void Borrar();
	void Cambiar_Direccion_Vertical();
	void Cambiar_Direccion_Horizontal();
	void Cambiar_Relleno();
};
CManejador::CManejador(){}
void CManejador::Insertar()
{
	Random f;
	int tipo = f.Next(1, 3);
	if (tipo == 1)//vertical verde
		veccua.push_back(CCuadrado(f.Next(1, 70), f.Next(1, 18), 0, 1, tipo, f.Next(2, 5)));
	if (tipo == 2)//horizontal amarrillo
		veccua.push_back(CCuadrado(f.Next(1, 70), f.Next(1, 18), 1, 0, tipo, f.Next(2, 5)));
}
void CManejador::Dibujar()
{
	for (int i = 0; i < veccua.size(); i++)
		veccua[i].Dibujar();
}
void CManejador::Mover()
{
	for (int i = 0; i < veccua.size(); i++)
		veccua[i].Mover();
}
void CManejador::Borrar()
{
	for (int i = 0; i < veccua.size(); i++)
		veccua[i].Borrar();
}
void CManejador::Cambiar_Direccion_Vertical()
{
	for (int i = 0; i < veccua.size(); i++)
		veccua[i].SetDY(veccua[i].getDy() * -1);
}
void CManejador::Cambiar_Direccion_Horizontal()
{
	for (int i = 0; i < veccua.size(); i++)
		veccua[i].SetDX(veccua[i].getDx() * -1);
}
void CManejador::Cambiar_Relleno()
{
	for (int i = 0; i < veccua.size(); i++)
		if (veccua[i].getRelleno() == 0)
			veccua[i].SetRelleno(1);
		else
			veccua[i].SetRelleno(0);
}
