#include <string>
#include <iostream>

using namespace std;

class Employee{
private:
	string name, social;
public:
	Employee(string name, string social) : name(name), social(social){}
	void print() const
	{
		cout << name << " - " << social << endl;
	}
};

class Hourly : Employee{
private:
	double wage, hours;
public:

};

int main()
{
	Employee emp1("Joe", "12345");
	emp1.print();

	system("Pause");
}