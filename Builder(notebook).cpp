#include <iostream>
#include <string>
#include <map>
using namespace std;
class Notebook
{
private:
	string name;
	map <string, string> part;
public:
	Notebook()
	{}
	Notebook(string name = "notebook"):name(name)
	{}
	string getPart(const string & key)
	{
		return part[key];
	}
	void setPart(const string &key, string value)
	{
		part[key] = value;
	}
	void Show()
	{
		cout << name << endl;
		for ( auto el: part )
		{
			cout << el.first << el.second << "\t";
		}
		cout << endl;
	}
	bool Checkout(const string&key, string value)
	{
		if (!part[key].find(key))
		{
			return false;
		}
		else return true;
	}
};
class NotebookBuilder
{
protected:
	Notebook * device;
public:
	virtual void setMemory() = 0;
	virtual void setHDD() = 0;
	virtual void setProcessor() = 0;
	Notebook * getNotebook()
	{
		return device;
	}
	virtual ~NotebookBuilder()
	{}
};
class GamerNotebook: public NotebookBuilder
{

public:
	GamerNotebook()
	{
		device = new Notebook("Gamernotebook");
	}
	void setMemory()
	{
		device->setPart("Memory: ", "8 Gb\t");
	}
	void setHDD()
	{
		device->setPart("HDD: ", "1 T\t");
	}
	void setProcessor()
	{
		device->setPart("Processor: ", "Intel Core i7-8750H\t");
	}
};
class HomeNotebook : public NotebookBuilder
{
public:
	HomeNotebook()
	{
		device = new Notebook("Homenotebook");
	}
	void setMemory()
	{
		device->setPart("Memory: ", "8 Gb\t");
	}
	void setHDD()
	{
		device->setPart("HDD: ", "128 Gb SSD\t");
	}
	void setProcessor()
	{
		device->setPart("Processor: ", "Intel Core i5-8265U\t");
	}
};
class BusinessNotebook :public NotebookBuilder
{
public:
	BusinessNotebook()
	{
		device = new Notebook("Businessnotebook");
	}
	void setMemory()
	{
		device->setPart("Memory: ", "8 Gb\t");
	}
	void setHDD()
	{
		device->setPart("HDD: ", "256 Gb SSD\t");
	}
	void setProcessor()
	{
		device->setPart("Processor: ", "Intel Core i5-8265U\t");
	}
};
class TripNotebook :public NotebookBuilder
{
public:
	TripNotebook()
	{
		device = new Notebook("Tripnotebook");
	}
	void setMemory()
	{
		device->setPart("Memory: ", "2 Gb\t");
	}
	void setHDD()
	{
		device->setPart("HDD: ", "32 Gb\t");
	}
	void setProcessor()
	{
		device->setPart("Processor: ", "Intel Atom x5-Z8350\t");
	}
};

class Shop
{
public:
	void createNotebook(NotebookBuilder * builder )
	{
		builder->setMemory();
		builder->setHDD();
		builder->setProcessor();
	}
};
void main()
{
	Shop * shop = new Shop();
	NotebookBuilder * builder;
	int menu;
	do {
		cout << "Gamer Notebook(1)" << endl;
		cout << "Home Notebook(2)" << endl;
		cout << "Business Notebook(3)" << endl;
		cout << "Trip Notebook(4)" << endl;
		cout << "Exit(5)" << endl;
		cout << "Your change: ";
		cin >> menu;
		switch (menu)
		{
			case 1:
			{
				cout << endl;
				builder = new GamerNotebook();
				shop->createNotebook(builder);
				builder->getNotebook()->Show();
				delete builder;
				cout << endl;
				break;
			}
			case 2:
			{
				cout << endl;
				builder = new HomeNotebook();
				shop->createNotebook(builder);
				builder->getNotebook()->Show();
				delete builder;
				cout << endl;
				break;
			}
			case 3:
			{
				cout << endl;
				builder = new BusinessNotebook();
				shop->createNotebook(builder);
				builder->getNotebook()->Show();
				delete builder;
				cout << endl;
				break;
			}
			case 4:
			{
				cout << endl;
				builder = new TripNotebook();
				shop->createNotebook(builder);
				builder->getNotebook()->Show();
				delete builder;
				cout << endl;
				break;
			}
			case 5:
			{
				system("cls");
				return;
				break;
			}
		default:
			break;
		}
	} while (true);
	system("pause");
}