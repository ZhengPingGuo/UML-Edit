#include"MyFrame.h"
#include"MyView.h"
#include"ButtonPanel.h"
#include"resource.h"
#include"GroupObj.h"

MyFrame::MyFrame()
{
	mydialog = NULL;
}
MyFrame::~MyFrame()
{
}

CSplitterWnd * MyFrame::getCSplitterWnd()
{
	return &(this->staticsplit);
}

BOOL MyFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	CSplitterWnd *split = getCSplitterWnd();
	split->CreateStatic(this, 1, 2);
	split->CreateView(0, 0, RUNTIME_CLASS(ButtonPanel), CSize(160, 400), pContext);
	split->CreateView(0, 1, RUNTIME_CLASS(MyView), CSize(300, 400), pContext);
	split->SetActivePane(0, 1);
	return TRUE;
}

afx_msg void MyFrame::OnExit()
{
	if (MessageBox(TEXT("要關閉視窗嗎?"), TEXT("提示"), MB_OKCANCEL | MB_ICONQUESTION) == 1)
	{
		DestroyWindow();
	}
}

afx_msg void MyFrame::OnGroup()
{
	MyDocument *doc = (MyDocument *)GetActiveDocument();
	int counter = 0;
	std::vector<int> temp_num;

	for (int a = 0; a < doc->getContainerSize(); a++)
	{
		Shape *ptr = doc->getObjFromIndex(a);
		int temp = ptr->getIsSelete();
		if (temp == true)
		{
			counter++;
			temp_num.push_back(a);
		}
	}
	if (counter > 1)
	{
		GroupObj *ptr = new GroupObj;
		for (int a = 0; a < temp_num.size(); a++)
		{
			ptr->addObj( doc->getObjFromIndex( temp_num[a] ) );
		}
		for (int a = temp_num.size()-1 ; a >= 0; a--)
		{
			doc->deleteObjFromIndex(temp_num[a]);
		}
		doc->addObj(ptr);
	}
	else
	{
		MessageBox(_T("需要選多個"));
	}
}

afx_msg void MyFrame::UnGroup()
{
	MyDocument *doc = (MyDocument *)GetActiveDocument();
	int counter = 0;
	int index = 0;
	Shape *curr = NULL;

	for (int a = 0; a < doc->getContainerSize(); a++)
	{
		Shape *ptr = doc->getObjFromIndex(a);
		bool temp = ptr->getIsSelete();
		if (temp == true)
		{
			counter++;
			curr = ptr;
			index = a;
		}
	}
	if (counter == 1)
	{
		if (curr->isGroupClass())
		{
			curr->unGroup(doc);
			doc->deleteObjFromIndex(index);
			delete curr;
		}
	}
}

afx_msg void MyFrame::ChangeName()
{
	MyDocument *doc = (MyDocument *)GetActiveDocument();
	int counter = 0;
	Shape *curr = NULL;

	for (int a = 0; a < doc->getContainerSize(); a++)
	{
		Shape *ptr = doc->getObjFromIndex(a);
		int temp = ptr->getIsSelete();
		if (temp == true)
		{
			counter++;
			curr = ptr;
		}
	}

	if (counter == 1)
	{
		if (mydialog == NULL)
		{
			mydialog = new MyDialogForName();
			mydialog->Create(IDD_DIALOG1, this);
			mydialog->ShowWindow(SW_SHOW);
			mydialog->setFrame(this);
			mydialog->setObjForChangeName(curr);
		}
	}
	else
	{
		MessageBox(_T("只能選一個"));
	}
}

void MyFrame::initMyDialog()
{
	mydialog = NULL;
}

IMPLEMENT_DYNCREATE(MyFrame, CFrameWnd)
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_COMMAND(ID_APP_EXIT, OnExit)
	ON_COMMAND(ID_EDIT_GROUP, OnGroup)
	ON_COMMAND(ID_EDIT_UNGROUP, UnGroup)
	ON_COMMAND(ID_EDIT_CHANGENAME, ChangeName)
END_MESSAGE_MAP()