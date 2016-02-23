#include"Shape.h"
#include<afxwin.h>
#include <afxext.h>
#include"Port.h"
#include"BasicObj.h"

class MyDocument;

class LineObj : public Shape
{
public:
	LineObj(Port *, Port *);
	virtual ~LineObj();

	virtual void draw(CDC *);
	virtual bool pointInShape(CPoint);
	virtual bool shapeInRect(CPoint, CPoint);
	virtual void setIsSelete(bool);
	virtual bool getIsSelete();
	virtual CPoint *getMyPoint();
	virtual Port *getMyPort(int);
	virtual void objMove(int, int);
	virtual void changeObjName(CString);

	virtual void unGroup(MyDocument *);
	virtual bool isGroupClass();
protected:
	Port *head;
	Port *tail;
};