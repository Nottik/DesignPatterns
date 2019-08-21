#pragma once
#include <iostream>
#include <string>

using namespace std;
class GuiElement abstract {
	string name;
public:
	GuiElement(string name) : name(name) {}
	void print()
	{
		cout << name << " created" << endl;
	}
};
class Button : public GuiElement {
public:
	Button(string name) : GuiElement(name) {}
};
class CheckBox : public GuiElement {
public:
	CheckBox(string name) : GuiElement(name) {}
};
class WinButton : public Button
{
public:
	WinButton() : Button("windows button") {}
};
class MacButton : public Button
{
public:
	MacButton() : Button("Mac button") {}
};
class MacCheckBox : public CheckBox
{
public:
	MacCheckBox() : CheckBox("Mac CheckBox") {}
};
class WinCheckBox : public CheckBox
{
public:
	WinCheckBox() : CheckBox("Win CheckBox") {}
};
__interface GuiElementsFactory {
public:
	virtual Button* createBtn() = 0;
	virtual CheckBox* createCheckBox() = 0;
};
class WinButtonsFactory : public GuiElementsFactory {
public:
	Button* createBtn() override {
		return new WinButton();
	}
	CheckBox* createCheckBox() override {
		return new WinCheckBox();
	}
};
class MacButtonsFactory : public GuiElementsFactory {
public:
	Button* createBtn() override {
		return new MacButton();
	}
	CheckBox* createCheckBox() override {
		return new MacCheckBox();
	}
};

void useGui(GuiElementsFactory* el) {
	Button* btn = el->createBtn();
	CheckBox * check = el->createCheckBox();
	btn->print();
	check->print();
}