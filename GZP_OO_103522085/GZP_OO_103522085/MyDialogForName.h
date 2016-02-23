#pragma once
#include"resource.h"
#include <afxcontrolbars.h>
#include"MyFrame.h"
#include"Shape.h"

class MyFrame;
// MyDialogForName ��ܤ��

class MyDialogForName : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialogForName)

public:
	MyDialogForName(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~MyDialogForName();

// ��ܤ�����
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	void setFrame(MyFrame *);
	void setObjForChangeName(Shape *);


private:
	MyFrame *frame;
	Shape *obj_for_change_name;
};
