#include <iostream>
using namespace std;

/*
? Compiletime polymorphism is faster than function overriding. 
? Allows you to use the same function or operator name for different types improving code readability and maintenance.
*/

/*
! Compile Time Polymorphism
* Function Overloading: Allows multiple functions to have the same name but with different parameter list.
* define multiple functions with the same name but with different parameters(either in type, number, or both) compiler decides which function to call based on the arguments passed.
*/
class Base {
    public:
        void func1(){
            cout << "Funtion with 0 parameters" << endl;
        }
        void func1(int x){
            cout << "Function with 1 parameter" << endl;
        }
        void func1(int x, int y){
            cout << "Function with 2 parameters" << endl;
        }
};

// Function Overloading
void add(int a, int b){
    cout << "Int Sum: " << (a + b) << endl;
}

void add(double a, double b){
    cout << "Double Sum: " << (a + b) << endl;
}

// Constructor Overloading
class Base {
    public:
        float area;
        Base(){
            area = 0;
        }
        Base(int a, int b){
            area = a * b;
        }
        Base(double a, double b, double c){
            area = (a + b) * c;
        }
        void display(){
            cout << "Area: " << area << endl;
        }
};

/*
! Functions that cannot be overloaded
*/

//* Function declarations that differ only in the return type cannot be overloaded
// int foo(){
//     return 10;
// }
// double foo(){
//     return 10.8;
// }

//* Member function declarations with the same name and the name parameter type list cannot be overloaded if any of them is a static member function declaration
// class Test {
//     static void fun(int i){}
//     void fun(int i){}
// };

//* Parameter declarations that differ only in a pointer vs an array are equivalent.
// int fun(int *ptr);
// int fun(int ptr[]);

//* Parameter declarations that differ only in that one is a function type and the other is a pointer to the same function type are equivalent
// void foo(int ());
// void foo(int (*)());

/*
! Operator Overloading
* allows you to define or change the behaviour of oeprators for user defined types such as classes. This enables the use of operators with user-defined daa types in a way that is intutive and consistent with built in types
*/
class Complex {
    public:
        int real, image;

        Complex(int r = 0, int i = 0){
            real = r;
            image = i;
        }

        Complex operator + (const Complex &obj){
            Complex result;
            result.real = real + obj.real;
            result.image = image + obj.image;
            return result;
        }
        void display(){
            cout << real << " + " << image << "i" << endl;
        }
};

int main()
{
    Complex c1(3, 4), c2(10, 5);
    Complex c3 = c1 + c2;
    c3.display();

    add(6, 7);
    add(7.8, 3.4);

    Base b1;
    Base b2(10, 20);
    Base b3(10.2, 20.3, 11.6);

    b1.display();
    b2.display();
    b3.display();
    return 0;
}