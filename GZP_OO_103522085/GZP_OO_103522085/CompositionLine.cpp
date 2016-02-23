#include"CompositionLine.h"

CompositionLine::CompositionLine(Port *p1, Port *p2)
	:LineObj(p1,p2)
{

}

CompositionLine::~CompositionLine()
{

}

void CompositionLine::draw(CDC *aDC)
{
	int temp_num = 0;
	for (int a = 1; a < 5; a++)
	{
		Port *ptr = tail->getRelateObj()->getMyPort(a);
		if (ptr != NULL)
		{
			if (ptr == tail)
				temp_num = a;
		}
	}
	switch (temp_num)
	{
	case 1:
		aDC->MoveTo(((head->getRelateObj())->getMyPoint())->x + (head->getRelateX()), ((head->getRelateObj())->getMyPoint())->y + (head->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) -8);
		aDC->MoveTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) -4 , ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) -4);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) , ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) -8);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) +4, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) - 4);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		break;
	case 2:
		aDC->MoveTo(((head->getRelateObj())->getMyPoint())->x + (head->getRelateX()), ((head->getRelateObj())->getMyPoint())->y + (head->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) + 8);
		aDC->MoveTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) - 4, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) + 4);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) + 8);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) + 4, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) + 4);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		break;
	case 3:
		aDC->MoveTo(((head->getRelateObj())->getMyPoint())->x + (head->getRelateX()), ((head->getRelateObj())->getMyPoint())->y + (head->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) -8, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		aDC->MoveTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) - 4, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) - 4);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) -8, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) - 4, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) + 4);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		break;
	case 4:
		aDC->MoveTo(((head->getRelateObj())->getMyPoint())->x + (head->getRelateX()), ((head->getRelateObj())->getMyPoint())->y + (head->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) +8, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		aDC->MoveTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) + 4, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) - 4);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) +8 , ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) + 4, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) + 4);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		break;
	default:
		break;
	}
}

bool CompositionLine::pointInShape(CPoint point)
{
	return 0;
}
bool CompositionLine::shapeInRect(CPoint p1, CPoint p2)
{
	return 0;
}

void CompositionLine::setIsSelete(bool b)
{

}