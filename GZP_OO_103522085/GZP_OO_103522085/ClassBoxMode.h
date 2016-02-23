#ifndef _CLASSBOXMODE_H_
#define _CLASSBOXMODE_H_

#include"Mode.h"
#include"MyDocument.h"

class ClassBoxMode : public Mode
{
public:
	ClassBoxMode();
	virtual ~ClassBoxMode();

	virtual void OnLButtonDown(CPoint, MyDocument*);
	virtual void OnMouseMove(CPoint, MyDocument*);
	virtual void OnLButtonUp(CPoint, MyDocument*);
};

#endif