#pragma once
#include "cuadrado.h"


class figura
{
public:
	figura(unsigned short num); // 1 ELE - 2 ELE INVERTIDA - 3 CUBO - 4 TRIANGULO - 5 PALO
	void actualizar();
	void dibujar();
	void set_x(double x);
	void set_y(double y);
	void rotar(); // rota toda la figura


private:
	cuadrado cuadrados[4];
	unsigned short id;
	unsigned short rotacion;





};

