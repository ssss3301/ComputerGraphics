#include "LineClip.h"
#include "../Chapter3/BresenhamLine.h"

void LineClip::lineClip(LinePoint winMin, LinePoint winMax, LinePoint p1, LinePoint p2)
{
	int code1 = encode(winMin, winMax, p1);
	int code2 = encode(winMin, winMax, p2);

	float m;
	bool done = false;
	bool plotLine = false;
	while (!done)
	{
		if (accpect(code1, code2))
		{
			done = true;
			plotLine = true;
		}
		else
		{
			if (reject(code1, code2))
			{
				done = true;
				plotLine = false;
			}
			else
			{
				if (inside(code1))
				{
					swapLinePoint(&p1, &p2);
					swapCode(&code1, &code2);
				}
				m = (p2.y - p1.y) / (p2.x - p1.x);

				if (code1 & LeftBitCode)
				{
					p1.x = winMin.x;
					p1.y = p2.y + (p1.x - p2.x) * m;
				} 
				else if (code1 & RightBitCode)
				{
					p1.x = winMax.x;
					p1.y = p2.y + (p1.x - p2.x) * m;
				}
				else if (code1 & BottomBitCode)
				{
					p1.y = winMin.y;
					if (p1.x != p2.x)
						p1.x = p2.x + (p1.y - p2.y) / m;
				}
				else
				{
					p1.y = winMax.y;
					if (p1.x != p2.x)
						p1.x = p2.x + (p1.y - p2.y) / m;
				}
			}
			
			code1 = encode(winMin, winMax, p1);
			code2 = encode(winMin, winMax, p2);
		}
	}

	if (plotLine)
		BresenhamLine::drawLine(p1, p2);
}


int LineClip::encode(LinePoint winMin, LinePoint winMax, LinePoint p)
{
	int code = 0x0;
	if (p.x < winMin.x)
		code = code | LeftBitCode;
	if (p.x > winMax.x)
		code = code | RightBitCode;
	if (p.y < winMin.y)
		code = code | BottomBitCode;
	if (p.y > winMax.y)
		code = code | TopBitCode;

	return code;
}

void LineClip::swapLinePoint(LinePoint* p1, LinePoint* p2)
{
	LinePoint tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void LineClip::swapCode(int* code1, int* code2)
{
	int tmp;
	tmp = *code1;
	*code1 = *code2;
	*code2 = tmp;
}

void LineClip::lineClip_Barsky(LinePoint winMin, LinePoint winMax, LinePoint p1, LinePoint p2)
{
	float u1 = 0.0f, u2 = 1.0f;
	float dx = p2.x - p1.x;
	if (clipTest(-dx, p1.x - winMin.x, &u1, &u2))
	{
		if (clipTest(dx, winMax.x - p1.x, &u1, &u2))
		{
			float dy = p2.y - p1.y;
			if (clipTest(-dy, p1.y - winMin.y, &u1, &u2))
			{
				if (clipTest(dy, winMax.y - p1.y, &u1, &u2))
				{
					if (u2 < 1.0)
					{
						p2.x = p1.x + u2 * dx;
						p2.y = p1.y + u2 * dy;
					}

					if (u1 > 0)
					{
						p1.x = p1.x + u1 * dx;
						p1.y = p1.y + u1 * dy;
					}
					
					
					BresenhamLine::drawLine(p1, p2);
				}
			}
		}
	}
}

int LineClip::clipTest(float p, float q, float* u1, float* u2)
{
	int returnValue = true;
	float r = 0.0f;
	if (p < 0.0f)
	{
		r = q / p;
		if (*u1 < r)
			*u1 = r;
		if (*u1 > *u2)
			returnValue = false;
	}
	else
	{
		if (p > 0.0f)
		{
			r = q / p;
			if (*u2 > r)
				*u2 = r;

			if (*u2 < *u1)
				returnValue = false;
		}
		else
		{
			if (q < 0)
				returnValue = false;
		}
	}

	return returnValue;
}

