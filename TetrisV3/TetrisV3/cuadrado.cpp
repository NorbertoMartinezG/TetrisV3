#include "cuadrado.h"


cuadrado::cuadrado()
{


}

void cuadrado::dibujar()
{
	glPushMatrix();

	glBegin(GL_QUAD_STRIP);
	glVertex2f(0, 0);
	glVertex2f(30, 0);
	glVertex2f(0, 30);
	glVertex2f(30, 30);



	glPopMatrix();



}
