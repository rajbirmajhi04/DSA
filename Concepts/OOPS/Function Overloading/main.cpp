#include <iostream>
using namespace std;

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




















int main()
{
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