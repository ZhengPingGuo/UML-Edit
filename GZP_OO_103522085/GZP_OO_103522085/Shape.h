#ifndef _SHAPE_H_
#define _SHAPE_H_

#include<afxwin.h>
#include <afxext.h>
//#include"Port.h"

class Port;
class MyDocument;

class Shape
{
public:
	Shape(){}
	virtual ~Shape(){}

	virtual void draw(CDC *) = 0;
	virtual bool pointInShape(CPoint) = 0;
	virtual bool shapeInRect(CPoint, CPoint) = 0;
	virtual void setIsSelete(bool) = 0;
	virtual bool getIsSelete() = 0;
	virtual CPoint *getMyPoint() = 0;
	virtual Port *getMyPort(int) = 0;
	virtual void objMove(int, int) = 0;
	virtual void changeObjName(CString) = 0;
	virtual void unGroup(MyDocument *) = 0;
	virtual bool isGroupClass() = 0;
};

#endif