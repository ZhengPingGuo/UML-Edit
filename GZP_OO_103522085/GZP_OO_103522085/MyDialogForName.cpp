// MyDialogForName.cpp : ��@��
//

#include "stdafx.h"
#include "MyDialogForName.h"
#include "afxdialogex.h"


// MyDialogForName ��ܤ��

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


// MyDialogForName �T���B�z�`��


void MyDialogForName::OnBnClickedOk()
{
	// TODO:  �b���[�J����i���B�z�`���{���X
	CString strValue;
	GetDlgItem(IDC_EDIT1)->GetWindowText(strValue);
	obj_for_change_name->changeObjName(strValue);

	frame->initMyDialog();
	CDialogEx::OnOK();
}


void MyDialogForName::OnBnClickedCancel()
{
	// TODO:  �b���[�J����i���B�z�`���{���X
	MessageBox(_T("������W"));
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

