#ifndef __EX32_H__
#define __EX32_H__

#include "../../Define.h"

class Ex32
{
public:
	Ex32();
	virtual ~Ex32();

public:
	void drawLineWithBresenham(LinePoint start, LinePoint end);
};

#endif //__EX32_H__