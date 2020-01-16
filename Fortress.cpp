#include <iostream>
#include <vector>
using namespace std;
class Unit abstract
{
public:
	virtual void play() = 0;
	virtual ~Unit() {}
};
class Archer : public Unit
{
public:
	virtual void play()
	{
		cout << "Archer is play" << endl;
	}
};
class Mage : public Unit
{
	virtual void play()
	{
		cout << "Mage is play" << endl;
	}
};
class Swardsman : public Unit
{
	virtual void play()
	{
		cout << "Swardsman is play" << endl;
	}
};
class FactoryMethod abstract
{
public:
	virtual Unit* createPlayer() = 0;
};
class FactoryMethodArcher : public FactoryMethod
{
public:
	Unit* createPlayer() {
		return new Archer();
	}
};
class FactoryMethodMage : public FactoryMethod
{
public:
	Unit* createPlayer()
	{
		return new Mage();
	}
};
class FactoryMethodSwardsman : public FactoryMethod
{
public:
	Unit* createPlayer()
	{
		return new Swardsman();
	}
};
void main()
{
	FactoryMethodArcher f1;
	FactoryMethodMage f2;
	FactoryMethodSwardsman f3;
	vector<Unit*>team;

	FactoryMethod* fact[] = { &f1, &f2, &f3 };
	int menu;
	while (true)
	{
		cout << "Archer(1)" << endl;
		cout << "Mage(2)" << endl;
		cout << "Swardsman(3)" << endl;
		cout << "Exit(4)" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
		case 2:
		case 3:
			team.push_back(fact[menu - 1]->createPlayer());
			break;
		case 4:
		{
			system("cls");
			return;
			break;
		}
		default:
			break;
		}
		for (auto el : team)
		{
			el->play();
		}
	}
	/*while (true)
	{
		cout << "Archer(1)" << endl;
		cout << "Mage(2)" << endl;
		cout << "Swardsman(3)" << endl;
		cout << "Exit(4)" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			team.push_back(new Archer());
			break;

		}
		case 2:
		{
			team.push_back(new Mage());
			break;
		}
		case 3:
		{
			team.push_back(new Swardsman());
			break;
		}
		case 4:
		{
			system("cls");
			return;
			break;
		}
		default:
			break;
		}
		for (auto el : team)
		{
			el->play();
		}
	}*/
	system("pause");
}