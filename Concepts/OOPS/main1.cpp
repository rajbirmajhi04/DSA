#include <iostream>
using namespace std;

// forward declaration needed for defining member function as a friend function 
class Employee;
class anotherClass{
    public:
        void memberFunction(Employee& emp_obj);
};

// base class
class Employee {
    private:
        int emp_id;
    protected:
        int emp_account_id;
    public:
        Employee(){
            emp_id = 679;
            emp_account_id = 45673452;
        }
        // declaration of friend class 
        friend class display_data;
        // declaration of friend function
        friend void display(Employee& emp_obj);
        // declaration of member function of another class as friend function
        friend void anotherClass::memberFunction(Employee& emp_obj);
};

// friend function definition
void anotherClass::memberFunction(Employee& emp_obj){
    cout << "Private Variable: " << emp_obj.emp_id;
    cout << "Protected Variable: " << emp_obj.emp_account_id;
}

// here class display_data is declared as a friend inside the parent class Employee
class display_data{
    public:
        void display(Employee& e){
            cout << "Employee ID: " << e.emp_id << endl;
            cout << "Employee Account ID: " << e.emp_account_id << endl;
        }
};

// global function as a friend function
void display(Employee& emp_obj){
    cout << "Private Variable: " << emp_obj.emp_id << endl;
    cout << "Protected Variable: " << emp_obj.emp_account_id << endl;
}

int main()
{
    Employee e;
    display_data d;

    d.display(e);
    display(e);

    anotherClass ac;
    ac.memberFunction(e);
    return 0;
}