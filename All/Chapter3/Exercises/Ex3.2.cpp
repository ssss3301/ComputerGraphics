#include "Ex3.2.h"
#include "GL/freeglut.h"
#include "GL/glut.h"
#include <algorithm>

Ex32::Ex32()
{

}

Ex32::~Ex32()
{

}

void Ex32::drawLineWithBresenham(LinePoint start, LinePoint end)
{
	if (start.x - end.x == 0 || start.y - end.y == 0)
	{
		glBegin(GL_POINTS);
		if (start.x - end.x == 0)
		{
			int y = start.y;
			int yEnd = end.y;
			if (start.y > end.y)
			{
				y = end.y;
				yEnd = start.y;
			}
			while (y < yEnd)
			{
				glVertex2f(start.x, y);
				++y;
			}
		}
		else
		{
			int x = start.x;
			int xEnd = end.x;
			if (start.x > end.x)
			{
				x = end.x;
				xEnd = start.x;
			}
			while (x < xEnd)
			{
				glVertex2f(x, start.y);
				x++;
			}
		}
		glEnd();
		glFlush();
		return;
	}

	if (start.x > end.x)
		std::swap(start, end);


	float xStart = start.x;
	float yStart = start.y;
	float xEnd = end.x;
	float yEnd = end.y;


	float m = (yEnd - yStart) / (xEnd - xStart);
	if (m < 0)
	{
		float tmpX = xStart - (xEnd - xStart);
		float tmpY = yEnd;

		xEnd = xStart;
		yEnd = yStart;

		xStart = tmpX;
		yStart = tmpY;
	}

	float dx = xEnd - xStart;
	float dy = yEnd - yStart;
	float dx2 = 2 * dx;
	float dy2 = 2 * dy;
	float p = 2 * dy - dx;

	float new_m = (yEnd - yStart) / (xEnd - xStart);

	glBegin(GL_POINTS);
	if (m < 0)
		glVertex2f(2 * xEnd - xStart, yStart);
	else
		glVertex2f(xStart, yStart);
	float x = xStart;
	float y = yStart;
	if (new_m < 1 && new_m > 0)
	{
		while (x < xEnd)
		{
			++x;
			if (p < 0)
			{
				p += dy2;
				if (m < 0)
					glVertex2f(2 * xEnd - x, y);
				else
					glVertex2f(x, y);
			}
			else
			{
				p += dy2 - dx2;
				y++;
				if (m < 0)
					glVertex2f(2 * xEnd - x, y);
				else
					glVertex2f(x, y);
			}

		}
	}
	else
	{
		while (y < yEnd)
		{
			++y;
			if (p <= 0)
			{
				p += dx2;
				if (m < 0)
					glVertex2f(2 * xEnd - x, y);
				else
					glVertex2f(x, y);
			}
			else
			{
				p += dx2 - dy2;
				x++;
				if (m < 0)
					glVertex2f(2 * xEnd - x, y);
				else
					glVertex2f(x, y);
			}

		}
	}
	
	glEnd();
	glFlush();
}
