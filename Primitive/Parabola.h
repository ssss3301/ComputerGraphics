#ifndef __Parabola_H__
#define __Parabola_H__

class ParabolaRenderer
{
public:
	ParabolaRenderer();
	virtual ~ParabolaRenderer();

	void setParabolaFocus(int focusX, int focusY, int axisRange);
	void render();

private:
	void parabolaMidPoint();

private:
	int		m_focusX;
	int		m_focusY;
};

#endif //__Parabola_H__