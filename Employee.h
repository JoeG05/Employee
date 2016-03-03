#pragma once
#include <string>
#include <iostream>

using namespace std;

class Employee
{

private:
	string name;
	string social;

public:
	//Employee(string name, string social) :name(name), social(social){};
	virtual ~Employee();
	virtual void print() const
	{
		cout << name << " - " << social << endl;
	}
};

