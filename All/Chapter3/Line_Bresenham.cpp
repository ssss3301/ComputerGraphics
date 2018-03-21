#include "gl/freeglut.h"
#include "gl/glut.h"
#include <algorithm>

/*
void linebresenham_slope_greater_negative_1(int xStart, int yStart, int xEnd, int yEnd)
{
	int dx = std::abs(xEnd - xStart);
	int dy = std::abs(yEnd - yStart);
	int p = dx;

	int x, y;
	if (xStart > xEnd)
	{
		x = xEnd;
		y = yEnd;
		xEnd = xStart;
	}
	else
	{
		x = xStart;
		y = yStart;
	}

	glVertex2f(x, y);
	while (x < xEnd)
	{
		x++;
		if (p < 0)
		{
			p += 2 * dy;
		}
		else
		{
			y--;
			p += 2 * dy - 2 * dx;
		}
		glVertex2f(x, y);
	}
}

void line_bresenham_slop_less_negative_1(int xStart, int yStart, int xEnd, int yEnd)
{
	int dx = std::abs(xEnd - xStart);
	int dy = std::abs(yEnd - yStart);
	int p = -dy;

	int x, y;
	if (yStart > yEnd)
	{
		x = xEnd;
		y = yEnd;
		yEnd = yStart;
	}
	else
	{
		x = xStart;
		y = yStart;
	}

	glVertex2f(x, y);
	while (y < yEnd)
	{
		y++;
		if (p < 0)
		{
			p += 2 * dx;
		}
		else
		{
			x--;
			p += 2 * dx - dy * 2;
		}
		glVertex2f(x, y);
	}
}

void line_bresenham_slope_greater_1(int xStart, int yStart, int xEnd, int yEnd)
{
	int dx = std::abs(xEnd - xStart);
	int dy = std::abs(yEnd - yStart);
	int p = 2 * dx - dy;

	int x, y;
	if (yStart > yEnd)
	{
		x = xEnd;
		y = yEnd;
		yEnd = yStart;
	}
	else
	{
		x = xStart;
		y = yStart;
	}

	glVertex2f(x, y);
	while (y < yEnd)
	{
		y++;
		if (p < 0)
		{
			p += 2 * dx;
		}
		else
		{
			x++;
			p += 2 * dx - 2 * dy;
		}

		glVertex2f(x, y);
	}
}

void line_bresenham_slope_less_1(int xStart, int yStart, int xEnd, int yEnd)
{
	int dx = std::abs(xEnd - xStart);
	int dy = std::abs(yEnd - yStart);
	int two_dx = 2 * dx;
	int two_dy = 2 * dy;
	int twoDy_dx = two_dy - dx;
	int twoDy_twoDx = two_dy - two_dx;
	int p = twoDy_dx;

	int x, y;
	if (xStart > xEnd)
	{
		x = xEnd;
		y = yEnd;
		xEnd = xStart;
	}
	else
	{
		x = xStart;
		y = yStart;
	}

	glVertex2f(x, y);
	while (x < xEnd)
	{
		x++;
		if (p < 0)
		{
			p += two_dy;
		}
		else
		{
			y++;
			p += twoDy_twoDx;
		}

		glVertex2f(x, y);
	}
}

void line_bresenham_slope_equal_0(int xStart, int yStart, int xEnd, int yEnd)
{
	int dx = std::abs(xEnd - xStart);
	int dy = std::abs(yEnd - yStart);

	int x, y, steps;
	if (dx == 0)
	{
		if (yStart > yEnd)
		{
			y = yEnd;
			steps = yStart - yEnd;
		}
		else
		{
			y = yStart;
			steps = yEnd - yStart;
		}
		glVertex2f(xStart, y);
		for (int i = 0; i < steps; ++i)
		{
			y++;
			glVertex2f(xStart, y);
		}
	}
	else
	{
		if (xStart > xEnd)
		{
			x = xEnd;
			steps = xStart - xEnd;
		}
		else
		{
			x = xStart;
			steps = xEnd - xStart;
		}
		glVertex2f(x, yStart);
		for (int i = 0; i < steps; ++i)
		{
			x++;
			glVertex2f(x, yStart);
		}
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
	line_bresenham_slope_equal_0(200, 100, 30, 100);
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