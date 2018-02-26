#ifndef __BresenhamLine_H__
#define __BresenhamLine_H__

#include <vector>

typedef struct LinePoint 
{
	int x;
	int y;
};

class BresenhamLine
{
public:
	static void drawLine(LinePoint p1, LinePoint p2);
	static void drawPolygonalLine(const std::vector<LinePoint> points);

protected:
	BresenhamLine();
	virtual ~BresenhamLine();

private:
	static void line_slope_greater_negative_1(int xStart, int yStart, int xEnd, int yEnd);
	static void line_slop_less_negative_1(int xStart, int yStart, int xEnd, int yEnd);
	static void line_slope_greater_1(int xStart, int yStart, int xEnd, int yEnd);
	static void line_slope_less_1(int xStart, int yStart, int xEnd, int yEnd);
	static void line_slope_equal_0(int xStart, int yStart, int xEnd, int yEnd);
};


#endif//__BresenhamLine_H__