#include"Port.h"

Port::Port()
{
	relation_obj = NULL;
}

Port::~Port()
{

}

int Port::getRelateX()
{
	return this->relatex;
}

int Port::getRelateY()
{
	return this->relatey;
}

void Port::setRelateX(int rx)
{
	relatex = rx;
}

void Port::setRelateY(int ry)
{
	relatey = ry;
}

void Port::setRelateObj(Shape *obj)
{
	relation_obj = obj;
}

Shape *Port::getRelateObj()
{
	return relation_obj;
}