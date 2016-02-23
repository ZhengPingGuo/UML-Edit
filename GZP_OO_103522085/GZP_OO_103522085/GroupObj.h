#include"Shape.h"
#include<vector>
#include"MyDocument.h"

class GroupObj : public Shape
{
public:
	GroupObj();
	virtual ~GroupObj();

	virtual void draw(CDC *);
	virtual bool pointInShape(CPoint);
	virtual bool shapeInRect(CPoint, CPoint);
	virtual void setIsSelete(bool);
	virtual bool getIsSelete();
	virtual CPoint *getMyPoint();
	virtual Port *getMyPort(int);
	virtual void objMove(int, int);
	virtual void changeObjName(CString);
	void addObj(Shape*);

	virtual void unGroup(MyDocument *);
	virtual bool isGroupClass();

private:
	std::vector<Shape*> obj_vect;
};