#include <iostream>
#include <string>
using namespace std;
class oldCoffeeMachine
{
private:
	int coffee;
	int milk;
public:
	oldCoffeeMachine()
	{}
	oldCoffeeMachine(int coffee, int milk):coffee(coffee), milk(milk)
	{}
	void makeCoffee()
	{
		if(coffee!=0)
		{
			coffee -= 1;
			cout << "Machine prepare coffee." << endl;
		}
		else
			cout << "ERROR\n Coffee is absent!" << endl;
	}
	void addMilk()
	{
		if (milk != 0)
		{
			milk -= 1;
			cout << "Machine add milk." << endl;
		}
		else
			cout << "ERROR\n Milk is absent!" << endl;
	}
	void Status()
	{
		cout << "Coffee: " << coffee<<endl;
		cout << "Milk: " << milk << endl;
	}
	int getCoffee()
	{
		return this->coffee;
	}
	void setCoffee(int coffee)
	{
		this->coffee = coffee;
	}
	int getMilk()
	{
		return this->milk;
	}
	void setMilk(int milk)
	{
		this->milk = milk;
	}
};
class NewCoffeeMachine
{
public:
	virtual void pureCoffee() = 0;
	virtual void makeCoffeeWithMilk() = 0;
};
class CoffeeAdapter :public NewCoffeeMachine, private oldCoffeeMachine
{
public:
	CoffeeAdapter(int coffee, int milk) :oldCoffeeMachine(coffee,milk)
	{}
	void pureCoffee()
	{
		makeCoffee();
	}
	void makeCoffeeWithMilk()
	{
		makeCoffee();
		addMilk();
	}
};
void main()
{
	NewCoffeeMachine* machine = new CoffeeAdapter(20, 10);
	
	do{
		int menu;
		cout << "Coffee(1)" << endl;
		cout << "Coffee with milk(2)" << endl;
		cout << "Exit(3)" << endl;
		cout << "Your change: ";
		cin >> menu;
		switch (menu)
		{
			
			case 1:
			{
				machine->pureCoffee();
				break;
			}
			case 2:
			{
				machine->makeCoffeeWithMilk();
				break;
			}
			case 3:
			{
				system("cls");
				return;
				break;
			}
			default:
			break;
			}
	}while (true);
	
	system("pause");
}