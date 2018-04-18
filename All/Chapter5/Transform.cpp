#include "GL/freeglut.h"
#include "GL/glut.h"
#include "Transform.h"
#include <math.h>

#define PI 3.1415926

CTransform::CTransform()
{

}

CTransform::~CTransform()
{

}

void CTransform::translate(Point* pt, int vertices, float translate_x, float translate_y)
{
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertices; ++i)
	{
		float x = pt[i].x + translate_x;
		float y = pt[i].y + translate_y;
		glVertex2f(x, y);
	}
	glEnd();
}

void CTransform::rotate(Point* pt, int vertices, Point pivot, float angle)
{
	float radian = angle / 180.0 * PI;
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertices; ++i)
	{
		float x = (pt[i].x - pivot.x) * cos(radian) - (pt[i].y - pivot.y) * sin(radian) + pivot.x;
		float y = (pt[i].x - pivot.x) * sin(radian) + (pt[i].y - pivot.y) * cos(radian) + pivot.y;
		glVertex2f(x, y);
	}
	glEnd();
}

void CTransform::scale(Point* pt, int verices, Point fixedPoint, float scale)
{
	glBegin(GL_POLYGON);
	for (int i = 0; i < verices; ++i)
	{
		float x = pt[i].x * scale + fixedPoint.x * (1.0f - scale);
		float y = pt[i].y * scale + fixedPoint.y * (1.0f - scale);
		glVertex2f(x, y);
	}
	glEnd();
}

void CTransform::directionalScale(Point* pt, int verices, float angle, float s1, float s2)
{
	float radian = angle / 180.0 * PI;
	float cosVal = cos(radian);
	float sinVal = sin(radian);
	glBegin(GL_POLYGON);
	for (int i = 0; i < verices; ++i)
	{
		float x = (s1 * cosVal * cosVal + s2 * sinVal * sinVal) * pt[i].x
			+  (s2 - s1) * cosVal * sinVal * pt[i].y;
		float y = (-s1 * sinVal * cosVal + s2 * sinVal * cosVal) * pt[i].x
			+ (s1 * sinVal * sinVal + s2 * cosVal * cosVal) * pt[i].y;
		glVertex2f(x, y);
	}
	glEnd();
}
