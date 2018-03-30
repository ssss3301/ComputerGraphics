#include "Ex3.3.h"
#include "Ex3.2.h"
#include "gl/freeglut.h"
#include "gl/glut.h"

Ex33::Ex33()
{

}

Ex33::~Ex33()
{

}

void Ex33::drawPolyLine(const std::vector<LinePoint>& points)
{
	if (points.size() <= 0)
		return;

	if (points.size() == 1)
	{
		glBegin(GL_POINTS);
		glVertex2f(points[0].x, points[0].y);
		glEnd();
		glFlush();
	}

	Ex32 ex32;
	LinePoint start = points.at(0);
	for (int i = 1; i < points.size(); ++i)
	{
		LinePoint end = points.at(i);
		ex32.drawLineWithBresenham(start, end);
		start = end;
	}
}
