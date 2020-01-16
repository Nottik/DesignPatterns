#include <iostream>
#include <string>
using namespace std;
class Logger
{
	string logger;
	static Logger *obj;
	Logger(string l) :logger(l)
	{}
public:
	static Logger * getObj(string l = "admin")
	{
		if (obj == nullptr)
			obj = new Logger(l);
		return obj;
	}
	string getValue()const
	{
		return this->logger;
	}
	void setValue(string l)
	{
		this->logger = l;
	}
	void Print()
	{
		cout << logger << " is active" << endl;
	}
};
Logger* Logger::obj = 0;
void main()
{
	Logger* logger1 = Logger::getObj();
	logger1->Print();
	Logger * logger2 = Logger::getObj();
	logger2->setValue("user");
	logger2->Print();
	system("pause");
}







//#include <iostream>
//using namespace std;
//class Singleton
//{
//	int value;
//	static Singleton *obj;
//	Singleton(int v ):value(v)
//	{}
//public:
//	static Singleton * getObj(int v=4100)
//	{
//		if (obj == nullptr)
//			obj = new Singleton(v);
//		return obj;
//	}
//	int getValue()const
//	{
//		return this->value;
//	}
//	void setValue(int value)
//	{
//		this->value = value;
//	}
//};
//Singleton* Singleton::obj = 0;
//void main()
//{
//	Singleton * vallet1 = Singleton::getObj();
//	cout << vallet1->getValue() << endl;
//	Singleton * vallet2 = Singleton::getObj(5000);
//	vallet2->setValue(5000);
//	cout << vallet2->getValue()<<endl;
//	system("pause");
//}