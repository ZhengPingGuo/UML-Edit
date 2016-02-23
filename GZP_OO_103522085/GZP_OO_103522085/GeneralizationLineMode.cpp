#include"GeneralizationLineMode.h"
#include"GeneralizationLine.h"

GeneralizationLineMode::GeneralizationLineMode()
{
	is_mouse_down = 0;
	use_for_Obj = NULL;
}

GeneralizationLineMode::~GeneralizationLineMode()
{

}

void GeneralizationLineMode::OnLButtonDown(CPoint point, MyDocument* doc)
{
	Shape *minidepth = NULL;
	for (int a = 0; a < doc->getContainerSize(); a++)
	{
		Shape *ptr = doc->getObjFromIndex(a);
		int temp_num = ptr->pointInShape(point);
		if (temp_num == 1) //先建的深度較深
		{
			minidepth = ptr;
		}
	}
	if (minidepth != NULL)
	{
		is_mouse_down = 1;
		use_for_Obj = minidepth;
	}
}

void GeneralizationLineMode::OnMouseMove(CPoint, MyDocument*)
{

}

void GeneralizationLineMode::OnLButtonUp(CPoint point, MyDocument* doc)
{
	if (is_mouse_down == 1)
	{
		is_mouse_down = 0;

		Shape *shape_ptr = NULL;
		for (int a = 0; a < doc->getContainerSize(); a++)
		{
			Shape *ptr = doc->getObjFromIndex(a);
			int temp_num = ptr->pointInShape(point);
			if (temp_num == 1) //先建的深度較深
			{
				shape_ptr = ptr;
			}
		}

		if (shape_ptr != NULL)
		{
			if (use_for_Obj != shape_ptr && !(use_for_Obj->isGroupClass()) && !(shape_ptr->isGroupClass()))
			{
				CPoint temp_num = determinePosition(use_for_Obj->getMyPoint(), shape_ptr->getMyPoint());
				GeneralizationLine *g_line = new GeneralizationLine(use_for_Obj->getMyPort(temp_num.x), shape_ptr->getMyPort(temp_num.y));
				doc->addObj(g_line);
			}
		}
	}
}
CPoint GeneralizationLineMode::determinePosition(CPoint *c1, CPoint *c2)
{
	CPoint p;
	
	if (c1->x <= c2->x)
	{
		if (c1->y <= c2->y)
		{
			if (c1->y + 150 <= c2->y)
			{
				if (c1->x + 150 <= c2->x)
				{
					p.x = 4;
					p.y = 3;
				}
				else
				{
					p.x = 2;
					p.y = 1;
				}
			}
			else
			{
				if (c1->x + 150 <= c2->x)
				{
					p.x = 4;
					p.y = 3;
				}
				else
				{
					p.x = 4;
					p.y = 3;
				}
			}
		}
		else
		{
			if (c1->y - 150 <= c2->y)
			{
				if (c1->x + 150 <= c2->x)
				{
					p.x = 4;
					p.y = 3;
				}
				else
				{
					p.x = 4;
					p.y = 3;
				}
			}
			else
			{
				if (c1->x + 150 <= c2->x)
				{
					p.x = 4;
					p.y = 3;
				}
				else
				{
					p.x = 1;
					p.y = 2;
				}
			}
		}
	}
	else
	{
		if (c1->y <= c2->y)
		{
			if (c1->y + 150 <= c2->y)
			{
				if (c1->x - 150 <= c2->x)
				{
					p.x = 2;
					p.y = 1;
				}
				else
				{
					p.x = 3;
					p.y = 4;
				}
			}
			else
			{
				if (c1->x - 150 <= c2->x)
				{
					p.x = 3;
					p.y = 4;
				}
				else
				{
					p.x = 3;
					p.y = 4;
				}
			}
		}
		else
		{
			if (c1->y - 150 <= c2->y)
			{
				if (c1->x - 150 <= c2->x)
				{
					p.x = 3;
					p.y = 4;
				}
				else
				{
					p.x = 3;
					p.y = 4;
				}
			}
			else
			{
				if (c1->x - 150 <= c2->x)
				{
					p.x = 1;
					p.y = 2;
				}
				else
				{
					p.x = 3;
					p.y = 4;
				}
			}
		}
	}
	return p;
}