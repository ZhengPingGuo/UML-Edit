#ifndef _CANVAS_H_
#define _CANVAS_H_

#include<afxwin.h>
#include<afxext.h>
#include"Mode.h"
#include"MyDocument.h"


class Canvas
{
private:
	static Canvas *uniqueInstance; //Canvas* : singleton use
	Mode *current_mode;

public:
	Canvas();
	~Canvas();
	static Canvas *getInstance();  //singleton
	void OnDraw(CDC *aDC, MyDocument*);
	void OnLButtonDown(CPoint, MyDocument*);
	void OnMouseMove(CPoint, MyDocument*);
	void OnLButtonUp(CPoint, MyDocument*);
	void setCurrentMode(Mode *);
};

#endif