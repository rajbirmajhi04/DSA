#include <iostream>
using namespace std;

//! Runtime Polymorphism: (Dynamic)

/*
* This type of polymorphism is acived by Function Overriding. 
* Late Binding and Dynamic polymorphism are the other naems for runtime polymorphism.
* The function call is resolved at runtime in runtime polymorphism.
*/

/*
* Function Overriding occurs when a derived class defines a function that has the same naem and signature as a function in its base class. When you call the overridden function using an object of the derived class, the derived class's version is executed.

* However if you call the function through a base class pointer or reference the base class version is executed unless the function is declared as virtual in the base class. 
*/

// In this examle the derived class overrides the show() function of the base class
class Base {
    public:
        void show(){
            cout << "Base Class" << endl;
        }
};

class Derived: public Base {
    public:
        void show(){
            cout << "Derived Class" << endl;
        }
};

/*
* Function overriding with Virtual Function: 
? Base Class Function with "virtual" keyword: Indicate that it is intended to be overridden in any derived class.
*/

class Animal {
    public:
        virtual void sound(){
            cout << "Some generic animal sound" << endl;
        }
        void display(){
            cout << "Called from base class" << endl;
        }
};

class Dog: public Animal {
    public:
        void sound() override {
            cout << "Bark" << endl;
        }
        void display(){
            cout << "Called from derived class" << endl;
        }
};

/*
! Using Virtual Function: (Runtime Polymorphism)
*/
class Shape {
    public:
        virtual void calculate(){
            cout << "Area of your shape: ";
        }
        virtual ~Shape(){
            cout << "Shape destructor called" << endl;
        }
};

class Rectangle: public Shape {
    public:
        int width, height, area;
        void calculate(){
            cout << "Enter width of rectangle: ";
            cin >> width;
            cout << "Enter height of rectangle: ";
            cin >> height;
            area = width * height;
            cout << "Area of rectangle: " << area << endl;
        }
        virtual ~Rectangle(){
            cout << "Rectangle destructor called" << endl;
        }
};

class Square: public Shape {
    public:
        int side, area;
        void calculate(){
            cout << "Enter one side of your square: ";
            cin >> side;

            area = side * side;
            cout << "Area of square: " << area << endl;
        }
        virtual ~Square(){
            cout << "Square destructor called" << endl;
        }
};

int main()
{
    Base *b;
    Derived *d;
    b = d;

    // Base class version will be called
    b->show();
    // Derived class version will be called
    d->show();

    Animal *a;
    Dog dg;
    a = &dg;
    a->sound();
    a->display();

    Shape *s;
    Rectangle re;
    Square sq;

    s = &re;
    s->calculate();

    s = &sq;
    s->calculate();

    
    return 0;
}