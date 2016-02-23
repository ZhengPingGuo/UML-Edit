#include"BasicObj.h"

BasicObj::BasicObj(CPoint point, CString name, int d)
{
	mypoint = new CPoint(point.x, point.y);
	depth = d;
	this->name = name;
}
BasicObj::~BasicObj()
{
	delete mypoint;
}

void BasicObj::draw(CDC *aDC)
{

}

bool BasicObj::pointInShape(CPoint point)
{
	return 0;
}

void BasicObj::setIsSelete(bool)
{

}

bool BasicObj::shapeInRect(CPoint, CPoint)
{
	return 0;
}


CPoint *BasicObj::getMyPoint()
{
	return mypoint;
}

Port *BasicObj::getMyPort(int n)
{
	return NULL;
}

void BasicObj::objMove(int, int)
{

}

bool BasicObj::getIsSelete()
{
	return false;
}

void BasicObj::changeObjName(CString myname)
{
	this->name = myname;
}

void BasicObj::unGroup(MyDocument *)
{

}

bool BasicObj::isGroupClass()
{
	return false;
}