#include <iostream>
using namespace std;
int main()
{
    /*
    ? Dynamically allocate memory in the Heap and non-static and local variables get memory allcoated in Stack
    ? C lang uses malloc() and calloc() for memory allocation whereas C++ uses new and delete for better memory management
    ? the new() operators denotes a request for memory allcoation on the free store, If sufficient memory is present.

    ! int *pointer_variable = new (int) --> allocates memory for a single int
    ! int *array = new int[10] --> allocates memory for an array 10 ints
    */

    // Method 1
    int *point_Var = new int; // allocate memory for a single int
    *point_Var = 10; // assign value to the allocated memory
    cout << "Single integer value: " << *point_Var << endl;

    delete point_Var;
    point_Var = nullptr;

    // Method 2
    int *pv = new int(45);
    delete pv;
    pv = nullptr;

    // Allocate memory for an array
    int *intArray = new int[5];
    for(int i = 0; i < 5; i++){
        intArray[i] = i * 10;
    }
    for(int i = 0; i < 5; i++){
        cout << intArray[i] << " ";
    }
    cout << endl;
    delete[] intArray;
    intArray = nullptr;

    // Example
    // if not enough memory is not present then new operator throws an error "nothrow"
    int *p = NULL;
    p = new(nothrow) int;

    if(!p){
        cout << "Mmeory allcoation failed!" << endl;
        exit(0);
    }
    else {
        *p = 20;
        cout << "Assigned Value: " << *p << endl;
        delete p;
        p = nullptr;
    }

    int *pV = new(nothrow) int(56);

    // Request block of memory using new. Single step initialization
    float *f = new float(75.25);
    cout << "Assigned Value: " << *f << endl;

    // Request a block of memory of n size
    int size;
    cout << "Enter Size: ";
    cin >> size;
    int *q = new(nothrow) int[size];

    



    





    





    return 0;
}