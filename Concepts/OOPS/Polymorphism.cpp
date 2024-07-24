#include <iostream>
using namespace std;

// Types: Compile time polymorphism and Runtime Polymorphism
// Compile time: Operator overloading and function overloading
// Runtime: virtual function

// function and operator overloading polymorphism
class Quadrilateral{
    private:
        void func1(){} // function with 0 parameters
        void func1(int x){} // function with 1 parameter
        void func1(int x, int y){} // function with 2 parameters
};


class Complex {
    private:
        int real, image;

    public:
        Complex(int r = 0, int i = 0){
            this->real = r;
            this->image = i;
        }

        
};

int main()
{
    return 0;
}