#ifndef _MYBUTTON_H_
#define _MYBUTTON_H_

#include<afxwin.h>
#include<afxext.h>
#include"Mode.h"

class ButtonPanel;

class MyButton : public CButton
{
public:
	MyButton(int, ButtonPanel*, Mode *);
	~MyButton();
	void setCanvasCurrentMode(); //³]©wCanvas Current Mode
	int getMyButtonID();
private:
	int id; //Button id
	Mode *current_mode;
	ButtonPanel *my_button_panel_ptr;
};

#endif