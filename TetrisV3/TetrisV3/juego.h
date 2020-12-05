#pragma once
#include "GL\glut.h"
#include "figura.h" // para dibujar los cuadrados
#include <iostream>
#include <list>
#include <ctime>

using namespace std;




class juego
{
public:
	juego();
	static void dibujar();
	static void procesar_teclado(unsigned char p, int x, int y);
	static void actualizar();
	static void iniciar();// iniciar model matriz y perspectivas
	static void dibujar_tablero();
	static void dibujar_cuadradosList();

	int exportar_alto();
	int exportar_ancho();
	static void dibujar_cuadrados(); //
	static void chequear_colision();
	static void chequear_lineas();
	


private:
	static int h , w ;
	static float fps;
	static figura pieza; 
	static list<cuadrado> cuadradosLista; //lista de objetos cuadradaditos que se van almacenando en la pantalla
	static float tiempo_actualizar;
};

