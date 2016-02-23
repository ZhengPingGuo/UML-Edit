#include"MyButton.h"
#include"ClassBoxMode.h"
#include"Canvas.h"
#include"ButtonPanel.h"

MyButton::MyButton(int button_id, ButtonPanel *ptr, Mode *cur_mode)
{
	this->id = button_id;
	this->my_button_panel_ptr = ptr;
	this->current_mode = cur_mode;
}

MyButton::~MyButton()
{
	delete current_mode;
}

//³]©wCanvas Current Mode
void MyButton::setCanvasCurrentMode()
{
	(Canvas::getInstance())->setCurrentMode(this->current_mode);
}

int MyButton::getMyButtonID()
{
	return this->id;
}