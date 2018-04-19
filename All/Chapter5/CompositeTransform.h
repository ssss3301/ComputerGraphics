#ifndef __CompositeTransform_H__
#define __CompositeTransform_H__

class CompositeTransform
{
	typedef GLfloat Matrix3X3[3][3];

public:
	CompositeTransform();
	virtual ~CompositeTransform();

public:
	void transform(Point* vertices, int verticesCount, float tx, float ty, float rotateAngle, float scale);

private:
	void matrix3X3SetIdentity(Matrix3X3 mat);
	void matrixMultiply(Matrix3X3 mat1, Matrix3X3 mat2);
	void translate(Matrix3X3 mat, float tx, float ty);
	void rotate(Matrix3X3 mat, float rotateAngle);
	void Scale(Matrix3X3 mat, float scale);

private:
	Matrix3X3	m_compositeMatrix;
	Point		m_pivotPoint;
	Point		m_fixedPoint;
};

#endif //__CompositeTransform_H__