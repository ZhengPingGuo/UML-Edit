#include"MyDocument.h"

MyDocument::MyDocument()
{
}
MyDocument::~MyDocument()
{
}

void MyDocument::addObj(Shape *obj)
{
	mycontainer.push_back(obj);
}

void MyDocument::rmObj(Shape *obj)
{
}

int MyDocument::getContainerSize()
{
	return mycontainer.size();
}

Shape *MyDocument::getObjFromIndex(int index)
{
	if (this->getContainerSize() > index)
		return mycontainer[index];
	else
		return NULL;
}

void MyDocument::deleteObjFromIndex(int index)
{
	mycontainer.erase(mycontainer.begin() + index);
}

IMPLEMENT_DYNCREATE(MyDocument, CDocument)
BEGIN_MESSAGE_MAP(MyDocument, CDocument)
END_MESSAGE_MAP()