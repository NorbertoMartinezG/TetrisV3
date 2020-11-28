#pragma once
#include "GL\glut.h"

class cuadrado
{
public:
	cuadrado(); // constructor
	cuadrado(double x, double y) { pos_x = x, pos_y = y; } // constructor para pasar posiciones que seran guardadas en la lista cuadradosList
	void dibujar();
	void set_x(double x) { pos_x += x; } //define posicion que es pasada
	void set_y(double y) { pos_y += y; }

	void set_rotacion(unsigned short num); // sustituye rotacion de figura.h

	void actualizar(); // actualiza el cuadrado para que vaya cayendo

	double get_x() { return pos_x; } // retorna posiciones
	double get_y() { return pos_y; }



private:
	double pos_x; // posicion inicial
	double pos_y;	// posicion inicial
	unsigned short rotacion; // rotacion desde cuadrado que sustituye la rotacion de figura

};

