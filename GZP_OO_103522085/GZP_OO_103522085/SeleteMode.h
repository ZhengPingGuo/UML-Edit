#ifndef _SELETEMODE_H_
#define _SELETEMODE_H_

#include"Mode.h"
#include"MyDocument.h"

class SeleteMode : public Mode
{
public:
	SeleteMode();
	virtual ~SeleteMode();

	virtual void OnLButtonDown(CPoint, MyDocument*);
	virtual void OnMouseMove(CPoint, MyDocument*);
	virtual void OnLButtonUp(CPoint, MyDocument*);

private:
	bool is_mouse_down;
	bool mouse_down_for_move;
	bool chose;
	Shape *ptr_for_move;
	CPoint use_for_selete;
	CPoint use_for_move;
};

#endif