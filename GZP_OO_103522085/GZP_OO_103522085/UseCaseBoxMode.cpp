#include"UseCaseBoxMode.h"
#include"UseCaseBox.h"

UseCaseBoxMode::UseCaseBoxMode()
{
}

UseCaseBoxMode::~UseCaseBoxMode()
{
}

void UseCaseBoxMode::OnLButtonDown(CPoint point, MyDocument *doc)
{
	Shape *ptr = new UseCaseBox(point, _T("Empty"), 99);
	doc->addObj(ptr);
}

void UseCaseBoxMode::OnMouseMove(CPoint point, MyDocument *doc)
{
}

void UseCaseBoxMode::OnLButtonUp(CPoint point, MyDocument *doc)
{
}