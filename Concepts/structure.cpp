#include <iostream>
using namespace std;

// Passing structure to functions
struct Employee
{
	int id;
	string fname;
	string lname;
	int age;
	float salary;

	// member function
	void displayInfo(){
		cout << "************************ " << endl;
		cout << "ID: " << id << endl;
		cout << "Firt name: " << fname << endl;
		cout << "Last name: " << lname << endl;
		cout << "Age: " << age << endl;
		cout << "Salary: " << salary << endl;
		cout << "************************ " << endl;
	}
};
struct Item
{
	string item_name;
	double quantity;
	double price;
	double total = quantity * price;
};

void display(const Item& I){
	cout << "************************ " << endl;
	cout << "Item Name: " << I.item_name<< endl;
	cout << "Item Quantity:  " << I.quantity<< endl;
	cout << "Item Price: " << I.price<< endl;
	cout << "Total Price" << I.total<< endl;
	cout << "************************ " << endl;
}

// Return structure from function
struct random_data {
	int num1;
	double num2;
	float num3;
};

// Pointers to structures
struct Distance {
	int meter;
	double inch;
};
struct Books {
	string bookName;
};

// declare functions prototype
random_data get_data();
void display_data(const random_data& rd);

int main() {

	Employee e1;
	Employee *employeePointer = &e1;
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

	// calling member function
	e1.displayInfo(); 
	
	// calling member function using arrow
	employeePointer -> displayInfo();

	//calling the functions
	random_data rd = get_data();
	display_data(rd); 

	// Pointers to structures
	Distance d;
	Distance *pointer = &d;
	cout << "Enter meter: ";
	cin >> (*pointer).meter;
	cout << "Enter inch: ";
	cin >> (*pointer).inch;
	cout << "Displaying Info: "<< endl;
	cout << "Distance = " << (*pointer).meter << " Inch = " << (*pointer).inch << endl;

	// Accessing members using arrow (-->) operator
	Books b;
	Books *bookPointer = &b;
	cout << "Enter book name: ";
	cin >> bookPointer -> bookName;
	cout << "Book Name is " << bookPointer -> bookName << endl;
	
  	return 0;
}

// declare the functions 
random_data get_data(){

	random_data rd;
	int num1;
	double num2;
	float num3;

	cout << "Enter int: ";
	cin >> num1;
	cout << "Enter double: ";
	cin >> num2;
	cout << "Enter float: ";
	cin >> num3;

	// return structure variable
	return random_data{num1, num2, num3};

}
void display_data(const random_data& rd){
	cout << rd.num1 << endl;
	cout << rd.num2 << endl;
	cout << rd.num3 << endl;
}


