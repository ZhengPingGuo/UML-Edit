#ifndef _MODE_H_
#define _MODE_H_

#include<afxwin.h>
#include<afxext.h>
#include"MyDocument.h"

class Mode
{
public:
	Mode();
	virtual ~Mode();
	
	virtual void OnLButtonDown(CPoint, MyDocument*) = 0;
	virtual void OnMouseMove(CPoint, MyDocument*) = 0;
	virtual void OnLButtonUp(CPoint, MyDocument*) = 0;
};

#endif