#include <iostream>
using namespace std;

/*
* virtual function is also a member function that is declared within a base class and is re-defined (overriden) by a derived class.

* virtual function ensure that the corrct functon is called for an object, regardless of the type of reference (or pointer) used for the function call
* they are mainly used to achieve runtime polymorphism
* function are declared with a virtual keyword in base class
* resolving of a function call is done at runtime
*/

/*
! Rules:
* virtual functions cannot be static
* a virtual function can be a friend function of another class
* virtual functions should be accessed using a pointer or reference of base class type to achieve runtime polymorphism
* the prototype of virtual functions should be the same in the base as well as the derived class
* they are always defined in the base class and overridden in a derived class. It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used
* a class may have a virtual destructor but it cannot have a virtual constructor
*/












int main()
{
    return 0;
}