#include "figura.h"

figura::figura(unsigned short num)
{
	id = num;


}

void figura::actualizar()
{
	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].actualizar(); // llama a funcion actulizar de la clase cuadrado no se refiere a la de esta clase
	}

	
}

void figura::dibujar()
{
	// cuadrados[0] mantiene su posicion
	switch (id)
	{
	case 1: // L ELE
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(-30);
		cuadrados[3].set_y(-30);
	
	default:
		break;
	}
	
	
	
	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].dibujar(); // llama a funcion dibujar de la clase cuadrado no se refiere a la de esta clase
	}

}
