#include <iostream>
using namespace std;

/*
* Single Inheritance: A class is only allowed to inherit from only one class.
*/

class vehicle {
    vehicle(){
        cout << "This is a vehicle" << endl;
    }
};

class car: public vehicle {
    public:
        car(){
            cout << "This vehicle is car" << endl;
        }
};

/*
* Multiple Inheritance: where a class can inherit from more than one class
*/
class Fourwheeler {
    public:
        Fourwheeler(){
            cout " This is a 4 wheel vehicle" << endl;
        }
};

class Truck: public vehicle, public Fourwheeler {
    cout << "This is a truck" << endl;
};

/*
* Multilevel Inheritance: A derived class is created from another derived class and that derived class can be derived from a base class or any other derived class
*/
class Base {};
class Child1: public Base {};
class Child2: public Child1 {};

/*
* Hierarchical Inheritance: More than one subclass is inherited from a single base class
*/
class Child3: public Base {};
class Child4: public Base {};

/*
* Hybrid Inheritance: Mix of above inheritances
*/

//* Constructors in multiple inheritance
class A1 {
    public:
        A1(){
            cout << "Constructor of the base class A1" << endl;
            int a = 20, b = 35, c;
            c = a + b;
            cout << "Sum: " << c << endl;
        }
};

class A2 {
    public:
        A2(){
            cout << "Constructor of the base class A2" << endl;
            int x = 50, y = 42, z;
            z = x + y;
            cout << "Sum: " << z << endl;
        }
};

class A3 {
    public:
        A3(){
            cout << "Constructor of the base class A3" << endl;
            int p = 78, q = 32, r;
            r = p - q;
            cout << "Difference: " << r << endl;
        }
};

class S: public A1, public A2, virtual A3 {
    public:
        S(): A1(), A2(), A3() {
            cout << "Constructor of the derived class" << endl;
            int s = 40, d = 78, f;
            f = s * d;
            cout << "Product: " << f << endl;
        }
};

//* Working of overloading in inheritance
class Base {
    public:
        int fun(int i){
            cout << "fun(int): ";
            return (i + 3);
        }
};

class Child: public Base {
    public:
        double fun(double d){
            cout << " fun(double): ";
            return (d + 3.3);
        }
};

int main()
{
    S obj;

    Child *ch = new Child;
    cout << ch->fun(3) << endl;
    cout << ch->fun(3.3) << endl;
    delete ch;
    return 0;
}