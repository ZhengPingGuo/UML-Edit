#include"AssociationLine.h"

AssociationLine::AssociationLine(Port *p1, Port *p2)
	:LineObj(p1,p2)
{

}

AssociationLine::~AssociationLine()
{

}

void AssociationLine::draw(CDC *aDC)
{
	aDC->MoveTo(((head->getRelateObj())->getMyPoint())->x + (head->getRelateX()), ((head->getRelateObj())->getMyPoint())->y + (head->getRelateY()));
	aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
}

bool AssociationLine::pointInShape(CPoint point)
{
	return 0;
}
bool AssociationLine::shapeInRect(CPoint p1, CPoint p2)
{
	return 0;
}

void AssociationLine::setIsSelete(bool b)
{

}