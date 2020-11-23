#include "juego.h"

int juego::h = 600;
float juego::fps = 60.f;
int juego::w = 800;
figura juego::ele(5);// manda llamar el objeto de la clase cuadrado a travez de juego.h
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

void juego::iniciar()
{
	glClearColor(0, 0, 0, 0.1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(0, w, 0, h, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


}

void juego::dibujar_tablero()
{
	glPushMatrix();

	glTranslated(-150, 300, 0); //despues de encontrarse en el centro de la pantalla se reposiciona al punto superior izq de pantalla 

	glColor3f(1, 1, 1);
	glBegin(GL_QUAD_STRIP); // dibujando rectangulo central
	glVertex2f(0, 0);
	glVertex2f(300, 0);
	glVertex2f(0, -600);
	glVertex2f(300, -600);
	glEnd(); // terminando dibujado de rectangulo y central y volviendo a posicion original

	glPopMatrix();

}


void juego::dibujar()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//cout << "Si actualiza a 60 fps" << endl;
	glPushMatrix();
	glTranslatef(w / 2, h / 2, 0); // reposicionando en el centro
	
	dibujar_tablero();

	//dibujando cuadrado
	ele.dibujar();
	//objeto1.actualizar(); // esta instruccion se llevo a objeto1.dibujar();
	

	glPopMatrix();


	glutSwapBuffers(); //muestra
}

void juego::procesar_teclado(unsigned char p, int x, int y)
{


}

void juego::actualizar()
{
	static float tiempo_transcurrido = 0;
	
	static float actualizar_cuadrado = 0;
	
	if (glutGet(GLUT_ELAPSED_TIME) - (tiempo_transcurrido + 1.f/fps) > 0)
	{
		if (glutGet(GLUT_ELAPSED_TIME) > actualizar_cuadrado + 1000.f) // actualiza posicion del cuadrado cada 1 segundo
		{
			actualizar_cuadrado = glutGet(GLUT_ELAPSED_TIME);
			ele.actualizar();
		}




		tiempo_transcurrido = glutGet(GLUT_ELAPSED_TIME);
		glutPostRedisplay();

	}
	
	
	
}


