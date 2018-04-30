#include "GL/glew.h"
#include "GL/freeglut.h"
#include "GL/glut.h"

#include "Chapter5/LineClip.h"
#include "Chapter3/BresenhamLine.h"

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	LinePoint winMin = { 100, 100 };
	LinePoint winMax = { 200, 200 };
	LinePoint p1 = { 50, 50 };
	LinePoint p2 = { 250, 250 };
	LineClip clipper;

	glBegin(GL_POINTS);
	clipper.lineClip_Barsky(winMin, winMax, p1, p2);
	//BresenhamLine::drawLine(p1, p2);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glPolygonMode(GL_FRONT, GL_LINE);
	glBegin(GL_POLYGON);
	glVertex2f(100, 100);
	glVertex2f(200, 100);
	glVertex2f(200, 200);
	glVertex2f(100, 200);
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}