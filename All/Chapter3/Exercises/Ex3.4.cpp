#include "Ex3.4.h"
#include "gl/freeglut.h"
#include "gl/glut.h"
#include <algorithm>

Ex34::Ex34()
{

}

Ex34::~Ex34()
{

}

void Ex34::drawLineWithMidPoint(LinePoint start, LinePoint end)
{
	if (start.x > end.x)
		std::swap(start, end);

	int dx = end.x - start.x;
	int dy = end.y - start.y;
	float p = dx / 2.0f - dy;

	glBegin(GL_POINTS);

	int x = start.x;
	int y = start.y;

	glVertex2f(x, y);
	while (x < end.x)
	{
		++x;
		if (p < 0)
		{
			++y;
			p += dx - dy;
			glVertex2f(x, y);
		}
		else
		{
			p += -dy;
			glVertex2f(x, y);
		}
	}
	glEnd();
	glFlush();
}
