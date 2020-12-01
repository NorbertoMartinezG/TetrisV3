#include "figura.h"
#include <cmath>
#include <iostream>
using namespace std;



figura::figura(unsigned short num)
{
	id = num;
	rotacion = 1;
	//pos_x = 0;
	pos_x = 15; //se modifico el anterior para que el cuadrito central de 15 colisione exactamente con el area de juego
	//pos_y = 300;
	//se modifico el anterior para que el cuadrito central de 15 colisione exactamente con el area de juego
	pos_y = 345;

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

	case 6: // ESE
		cuadrados[1].set_x(-30);
		cuadrados[2].set_y(30);
		cuadrados[3].set_x(30);
		cuadrados[3].set_y(30);
		break;

	default:
		break;
	}


}

bool figura::actualizar()
{
	
	//llama a la funcion que hace caer el cuadrito pero ya no sera necesaria ya que se le indicara en la funcion actualizar de esta clase que vaya cayendo
	//for (int i = 0; i < 4; i++)
	//{
	//	cuadrados[i].actualizar(); // llama a funcion actulizar de la clase cuadrado no se refiere a la de esta clase
	//}
	//pos_y -= 30; // va sumando menos 30 a la posicion

	// creando colision limitando el desplazamiento hacia abajo
	bool colisionPiso = false;
	
	if (pos_y > -285)
	{
		pos_y -= 30;
	}
	else
	{
		colisionPiso = true;
	}

	return colisionPiso;
	
}

void figura::dibujar()
{
	// cuadrados[0] mantiene su posicion
	
	switch (id) // asigna el color dependiendo de la figura que se va a dibujar
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

	case 6:
		glColor3f(0, 1, 0);
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
	//pos_x += x;

	//creando limites a los lados (colision)
	if (x > 0)
	{
		if (pos_x < 135)
		{
			pos_x += x;
		}
	}
	else
	{
		if (pos_x > -135)
		{
			pos_x += x;
		}
	}


}

void figura::set_y(double y)
{
	//for (int i = 0; i < 4; i++)
	//{
	//	cuadrados[i].set_y(y); // modifica la posicion de los cuadrados para que se mueva arriba o abajo, en este caso solo abajo
	//}
	// SE MOVIA LA MATRIZ CUADRITOS PERO CAMBIAN LAS FLECHAS DE POSICION TAMBIEN
	// POR ESO ES MEJOR MOVER LA MATRIZ FIGURA PARA QUE LAS FLECHAS NO CAMBIEN AL ROTAR
	
	// creando colision limitando el desplazamiento hacia abajo // LIMITE SUELO
	
	
	
	if (pos_y >-285)
	{
		pos_y += y;
	}
	

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

// para calcular angulo global de cada uno de los cuadraditos
double figura::get_angulo_cuadradito(unsigned short num)
{

	double angulo_cuadradito = atan2f(cuadrados[num].get_y(), cuadrados[num].get_x()); // obtiene rotacion de cada cuadradito // lo devuelve en radianes aun falta transformarlo con rad2deg
	
	//cout <<"angulo cuadradito " <<(angulo_cuadradito) << endl;
	
	double rotacion_local = (rotacion - 1.0) * 90.0; // obtiene rotacion de la figura

	//cout << "rotacion local " << deg2rad(rotacion_local) << endl;
	
	//return rad2deg(angulo_cuadradito) + (rotacion_local); // obtener el valor de la rotacion en radianes para llevarlo a calcular posiciones globales del cuadradito en la sig. funcion
	return angulo_cuadradito + deg2rad(rotacion_local); // obtener el valor de la rotacion en radianes para llevarlo a calcular posiciones globales del cuadradito en la sig. funcion
}

double figura::calcular_posicion_x(unsigned short num)
{
	double hipotenusa;

	hipotenusa = sqrt(pow((cuadrados[num].get_x()), 2) + pow((cuadrados[num].get_y()), 2)) ; //suma posicion de la figura y la del cuadradito para aplicar arquimides
	
	//cout << "hipotenusa : "<<hipotenusa << endl;


	return cos(get_angulo_cuadradito(num) ) * hipotenusa + pos_x;
}

double figura::calcular_posicion_y(unsigned short num)
{
	double hipotenusa;

	hipotenusa = sqrt(pow((cuadrados[num].get_x()), 2) + pow((cuadrados[num].get_y()), 2)); //suma posicion de la figura y la del cuadradito para aplicar arquimides

	return sin(get_angulo_cuadradito(num) ) * hipotenusa + pos_y; // EL SENO SE CALCULO EN RADIANES

}
