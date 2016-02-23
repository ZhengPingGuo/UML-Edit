#include"SeleteMode.h"

SeleteMode::SeleteMode()
{
	is_mouse_down = 0;
	mouse_down_for_move = 0;
	chose = 0;
	ptr_for_move = NULL;
}

SeleteMode::~SeleteMode()
{

}

void SeleteMode::OnLButtonDown(CPoint point, MyDocument* doc)
{
	Shape *minidepth=NULL;
	for (int a = 0; a < doc->getContainerSize(); a++)
	{
		Shape *ptr = doc->getObjFromIndex(a);
		ptr->setIsSelete(0);
		int temp_num = ptr->pointInShape(point);
		if (temp_num == 1) //先建的深度較深
		{
			minidepth = ptr;
		}
	}
	if (minidepth == NULL)
	{
		is_mouse_down = 1;
		use_for_selete.x = point.x;
		use_for_selete.y = point.y;
	}
	else
	{
		minidepth->setIsSelete(1);
		mouse_down_for_move = 1;
		use_for_move.x = point.x;
		use_for_move.y = point.y;
		chose = 0;
		//-----------------------------
		Shape *ptr = NULL;
		int temp_num = 0;

		for (int a = 0; a < doc->getContainerSize(); a++)
		{
			ptr = doc->getObjFromIndex(a);
			temp_num = ptr->pointInShape(point);
			if (temp_num == 1 && ptr->getIsSelete() == true)
			{
				ptr_for_move = ptr;
				break;
			}
		}
		//--------------------------------
	}
}

void SeleteMode::OnMouseMove(CPoint point, MyDocument* doc)
{
	if (mouse_down_for_move == 1)
	{
		/*
		Shape *ptr = NULL;
		int temp_num = 0;
		if (chose == 0)
		{
			for (int a = 0; a < doc->getContainerSize(); a++)
			{
				ptr = doc->getObjFromIndex(a);
				temp_num = ptr->pointInShape(point);
				if (temp_num == 1 && ptr->getIsSelete() == true)
				{
					ptr_for_move = ptr;
					break;
				}
			}
		}
		*/
		ptr_for_move->objMove(point.x - use_for_move.x, point.y - use_for_move.y);
		use_for_move.x = point.x;
		use_for_move.y = point.y;
	}
}

void SeleteMode::OnLButtonUp(CPoint point, MyDocument *doc)
{
	chose = 1;
	mouse_down_for_move = 0;
	if (is_mouse_down == 1)
	{
		is_mouse_down = 0;

		Shape *ptr = NULL;
		for (int a = 0; a < doc->getContainerSize(); a++)
		{
			ptr = doc->getObjFromIndex(a);
			ptr->setIsSelete(0);
			int temp_num = ptr->shapeInRect(point, use_for_selete);
			if (temp_num == 1) 
			{
				ptr->setIsSelete(1);
			}
		}
	}
}