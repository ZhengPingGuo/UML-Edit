#include"GroupObj.h"

GroupObj::GroupObj()
{

}

GroupObj::~GroupObj()
{

}

void GroupObj::draw(CDC *aDC)
{
	for (int a = 0; a < obj_vect.size(); a++)
	{
		obj_vect[a]->draw(aDC);
	}
}

bool GroupObj::pointInShape(CPoint point)
{
	for (int a = 0; a < obj_vect.size(); a++)
	{
		bool temp = obj_vect[a]->pointInShape(point);
		if (temp == true)
		{
			return true;
		}
	}
	return false;
}

bool GroupObj::shapeInRect(CPoint p1, CPoint p2)
{
	int counter = 0;
	for (int a = 0; a < obj_vect.size(); a++)
	{
		bool temp = obj_vect[a]->shapeInRect(p1,p2);
		if (temp == true)
		{
			counter++;
		}
	}
	if (counter == obj_vect.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GroupObj::setIsSelete(bool n)
{
	for (int a = 0; a < obj_vect.size(); a++)
	{
		obj_vect[a]->setIsSelete(n);
	}
}

bool GroupObj::getIsSelete()
{
	int counter = 0;

	for (int a = 0; a < obj_vect.size(); a++)
	{
		bool temp = obj_vect[a]->getIsSelete();
		if (temp == true)
		{
			counter++;
		}
	}
	if (counter == obj_vect.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

CPoint *GroupObj::getMyPoint()
{
	return NULL;
}

Port *GroupObj::getMyPort(int)
{
	return NULL;
}

void GroupObj::objMove(int x, int y)
{
	for (int a = 0; a < obj_vect.size(); a++)
	{
		obj_vect[a]->objMove(x,y);
	}
}

void GroupObj::changeObjName(CString)
{
}

void GroupObj::addObj(Shape *s)
{
	obj_vect.push_back(s);
}

void GroupObj::unGroup(MyDocument *doc)
{
	for (int a = 0; a < obj_vect.size(); a++)
	{
		doc->addObj(obj_vect[a]);
	}
}

bool GroupObj::isGroupClass()
{
	return true;
}