#include <iostream>
using namespace std;

/*
* Cosntructors(): is a special type of member function that is used to initialize the data members for an object of a class automatically when a object of the same class is created.
*/

class student {
    private:
        int rollno;
        string name;
        double fee;
    protected:
        int student_school_id;
        int math_marks;
        int physics_marks;
        int computerScience_marks;
    public:
        // constructors within the class
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
        // constructor and function outside the class
        student();
        void display();
};
student::student(){
    cout << "Math Marks: ";
    cin >> math_marks;
    cout << "Physics Marks: ";
    cin >> physics_marks;
    cout << "Computer Science Marks: ";
    cin >> computerScience_marks;
}
void student::display(){
    cout << "Student Name: " << name << endl;
    cout << "Math Marks: " << math_marks << endl;
    cout << "Physics Marks: " << physics_marks << endl;
    cout << "Computer Science Marks: " << computerScience_marks << endl;
}

/*
* Default Constructors: a constructor that accepts no arguments is called zero argument or default constructor
* If default constructor is not defined then compiler automatcally defines a default const.
* if default constructor is defined explicitly in the program then the compiler will not define the constructor implicitly, but it calls the constructor implicitly.

! used to create objects which do not have any specific initial value
! default constructor can have default values
*/

class Base {
    public:
        Base(){
            cout << "User defined constructor with no arguments" << endl;
        }
        Base(int a, int b){
            cout << "User defined constructor with arguments" << endl;
        }
        Base(int a = 0, int b = 0) {
            cout << "User defined constructor with default arguments" << endl;
        }
};  

/*
* Parameterized Constructor: are the type of constructors that can accept arguments/parameters
*/
class _Base {
    private:
        int val1;
        int val2;
        int val3;
    public:
        // parameterized constructor within the class using this operator
        _Base(int v1, int v2, int v3){
            this->val1 = v1;
            this->val2 = v2;
            this->val3 = v3;
        }

        // parameterized constructor within the class without this operator
        _Base(int v1, int v2, int v3){
            val1 = v1;
            val2 = v2;
            val3 = v3;
        }

        // parameterized constructor outside the class
        _Base(int v1, int v2, int v3);

        // parameterized constructor with default value
        _Base(int v1 = 0, int v2 = 0, int v3 = 0){
            this->val1 = v1;
            this->val2 = v2;
            this->val3 = v3;
        }

        /*
        * Member Initializer: provides a clean and compact way to initialize data members of the class using parameterized constructors
        */
        _Base(int v1, int v2, int v3): val1(v1), val2(v2), val3(v3){}

        /*
        * Copy Constructor: that initialize an object using another object of the same class. Basically a constructor which creates an object by initializing it with an object of the same class which has beenm created previously is known as copy.
        */
        _Base(int v1, int v2, int v3){
            this->val1 = v1;
            this->val2 = v2;
            this->val3 = v3;
        }
        _Base(_Base& bb){
            this->val1 = bb.val1;
            this->val2 = bb.val2;
            this->val3 = bb.val3;
        }
        // member function
        void display();
};
// declaration of parameterized constructor outside the class
_Base::_Base(int v1, int v2, int v3) {
    this->val1 = v1;
    this->val2 = v2;
    this->val3 = v3;
}
// declaration of member function
void _Base::display(){
    cout << "Value 1: " << val1 << endl;
    cout << "Value 2: " << val2 << endl;
    cout << "Value 3: " << val3 << endl;
}

/*
! Need of User Defined Copy Constructor? -> Shallow and Deep copy
*/

/*
* Move Constructor: used to create a new object from the already existing object of the same type but instead of making a copy of it, it makes the new object point to the already existing object in the memory leaving the source object in valid but unspecified state.

* works on the r-value reference and move semantics. Basically transfer the ownership of the already existing object to the new object without making any copy of it. it makes the new object point to the already existing object in the heap memory. 
*/

class Sample {
    private:
        int *data;
    public:
        Sample(int value): data(new int(value)){
            cout << "Constructor Called, Data = " << *data << endl;
        }
        ~Sample(){
            delete data;
            cout << "Destructor Called" << endl;
        }
        // Move Constructor
        Sample(Sample&& other): data(other.data){
            // nullify the other resource
            other.data = nullptr;
            cout << "Move constructor called" << endl;
        }
        // Move assignment operator
        Sample& operator = (Sample&& other){
            if(this != &other){
                delete data; // free existing resource
                data = other.data; // transfer ownership
                other.data = nullptr; // nullify source
                cout << "Move assignment operator" << endl;
            }
            return *this;
        }
        // Disable copy and assignment operator
        Sample(const Sample&) = delete;
        Sample& operator = (const Sample&) = delete;
        // Function to print the value
        void print(){
            if(data){
                cout << "Data: " << *data << endl;
            }
            else {
                cout << "Data is null" << endl;
            }
        }
};

class Move {
    private:
        int *data;
    public:
        // constructor
        Move(int d){
            // declare the object in the heap
            data = new int;
            *data = d;
            cout << "Constructor is called for " << d << endl;
        }
        // copy constructor
        Move(const Move& source): Move {*source.data}{
            // copying the data by making deep copy 
            cout << "Copy constructor called-deep copy for " << *source.data << endl;
        }
        // move constructor
        Move(Move&& source): data{source.data}{
            cout << "Move constructor for " << *source.data << endl;
            source.data = nullptr;
        }
        ~Move(){
            if(data != nullptr){
                cout << "Destructor is called for " << *data << endl;
            }
            else {
                cout << "destructor is called for null ptr" << endl;
                delete data;
            }
        }
};

int main()
{   
    _Base b(10, 20, 30);
    b.display();

    _Base b1(b);
    b1.display();
    return 0;
}