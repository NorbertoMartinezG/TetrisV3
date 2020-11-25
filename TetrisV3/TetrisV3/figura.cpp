#include "figura.h"

figura::figura(unsigned short num)
{
	id = num;
	rotacion = 1;
	pos_x = 0;
	pos_y = 300;

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
	
	//llama a la funcion que hace caer el cuadrito pero ya no sera necesaria ya que se le indicara en la funcion actualizar de esta clase que vaya cayendo
	//for (int i = 0; i < 4; i++)
	//{
	//	cuadrados[i].actualizar(); // llama a funcion actulizar de la clase cuadrado no se refiere a la de esta clase
	//}
	pos_y -= 30; // va sumando menos 30 a la posicion
	
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

	// ROTACION DE MATRIZ que contiene a la figura
	
	/* // esto se traslado a cuadrado.cpp para rotar los cuadrados no la figura.
	switch (rotacion) 
	{
	case 2:
		glRotatef(90.0, 0, 0, 1);
		break;
	case 3:
		glRotatef(180.0, 0, 0, 1);
		break;
	case 4:
		glRotatef(270.0, 0, 0, 1);
		break;

	default:
		break;
	}*/

	//creando nueva posicion de matriz para que dibuje
	glPushMatrix();
	glTranslatef(pos_x, pos_y, 0);

	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].dibujar(); // llama a funcion dibujar de la clase cuadrado no se refiere a la de esta clase
	}
	
	glPopMatrix(); // cierra matriz

}

void figura::set_x(double x)
{
	//for (int i = 0; i < 4; i++)
	//{
	//	cuadrados[i].set_x(x); // modifica la posicion de los cuadrados para que se muevan a derecha o izquierda
	//}
	// SE MOVIA LA MATRIZ CUADRITOS PERO CAMBIAN LAS FLECHAS DE POSICION TAMBIEN
	// POR ESO ES MEJOR MOVER LA MATRIZ FIGURA PARA QUE LAS FLECHAS NO CAMBIEN AL ROTAR
	pos_x += x;


}

void figura::set_y(double y)
{
	//for (int i = 0; i < 4; i++)
	//{
	//	cuadrados[i].set_y(y); // modifica la posicion de los cuadrados para que se mueva arriba o abajo, en este caso solo abajo
	//}
	// SE MOVIA LA MATRIZ CUADRITOS PERO CAMBIAN LAS FLECHAS DE POSICION TAMBIEN
	// POR ESO ES MEJOR MOVER LA MATRIZ FIGURA PARA QUE LAS FLECHAS NO CAMBIEN AL ROTAR
	pos_y += y;


}

void figura::rotar()
{
	rotacion++;
	if (rotacion > 4) rotacion = 1;
	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].set_rotacion(rotacion);
	}
	
}
