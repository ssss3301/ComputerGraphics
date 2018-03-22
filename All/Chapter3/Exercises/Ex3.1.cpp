#include "gl/freeglut.h"
#include "gl/glut.h"
#include "Ex3.1.h"

Ex31::Ex31()
{

}

Ex31::~Ex31()
{

}

void Ex31::drawPolyLine_DDA(std::vector<LinePoint> points)
{
	if (points.size() <= 0)
		return;

	glBegin(GL_POINTS);
	
	float xStart = points[0].x;
	float yStart = points[0].y;
	glVertex2f(xStart, yStart);
	for (int i = 1; i < points.size(); ++i)
	{
		float xEnd = points[i].x;
		float yEnd = points[i].y;

		float dx = xEnd - xStart;
		float dy = yEnd - yStart;
		
		float step = (std::abs(dx) > std::abs(dy) ? std::abs(dx) : std::abs(dy));

		float xIncrease = dx / step;
		float yIncrease = dy / step;

		float x = xStart;
		float y = yStart;
		for (int j = 0; j < step; ++j)
		{
			x += xIncrease;
			y += yIncrease;
			glVertex2f(x, y);
		}

		xStart = xEnd;
		yStart = yEnd;
	}

	glEnd();
	glFlush();
}

