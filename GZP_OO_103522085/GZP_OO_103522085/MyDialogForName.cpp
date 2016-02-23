// MyDialogForName.cpp : 實作檔
//

#include "stdafx.h"
#include "MyDialogForName.h"
#include "afxdialogex.h"


// MyDialogForName 對話方塊

IMPLEMENT_DYNAMIC(MyDialogForName, CDialogEx)

MyDialogForName::MyDialogForName(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDialogForName::IDD, pParent)
{

}

MyDialogForName::~MyDialogForName()
{
}

void MyDialogForName::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDialogForName, CDialogEx)
	ON_BN_CLICKED(IDOK, &MyDialogForName::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &MyDialogForName::OnBnClickedCancel)
END_MESSAGE_MAP()


// MyDialogForName 訊息處理常式


void MyDialogForName::OnBnClickedOk()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString strValue;
	GetDlgItem(IDC_EDIT1)->GetWindowText(strValue);
	obj_for_change_name->changeObjName(strValue);

	frame->initMyDialog();
	CDialogEx::OnOK();
}


void MyDialogForName::OnBnClickedCancel()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	MessageBox(_T("取消改名"));
	frame->initMyDialog();
	CDialogEx::OnCancel();
}

void MyDialogForName::setFrame(MyFrame *f)
{
	frame = f;
}

void MyDialogForName::setObjForChangeName(Shape *s)
{
	obj_for_change_name = s;
}

