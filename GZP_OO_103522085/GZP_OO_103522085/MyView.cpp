#include"MyView.h"
#include"Canvas.h"
#include"MyDocument.h"

MyView::MyView()
{
	my_aDC = NULL;
}

MyView::~MyView()
{
	if (my_aDC != NULL)
	{
		delete my_aDC;
	}
}

void MyView::OnDraw(CDC *aDC)
{
	MyDocument *doc = (MyDocument *)GetDocument();
	(Canvas::getInstance())->OnDraw(aDC, doc);
}

afx_msg void MyView::OnLButtonDown(UINT, CPoint point)
{
	MyDocument *doc = (MyDocument *)GetDocument();
	(Canvas::getInstance())->OnLButtonDown(point, doc);
	if (my_aDC == NULL)
	{
		my_aDC = new CClientDC(this);
	}
	Invalidate(true);
	this->OnDraw(my_aDC);
	/*
	CClientDC aDC(this);
	Invalidate(true);
	this->OnDraw(&aDC);
	*/
}
afx_msg void MyView::OnMouseMove(UINT, CPoint point)
{
	MyDocument *doc = (MyDocument *)GetDocument();
	(Canvas::getInstance())->OnMouseMove(point, doc);
	if (my_aDC == NULL)
	{
		my_aDC = new CClientDC(this);
	}
	Invalidate(true);
	this->OnDraw(my_aDC);
	/*
	CClientDC aDC(this);
	Invalidate(true);
	this->OnDraw(&aDC);
	*/
}

afx_msg void MyView::OnLButtonUp(UINT, CPoint point)
{
	MyDocument *doc = (MyDocument *)GetDocument();
	(Canvas::getInstance())->OnLButtonUp(point, doc);
	if (my_aDC == NULL)
	{
		my_aDC = new CClientDC(this);
	}
	Invalidate(true);
	this->OnDraw(my_aDC);
	/*
	CClientDC aDC(this);
	Invalidate(true);
	this->OnDraw(&aDC);
	*/
}


IMPLEMENT_DYNCREATE(MyView, CView)
BEGIN_MESSAGE_MAP(MyView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()