#include <iostream>
using namespace std;

/*
* Shallow Copy: copies all the member fields values. However if the object contains pointer, the shallow copy will copy the pointer values not the data they point to. Means both the original and the copied object will point to the same memory location for any pointer members. This can lead to issues.
*/
class Shallow {
    public:
        int *data;
        Shallow(int value){
            data = new int(value);
        }
        void display(){
            cout << "Value: " << *data << endl;
            cout << "Address: " << data << endl;
        }
        ~Shallow(){
            delete data;
        }
};

/*
* Deep Copy: Involes creating a new copy of the actual data that any pointer members point to not just copying the pointer values. Ensures that the original and copied objects are completely independent of each other, with separate memory allocations. Modifying one object's data does not affect the other and when object is destroyed the other retains its own data.
*/

class Deep {
    public:
        int *data;
        Deep(int value){
            data = new int(value);
        }
        // deep copy constructor (user defined)
        Deep(const Deep& other){
            data = new int(*other.data);
        }
        void display(){
            cout << "Value: " << *data << endl;
            cout << "Address: " << data << endl;
        }
        ~Deep(){
            delete data;
        }
};

int main()
{
    Shallow original(55);
    original.display();

    Shallow copy = original; // shallow copy
    original.display();

    Deep original_deep(56);
    original_deep.display();

    Deep copy_deep = original_deep;
    copy_deep.display();
   
 
    return 0;
}