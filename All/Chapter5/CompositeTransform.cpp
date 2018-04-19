#include "GL/freeglut.h"
#include "GL/glut.h"
#include "Transform.h"
#include "CompositeTransform.h"
#include <math.h>

#define PI 3.1415926

CompositeTransform::CompositeTransform()
{
	m_pivotPoint = m_fixedPoint = { 0, 0 };
}

CompositeTransform::~CompositeTransform()
{

}

void CompositeTransform::transform(Point* vertices, int verticesCount, float tx, float ty, float rotateAngle, float scale)
{
	matrix3X3SetIdentity(m_compositeMatrix);

	int sumX = 0;
	int sumY = 0;
	for (int i = 0; i < verticesCount; ++i)
	{
		sumX += vertices[i].x;
		sumY += vertices[i].y;
	}

	m_pivotPoint.x = sumX / verticesCount;
	m_pivotPoint.y = sumY / verticesCount;
	m_fixedPoint = m_pivotPoint;

	glBegin(GL_POLYGON);

	rotate(m_compositeMatrix, rotateAngle);
	for (int index = 0; index < verticesCount; ++index)
	{
		glColor3f(0.0, 1.0, 0.0);
		float x = m_compositeMatrix[0][0] * vertices[index].x + m_compositeMatrix[0][1] * vertices[index].y
			+ m_compositeMatrix[0][2];
		float y = m_compositeMatrix[1][0] * vertices[index].x + m_compositeMatrix[1][1] * vertices[index].y
			+ m_compositeMatrix[1][2];
		glVertex2f(x, y);
	}

	glEnd();

	glBegin(GL_POLYGON);
	translate(m_compositeMatrix, tx, ty);
	for (int index = 0; index < verticesCount; ++index)
	{
		glColor3f(1.0f, 0.0, 0.0);
		float x = m_compositeMatrix[0][0] * vertices[index].x + m_compositeMatrix[0][1] * vertices[index].y
			+ m_compositeMatrix[0][2];
		float y = m_compositeMatrix[1][0] * vertices[index].x + m_compositeMatrix[1][1] * vertices[index].y
			+ m_compositeMatrix[1][2];
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_POLYGON);
	translate(m_compositeMatrix, 100, 100);
	Scale(m_compositeMatrix, scale);
	for (int index = 0; index < verticesCount; ++index)
	{
		glColor3f(1.0, 1.0, 0.0);
		float x = m_compositeMatrix[0][0] * vertices[index].x + m_compositeMatrix[0][1] * vertices[index].y
			+ m_compositeMatrix[0][2];
		float y = m_compositeMatrix[1][0] * vertices[index].x + m_compositeMatrix[1][1] * vertices[index].y
			+ m_compositeMatrix[1][2];
		glVertex2f(x, y);
	}
	glEnd();

}

void CompositeTransform::matrix3X3SetIdentity(Matrix3X3 mat)
{
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 3; ++col)
		{
			mat[row][col] = (row == col);
		}
	}
}

void CompositeTransform::matrixMultiply(Matrix3X3 mat1, Matrix3X3 mat2)
{
	Matrix3X3 tmp;
	matrix3X3SetIdentity(tmp);

	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 3; ++col)
		{
			float sum = 0.0f;
			for (int i = 0; i < 3; ++i)
			{
				sum += mat1[row][i] * mat2[i][col];
			}
			tmp[row][col] = sum;
		}
	}

	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 3; ++col)
		{
			mat1[row][col] = tmp[row][col];
		}
	}
}

void CompositeTransform::translate(Matrix3X3 mat, float tx, float ty)
{
	Matrix3X3 tmp;
	matrix3X3SetIdentity(tmp);
	tmp[0][2] = tx;
	tmp[1][2] = ty;

	matrixMultiply(mat, tmp);
}

void CompositeTransform::rotate(Matrix3X3 mat, float rotateAngle)
{
	Matrix3X3 tmp;
	matrix3X3SetIdentity(tmp);
	
	float radian = rotateAngle * PI / 180.0;
	tmp[0][0] = cos(radian);
	tmp[0][1] = -sin(radian);
	tmp[1][0] = sin(radian);
	tmp[1][1] = cos(radian);

	matrixMultiply(mat, tmp);
}

void CompositeTransform::Scale(Matrix3X3 mat, float scale)
{
	Matrix3X3 tmp;
	matrix3X3SetIdentity(tmp);
	tmp[0][0] = scale;
	tmp[1][1] = scale;

	matrixMultiply(mat, tmp);
}
