#include"Shape.h"
#include<afxwin.h>
#include <afxext.h>

class MyDocument;

class BasicObj : public Shape
{
public:
	BasicObj(CPoint, CString, int);
	virtual ~BasicObj();

	virtual void draw(CDC *);
	virtual bool pointInShape(CPoint);
	virtual void setIsSelete(bool);
	virtual bool getIsSelete();
	virtual bool shapeInRect(CPoint, CPoint);

	virtual CPoint *getMyPoint();
	virtual Port *getMyPort(int);
	virtual void objMove(int, int);
	virtual void changeObjName(CString);

	virtual void unGroup(MyDocument *);
	virtual bool isGroupClass();
	/*
	CString getObjName();
	CPoint *getMyPoint();
	int getObjDepth();
	*/
protected:
	CPoint *mypoint;
	CString name;
	int depth;
};