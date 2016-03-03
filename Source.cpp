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
	Hourly(string name, string social, double wage, double hours) : Employee(name, social), wage(wage), hours(hours){}
	double calcEarned(double wage, double hours)
	{
		double overtime = hours - 40;
		return((hours * wage) + (overtime * .5));
	}
	void print(){
		Employee::print();
		cout << "Wage:   $" << wage << endl;
		cout << "Hours:   " << hours << endl;
		cout << "Earned: $" << calcEarned(wage, hours) << endl;
	}
		

};

int main()
{
	Employee emp1("Joe", "12345");
	emp1.print();

	Hourly emp2("Bob", "12346", 15, 40);
	emp2.print();
	system("Pause");
}