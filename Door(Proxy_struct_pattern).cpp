#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
enum Status
{
	CLOSED = 0,
    OPENED
};
__interface iDoor
{
public:
	virtual void open() = 0;
	virtual void close() = 0;
};
class Door:public iDoor
{
	bool status;
public:
	Door()
	{
		status = CLOSED;
	}
	void open()
	{
		status = OPENED;
		ShowStatus();
	}
	void close()
	{
		status = CLOSED;
		ShowStatus();
	}
	bool getStatus()const
	{
		return status;
	}
	void ShowStatus()
	{
		cout << "Door is " << (status == CLOSED ? "closed" : "opened") << endl;
	}
};
typedef string LOGIN;
typedef string PASSWORD;
class SecureProxy
{
	Door * door;
	LOGIN login;
	PASSWORD password;
	map<LOGIN, PASSWORD>users;
public:
	SecureProxy() 
	{}
	SecureProxy(Door*door):door(door)
	{
		ifstream in("users.db");
		string log, pass;
		if (in.is_open())
		{
			in >> log;
			in >> pass;
			users[log] = pass;
		}
		else
		{
			cout << "error opening file"<<endl;
		}
	}
	bool getAuthorisation(LOGIN login, PASSWORD pass)
	{
		auto it = users.find(login);
		if (it != users.end())
		{
			if(it->second == pass)
			{
				return true;
			}
		}	
		 return false;
	}
	void open(LOGIN login, PASSWORD pass) 
	{
		if (door->getStatus() == OPENED)
		{
			cout << "Doors has been already opened!" << endl;
			//door->ShowStatus();
			return;
		}
		if (getAuthorisation(login, pass))
		{
			door->open();
		}
		else
			cout << "Access is denied" << endl;
	}
	void close()
	{
		if (door->getStatus() == CLOSED)
		{
			cout << "Door has been already closed!" << endl;
			return;
		}
		door->close();
	}
	~SecureProxy()
	{
		delete door;
	}
};
void main()
{
	Door * door = new Door();
	SecureProxy * proxy = new SecureProxy(door);
	//proxy->close();
	proxy->open("admin", "123");
	//proxy->close("user", "456");
	system("pause");
}