#ifndef _ASSOCIATIONLINEMODE_H_
#define _ASSOCIATIONLINEMODE_H_

#include"Mode.h"
#include"MyDocument.h"

class AssociationLineMode : public Mode
{
public:
	AssociationLineMode();
	virtual ~AssociationLineMode();

	virtual void OnLButtonDown(CPoint, MyDocument*);
	virtual void OnMouseMove(CPoint, MyDocument*);
	virtual void OnLButtonUp(CPoint, MyDocument*);
	CPoint determinePosition(CPoint*, CPoint*);
private:
	bool is_mouse_down;
	Shape *use_for_Obj;
};

#endif