#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Theme 
{
protected:
	string color;
public:
	Theme()
	{}
	Theme(string color) :color(color)
	{}
	virtual string getColor() = 0;
	virtual ~Theme()
	{}
};
class Webpage 
{
protected:
	Theme * th;
	string content;
public:
	Webpage()
	{}
	Webpage(Theme * th,string content):th(th),content(content)
	{}
	virtual string getContent() = 0;
	virtual ~Webpage()
	{}
};

class Dark :public Theme
{
	public:
	Dark()
	{}
	Dark(string color):Theme("Dark")
	{}
	string getColor()
	{
		return this->getColor();
	}
};
class Light :public Theme
{
public:
	Light()
	{}
	Light(string color) :Theme("Light")
	{}
	string getColor()
	{
		return this->getColor();
	}
};
class Blue :public Theme
{
public:
	Blue()
	{}
	Blue(string color) :Theme("Blue")
	{}
	string getColor()
	{
		return this->getColor();
	}
};
class Home:public Webpage
{
public:
	Home()
	{}
	Home(Theme *th):Webpage(th,"Home page")
	{}
	string getContent()
	{
		Show();
		return getContent(); //+ th->getColor();
	}
	void Show()
	{
		cout << getContent() + th->getColor();
	}
};
class About :public Webpage
{
public:
	About()
	{}
	About(Theme *th) :Webpage(th, "About page")
	{}
	string getContent()
	{
		Show();
		return getContent() + this->th->getColor();
	}
	void Show()
	{
		cout << getContent() + th->getColor();
	}
};
class Carees :public Webpage
{
public:
	Carees()
	{}
	Carees(Theme *th) :Webpage(th, "Carees page")
	{}
	string getContent()
	{
		Show();
		return getContent() + th->getColor();
	}
	void Show()
	{
		cout << getContent() + th->getColor();
	}
};
void main()
{
	Theme *t = new Dark();
	vector<Webpage*> site;
	site.push_back(new Home(t));
	for (auto el: site)
	{
		cout << el->getContent() << "\t";
	}
	system("pause");
}