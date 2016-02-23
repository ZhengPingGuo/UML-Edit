#ifndef _PORT_H_
#define _PORT_H_

#include<afxwin.h>
#include <afxext.h>
//#include"Shape.h"

class Shape;

class Port
{
public:
	Port();
	~Port();

	int getRelateX();
	int getRelateY();
	void setRelateX(int);
	void setRelateY(int);
	void setRelateObj(Shape *);
	Shape *getRelateObj();
private:
	int relatex;
	int relatey;
	Shape *relation_obj;
};

#endif