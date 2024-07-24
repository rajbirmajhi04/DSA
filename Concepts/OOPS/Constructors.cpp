#include <iostream>
using namespace std;

/*
? Cosntructors(): is a special type of member function that is used to initialize the data members for an object of a class automatically when a object of the same class is created.
? do not return any value.
? can be overloaded and cannot be declared virtual
*/

class student{
    private:
        int rollno;
        string name;
        double fee;
    protected:
        int student_school_id;
    public:
        student(){
            cout << "Enter roll no: ";
            cin >> rollno;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter school fees: ";
            cin >> fee;
            cout << "Enter student school id: ";
            cin >> student_school_id;
            cout << endl;
        }
        void display_data(){
            cout << "!!!***** Displaying Student Data *****!!!" << endl;
            cout << "Student Name: " << name << endl;
            cout << "Student Roll No: " << rollno << endl;
            cout << "Student Current Fees: " << fee << endl;
            cout << "Student School ID: " << student_school_id << endl;
        }
};

// Default Constructor
class buffer {
    public:
        // compiler "declared" constructor 
};
class loading {
    public:
        // user defined constructor
        loading(){ cout << "User Defined Constructor" << endl; }
        int size;
};
class B: public loading {
    // compiler defined default constructor of B and inserts stub to call loading constructor
    // compiler won't initialize any data of A
};
class c: public loading {
    public:
        c(){ cout << "C Constructor" << endl; }
};

// parameterized constructor
class employee {
    private:
        int emp_id;
        string emp_name;
        double emp_salary;
    
    public:
        employee(int, string, double);
        void display();
};
// parameterized constructor outside the class 
employee::employee(int i, string n, double s){
    emp_id = i;
    emp_name = n;
    emp_salary = s;
}
void employee::display(){
    cout << "Employee Name: " << emp_name << endl;
    cout << "Employee Salary: " << emp_salary << endl;
    cout << "Employee ID: " << emp_id << endl;
}

// parameterized constructor with default value
class GFG {
private:
    int data;

public:
    // parameterized constructor with default values
    GFG(int x = 0) { data = x; }
    int getData() { return data; }
};

// member initializer Lists: provides a clean and compact way to initilize data members of the ckass 
// using parameterized constructor
class Car {
    public:
        Car(string n, string c, int ts, int m): name(n), color(c), top_speed(ts), mileage(m){}
        string name;
        string color;
        int top_speed;
        int mileage;
};

//copy constructor: is a type of constructor that initializes an object using object of the same class,
// a constructor which creats an object by initializing it with an object of the same class which has been,
// created previously is known as copy constructor.

int main()
{
    // student s;
    // s.display_data();

    // employee e(34, "Rahul", 50000.00);
    // e.display();

    // Car c("BMW", "Red", 275, 22);

    return 0;
}

  