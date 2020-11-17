#pragma once
#include "GL\glut.h"

class cuadrado
{
public:
	cuadrado(); // constructor
	void dibujar();
	void set_x(double x) { pos_x = x; } //define posicion que es pasada
	void set_y(double y) { pos_x = y; }
	double get_x() { return pos_x; } // retorna posiciones
	double get_y() { return pos_y; }



private:
	double pos_x; // posicion inicial
	double pos_y;	// posicion inicial

};

