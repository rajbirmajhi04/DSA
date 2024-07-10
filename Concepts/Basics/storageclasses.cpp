#include <iostream>
using namespace std;

// auto: local variables declared in a block automatically belongs to this class
void autoStorageClass(){
    int number = 10;
    cout << "Number: " << number << endl;
}

// extern: basically it is a global variable
// defualt value is zero;
int x;
void externalStorageClass(){
    extern int x;
    cout << "External variable (before change): " << x << endl;
    x = 5;
    cout << "External variable (after change): " << x << endl;
}

// static: preserve their value even after they are out of their scope
// function containing static variables memory is retained during exection
int static_func(){
    static int count = 0;
    count++;
    return count; 
}
// function containing non static variables memory is destroyed
int nonstatic_func(){
    int count = 0;
    count++;
    return count;
}

// register: same as auto but the compiler tries to store these variables in the register
// of the microprocessor, if a free register is available. this makes the use of register 
// variables much faster than that of the variables that are stored in the memory.
// Address of register variables cannot be obtained by pointers.
void registerStorageClass(){
    register char b = 'b';
    cout << "value of varible b decalred as register: " << b << endl;
}


int main()
{
    autoStorageClass();
    externalStorageClass();
    cout << "Static Variables: " << static_func() << endl;
    cout << "Static Variables: " << static_func() << endl;
    cout << "Non Static Variables: " << nonstatic_func() << endl;
    cout << "Non Static Variables: " << nonstatic_func() << endl;
    registerStorageClass();
    return 0;
}