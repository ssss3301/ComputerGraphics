#include "gl/freeglut.h"
#include "gl/glut.h"

/*
void PlotPoints(int x, int y, int circleCenterX, int circleCenterY)
{
	glVertex2f(x + circleCenterX, y + circleCenterY);

	//��һ���� (x,y)����y = x�Գ�
	glVertex2f(y + circleCenterX, x + circleCenterY);

	//�ڶ����� (x,y)����y = 0�Գ�
	glVertex2f(-x + circleCenterX, y + circleCenterY);

	//�ڶ����� (-x,y)����y = -x�Գ�
	glVertex2f(y + circleCenterX, -x + circleCenterY);

	//��������(-x, y)����x = 0�Գ�
	glVertex2f(-x + circleCenterX, -y + circleCenterY);

	//��������(-x,-y)����y = x�Գ�
	glVertex2f(-y + circleCenterX, -x + circleCenterY);

	//��������(x,y)����x = 0�Գ�
	glVertex2f(x + circleCenterX, -y + circleCenterY);

	//��������(x,-y)����y = -x�Գ�
	glVertex2f(-y + circleCenterX, x + circleCenterY);
}

void CircleMidPoint(int radius, int x, int y)
{
	int tx = 0;
	int ty = radius;
	int p = 5 / 4 - radius;

	PlotPoints(tx, ty, x, y);
	while (tx < ty)
	{
		tx++;
		if (p < 0)
		{
			p += 2 * tx + 1;
		}
		else
		{
			ty--;
			p += 2 * tx + 1 - 2 * ty;
		}
		PlotPoints(tx, ty, x, y);
	}
}

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
	glBegin(GL_POINTS);
	CircleMidPoint(50, 100, 100);
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