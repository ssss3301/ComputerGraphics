#include "gl/freeglut.h"
#include "gl/glut.h"
#include <algorithm>
#include "BresenhamLine.h"

BresenhamLine::BresenhamLine()
{

}

BresenhamLine::~BresenhamLine()
{

}

void BresenhamLine::drawLine(LinePoint p1, LinePoint p2)
{
	LinePoint lineStart;
	LinePoint lineEnd;
	if (p1.x > p2.x)
	{
		lineStart = p2;
		lineEnd = p1;
	}
	else
	{
		lineStart = p1;
		lineEnd = p2;
	}

	glBegin(GL_POINTS);

	int dx = lineEnd.x - lineStart.x;
	int dy = lineEnd.y - lineStart.y;
	if (dx != 0 && dy != 0)
	{
		float k = (float)dy / (float)dx;
		if (k > 1)
			line_slope_greater_1(lineStart.x, lineStart.y, lineEnd.x, lineEnd.y);
		else if (k > 0)
			line_slope_less_1(lineStart.x, lineStart.y, lineEnd.x, lineEnd.y);
		else if (k > -1)
			line_slope_greater_negative_1(lineStart.x, lineStart.y, lineEnd.x, lineEnd.y);
		else
			line_slop_less_negative_1(lineStart.x, lineStart.y, lineEnd.x, lineEnd.y);
	}
	else
	{
		line_slope_equal_0(lineStart.x, lineStart.y, lineEnd.x, lineEnd.y);
	}
	glEnd();
	glFlush();
}

void BresenhamLine::drawPolygonalLine(const std::vector<LinePoint> points)
{
	for (int i = 0; i < points.size() - 1; ++i)
	{
		LinePoint p1 = points.at(i);
		LinePoint p2 = points.at(i + 1);
		drawLine(p1, p2);
	}
}


void BresenhamLine::line_slope_greater_negative_1(int xStart, int yStart, int xEnd, int yEnd)
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

void BresenhamLine::line_slop_less_negative_1(int xStart, int yStart, int xEnd, int yEnd)
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

void BresenhamLine::line_slope_greater_1(int xStart, int yStart, int xEnd, int yEnd)
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

void BresenhamLine::line_slope_less_1(int xStart, int yStart, int xEnd, int yEnd)
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

void BresenhamLine::line_slope_equal_0(int xStart, int yStart, int xEnd, int yEnd)
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
