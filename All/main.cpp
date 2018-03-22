#include "gl/freeglut.h"
#include "gl/glut.h"

#include "Define.h"
#include "Chapter3/Exercises/Ex3.1.h"
#include "Chapter3/Exercises/Ex3.2.h"

LinePoint p1 = { 30, 30 };
LinePoint p2 = { 30, 50 };
LinePoint p3 = { 200, 50 };
LinePoint p4 = { 100, 200 };

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
	std::vector<LinePoint> pts;
	pts.push_back(p1);
	pts.push_back(p2);
	pts.push_back(p3);
	pts.push_back(p4);
	Ex32 ex32;
	ex32.drawLineWithBresenham(p2, p1);
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