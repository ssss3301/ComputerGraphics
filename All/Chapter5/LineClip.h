#ifndef __LineClip_H__
#define __LineClip_H__

#include "../Define.h"

class LineClip
{
public:
	void lineClip(LinePoint winMin, LinePoint winMax, LinePoint p1, LinePoint p2);
	void lineClip_Barsky(LinePoint winMin, LinePoint winMax, LinePoint p1, LinePoint p2);

private:
	int encode(LinePoint winMin, LinePoint winMax, LinePoint p);
	void swapLinePoint(LinePoint* p1, LinePoint* p2);
	void swapCode(int* code1, int* code2);

	inline bool inside(int code) { return !code; }
	inline bool reject(int code1, int code2) { return code1 & code2; }
	inline bool accpect(int code1, int code2) { return !(code1 | code2); }

	int clipTest(float p, float q, float* u1, float* u2);

private:
	const static int TopBitCode = 0x8;
	const static int BottomBitCode = 0x4;
	const static int RightBitCode = 0x2;
	const static int LeftBitCode = 0x01;
};

#endif