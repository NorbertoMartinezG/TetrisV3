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

	double rad2deg(double radianes) { return radianes * 180 / 3.14; } // 

private:
	cuadrado cuadrados[4];
	unsigned short id;
	double rotacion;
	double pos_x;
	double pos_y;





};

