#include "juego.h"

int juego::h = 600;
float juego::fps = 60.f;
int juego::w = 800;
figura juego::pieza(rand() % 6 + 1);// manda llamar el objeto de la clase cuadrado a travez de juego.h
//cuadrado* ob1 = new cuadrado(); //extraer variable directamente de clase 
//figura* pieza = new figura(rand() % 6 + 1); // extraido directamente de figura.h sin declarar la variable en figura.h sino aqui directamente
list<cuadrado> juego::cuadradosLista;
float juego::tiempo_actualizar = 1000.f;


juego::juego()
{
	srand(time(NULL)); // toma la hora del sistema para generar numeros aleatorios tuto33
	pieza = figura(rand() % 6 + 1);
	
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
		tiempo_actualizar = 50.f;
		pieza.set_y(-30);//mueve la figura a hacia abajo
		break;

	
	
	case ' ':
		pieza.rotar();
		for (int i = 0; i < 4; i++) // obtener angulo global de cada cuadradito en grados 
		{
			pieza.calcular_posicion_x(i);
			//cout << pieza.calcular_posicion_x(i) <<" esto es del case"<< endl;

			//pieza.calcular_posicion_y(i);
		}
		break;

	default:
		break;
	}

}

void juego::actualizar()
{
	static float tiempo_transcurrido = 0;
	
	static float actualizar_cuadrado = 0;

	if (glutGet(GLUT_ELAPSED_TIME) > tiempo_transcurrido + 1.f/fps)
	{
		if (glutGet(GLUT_ELAPSED_TIME) > actualizar_cuadrado + tiempo_actualizar) // actualiza posicion del cuadrado cada 1 segundo
		{
			chequear_colision();
			actualizar_cuadrado = glutGet(GLUT_ELAPSED_TIME);
		
			// TUTORIAL 32 SE COMPLICA --------
			if (pieza.actualizar()) // se se activa la colision de la funcion actualizar de la clase figura
			{
				for (int i = 0; i < 4; i++)
				{
					//cuadradosLista.push_back(cuadrado(pieza.get_x(i),pieza.get_y(i) )); // a cuadradosList le vamos a agregar un objeto cuadrado
					cuadradosLista.push_back(cuadrado(pieza.calcular_posicion_x(i), pieza.calcular_posicion_y(i))); // a cuadradosList le vamos a agregar un objeto cuadradito de acuerdo a las posiciones globales calculadas en figura en base a los cuadraditos
				}
				chequear_lineas(); // chequea lineas desde la base
				pieza = figura(rand()%6+1); // se crea nueva figura aleatoria de 1 a 6
			}
		}
		tiempo_transcurrido = glutGet(GLUT_ELAPSED_TIME);
		tiempo_actualizar = 1000.f;
		glutPostRedisplay();
	}
	
}

void juego::dibujar_cuadradosList()
{
	list<cuadrado>::iterator p = cuadradosLista.begin(); //recorrer lista para volver a dibujar piezas que llegaron al piso
	while (p != cuadradosLista.end()) // mientras p no sea el ultimo objeto del cuadrado entonces
	{
		glColor3f(1, 1, 1);
		p->dibujar(); // cast por que es dinamico
		p++;
	}
}


void juego::chequear_colision()
{
	bool gameOver = false;
	
	list<cuadrado>::iterator p = cuadradosLista.begin(); //recorrer lista para volver a dibujar piezas que llegaron al piso
	while (p != cuadradosLista.end()) // mientras p no sea el ultimo objeto del cuadrado entonces
	{
		bool hubo_colision = false;

		for (int i = 0; i < 4; i++)
		{
			if (abs(p->get_y() - ((int)pieza.calcular_posicion_y(i) - 30.0)) < 15)
			{
				if (abs(p->get_x() - (int)pieza.calcular_posicion_x(i)) < 5)
				{
					hubo_colision = true;
				}
			}
		}
		if (hubo_colision)
		{
			for (int i = 0; i < 4; i++)
			{
				//cuadradosLista.push_back(cuadrado(pieza.get_x(i),pieza.get_y(i) )); // a cuadradosList le vamos a agregar un objeto cuadrado
				cuadradosLista.push_back(cuadrado(pieza.calcular_posicion_x(i), pieza.calcular_posicion_y(i))); // a cuadradosList le vamos a agregar un objeto cuadradito de acuerdo a las posiciones globales calculadas en figura en base a los cuadraditos

				if ((int)pieza.calcular_posicion_y(i) > 300) //revisa si la posicion va mas alla de la parte superior cambia la variable gameOver
				{
					gameOver = true;
				}


			}
			chequear_lineas();// revisa si hay una linea de cuadraditos
			
			pieza = figura(rand() % 6 + 1); // se crea nueva figura aleatoria de 1 a 6
		}
		p++;
	}

	if (gameOver)
	{
		exit(1);
	}

}

void juego::chequear_lineas()
{
	for (int i = 0; i < 4; i++)
	{
		int contar_cuadraditos = 0;

		list<cuadrado>::iterator p = cuadradosLista.begin();
		while (p != cuadradosLista.end())
		{
			if (abs((int)pieza.calcular_posicion_y(i) - p->get_y()) < 15)
			{
				contar_cuadraditos++;
			}
			p++;
		}
		if (contar_cuadraditos == 10)
		{
			p = cuadradosLista.begin();
			while (p != cuadradosLista.end())
			{
				if (abs((int)pieza.calcular_posicion_y(i) - p->get_y()) < 15)
				{
					p= cuadradosLista.erase(p);

				}
				else
				{
					if (p->get_y() > ((int)pieza.calcular_posicion_y(i))) // para bajar piezas despues de borrarla
					{
						p->set_y(-30); // se sume menos 30
					}
					p++;
				}
				
			}

		}

	}

}
