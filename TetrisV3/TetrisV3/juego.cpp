#include "juego.h"

int juego::h = 600;
float juego::fps = 60.f;
int juego::w = 800;
figura juego::pieza(rand() % 6 + 1);// manda llamar el objeto de la clase cuadrado a travez de juego.h
//cuadrado* ob1 = new cuadrado(); //extraer variable directamente de clase 
//figura* pieza = new figura(rand() % 6 + 1); // extraido directamente de figura.h sin declarar la variable en figura.h sino aqui directamente
list<cuadrado> juego::cuadradosLista;


juego::juego()
{
	srand(time(NULL)); // toma la hora del sistema para generar numeros aleatorios tuto33

	
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
	glClearColor(0.5, 0, 0, 0.1);

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

	glColor3f(0, 0, 0);
	glBegin(GL_QUAD_STRIP); // dibujando rectangulo central
	glVertex2f(0, 0);
	glVertex2f(300, 0);
	glVertex2f(0, -600);
	glVertex2f(300, -600);
	glEnd(); // terminando dibujado de rectangulo y central y volviendo a posicion original

	glPopMatrix();

}

void juego::dibujar_cuadradosList()
{
	list<cuadrado>::iterator p = cuadradosLista.begin(); //recorrer lista para volver a dibujar piezas que llegaron al piso
	while (p != cuadradosLista.end()) // mientras p no sea el ultimo objeto del cuadrado entonces
	{
		p->dibujar(); // cast por que es dinamico
		p++;
	}
}


void juego::dibujar()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//cout << "Si actualiza a 60 fps" << endl;
	glPushMatrix();
	glTranslatef(w / 2, h / 2, 0); // reposicionando en el centro
	
	dibujar_tablero();

	//dibujando cuadrado
	pieza.dibujar();
	//objeto1.actualizar(); // esta instruccion se llevo a objeto1.dibujar();
	
	// PARA DIBUJAR LAS PIEZAS QUE LLEGARON AL FINAL DEL ESPACIO EN EL TETRIS Y QUE SE GUARDARON EN UNA LISTA
	dibujar_cuadradosList();


	glPopMatrix();


	glutSwapBuffers(); //muestra
}

void juego::procesar_teclado(unsigned char c, int x, int y)
{
	switch (c)
	{
	case 'A': case 'a':
		pieza.set_x(-30); //mueve la figura a lado izquierdo la funcion viene desde cuadrado.h
	
		break;

	case 'D': case 'd':
		pieza.set_x(30);//mueve la figura a lado derecho
		break;

	case 'S': case 's':
		pieza.set_y(-30);//mueve la figura a hacia abajo
		break;

	case ' ':
		pieza.rotar();

	default:
		break;
	}

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
			
			// TUTORIAL 32 SE COMPLICA --------
			if (pieza.actualizar()) // se se activa la colision de la funcion actualizar de la clase figura
			{
				for (int i = 0; i < 4; i++)
				{
					cuadradosLista.push_back(cuadrado(pieza.get_x(i),pieza.get_y(i)-285)); // a cuadradosList le vamos a agregar un objeto cuadrado
				}
				pieza = figura(rand()%6+1); // se crea nueva figura aleatoria de 1 a 6
			}
		}




		tiempo_transcurrido = glutGet(GLUT_ELAPSED_TIME);
		glutPostRedisplay();

	}
	
	
	
}


