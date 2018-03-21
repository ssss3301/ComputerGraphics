#include "gl/freeglut.h"
#include "gl/glut.h"
#include <algorithm>

//DDA(digital differential analyzer Êı×ÖÎ¢·Ö·ÖÎöÒÇ)

/*void lineDDA(int xStart, int yStart, int xEnd, int yEnd)
{
	float dx = xEnd - xStart;
	float dy = yEnd - yStart;

	int steps = std::max(abs(dx), abs(dy));
	float xIncreasement = dx / steps;
	float yIncreasement = dy / steps;

	float x = xStart;
	float y = yStart;
	glVertex2f(std::round(x), std::round(y));
	for (int i = 0; i < steps; ++i)
	{
		x += xIncreasement;
		y += yIncreasement;
		glVertex2f(std::round(x), std::round(y));
	}
}

void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 300, 0, 300);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0, 0.0);
	glBegin(GL_POINTS);
	lineDDA(0, 0, 200, 300);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow(argv[0]);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(300, 300);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}*/