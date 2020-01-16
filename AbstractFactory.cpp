#include <iostream>
#include <string>
using namespace std;
class Toy abstract
{
	string name;
public:
	Toy()
	{}
	Toy(string n) : name(n)
	{}
	string getName()
	{
		return this->name;
	}
	void setName(string n)
	{
		this->name = n;
	}
	void Print()
	{
		cout << "Toy: " << name << endl;
	}
};
class Cat :public Toy
{
public:
	Cat(string n) :Toy(n)
	{}
};
class Bear :public Toy
{
public:
	Bear(string n) :Toy(n)
	{}
};
class TeddyCat :public Cat
{
public:
	TeddyCat() :Cat("teddy cat")
	{}
};
class TeddyBear :public Bear
{
public:
	
	TeddyBear() :Bear("teddy bear")
	{}
};
class WoodenBear :public Bear
{
public:
	
	WoodenBear() :Bear("wooden bear")
	{}
};
class WoodenCat :public Cat
{
public:
	
	WoodenCat() :Cat("wooden cat")
	{}
};
class iToysFactory abstract
{
public:
	virtual Bear* createBear() = 0;
	virtual Cat* createCat() = 0;
};
class WoodenToys :public iToysFactory
{
	Bear* createBear()override
	{
		return new WoodenBear();
	}
	Cat* createCat()override
	{
		return new WoodenCat();
	}
};
class TeddyToys : public iToysFactory
{
	Bear* createBear() override
	{
		return new TeddyBear();
	}
	Cat* createCat()override
	{
		return new TeddyCat();
	}
};
void useToys(iToysFactory* fact)
{
	Bear* bear = fact->createBear();
	bear->Print();
	Cat* cat = fact->createCat();
	cat->Print();
}
void main()
{
	WoodenToys* wt = new WoodenToys();
	useToys(wt);
	TeddyToys* tt = new TeddyToys();
	useToys(tt);
	system("pause");
}