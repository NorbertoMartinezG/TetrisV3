// TetrisV3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

//

#include "GL\glut.h"
#include <iostream>
#include "juego.h"




int main(int argc, char* args[])
{

	glutInit(&argc, args);

	//objeto juego
	juego partida1;

	glutMainLoop();



	return 0;


}