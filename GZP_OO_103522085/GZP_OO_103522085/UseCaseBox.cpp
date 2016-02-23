#include"UseCaseBox.h"

UseCaseBox::UseCaseBox(CPoint point, CString name, int d)
	:BasicObj(point, name, d)
{
	textx = 20;
	texty = 15;
	arealength = 100;
	areahigh = 50;
	isselete = false;

	myuserect = new CRect(point.x, point.y, point.x + arealength, point.y + areahigh);

	my_port[0].setRelateX(arealength / 2);
	my_port[0].setRelateY(0);
	my_port[0].setRelateObj(this);

	my_port[1].setRelateX(arealength / 2);
	my_port[1].setRelateY(areahigh);
	my_port[1].setRelateObj(this);

	my_port[2].setRelateX(0);
	my_port[2].setRelateY(areahigh / 2);
	my_port[2].setRelateObj(this);

	my_port[3].setRelateX(arealength);
	my_port[3].setRelateY(areahigh / 2);
	my_port[3].setRelateObj(this);
}
UseCaseBox::~UseCaseBox()
{
	delete myuserect;
}

void UseCaseBox::draw(CDC *aDC)
{
	aDC->Ellipse(myuserect);
	aDC->TextOutW(mypoint->x + textx, mypoint->y + texty, name);

	if (isselete == 1)
	{
		CBrush brush(RGB(0, 255, 0));
		aDC->FillRect(CRect((mypoint->x + my_port[0].getRelateX() - 2), (mypoint->y + my_port[0].getRelateY() - 4),
			(mypoint->x + my_port[0].getRelateX() + 2), (mypoint->y + my_port[0].getRelateY())), &brush);
		aDC->FillRect(CRect((mypoint->x + my_port[1].getRelateX() - 2), (mypoint->y + my_port[1].getRelateY()),
			(mypoint->x + my_port[1].getRelateX() + 2), (mypoint->y + my_port[1].getRelateY() + 4)), &brush);
		aDC->FillRect(CRect((mypoint->x + my_port[2].getRelateX() - 4), (mypoint->y + my_port[2].getRelateY() - 2),
			(mypoint->x + my_port[2].getRelateX()), (mypoint->y + my_port[2].getRelateY() + 2)), &brush);
		aDC->FillRect(CRect((mypoint->x + my_port[3].getRelateX()), (mypoint->y + my_port[3].getRelateY() - 2),
			(mypoint->x + my_port[3].getRelateX() + 4), (mypoint->y + my_port[3].getRelateY() + 2)), &brush);
	}
}

bool UseCaseBox::pointInShape(CPoint point)
{
	if (point.x > mypoint->x && point.x < mypoint->x + arealength && point.y > mypoint->y && point.y < mypoint->y + areahigh)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool UseCaseBox::shapeInRect(CPoint p1, CPoint p2)
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
		if (p1.x <= mypoint->x && p1.y <= mypoint->y && p2.x >= mypoint->x + arealength && p2.y >= mypoint->y + areahigh)
		{
			return 1;
		}
	}
	else
	{
		if (p1.x <= mypoint->x && p1.y >= mypoint->y + areahigh && p2.x >= mypoint->x + arealength && p2.y <= mypoint->y)
		{
			return 1;
		}
	}
	return 0;
}

void UseCaseBox::setIsSelete(bool is_selete)
{
	this->isselete = is_selete;
}

Port *UseCaseBox::getMyPort(int n)
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

void UseCaseBox::objMove(int x, int y)
{
	mypoint->x += x;
	mypoint->y += y;
	this->adjustRect();
}

void UseCaseBox::adjustRect()
{
	myuserect->SetRect(mypoint->x, mypoint->y, mypoint->x + arealength, mypoint->y + areahigh);
}

bool UseCaseBox::getIsSelete()
{
	return isselete;
}