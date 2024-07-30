#include <iostream>
using namespace std;

// forward declaration needed for defining member function as a friend function
class base;
class secondary{
    public:
        void memberFunction(base& base_object);
};

// defining base class
class base{
    private:
        int num1;
    protected:
        int num2;
    public:
        base(){
            num1 = 100;
            num2 = 567;
        }
        // declaration of friend class
        friend class displayFunction;
        // declaration of friend function
        friend void display_data(base& base_object);
        // declaration of member function of another class as friend function
        friend void secondary::memberFunction(base& base_object);
};

// friend class definition 
class displayFunction{
    public:
        void display(base& base_object){
            cout << "Num 1: " << base_object.num1 << endl; 
            cout << "Num 2: " << base_object.num2 << endl; 
        }
};

// friend function definition
void display_data(base& base_object){
    cout << "Num 1: " << base_object.num1 << endl;
    cout << "Num 2: " << base_object.num2 << endl;
}

// definition of member function of another class
void secondary::memberFunction(base& base_object){
    cout << "Num 1: " << base_object.num1 << endl;
    cout << "Num 2: " << base_object.num2 << endl;
}

int main()
{
    base b;
    displayFunction df;
    secondary s;

    df.display(b);
    display_data(b);
    s.memberFunction(b);
    return 0;
}