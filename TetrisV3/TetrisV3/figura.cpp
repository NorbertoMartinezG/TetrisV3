#include "figura.h"

figura::figura(unsigned short num)
{
	id = num;

	switch (id)
	{
	case 1: // L ELE
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(-30);
		cuadrados[3].set_y(30);
		break;

	case 2: // L ELE invertida
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(30);
		cuadrados[3].set_y(30);
		break;

	case 3: // T TE 
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(0);
		cuadrados[3].set_y(30);
		break;

	case 4: // CUBO
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(30);
		cuadrados[2].set_y(30);
		cuadrados[3].set_x(0);
		cuadrados[3].set_y(30);
		break;


	case 5: // PALO
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(-60);
		//cuadrados[3].set_y(-30);
		break;


	default:
		break;
	}


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
	case 1:
		glColor3f(1, 1, 0);
		break;
	case 2:
		glColor3f(0, 1, 0);
		break;
	case 3:
		glColor3f(1, 0, 1);
		break;
	case 4:
		glColor3f(0, 0, 1);
		break;
	case 5:
		glColor3f(1, 0, 0);
		break;
	default:
		break;
	}
	
	
	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].dibujar(); // llama a funcion dibujar de la clase cuadrado no se refiere a la de esta clase
	}

}
