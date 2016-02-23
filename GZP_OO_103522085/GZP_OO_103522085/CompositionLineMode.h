#ifndef _COMPOSITIONLINEMODE_H_
#define _COMPOSITIONLINEMODE_H_

#include"Mode.h"
#include"MyDocument.h"

class CompositionLineMode : public Mode
{
public:
	CompositionLineMode();
	virtual ~CompositionLineMode();

	virtual void OnLButtonDown(CPoint, MyDocument*);
	virtual void OnMouseMove(CPoint, MyDocument*);
	virtual void OnLButtonUp(CPoint, MyDocument*);
	CPoint determinePosition(CPoint*, CPoint*);
private:
	bool is_mouse_down;
	Shape *use_for_Obj;
};

#endif