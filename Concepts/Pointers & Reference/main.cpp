#include <iostream>
using namespace std;

// call by value
int square1(int n){
    // address of n in square1 is not the same as n1 in main()
    cout << "address of n1 in square1(): " << &n << endl;
    // clone the modified inside the function
    n = n * n;
    return n;
}
// pass by reference with pointer arguments
int square2(int *n){
    // address of n in square2 is same as the n2 in main()
    cout << "Address of n2 in square2(): " << &n << endl;
    // explicit de-referencing to get the value pointed to
    *n = *n * *n;
}
// pass by reference with reference arguments
int square3(int &n){
    cout << "Address of n3 in square3(): " << &n << endl;
    // implicit de-referencing to get the value pointed to (without *)
    n = n * n;
}

int main()
{
    // Pointers
    int x = 10;
    // storing address &x in pointer *pointer
    int *pointer = &x;
    cout << "Address: " << pointer << endl;
    cout << "Value: " << *pointer << endl;

    // Changing value pointed by pointers
    *pointer = 20; 
    cout << "Address: " << pointer << endl;
    cout << "New Value: " << *pointer << endl;
    
    /*
        There are 3 ways to pass arguments into a function:
        1) call-by-value
        2) call-by-reference with a pointer argument
        3) call-by-reference with a reference argument
    */

    // call by value
    int n1 = 8;
    cout << "address of n1 in main(): " << &n1 << endl;
    cout << "square of n1: " << square1(n1) << endl;
    cout << "no change in n1: " << n1 << endl;

    cout << "*****************************" << endl;

    // call by reference with pointer argument
    int n2 = 10;
    cout << "address of n2 in main(): " << &n2 << endl;
    square2(&n2);
    cout << "square of n2: " << n2 << endl;
    cout << "change refelected in n2: " << n2 << endl;

    cout << "*****************************" << endl;

    // call by refernce with reference argument
    int n3 = 4;
    cout << "address of n3 in main(): " << &n3 << endl;
    square3(n3);
    cout << "square of n3: " << n3 << endl;
    cout << "change refelected in n3: " << n3 << endl;

    cout << "*****************************" << endl;

    /*
        Array name as pointers: an array name contains teh address of teh first elements of the array which acts like a cosntant 
        pointer. it means the address stored in the array cant be changed. 
    */

    // declare array
    int val[3] = {1, 2, 3};

    // declare pointer and assign address (way 1)
    int *arrayPointer = &val[0];

    // declare pointer and assign address (way 2)
    int *arrayPointer1 = val;

    cout << "Elements of the array are: ";
    cout << arrayPointer[0] << " " << arrayPointer[1] << " " << arrayPointer[2] << endl;

    // Pointer expressions and Pointer arithmetic
    // ++, --, +, - and difference between two pointer

    int v[3] = {1, 2, 3};
    int *ptr;
    ptr = v;
    for(int i = 0; i < 3; i++){
        cout << "Address ptr: " << ptr << endl;
        cout << "Value at *ptr: " << *ptr << endl;
        ptr++;
    }

    cout << *(ptr + 0) << endl;
    cout << *(ptr + 1) << endl;
    cout << *(ptr + 2) << endl;

    // double pointer is used when we want to store the address of another pointer
    int var = 720;
    int *var1 = &var;
    int **var2 = &var1;

    cout << var << endl;
    cout << *var1 << endl;
    cout << **var2 << endl;

    // chain of pointers
    int ***var3 = &var2;

    // pointer to multidimensional array
    int array[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int (*p)[4] = array;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++) {
            cout << *(*(array + i) + j) << " ";
        }
        cout << endl;
    } 

    // dereferencing 
    cout << p << p + 1 << p + 2 << p + 3 << endl;
    cout << *p << *(p + 1) << *(p + 2) << *(p + 3) << endl;
    cout << **p << *(*(p + 1)) << *(*(p + 2)) << *(*(p + 3)) << endl;

    // pointers to constant
    // value pointed by the pointer cannot be changed but the pointer itself can be changed 
    int high{100};
    int low{60};

    const int* score{&high};

    cout << *score << endl;

    score = &low;
    cout << *score << endl;

    // cosntant pointers
    // the pointer points to a fixed memory location and the value at the location can be changed
    int* const point{&high};
    *point = 56;

    cout << *point << endl;
    cout << point << endl;

    // constant pointers to constant
    // both the data and the pointer cannot be changed
    const int* const pr{&high};

    


















   











    



    return 0;
}