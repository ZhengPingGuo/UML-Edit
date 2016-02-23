#include"BasicObj.h"
#include<afxwin.h>
#include <afxext.h>
#include"Port.h"

class UseCaseBox : public BasicObj
{
public:
	UseCaseBox(CPoint, CString, int);
	virtual ~UseCaseBox();

	virtual void draw(CDC *);
	virtual bool pointInShape(CPoint);
	virtual void setIsSelete(bool);
	virtual bool getIsSelete();
	virtual bool shapeInRect(CPoint, CPoint);
	virtual Port *getMyPort(int);
	virtual void objMove(int, int);
	void adjustRect();
private:
	int textx;
	int texty;
	int arealength;
	int areahigh;
	BOOL isselete;
	CRect *myuserect;
	Port my_port[4];
};