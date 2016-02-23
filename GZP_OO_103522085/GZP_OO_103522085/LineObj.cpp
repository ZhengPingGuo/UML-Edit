#include"LineObj.h"

LineObj::LineObj(Port *p1, Port *p2)
:head(p1), tail(p2)
{
}

LineObj::~LineObj()
{
	if (head != NULL)
	{
		delete head;
	}
	if (tail != NULL)
	{
		delete head;
	}
}

void LineObj::draw(CDC *aDC)
{

}
bool LineObj::pointInShape(CPoint point)
{
	return 0;
}

bool LineObj::shapeInRect(CPoint p1, CPoint p2)
{
	return 0;
}

void LineObj::setIsSelete(bool)
{

}

CPoint *LineObj::getMyPoint()
{
	return NULL;
}

Port *LineObj::getMyPort(int n)
{
	return NULL;
}

void LineObj::objMove(int, int)
{

}

bool LineObj::getIsSelete()
{
	return false;
}

void LineObj::changeObjName(CString)
{

}

void LineObj::unGroup(MyDocument *)
{

}

bool LineObj::isGroupClass()
{
	return false;
}