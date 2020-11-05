#pragma once
#include "GL\glut.h"




class juego
{
public:
	juego();
	static void dibujar();
	static void procesar_teclado(unsigned char p, int x, int y);
	static void actualizar();
	static void iniciar();// iniciar model matriz y perspectivas
	static void dibujar_tablero();
	int exportar_alto();
	int exportar_ancho();
	static void dibujar_cuadrados(); //
	static void chequear_colision();


private:
	static int h , w ;

};

