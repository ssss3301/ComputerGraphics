#include "GL/freeglut.h"
#include "GL/glut.h"
#include "Chapter5/GLTransform.h"

CGLTransform::CGLTransform()
{

}

CGLTransform::~CGLTransform()
{

}

void CGLTransform::translate(float tx, float ty, float tz)
{
	glTranslatef(tx, ty, tz);
}

void CGLTransform::rotate(float angle, float vx, float vy, float vz)
{
	glRotatef(angle, vx, vy, vz);
}

void CGLTransform::scale(float sx, float sy, float sz)
{
	glScalef(sx, sy, sz);
}
