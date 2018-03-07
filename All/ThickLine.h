#ifndef __ThickLine_H__
#define __ThickLine_H__

#include "Define.h"

class ThickLine
{
public:
	static void drawLine(LinePoint p1, LinePoint p2, int lineWidth);

protected:
	ThickLine();
	virtual ~ThickLine();

private:
	static void line_slope_greater_negative_1(LinePoint start, LinePoint end, float slope, int lineWidth);
	static void line_slop_less_negative_1(LinePoint start, LinePoint end, float slope, int lineWidth);
	static void line_slope_greater_1(LinePoint start, LinePoint end, float slope, int lineWidth);
	static void line_slope_less_1(LinePoint start, LinePoint end, float slope, int lineWidth);
	static void line_slope_equal_0(LinePoint start, LinePoint end, float slope, int lineWidth);

private:
	static void point_bold_vertical(LinePoint lineStartPoint, LinePoint lineEndPoint, LinePoint currentPoint
		, float lineSlope, int width, bool b, bool bAddCap = true);
	static void point_bold_horizontal(LinePoint lineStartPoint, LinePoint lineEndPoint, LinePoint currentPoint
		, float lineSlope, int width, bool b, bool bAddCap = true);
	static void procLineCap(LinePoint linePoint, int& x, int& y, float slope, int lineWidth, bool greaterZero);

	static void calcSymmetricPoint(int& x, int& y, float lineSlope, float b);
};

#endif //__ThickLine_H__