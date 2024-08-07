#include <iostream>
using namespace std;

/*
* It is a special constructor used to create a new object as a copy of an existing object. It is called when an object is initialized from another object of the same class, when an object is passed by value to a function, or when an object is returned by value from a function.

! Key Points:
? It takes reference to an object of the same class as a parameter
? Compiler provides default copy constrctor if not defined by the user --> performs shallow copy
? If class involves dynamic memory allocation, you should define a custom copy constructor to perform a deep copy to avoid issues like double deletion.
*/

class Sample {
    private: 
        int *ptr;
    
    public:
        Sample(int value){
            ptr = new int;
            *ptr = value;
            cout << "constructor called" << endl;
        }
        Sample(const Sample &obj){
            ptr = new int;
            *ptr = *(obj.ptr);
            cout << "copy constructor called" << endl;
        }
        ~Sample(){
            delete ptr;
            cout << "destructor called" << endl;
        }
        void display(){
            cout << "value: " << *ptr << endl;
        }
};

class DynamicArray {
    private:
        int *array;
        int size;
    public:
        DynamicArray(int s): size(s){
            array = new int[size];
            for(int i = 0; i < size; i++){
                array[i] = i + 1;
            }
            cout << "Array Constructor Called" << endl;
        }
        DynamicArray(const DynamicArray &obj): size(obj.size){
            array = new int[size];
            for(int i = 0; i < size; i++){
                array[i] = obj.array[i];
            }
            cout << "Copy Array Constructor Called" << endl;
        }
        ~DynamicArray(){
            delete[] array;
            cout << "Array Destructor Called" << endl;
        }
        void display() const {
            for(int i = 0; i < size; i++){
                cout << array[i] << " ";
            }
            cout << endl;
        }
};


int main()
{
    Sample s1(11); // constructor called
    Sample s2 = s1; // copy constructor called

    s1.display();
    s2.display();

    DynamicArray array1(5);
    array1.display();

    DynamicArray array2 = array1;
    array2.display();
    return 0;
}