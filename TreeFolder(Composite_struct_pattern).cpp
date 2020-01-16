#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class Component 
{
private:
	string name;
public:
	Component()
	{}
	Component(string name):name(name)
	{}
	string getName()
	{
		return name;
	}
	virtual int getSize() = 0;
	virtual void operation() = 0;
	virtual void add(Component *) = 0;
	virtual void remove(int index) = 0;
	virtual Component* getChild(int index) = 0;
};
class Composite : public Component
{
	vector <Component*> tree;
public:
	Composite()
	{}
	Composite(string name) : Component(name)
	{
		ifstream in("folder.db");
		if (in.is_open())
		{
			in >> name;
		}
		else
		{
			cout << "error opening file" << endl;
		}
	}
	void operation()
	{
		cout << getName() << endl;
		for(auto el: tree)
		{
			el->operation();
		}
	}
	void add(Component * obj)
	{
		tree.push_back(obj);
	}
	void remove(int index)
	{
		tree.erase(tree.begin()) + index;
	}
	Component* getChild(int index)
	{
		if ((index < tree.size()) && (index >= 0))
		{
			return tree[index];
		}
		throw("Invalid index");
	}
	int getSize()
	{
		int tmp = 0;
		for (auto el : tree)
		{
			tmp += el->getSize();
		}
		cout << "Size = " << tmp<<endl;
		return tmp;
	}
};
class Unit :public Component
{
	int size;
public:
	Unit()
	{}
	Unit(string name): Component(name), size(size)
	{}
	void operation()
	{
		cout << getName() << "\t";
	}
	void add(Component * obj)
	{
		throw("Invalid add");
	}
	void remove(int index)
	{
		throw("Invalid remove");
	}
	Component* getChild(int index)
	{
		throw("Invalid index");
	}
	int getSize()
	{
		return sizeof(getName());
	}
};
void main()
{
	Component * root = new Composite("root");
	Component * f1 = new Composite("folder1");
	Component * f2 = new Composite("folder2");
	Component * leaf1 = new Composite("folder3");
	Component * leaf2 = new Unit("file1");
	Component * leaf3 = new Unit("file2");
	/*root->add(f1);
	root->add(f2);
	f1->add(leaf1);
	f2->add(leaf2);
	f2->add(leaf3);
	root->operation();*/
	f2->add(leaf2);
	root->add(f1);
	//root->add(f2);
	f1->add(f2);
	leaf2->getSize();
	system("pause");
}