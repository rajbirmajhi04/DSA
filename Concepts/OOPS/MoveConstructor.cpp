#include <iostream>
#include <utility>
using namespace std;

/*
* Used to move resources from one object to another rather than copying them.
! Key Points:
? R Value Reference: Moves constructors typically take an rvalue reference to the object they are moving. An rvalue reference is denoted by "Type&&" and allows modification of temp objects.
? Resource Transfer: the move constructor transfers resources (like dynamic memory) from the source object to the new object leaving the source in a valid but unspecified state.
*/

class Sample {
    private:
        int *data;
    
    public:
        Sample(int value): data(new int(value)){
            cout << "constructor called, data" << *data << endl;
        }
        ~Sample(){
            delete data;
            cout << "destructor called" << endl;
        }
        Sample(const Sample &obj): data(new int(*obj.data)){
            cout << "copy constructor called" << endl;
        }
        Sample(Sample &&obj) noexcept: data(new int(*obj.data)){
            obj.data = nullptr;
            cout << "move constructor called" << endl;
        }
        // method to access the data
        int getData() const{
            return data ? *data: 0;
        }
};

int main()
{
    return 0;
}