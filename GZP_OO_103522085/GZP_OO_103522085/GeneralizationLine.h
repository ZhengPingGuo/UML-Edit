#include"LineObj.h"
#include<afxwin.h>
#include <afxext.h>
#include"Port.h"

class GeneralizationLine : public LineObj
{
public:
	GeneralizationLine(Port *, Port *);
	virtual ~GeneralizationLine();

	virtual void draw(CDC *);
	virtual bool pointInShape(CPoint);
	virtual bool shapeInRect(CPoint, CPoint);
	virtual void setIsSelete(bool);
};