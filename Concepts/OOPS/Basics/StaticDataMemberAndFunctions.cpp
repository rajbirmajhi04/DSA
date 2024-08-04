#include <iostream>
using namespace std;

/*
* Static Data Members: 
? Only one copy of that member is created for the entire class and is shared by all the objects of that class no matter how many objects are created.
*/
class Base {
    public:
        static int x;
        Base(){
            cout << "Base constructor called" << endl;
        }
};
/*
* Static data members cannot be initialized inside the class but can be initialized outisde the class using scope resoultion operator
*/
int Base::x = 2;

int main()
{
    cout << "Accessing the static data member: " << Base::x << endl;
    return 0;
}