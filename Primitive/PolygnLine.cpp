#include "gl/freeglut.h"
#include "gl/glut.h"
#include "BresenhamLine.h"

/*
const LinePoint points[5] = { { 20, 100 }, { 50, 150 }, { 90, 50 }, { 200, 150 }, {300, 150} };

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 300, 0, 300);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	BresenhamLine::drawPolygonalLine(std::vector<LinePoint>(points, points + 5));
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