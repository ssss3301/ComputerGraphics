#ifndef __EX33_H__
#define __EX33_H__

#include "../../Define.h"
#include <vector>

class Ex33
{
public:
	Ex33();
	virtual ~Ex33();

public:
	void drawPolyLine(const std::vector<LinePoint>& points);
};


#endif //__EX33_H__