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
    return 0;
}