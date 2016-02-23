#ifndef _USECASEBOXMODE_H_
#define _USECASEBOXMODE_H_

#include"Mode.h"
#include"MyDocument.h"

class UseCaseBoxMode : public Mode
{
public:
	UseCaseBoxMode();
	virtual ~UseCaseBoxMode();

	virtual void OnLButtonDown(CPoint, MyDocument*);
	virtual void OnMouseMove(CPoint, MyDocument*);
	virtual void OnLButtonUp(CPoint, MyDocument*);
};

#endif