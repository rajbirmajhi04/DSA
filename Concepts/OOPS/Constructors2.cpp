#include <iostream>
using namespace std;

// copy constructor: is a type of constructor that initializes an object using object of the same class,
// a constructor which creats an object by initializing it with an object of the same class which has been,
// created previously is known as copy constructor.

class student {
    private:
        int rollno;
        string name;
        double fees;
    
    public:
        // parameterized constructor 
        student(int, string, double);
        // copy constructor
        student(student& t){
            rollno = t.rollno;
            name = t.name;
            fees = t.fees;
            cout << "Copy Constructor Called!" << endl;
        }
        // member function
        void display();
};

// implementation of parameerized constructor
student::student(int no, string n, double f){
    rollno = no;
    name = n;
    fees = f;
}

// implementation of display function
void student::display(){
    cout << "Student Name: " << name << endl;
    cout << "Roll No: " << rollno << endl;
    cout << "Fees: " << fees << endl;
}

int main()
{   
    // create a student object with parameterized constructor
    student s(1001, "Rahul", 12000.00);
    s.display();

    // create anoterh student object using the copy constructor
    student manjeet(s);
    manjeet.display();
    return 0;
}