#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


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

	string checkSoc() const {
		return social;
	}
};

bool operator==(const Employee &a, const Employee &b)
{
	if (a.checkSoc() == b.checkSoc())
		return true;
	return false;
}

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

class Salaried : Employee{
private:
	double salary;
public:
	Salaried(string name, string social, double salary) : Employee(name, social), salary(salary){}
	double weeklySalary(double salary)
	{
		return salary / 52;
	}
	void print(){
		Employee::print();
		cout << "Salary:  $" << salary << endl;
		cout << "Weekly:  $" << weeklySalary(salary) << endl;
	}

};

class Roster{

private:
	vector<Employee> staff;
public:
	void add(Employee e){
		if (doesExist(e))
		{
			cout << "Employee already exists" << endl;
			return;
		}
		staff.push_back(e);
	}

	void remove(){}

	void print(){
		for (std::vector<Employee>::iterator it = staff.begin(); it != staff.end(); ++it)
		{
			it->print();
			cout << endl;
		}
	}

	bool doesExist(Employee e){
		if (std::find(staff.begin(), staff.end(), e) != staff.end())
			return true;
		return false;
	}

} roster;

int main()
{
	Employee emp1("Joe", "12345");
	Employee emp5("Joe", "12345");
	

	Hourly emp2("Bob", "12346", 15, 40);
	Salaried emp3("Chris", "12347", 52000);

	
	roster.add(emp1);
	roster.add(emp1);
	roster.add(emp5);
	
	roster.print();
	
	
	system("Pause");
}