#include "juego.h"

int juego::h = 600;
//float juego::fps = 60.f;
int juego::w = 800;
//cuadrado* ob1 = new cuadrado(); //extraer variable directamente de clase 
//figura* pieza = new figura(rand() % 6 + 1); // extraido directamente de figura.h sin declarar la variable en figura.h sino aqui directamente
//list<cuadrado> cuadradosList;


juego::juego()
{
	
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //inicializa con doble bufer
	glutInitWindowPosition(50, 50); // posicion inicial
	glutInitWindowSize(w, h); // tamaño ventana
	glutCreateWindow("Tetris V2"); // crear ventana con titulo
	
	glutDisplayFunc(dibujar); // funcion para dibujar
	glutKeyboardFunc(procesar_teclado);
	glutIdleFunc(actualizar); // funcion actualizar
	iniciar(); // iniciar model matriz y perspectivas

}


void juego::dibujar()
{
	//glClear(GL_COLOR_BUFFER_BIT);
	//glPushMatrix();
	//glTranslatef(w / 2, h / 2, 0); // reposicionando en el centro
	//dibujar_tablero();

	////dibujando cuadrado
	////cuadrado* ob1 = new cuadrado();
	////ob1->dibujar();
	////pieza->dibujar();

	////RECORRER LISTA
	//dibujar_cuadrados();

	///*objeto1.dibujar();*/


	//glPopMatrix();


	//glutSwapBuffers(); //muestra
}