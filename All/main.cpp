#include "gl/freeglut.h"
#include "gl/glut.h"

#include "Ellipse.h"

EllipseRenderer renderer;

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 300, 0, 300);

	renderer.setEllipseParameter(30, 50, 150, 150);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0, 0);
	renderer.render();
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