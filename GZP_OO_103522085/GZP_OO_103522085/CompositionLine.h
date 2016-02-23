#include"LineObj.h"
#include<afxwin.h>
#include <afxext.h>
#include"Port.h"

class CompositionLine : public LineObj
{
public:
	CompositionLine(Port *, Port *);
	virtual ~CompositionLine();

	virtual void draw(CDC *);
	virtual bool pointInShape(CPoint);
	virtual bool shapeInRect(CPoint, CPoint);
	virtual void setIsSelete(bool);
};