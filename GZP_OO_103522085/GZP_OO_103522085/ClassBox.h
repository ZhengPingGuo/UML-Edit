#include"BasicObj.h"
#include<afxwin.h>
#include <afxext.h>
#include"Port.h"

class ClassBox : public BasicObj
{
public:
	ClassBox(CPoint, CString, int);
	virtual ~ClassBox();

	virtual void draw(CDC *);
	virtual bool pointInShape(CPoint);
	virtual void setIsSelete(bool);
	virtual bool getIsSelete();
	virtual bool shapeInRect(CPoint, CPoint);
	virtual Port *getMyPort(int);
	virtual void objMove(int, int);
	void adjustRect();
private:
	int arealength;
	int areahigh;
	int areahigh1;
	int areahigh2;
	bool isselete;
	CRect *uprect;
	CRect *centerrect;
	CRect *downrect;
	int textx;
	int texty;
	Port my_port[4];
};