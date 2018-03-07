#include "gl/freeglut.h"
#include "gl/glut.h"
#include "ThickLine.h"
#include <algorithm>

void ThickLine::drawLine(LinePoint p1, LinePoint p2, int lineWidth)
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
			line_slope_greater_1(lineStart, lineEnd, k, lineWidth);
		else if (k > 0)
			line_slope_less_1(lineStart, lineEnd, k, lineWidth);
		else if (k > -1)
			line_slope_greater_negative_1(lineStart, lineEnd, k, lineWidth);
		else
			line_slop_less_negative_1(lineStart, lineEnd, k, lineWidth);

	}
	else
	{
		line_slope_equal_0(lineStart, lineEnd, 0, lineWidth);
	}
	glEnd();
	glFlush();
}

ThickLine::ThickLine()
{

}

ThickLine::~ThickLine()
{

}

void ThickLine::line_slope_greater_negative_1(LinePoint start, LinePoint end, float slope, int lineWidth)
{
	int dx = std::abs(end.x - start.x);
	int dy = std::abs(end.y - start.x);
	int p = dx;

	int x, y, xEnd;
	if (start.x > end.x)
	{
		x = end.x;
		y = end.y;
		xEnd = start.x;
		std::swap(start, end);
	}
	else
	{
		x = start.x;
		y = start.y;
		xEnd = end.x;
	}

	bool b = (start.y > end.y);

	glVertex2f(x, y);
	LinePoint currentPoint;
	currentPoint.x = x;
	currentPoint.y = y;
	point_bold_vertical(start, end, currentPoint, slope, lineWidth, b);
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
		currentPoint.x = x;
		currentPoint.y = y;
		point_bold_vertical(start, end, currentPoint, slope, lineWidth, b);
	}
}

void ThickLine::line_slop_less_negative_1(LinePoint start, LinePoint end, float slope, int lineWidth)
{
	int dx = std::abs(end.x - start.x);
	int dy = std::abs(end.y - start.y);
	int p = -dy;

	int x, y, yEnd;
	if (start.y > end.y)
	{
		x = end.x;
		y = end.y;
		yEnd = start.y;
		std::swap(start, end);
	}
	else
	{
		x = start.x;
		y = start.y;
		yEnd = end.y;
	}

	bool b = (start.y > end.y);

	glVertex2f(x, y);
	LinePoint currentPoint;
	currentPoint.x = x;
	currentPoint.y = y;
	point_bold_horizontal(start, end, currentPoint, slope, lineWidth, b);
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
		currentPoint.x = x;
		currentPoint.y = y;
		point_bold_horizontal(start, end, currentPoint, slope, lineWidth, b);
	}
}

void ThickLine::line_slope_greater_1(LinePoint start, LinePoint end, float slope, int lineWidth)
{
	int dx = std::abs(end.x - start.x);
	int dy = std::abs(end.y - start.y);
	int p = 2 * dx - dy;

	int x, y, yEnd;
	if (start.y > end.y)
	{
		x = end.x;
		y = end.y;
		yEnd = start.y;
		std::swap(start, end);
	}
	else
	{
		x = start.x;
		y = start.y;
		yEnd = end.y;
	}

	bool b = (start.y > end.y);

	glVertex2f(x, y);
	LinePoint currentPoint;
	currentPoint.x = x;
	currentPoint.y = y;
	point_bold_horizontal(start, end, currentPoint, slope, lineWidth, b);
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
		currentPoint.x = x;
		currentPoint.y = y;
		point_bold_horizontal(start, end, currentPoint, slope, lineWidth, b);
	}
}

void ThickLine::line_slope_less_1(LinePoint start, LinePoint end, float slope, int lineWidth)
{
	int dx = std::abs(end.x - start.x);
	int dy = std::abs(end.y - start.y);
	int two_dx = 2 * dx;
	int two_dy = 2 * dy;
	int twoDy_dx = two_dy - dx;
	int twoDy_twoDx = two_dy - two_dx;
	int p = twoDy_dx;

	int x, y, xEnd;
	if (start.x > end.x)
	{
		x = end.x;
		y = end.y;
		xEnd = start.x;
		std::swap(start, end);
	}
	else
	{
		x = start.x;
		y = start.y;
		xEnd = end.x;
	}

	bool b = (start.y > end.y);

	glVertex2f(x, y);
	LinePoint currentPoint;
	currentPoint.x = x;
	currentPoint.y = y;
	point_bold_vertical(start, end, currentPoint, slope, lineWidth, b);
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
		currentPoint.x = x;
		currentPoint.y = y;
		point_bold_vertical(start, end, currentPoint, slope, lineWidth, b);
	}

}

void ThickLine::line_slope_equal_0(LinePoint start, LinePoint end, float slope, int lineWidth)
{
	int dx = std::abs(end.x - start.x);
	int dy = std::abs(end.y - start.y);

	LinePoint pt;
	int x, y, steps;
	if (dx == 0)
	{
		if (start.y > end.y)
		{
			y = end.y;
			steps = start.y - end.y;
		}
		else
		{
			y = start.x;
			steps = end.y - start.y;
		}
		glVertex2f(start.x, y);
		pt.x = start.x;
		pt.y = y;
		point_bold_horizontal(start, end, pt, 0, lineWidth, false, false);
		for (int i = 0; i < steps; ++i)
		{
			y++;
			glVertex2f(start.x, y);
			pt.x = start.x;
			pt.y = y;
			point_bold_horizontal(start, end, pt, 0, lineWidth, false, false);
		}
	}
	else
	{
		if (start.x > end.x)
		{
			x = end.x;
			steps = start.x - end.x;
		}
		else
		{
			x = start.x;
			steps = end.x - start.x;
		}
		glVertex2f(x, start.y);
		pt.x = x;
		pt.y = start.y;
		point_bold_vertical(start, end, pt, 0, lineWidth, false, false);
		for (int i = 0; i < steps; ++i)
		{
			x++;
			glVertex2f(x, start.y);
			pt.x = x;
			pt.y = start.y;
			point_bold_vertical(start, end, pt, 0, lineWidth, false, false);
		}
	}

}


void ThickLine::point_bold_vertical(LinePoint lineStartPoint, LinePoint lineEndPoint, LinePoint currentPoint
	, float lineSlope, int width, bool b, bool bAddCap)
{
	int below = currentPoint.y - 1;
	int Above = currentPoint.y + 1;
	for (int i = 0; i < width - 1; ++i)
	{
		int tx = currentPoint.x;
		int ty;
		if (i % 2 == 0)
		{
			ty = Above;
			if (bAddCap)
			{
				procLineCap(lineStartPoint, tx, ty, lineSlope, width, b);
				procLineCap(lineEndPoint, tx, ty, lineSlope, width, !b);
			}
			glVertex2f(tx, ty);
			Above += 1;
		}
		else
		{
			ty = below;
			if (bAddCap)
			{
				procLineCap(lineStartPoint, tx, ty, lineSlope, width, b);
				procLineCap(lineEndPoint, tx, ty, lineSlope, width, !b);
			}
			glVertex2f(tx, ty);
			below -= 1;
		}
	}
}

void ThickLine::point_bold_horizontal(LinePoint lineStartPoint, LinePoint lineEndPoint, LinePoint currentPoint
	, float lineSlope, int width, bool b, bool bAddCap)
{
	int left = currentPoint.x - 1;
	int right = currentPoint.x + 1;
	for (int i = 0; i < width - 1; ++i)
	{
		int tx;
		int ty = currentPoint.y;
		if (i % 2 == 0)
		{
			tx = left;
			if (bAddCap)
			{
				procLineCap(lineStartPoint, tx, ty, lineSlope, width, b);
				procLineCap(lineEndPoint, tx, ty, lineSlope, width, !b);
			}
			glVertex2f(tx, ty);
			left -= 1;
		}
		else
		{
			tx= right;
			if (bAddCap)
			{
				procLineCap(lineStartPoint, tx, ty, lineSlope, width, b);
				procLineCap(lineEndPoint, tx, ty, lineSlope, width, !b);
			}
			glVertex2f(tx, ty);
			right += 1;
		}
	}

}

void ThickLine::procLineCap(LinePoint linePoint,int& x, int& y, float slope, int lineWidth
	, bool greaterZero)
{
	float b1 = linePoint.y - slope * linePoint.x; // y = mx + b

	float m = (-1) / slope;
	float b2 = linePoint.y - m * linePoint.x; // y = (-1)* x / m + b;

	bool bCalcSymmetricPoint = false;
	if (greaterZero)
	{
		if (y - (m * x + b2) > 0)
			bCalcSymmetricPoint = true;
	}
	else
	{
		if (y - (m * x + b2) < 0)
			bCalcSymmetricPoint = true;
	}

	if (bCalcSymmetricPoint)
	{
		calcSymmetricPoint(x, y, slope, b1);
		calcSymmetricPoint(x, y, m, b2);
	}
}

void ThickLine::calcSymmetricPoint(int& x, int& y, float lineSlope, float b)
{
	float divisor = lineSlope * lineSlope + 1;
	float polynomialValue = lineSlope * x - y + b;
	float symmetricPointX = x - 2 * lineSlope * polynomialValue / divisor;
	float symmetricPointY = y - 2 * (-1) * polynomialValue / divisor;
	
	x = std::round(symmetricPointX);
	y = std::round(symmetricPointY);
}