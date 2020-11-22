#pragma once
#include "cuadrado.h"


class figura
{
public:
	figura(unsigned short num); // 1 ELE - 2 ELE INVERTIDA - 3 CUBO - 4 TRIANGULO - 5 PALO
	void actualizar();
	void dibujar();


private:
	cuadrado cuadrados[4];
	unsigned char id;




};

