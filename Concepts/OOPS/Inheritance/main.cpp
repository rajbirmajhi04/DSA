#include <iostream>
using namespace std;

// Base class
class Parent {
    public:
        int parent_id;
        void display_parent_id(){
            cout << "Base ID: " << parent_id << endl;
        }

};

// Child class
class Child: public Parent {
    public:
        int child_id;
        void display_child_id(){
            cout << "Child ID: " << child_id << endl;
        }
};

class A {
    public:
        int x;
    private:
        int z;
    protected:
        int y;
};

class B: public A {
    // x is public
    // y is protected
    // z is not accessible
};

class C: protected A {
    // x is protected
    // y is protected
    // z is not accessible
};

class D: private A {
    // x is private
    // y is private
    // z is not accessible
};

/*
! To access the Private Members of the base class in Derived Class 
* Getter and Setter Method and Friend Class or Functions
*/
class Base {
    private:
        int private_Var;

    public:
        Base(int val): private_Var(val){}
        int getPrivateVar() const {
            return private_Var;
        }
        int setPrivateVar(int val){
            private_Var = val;
        }
        friend class Child;
};

class Derived: public Base {
    public:
        Derived(int val): Base(val){}
        void displayPrivateVar(){
            cout << "Value of private variable: " << getPrivateVar() << endl;
        }

        void modiffyPrivateVar(int val){
            setPrivateVar(val);
        }
};

//* Friend class definition to access the private members of the base class
class Child {
    public:
        void DisplayPrivateVar(Base &obj){
            cout << "Value of private var in base class: " << obj.private_Var << endl;
        }

        void ModifyPrivateVar(Base &obj, int value){
            obj.private_Var = value;
        }
};

int main()
{
    Child ch;

    ch.parent_id = 10;
    ch.display_parent_id();

    ch.child_id = 7;
    ch.display_child_id();

    Derived d(10);
    d.displayPrivateVar();

    d.modiffyPrivateVar(100);
    d.displayPrivateVar();
    return 0;
}