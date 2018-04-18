#include "gl/freeglut.h"
#include "gl/glut.h"

#include "Define.h"
#include "Chapter3/Exercises/Ex3.1.h"
#include "Chapter3/Exercises/Ex3.2.h"
#include "Chapter3/Exercises/Ex3.3.h"
#include "Chapter3/Exercises/Ex3.4.h"
#include "Chapter5/Transform.h"

LinePoint p1 = { 30, 30};
LinePoint p2 = { 100, 50};
LinePoint p3 = { 200, 50};
LinePoint p4 = { 100, 200};

CTransform trans;
unsigned char op = 0;
Point pt[4] = { { 0, 0 }, { 100, 0 }, { 100, 100 }, { 0, 100 } };
Point pivot = { 0, 0 };
Point fixedPoint = { 0, 0 };

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0, 0);
	switch (op)
	{
	case 'T':
	case 't':
		trans.translate(pt, 4, 100, 100);
		break;

	case 'R':
	case 'r':
		trans.rotate(pt, 4, pivot, 15.0);
		break;

	case 'S':
	case 's':
		trans.scale(pt, 4, fixedPoint, 1.8);
		break;

	case 'Q':
	case 'q':
		trans.directionalScale(pt, 4, 45, 1, 2);
		break;

	default:
		trans.translate(pt, 4, 0, 0);
		break;
	}
	glFlush();
}

void keyboard(unsigned char ch, int x, int y)
{
	op = ch;
	switch (ch)
	{
	case 'T':
	case 't':
	case 'R':
	case 'r':
	case 'S':
	case 's':
	case 'B':
	case 'b':
	case 'Q':
	case 'q':
		glutPostRedisplay();
		break;

	default:
		break;
	}
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
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}