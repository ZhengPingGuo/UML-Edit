#include"Canvas.h"

Canvas::Canvas()
{
	current_mode = NULL;
}

Canvas::~Canvas()
{
	if (uniqueInstance)
	{
		delete uniqueInstance;
	}
	if (current_mode)
	{
		delete current_mode;
	}
}

Canvas *Canvas::uniqueInstance = NULL;

Canvas *Canvas::getInstance()
{
	if (uniqueInstance == NULL)
	{
		uniqueInstance = new Canvas();
	}
	return uniqueInstance;
}

void Canvas::OnDraw(CDC *aDC, MyDocument *doc)
{
	for (int a = 0; a < doc->getContainerSize(); a++)
	{
		Shape *ptr = doc->getObjFromIndex(a);
		if (ptr != NULL)
			ptr->draw(aDC);
	}
}

void Canvas::OnLButtonDown(CPoint point, MyDocument *doc)
{
	if (current_mode != NULL)
		current_mode->OnLButtonDown(point, doc);
}

void Canvas::OnMouseMove(CPoint point, MyDocument *doc)
{
	if (current_mode != NULL)
		current_mode->OnMouseMove(point, doc);
}

void Canvas::OnLButtonUp(CPoint point, MyDocument *doc)
{
	if (current_mode != NULL)
		current_mode->OnLButtonUp(point, doc);
}

void Canvas::setCurrentMode(Mode * currentmode)
{
	this->current_mode = currentmode;
}