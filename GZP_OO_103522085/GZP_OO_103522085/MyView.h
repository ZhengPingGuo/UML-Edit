#include<afxwin.h>
#include<afxext.h>

class MyView : public CView
{
public:
	MyView();
	~MyView();
	void OnDraw(CDC *aDC);
	afx_msg void OnLButtonDown(UINT, CPoint point);
	afx_msg void OnMouseMove(UINT, CPoint point);
	afx_msg void OnLButtonUp(UINT, CPoint point);

private:
	CClientDC *my_aDC;

	DECLARE_DYNCREATE(MyView)
	DECLARE_MESSAGE_MAP()
};