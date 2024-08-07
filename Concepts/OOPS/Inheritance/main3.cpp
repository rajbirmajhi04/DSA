#include <iostream>
using namespace std;

/*
* Most obvious problem with multiple inheritance occurs during function overriding is Ambiguity
* This problem can be solved using scope resolution to specify.
*/

class Base1 {
    public:
        void someFunction() {
            cout << "Function 1" << endl;
        }
};

class Base2 {
    public:
        void someFunction(){
            cout << "Function 2" << endl;
        }
};

class Derived: public Base1, public Base2 {

};

/*
* Virtual Inheritance: is a technique that makes sure that the grandchild derived classes inherits only one copy of a base class's member variables.
*/
class Animal {
    private:
        string species_name;
    
    public:
        Animal(const string &name): species_name(name){
            cout << "Animal constructor called" << endl;
        }

        void show_species() const {
            cout << "This animal belongs to the species" << species_name << endl;
        }
};

class WingedAnimal: virtual public Animal {
    public:
        WingedAnimal(const string &name): Animal(name){
            cout << "Winged Animal constructor called" << endl;
        }
};

class Mamal: virtual public Animal {
    public:
        Mamal(const string &name): Animal(name){
            cout << "Mamals constructor called" << endl;
        }
};

class Bat: public WingedAnimal, public Mamal {
    public:
        Bat(): Animal("Bat"), WingedAnimal("Bat"), Mamal("Bat"){}
        void show_info(){
            cout << "It's an unique animal! Here are some details: " << endl;
            show_info();
        }
};

int main()
{
    Derived d;
    d.Base1::someFunction();
    d.Base2::someFunction();

    Bat myBat;
    myBat.show_info();
    return 0;
}