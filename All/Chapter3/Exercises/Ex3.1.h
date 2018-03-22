#ifndef __EX3_1_H__
#define __EX3_1_H__

#include <vector>
#include "../../Define.h"

class Ex31
{
public:
	Ex31();
	virtual ~Ex31();

public:
	void drawPolyLine_DDA(std::vector<LinePoint> points);
};


#endif //__EX3_1_H__