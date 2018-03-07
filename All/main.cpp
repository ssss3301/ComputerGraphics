#include "gl/freeglut.h"
#include "gl/glut.h"

#include "Ellipse.h"
#include "ThickLine.h"

LinePoint p1 = { 200, 120 };
LinePoint p2 = { 200, 20 };

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 300, 0, 300);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0, 0);
	glBegin(GL_POINTS);
	ThickLine::drawLine(p1, p2, 10);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow(argv[0]);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(100, 100);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}