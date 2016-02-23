#pragma once
#include"resource.h"
#include <afxcontrolbars.h>
#include"MyFrame.h"
#include"Shape.h"

class MyFrame;
// MyDialogForName 對話方塊

class MyDialogForName : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialogForName)

public:
	MyDialogForName(CWnd* pParent = NULL);   // 標準建構函式
	virtual ~MyDialogForName();

// 對話方塊資料
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

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
