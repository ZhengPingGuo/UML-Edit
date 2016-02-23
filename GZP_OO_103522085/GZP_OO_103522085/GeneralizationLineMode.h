#ifndef _GENERALIZATIONMODE_H_
#define _GENERALIZATIONMODE_H_

#include"Mode.h"
#include"MyDocument.h"

class GeneralizationLineMode : public Mode
{
public:
	GeneralizationLineMode();
	virtual ~GeneralizationLineMode();

	virtual void OnLButtonDown(CPoint, MyDocument*);
	virtual void OnMouseMove(CPoint, MyDocument*);
	virtual void OnLButtonUp(CPoint, MyDocument*);
	CPoint determinePosition(CPoint*, CPoint*);
private:
	bool is_mouse_down;
	Shape *use_for_Obj;
};

#endif