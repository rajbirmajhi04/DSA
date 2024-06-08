#include <iostream>
using namespace std;

struct Employee
{
	int id;
	string fname;
	string lname;
	int age;
	float salary;

	// member function
	void displayInfo(){
		cout << "ID: " << id << endl;
		cout << "Firt name: " << fname << endl;
		cout << "Last name: " << lname << endl;
		cout << "Age: " << age << endl;
		cout << "Salary: " << salary << endl;

	}
};


int main() {

	Employee e1;

	cout << "Enter ID: ";
	cin >> e1.id;

	cout << "Enter frist name: ";
	cin >> e1.fname;

	cout << "Enter last name: ";
	cin >> e1.lname; 

	cout << "Enter age: ";
	cin >> e1.age;

	cout << "Enter salary: ";
	cin >> e1.salary;

	cout << "Employee Details: " << endl;
	e1.displayInfo();
	
  	return 0;
}