#include "gl/freeglut.h"
#include "gl/glut.h"
#include "Ellipse.h"

inline int round(const float a){ return int(a + 0.5); }

EllipseRenderer::EllipseRenderer()
{
	m_minorAxis = 0;
	m_majorAxis = 0;
	m_posX = 0;
	m_posY = 0;
}

EllipseRenderer::~EllipseRenderer()
{

}

void EllipseRenderer::setEllipseParameter(int minorAxis, int majorAxis, int xPos, int yPos)
{
	m_minorAxis = minorAxis;
	m_majorAxis = majorAxis;
	m_posX = xPos;
	m_posY = yPos;
}

void EllipseRenderer::render()
{
	if (m_majorAxis < m_minorAxis || m_majorAxis == 0
		|| m_minorAxis == 0)
		return;

	glBegin(GL_POINTS);
	ellipseMidPoint();
	glEnd();
	glFlush();
}

void EllipseRenderer::ellipseMidPoint()
{

	int minorAxisSquare = m_minorAxis *  m_minorAxis;
	int majorAxisSquare = m_majorAxis * m_majorAxis;
	
	//第一象限

	//斜率大于-1区域
	int x = 0;
	int y = m_minorAxis;
	int p1 = round(minorAxisSquare - majorAxisSquare * m_minorAxis + majorAxisSquare *  0.25f);
	plotPoint(x, y);
	while (minorAxisSquare * x < majorAxisSquare * y)
	{
		x++;
		if (p1 < 0)
		{
			plotPoint(x, y);
			p1 += minorAxisSquare * x + minorAxisSquare;
		}
		else
		{
			y--;
			plotPoint(x, y);
			p1 += minorAxisSquare * x - majorAxisSquare * y + minorAxisSquare;
		}
	}

	plotPoint(x, y);

	//斜率小于-1区域
	int p2 = round(minorAxisSquare * (x + 0.5) * (x + 0.5) + majorAxisSquare * (y - 1) * (y - 1)
		- minorAxisSquare * majorAxisSquare);
	while (y > 0)
	{
		y--;
		if (p2 < 0)
		{
			x++;
			p2 += 2 * minorAxisSquare * (x  + 1)- 2 * majorAxisSquare * (y + 1);
		}
		else
		{
			p2 += -2 * majorAxisSquare * (y + 1);
		}
		plotPoint(x, y);
	}

}

void EllipseRenderer::plotPoint(int x, int y)
{
	//当前点
	glVertex2f(x + m_posX, y + m_posY);

	//Y轴对称点
	glVertex2f(-x + m_posX, y + m_posY);

	//X轴对称点
	glVertex2f(x + m_posX, -y + m_posY);

	//原点对称点
	glVertex2f(-x + m_posX, -y + m_posY);
}
