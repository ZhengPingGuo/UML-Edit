#include"GeneralizationLine.h"

GeneralizationLine::GeneralizationLine(Port *p1, Port *p2)
	:LineObj(p1,p2)
{

}

GeneralizationLine::~GeneralizationLine()
{

}

void GeneralizationLine::draw(CDC *aDC)
{
	//aDC->MoveTo();
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
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) -6);
		aDC->MoveTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) - 3, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) -6);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) + 3, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) - 6);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) , ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) - 3, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) - 6);
		break;
	case 2:
		aDC->MoveTo(((head->getRelateObj())->getMyPoint())->x + (head->getRelateX()), ((head->getRelateObj())->getMyPoint())->y + (head->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) +6);
		aDC->MoveTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) - 3, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) + 6);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) + 3, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) + 6);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) - 3, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) + 6);
		break;
	case 3:
		aDC->MoveTo(((head->getRelateObj())->getMyPoint())->x + (head->getRelateX()), ((head->getRelateObj())->getMyPoint())->y + (head->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) - 6, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		aDC->MoveTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) - 6, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) - 3);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) - 6, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) + 3);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) - 6, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) -3);
		break;
	case 4:
		aDC->MoveTo(((head->getRelateObj())->getMyPoint())->x + (head->getRelateX()), ((head->getRelateObj())->getMyPoint())->y + (head->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) + 6, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		aDC->MoveTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) + 6, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) - 3);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) + 6, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) + 3);
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()), ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()));
		aDC->LineTo(((tail->getRelateObj())->getMyPoint())->x + (tail->getRelateX()) + 6, ((tail->getRelateObj())->getMyPoint())->y + (tail->getRelateY()) - 3);
		break;
	default:
		break;
	}
}

bool GeneralizationLine::pointInShape(CPoint point)
{
	return 0;
}
bool GeneralizationLine::shapeInRect(CPoint p1, CPoint p2)
{
	return 0;
}

void GeneralizationLine::setIsSelete(bool b)
{

}