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


private:
	cuadrado cuadrados[4];
	unsigned short id;
	unsigned short rotacion;
	double pos_x;
	double pos_y;





};

