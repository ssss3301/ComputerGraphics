#ifndef __Ellipse_H__
#define __Ellipse_H__

class EllipseRenderer
{
public:
	EllipseRenderer();
	virtual ~EllipseRenderer();

public:
	//minorAxis∂Ã∞Î÷·, majorAxis≥§∞Î÷·
	void setEllipseParameter(int minorAxis, int majorAxis, int xPos, int yPos);
	void render();

private:
	void ellipseMidPoint();
	void plotPoint(int x, int y);

private:
	int		m_minorAxis;
	int		m_majorAxis;
	int		m_posX;
	int		m_posY;
};


#endif //__Ellipse_H__