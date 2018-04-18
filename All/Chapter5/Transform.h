#ifndef __Transform_H__
#define __Transform_H__

typedef struct Point
{
	float x;
	float y;
};

class CTransform
{
public:
	CTransform();
	virtual ~CTransform();

public:
	void translate(Point* pt, int vertices, float translate_x, float translate_y);
	void rotate(Point* pt, int vertices, Point pivot, float angle);
	void scale(Point* pt, int verices, Point fixedPoint, float scale);
	void directionalScale(Point* pt, int verices, float angle, float s1, float s2);
};

#endif