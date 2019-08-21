#include <iostream>
#include <string>
#include "AbstractFactory.h"
#include <fstream>

using namespace std;
class Toy abstract {
	string name;
public:
	Toy(string name) :name(name) {}
	virtual void print()
	{
		cout << "Name: " << this->name << endl;
	}
};

class Dog : public Toy
{
public:
	Dog(string name) :Toy(name) {}
};
class Cat : public Toy
{
public:
	Cat(string name) :Toy(name) {}
};

class WoodenDog : public Dog {
public:
	WoodenDog() :Dog("wooden dog") {}
};
class WoodenCat : public Cat {
public:
	WoodenCat() :Cat("wooden cat") {}
};
class TeddyDog : public Dog {
public:
	TeddyDog() :Dog("teddy dog") {}
};
class TeddyCat : public Cat {
public:
	TeddyCat() :Cat("teddy cat") {}
};

__interface IToysFactory {
public:
	virtual Cat* createCat() = 0;
	virtual Dog* createDog() = 0;
};

class WoodenToysFactory : public IToysFactory {
public:
	Cat* createCat() override
	{
		return new WoodenCat();
	}
	Dog* createDog() override
	{
		return new WoodenDog();
	}
};
class TeddyToysFactory : public IToysFactory {
public:
	Cat* createCat() override
	{
		return new TeddyCat();
	}
	Dog* createDog() override
	{
		return new TeddyDog();
	}
};

void useToy(IToysFactory* toy)
{
	Toy * cat = toy->createCat();
	cat->print();
	Toy* dog = toy->createDog();
	dog->print();
}

void main()
{
	//	IToysFactory * it = new TeddyToysFactory();
		//useToy(it);
		//delete it;
		//it = new WoodenToysFactory();
		//useToy(it);

	TeddyToysFactory td;
	useToy(&td);
	WoodenToysFactory wd;
	useToy(&wd);
	system("pause");
}