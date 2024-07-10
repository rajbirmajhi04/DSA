#include <iostream>
using namespace std;

// Pass By Value
void addition(int a, int b){
    int result = a + b;
    cout << "Sum: " << result << endl;
}

// Pass By Reference with Pointer 
void substract(int *a, int *b){
    int result = *a - *b;
    cout << "Substracted: " << result << endl;
}

// Pass By Reference with Reference Argument
void divide(int &a, int &b){
    int result = a / b;
    cout << "Divided: " << result << endl;
}

int main()
{
    // Pass By Value
    int x = 5, y = 10;
    addition(x, y);

    // Pass By Reference with Pointer
    int z = 7, r = 8;
    int *ptr1 = &z;
    int *ptr2 = &r;
    substract(ptr2, ptr1);

    // Pass By Reference with Reference
    int q = 6, t = 8;
    divide(q, t);

    return 0;
}