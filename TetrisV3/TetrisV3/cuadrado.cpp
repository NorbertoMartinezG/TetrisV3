#include "cuadrado.h"


cuadrado::cuadrado()
{
	pos_y = 330;
	pos_x = 0;

}

void cuadrado::dibujar()
{
	glPushMatrix();

	glTranslatef(pos_x, pos_y, 0); // traslada el dibujo a la posicion inicial

	//glColor3f(0, 0, 1); //color del cuadrito

	glBegin(GL_QUAD_STRIP);
	glVertex2f(0, 0);
	glVertex2f(30, 0);
	glVertex2f(0, 30);
	glVertex2f(30, 30);
	glEnd();


	glPopMatrix();



}

void cuadrado::actualizar()
{
	pos_y -= 30.0; // va callendo el cuadradito cada segundo

}
