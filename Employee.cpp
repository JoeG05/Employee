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
	virtual void print() const = 0;
	
	

	string checkSoc() const {
		return social;
	}
};

void Employee::print() const{
	cout << "Name:    " << name << endl;
	cout << "Social:  " << social << endl;
}



class Hourly : public Employee{
private:
	double wage, hours;
	
public:
	Hourly(string name, string social, double wage, double hours) : Employee(name, social), wage(wage), hours(hours){}
	
	void print() const{
		double overtime = hours - 40;
		
		Employee::print();
		cout << "Wage:   $" << wage << endl;
		cout << "Hours:   " << hours << endl;
		cout << "Earned: $" << (hours * wage) + (overtime * (wage * .5)) << endl;
	}
		

};

class Salaried : public Employee{
private:
	double salary;
public:
	Salaried(string name, string social, double salary) : Employee(name, social), salary(salary){}
	
	void print() const {
		Employee::print() ;
		cout << "Salary:  $" << salary << endl;
		cout << "Weekly:  $" << salary / 52 << endl;
	}

};

class Roster{

private:
	vector<Employee*> staff;
public:
	void add(Employee &e){
		if (doesExist(e))
		{
			cout << "Employee already exists" << endl;
			return;
		}
		staff.push_back(&e);
	}

	void remove(Employee &e){
		auto i = staff.begin();
		for ( ; i != staff.end(); ++i)
		{
			if ((*i)->checkSoc() == e.checkSoc())
				break;
		}
		staff.erase(i);
	}

	void print(){
		for (auto i = staff.begin(); i != staff.end(); ++i)
		{
			
			(*i)->print();
			cout << endl;
		}
	}

	bool doesExist(Employee &e){
		for (auto i = staff.begin(); i != staff.end(); ++i)
		{
			if ((*i)->checkSoc() == e.checkSoc())
				return true;
		}
		return false;
	}

} roster;

int main()
{
	Hourly emp1("Joe", "12345", 10, 50);
	Salaried emp2("Bob", "12346", 52000);

	

	roster.add(emp1);
	roster.add(emp2);

	roster.print();

	system("Pause");
}