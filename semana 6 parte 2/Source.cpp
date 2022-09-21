#include "CManejador.h"
#include <conio.h>
void main()
{
	CManejador obj;
	char  tecla;
	while (1)
	{
		if (kbhit())
		{
			tecla = toupper(_getch());
			if (tecla == 'C'|| tecla=='T') obj.Insertar(tecla);
			if (tecla == 'H') obj.Cambiar_Direccion_Horizontal();
			if (tecla == 'V') obj.Cambiar_Direccion_Vertical();
			if (tecla == 'R') obj.Cambiar_Relleno();
		}
		obj.Dibujar();
		_sleep(50);
		obj.Borrar();
		obj.Mover();
	}

}