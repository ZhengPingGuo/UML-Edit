#include"ClassBox.h"

ClassBox::ClassBox(CPoint point, CString name, int d)
	:BasicObj(point, name,d)
{
	arealength = 60;
	areahigh = 34;
	areahigh1 = 67;
	areahigh2 = 100;
	isselete = false;
	textx = 5;
	texty = 10;

	uprect = new CRect(point.x, point.y, point.x + arealength, point.y + areahigh);
	centerrect = new CRect(point.x, point.y + areahigh, point.x + arealength, point.y + areahigh1);
	downrect = new CRect(point.x, point.y + areahigh1, point.x + arealength, point.y + areahigh2);

	my_port[0].setRelateX(arealength / 2);
	my_port[0].setRelateY(0);
	my_port[0].setRelateObj(this);

	my_port[1].setRelateX(arealength / 2);
	my_port[1].setRelateY(areahigh2);
	my_port[1].setRelateObj(this);

	my_port[2].setRelateX(0);
	my_port[2].setRelateY(areahigh2 / 2);
	my_port[2].setRelateObj(this);

	my_port[3].setRelateX(arealength);
	my_port[3].setRelateY(areahigh2 / 2);
	my_port[3].setRelateObj(this);
}
ClassBox::~ClassBox()
{
	delete uprect;
	delete centerrect;
	delete downrect;
}

void ClassBox::draw(CDC *aDC)
{
	aDC->Rectangle(uprect);
	aDC->Rectangle(centerrect);
	aDC->Rectangle(downrect);
	aDC->TextOutW(mypoint->x + textx, mypoint->y + texty, name);

	if (isselete == 1)
	{
		CBrush brush(RGB(0, 255, 0));
		aDC->FillRect(CRect((mypoint->x + my_port[0].getRelateX() - 2), (mypoint->y + my_port[0].getRelateY() - 4), 
			(mypoint->x + my_port[0].getRelateX() + 2), (mypoint->y + my_port[0].getRelateY())), &brush);
		aDC->FillRect(CRect((mypoint->x + my_port[1].getRelateX() - 2), (mypoint->y + my_port[1].getRelateY()),
			(mypoint->x + my_port[1].getRelateX() + 2), (mypoint->y + my_port[1].getRelateY()+4)), &brush);
		aDC->FillRect(CRect((mypoint->x + my_port[2].getRelateX() - 4), (mypoint->y + my_port[2].getRelateY()-2),
			(mypoint->x + my_port[2].getRelateX()), (mypoint->y + my_port[2].getRelateY() + 2)), &brush);
		aDC->FillRect(CRect((mypoint->x + my_port[3].getRelateX()), (mypoint->y + my_port[3].getRelateY()-2),
			(mypoint->x + my_port[3].getRelateX() + 4), (mypoint->y + my_port[3].getRelateY() + 2)), &brush);
	}
}

bool ClassBox::pointInShape(CPoint point)
{
	if (point.x > mypoint->x && point.x < mypoint->x + arealength && point.y > mypoint->y && point.y < mypoint->y + areahigh2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool ClassBox::shapeInRect(CPoint p1, CPoint p2)
{
	if (p1.x > p2.x)
	{
		CPoint p3;
		p3.x = p1.x;
		p3.y = p1.y;
		p1.x = p2.x;
		p1.y = p2.y;
		p2.x = p3.x;
		p2.y = p3.y;
	}

	if (p1.y < p2.y)
	{
		if (p1.x <= mypoint->x && p1.y <= mypoint->y && p2.x >= mypoint->x + arealength && p2.y >= mypoint->y + areahigh2)
		{
			return 1;
		}
	}
	else
	{
		if (p1.x <= mypoint->x && p1.y >= mypoint->y + areahigh2 && p2.x >= mypoint->x + arealength && p2.y <= mypoint->y)
		{
			return 1;
		}
	}
	return 0;
}

void ClassBox::setIsSelete(bool is_selete)
{
	this->isselete = is_selete;
}

Port *ClassBox::getMyPort(int n)
{
	if (n > 4 || n <= 0)
		return NULL;
	switch (n)
	{
	case 1: //top
		return &my_port[0];
		break;

	case 2: //down
		return &my_port[1];
		break;

	case 3: //left
		return &my_port[2];
		break;

	case 4: //right
		return &my_port[3];
		break;

	default:
		return NULL;
		break;
	}
}

void ClassBox::objMove(int x, int y)
{
	mypoint->x += x;
	mypoint->y += y;
	this->adjustRect();
}

void ClassBox::adjustRect()
{
	uprect->SetRect(mypoint->x, mypoint->y, mypoint->x + arealength, mypoint->y + areahigh);
	centerrect->SetRect(mypoint->x, mypoint->y + areahigh, mypoint->x + arealength, mypoint->y + areahigh1);
	downrect->SetRect(mypoint->x, mypoint->y + areahigh1, mypoint->x + arealength, mypoint->y + areahigh2);
}

bool ClassBox::getIsSelete()
{
	return isselete;
}