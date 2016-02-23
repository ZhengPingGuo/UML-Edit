#include"LineObj.h"
#include<afxwin.h>
#include <afxext.h>
#include"Port.h"

class AssociationLine : public LineObj
{
public:
	AssociationLine(Port *,Port *);
	virtual ~AssociationLine();

	virtual void draw(CDC *);
	virtual bool pointInShape(CPoint);
	virtual bool shapeInRect(CPoint, CPoint);
	virtual void setIsSelete(bool);
};