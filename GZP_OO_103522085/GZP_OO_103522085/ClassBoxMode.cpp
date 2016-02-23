#include"ClassBoxMode.h"
#include"ClassBox.h"

ClassBoxMode::ClassBoxMode()
{
}

ClassBoxMode::~ClassBoxMode()
{
}

void ClassBoxMode::OnLButtonDown(CPoint point, MyDocument *doc)
{
	Shape *ptr = new ClassBox(point,_T("Empty"),99);
	doc->addObj(ptr);
}

void ClassBoxMode::OnMouseMove(CPoint point, MyDocument *doc)
{
}

void ClassBoxMode::OnLButtonUp(CPoint point, MyDocument *doc)
{
}