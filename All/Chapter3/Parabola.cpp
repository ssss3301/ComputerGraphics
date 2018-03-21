#include "gl/freeglut.h"
#include "gl/glut.h"
#include "Parabola.h"

ParabolaRenderer::ParabolaRenderer()
{
	m_focusX = 0;
	m_focusY = 0;
}

ParabolaRenderer::~ParabolaRenderer()
{

}

void ParabolaRenderer::setParabolaFocus(int focusX, int focusY, int axisRange)
{
	m_focusX = focusX;
	m_focusY = focusY;
}

void ParabolaRenderer::render()
{

}

void ParabolaRenderer::parabolaMidPoint()
{

}
