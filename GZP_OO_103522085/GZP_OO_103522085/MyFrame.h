#ifndef _MYFRAME_H_
#define _MYFRAME_H_

#include<afxwin.h>
#include<afxext.h>
#include "MyDialogForName.h"

class MyDialogForName;

class MyFrame : public CFrameWnd
{
public:
	MyFrame();
	~MyFrame();
	BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	CSplitterWnd * getCSplitterWnd();

	afx_msg void OnExit();
	afx_msg void OnGroup();
	afx_msg void UnGroup();
	afx_msg void ChangeName();
	void initMyDialog();

private:
	CSplitterWnd staticsplit;
	MyDialogForName *mydialog;

	DECLARE_DYNCREATE(MyFrame)
	DECLARE_MESSAGE_MAP()
};

#endif
