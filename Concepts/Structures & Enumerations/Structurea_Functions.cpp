#include <iostream>
using namespace std;

struct Person{
    string fname, lname;
    int age, salary;
};

// return structure from function
// define a function to return structure variable
struct Person get_data(){
    Person p;
    string fname, lname;
    int age, salary;

    cout << "Enter your first name: ";
    cin >> p.fname;
    cout << "Enter your last name: ";
    cin >> p.lname;
    cout << "Enter your age: ";
    cin >> p.age;
    cout << "Enter your salary: ";
    cin >> p.salary;

    // return structure variable
    return Person{fname, lname, age, salary};
}

// passing structure to a function 
void displayStats(const Person &p){
    cout << "First name: " << p.fname << endl;
    cout << "Last name: " << p.lname << endl;
    cout << "Age: " << p.age << endl;
    cout << "Salary: " << p.salary << endl;
}

int main()
{
    Person p = get_data();
    displayStats(p);
    return 0;
}