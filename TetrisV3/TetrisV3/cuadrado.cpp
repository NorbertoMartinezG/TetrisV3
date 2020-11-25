#include "cuadrado.h"


cuadrado::cuadrado()
{
	pos_y = 0;
	pos_x = 0;

}

void cuadrado::dibujar()
{
	glPushMatrix();

	// switch para rotas la matriz que encierra a los cuadraditos
	switch (rotacion)
	{
	case 2:
		glRotatef(90.0, 0, 0, 1);
		break;
	case 3:
		glRotatef(180.0, 0, 0, 1);
		break;
	case 4:
		glRotatef(270.0, 0, 0, 1);
		break;

	default:
		break;
	}


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

void cuadrado::set_rotacion(unsigned short num)
{
	rotacion = num;
}

void cuadrado::actualizar()
{
	// pos_y -= 30.0; // va callendo el cuadradito cada segundo

}
