#ifndef __GLTransform_H__
#define __GLTransform_H__

class CGLTransform
{
public:
	CGLTransform();
	virtual ~CGLTransform();

public:
	void translate(float tx, float ty, float tz);
	void rotate(float angle, float vx, float vy, float vz);
	void scale(float sx, float sy, float sz);
};

#endif