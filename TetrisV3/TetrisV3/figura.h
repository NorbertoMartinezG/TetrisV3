#pragma once
#include "cuadrado.h"


class figura
{
public:
	figura(unsigned short num); // 1 ELE - 2 ELE INVERTIDA - 3 CUBO - 4 TRIANGULO - 5 PALO
	bool actualizar();
	void dibujar();
	void set_x(double x);
	void set_y(double y);
	void rotar(); // rota toda la figura

	

	double get_x(unsigned short num) { return cuadrados[num].get_x() + pos_x; }
	double get_y(unsigned short num) { return cuadrados[num].get_y() + pos_y; }

	//para calcular angulo de cuadraditos en la posicion global
	double get_angulo_cuadradito(unsigned short num);

	float rad2deg(double radianes) { return radianes * 180.0 / 3.14; } // 
	float deg2rad(double grados) { return grados * 3.14 / 180.0; } // convertir de grados a radianes


	double calcular_posicion_x(unsigned short num); // calcula posicion global de cada cuadradito
	double calcular_posicion_y(unsigned short num); // calcula posicion global de cada cuadradito


private:
	cuadrado cuadrados[4];
	unsigned short id;
	double rotacion;
	double pos_x;
	double pos_y;





};

