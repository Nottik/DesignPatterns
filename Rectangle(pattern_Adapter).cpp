#include <iostream>
#include <string>
using namespace std;
class Rectangle
{
public:
	Rectangle()
	{}
	Rectangle(int x, int y, int x2, int y2):x(x),y(y), x2(x2), y2(y2)
	{}
	void Draw()
	{
		cout << "Draw rectangle (" << x << ";" << y << ";" << x2 << ";" << y2 << ")" << endl;
	}
	int getX()
	{
		return this->x;
	}
	void setX(int x)
	{
		this->x = x;
	}
	int getY()
	{
		return this->y;
	}
	void setY(int y)
	{
		this->y = y;
	}
	int getX2()
	{
		return this->x2;
	}
	void setX2(int x2)
	{
		this->x2 = x2;
	}
	int getY2()
	{
		return this->y2;
	}
	void setY2(int y2)
	{
		this->y2 = y2;
	}
private:
	int x;
	int y;
	int x2; 
	int y2;
};
class NewRectangle
{
public:
	NewRectangle()
	{}
	NewRectangle(string color):color(color)
	{}
	virtual void Draw() = 0;
	string getColor()
	{
		return this->color;
	}
	void setColor(string color )
	{
		this->color = color;
	}
private:
	string color;
};
class RectangleAdapter :public NewRectangle, private Rectangle
{
public:
	RectangleAdapter()
	{}
	RectangleAdapter(int x, int y, int w, int h):Rectangle(x,y,w+x,h+y)
	{}
	void Draw()
	{
		Rectangle::Draw();
		cout << getColor()<<endl;
	}
};
void main()
{
	NewRectangle* rect = new RectangleAdapter(10, 13, 4, 13);
	rect->setColor("red");
	rect->Draw();
	system("pause");
}