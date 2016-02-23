#ifndef _BUTTONPANEL_H_
#define _BUTTONPANEL_H_

#ifndef BUTTONNUMBER
#define BUTTONNUMBER 6
#endif

#include<afxwin.h>
#include<afxext.h>
#include<vector>
#include"MyButton.h"

class ButtonPanel : public CView
{
public:
	ButtonPanel();
	virtual ~ButtonPanel();

	void OnDraw(CDC *aDC);
	void buttonControl(MyButton *); //���U���s����ӫ��sdisable��Lenable
	int getButtonPanelSize();
	MyButton *findButton(int);
	virtual void OnInitialUpdate(); //��l��-�Ыث��s

	afx_msg void clickMyButton0();
	afx_msg void clickMyButton1();
	afx_msg void clickMyButton2();
	afx_msg void clickMyButton3();
	afx_msg void clickMyButton4();
	afx_msg void clickMyButton5();

private:
	std::vector<MyButton *> my_button_panel; //�x�s���s
	static LPCTSTR buttonname[BUTTONNUMBER]; //���s�W��

	DECLARE_DYNCREATE(ButtonPanel)
	DECLARE_MESSAGE_MAP()
};

#endif