#include "gl/freeglut.h"
#include "gl/glut.h"
/*
const float p1[] = { 20.0, 10.0 };
const float p2[] = { 50.0, 100.0 };
const float p3[] = { 30.0, 60.0 };
const float p4[] = { 200.0, 100.0 };
const float p5[] = { 150.0, 150.0 };

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 300, 0, 300);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3b(255, 0, 0); byte���� -128~127��255 = -128
	glColor3ub(255, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2fv(p1);
	glVertex2fv(p2);
	glVertex2fv(p3);
	glVertex2fv(p4);
	glVertex2fv(p5);
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
}
*/