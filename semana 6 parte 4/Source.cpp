#include "CManejador.h"
#include <conio.h>
void main()
{
	Console::CursorVisible = false;
	CManejador objman;
	char letra;
	while (1)
	{
		if (kbhit())
		{
			letra = toupper(_getch());
			if (letra == 'C' || letra == 'T') objman.Insertar(letra);
			if (letra == 'R') objman.Cambiar_Relleno();
		}
		objman.Dibujar();
		_sleep(50);
		objman.Borrar();
		objman.Colision();
		objman.Mover();
	}
}