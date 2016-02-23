#ifndef _MYDOCUMENT_H_
#define _MYDOCUMENT_H_

#include<afxwin.h>
#include <afxext.h>
#include <vector>
#include "Shape.h"

class MyDocument : public CDocument
{
public:
	MyDocument();
	~MyDocument();

	void addObj(Shape *);
	void rmObj(Shape *);
	int getContainerSize();
	Shape *getObjFromIndex(int);
	void deleteObjFromIndex(int);

private:
	std::vector<Shape *> mycontainer;

	DECLARE_DYNCREATE(MyDocument)
	DECLARE_MESSAGE_MAP()
};

#endif