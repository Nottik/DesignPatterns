#include <iostream>
using namespace std;
class Singleton {
public:
	int getValue() const;
	void setValue(int);
	static Singleton* getInstanse(int value = 100);
private:
	Singleton(int value = 100) : value(value) {}
	static Singleton* obj;
	int value;
};
Singleton* Singleton::obj = 0;
void main()
{
	Singleton *vallet1 = Singleton::getInstanse();
	cout << vallet1->getValue() << endl;
	Singleton *vallet2 = Singleton::getInstanse(200);
	vallet2->setValue(200);
	cout << vallet2->getValue() << endl;
	cout << vallet1->getValue() << endl;
	system("pause");
}
int Singleton::getValue() const
{
	return this->value;
}
void Singleton::setValue(int value)
{
	this->value = value;
}
Singleton * Singleton::getInstanse(int value)
{
	if (!obj)
		obj = new Singleton(value);
	return obj;
}