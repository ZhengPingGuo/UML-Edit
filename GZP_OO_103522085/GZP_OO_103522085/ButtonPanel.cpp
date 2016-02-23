#include"ButtonPanel.h"
#include<string>
#include"ClassBoxMode.h"
#include"UseCaseBoxMode.h"
#include"SeleteMode.h"
#include"AssociationLineMode.h"
#include"GeneralizationLineMode.h"
#include"CompositionLineMode.h"

ButtonPanel::ButtonPanel()
{
}

ButtonPanel::~ButtonPanel()
{
	//釋放new出的button記憶體
	for (int counter = 0; counter < BUTTONNUMBER; counter++)
	{
		MyButton *mybutton = my_button_panel[counter];
		delete mybutton;
	}
}

void ButtonPanel::OnDraw(CDC *aDC)
{
}

//按鈕名稱
LPCTSTR ButtonPanel::buttonname[BUTTONNUMBER] = { _T("Selete"), _T("Association Line"), _T("Generalization Line"),
													_T("Composition Line"), _T("Class"), _T("Use Case") };

//初始化-創建按鈕
//將按鈕存入Panel
void ButtonPanel::OnInitialUpdate()
{
	MyButton *mybutton[6];
	mybutton[0] = new MyButton(0, this, new SeleteMode);
	mybutton[1] = new MyButton(1, this, new AssociationLineMode);
	mybutton[2] = new MyButton(2, this, new GeneralizationLineMode);
	mybutton[3] = new MyButton(3, this, new CompositionLineMode);
	mybutton[4] = new MyButton(4, this, new ClassBoxMode);
	mybutton[5] = new MyButton(5, this, new UseCaseBoxMode);

	mybutton[0]->Create(_T("Selete"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(10, 10, 150, 50), this, 10000);
	mybutton[1]->Create(_T("Association Line"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(10, 70, 150, 110), this, 10001);
	mybutton[2]->Create(_T("Generalization Line"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(10, 130, 150, 170), this, 10002);
	mybutton[3]->Create(_T("Composition Line"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(10, 190, 150, 230), this, 10003);
	mybutton[4]->Create(_T("Class"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(10, 250, 150, 290), this, 10004);
	mybutton[5]->Create(_T("Use Case"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(10, 310, 150, 350), this, 10005);

	my_button_panel.push_back(mybutton[0]);
	my_button_panel.push_back(mybutton[1]);
	my_button_panel.push_back(mybutton[2]);
	my_button_panel.push_back(mybutton[3]);
	my_button_panel.push_back(mybutton[4]);
	my_button_panel.push_back(mybutton[5]);
	/*
	CPoint LTposition(10, 10), RDposition(150,50);
	int id = 10000;

	for (int counter = 0; counter < BUTTONNUMBER; counter++, LTposition.y += 60, RDposition.y += 60,id++)
	{
		MyButton *mybutton = new MyButton(counter,this); //counter -> button id 
		mybutton->Create(ButtonPanel::buttonname[counter], WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(LTposition.x, LTposition.y, RDposition.x, RDposition.y),
			this, id); //(id + counter) -> GUI button id 
		my_button_panel.push_back(mybutton);
	}
	*/
}

MyButton * ButtonPanel::findButton(int id)
{
	MyButton *ptr = NULL;
	for (int a = 0; a < this->getButtonPanelSize(); a++)
	{
		if (this->my_button_panel[a]->getMyButtonID() == id)
		{
			ptr = this->my_button_panel[a];
		}
	}
	return ptr;
}

void ButtonPanel::buttonControl(MyButton *ptr)
{
	for (int a = 0; a < this->getButtonPanelSize(); a++)
	{
		if (this->my_button_panel[a] == ptr)
		{
			this->my_button_panel[a]->EnableWindow(false);
		}
		else
		{
			this->my_button_panel[a]->EnableWindow(true);
		}
	}
}

int ButtonPanel::getButtonPanelSize()
{
	return (this->my_button_panel).size();
}

afx_msg void ButtonPanel::clickMyButton0()
{
	MyButton *ptr = findButton(0);
	this->buttonControl(ptr);
	ptr->setCanvasCurrentMode();
}

afx_msg void ButtonPanel::clickMyButton1()
{
	MyButton *ptr = findButton(1);
	this->buttonControl(ptr);
	ptr->setCanvasCurrentMode();
}

afx_msg void ButtonPanel::clickMyButton2()
{
	MyButton *ptr = findButton(2);
	this->buttonControl(ptr);
	ptr->setCanvasCurrentMode();
}

afx_msg void ButtonPanel::clickMyButton3()
{
	MyButton *ptr = findButton(3);
	this->buttonControl(ptr);
	ptr->setCanvasCurrentMode();
}

afx_msg void ButtonPanel::clickMyButton4()
{
	MyButton *ptr = findButton(4);
	this->buttonControl(ptr);
	ptr->setCanvasCurrentMode();
}

afx_msg void ButtonPanel::clickMyButton5()
{
	MyButton *ptr = findButton(5);
	this->buttonControl(ptr);
	ptr->setCanvasCurrentMode();
}

IMPLEMENT_DYNCREATE(ButtonPanel, CView)
BEGIN_MESSAGE_MAP(ButtonPanel, CView)
	ON_BN_CLICKED(10000, clickMyButton0)
	ON_BN_CLICKED(10001, clickMyButton1)
	ON_BN_CLICKED(10002, clickMyButton2)
	ON_BN_CLICKED(10003, clickMyButton3)
	ON_BN_CLICKED(10004, clickMyButton4)
	ON_BN_CLICKED(10005, clickMyButton5)
END_MESSAGE_MAP()