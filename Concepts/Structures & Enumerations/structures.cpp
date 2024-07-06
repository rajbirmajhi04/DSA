#include <iostream>
using namespace std;

struct variables {
    int var1;
    char var2;
    float var3;
    double var4;
};

struct point {
    int x, y;
};

typedef struct Employee {
    string name;
} emp;

int main()
{   
    // Method 1
    struct variables v;

    // Method 2
    emp emp1;
    emp emp2;
    emp emp3;
    emp emp4;

    v.var1 = 76;
    v.var2 = 'A';
    v.var3 = 45.56F;
    v.var4 = 45.56;

    cout << "Integer: "<< v.var1 << endl; 
    cout << "Char: "<< v.var2 << endl; 
    cout << "Float: "<< v.var3 << endl; 
    cout << "double: "<< v.var4 << endl; 
    
    struct point p1 = {0, 1}; // valid initialization
    cout << "value of x: " << p1.x << endl;
    cout << "value of y: " << p1.y << endl;

    // array of structures
    struct point arr[10];
    arr[0].x = 10;
    arr[0].y = 20;

    cout << arr[0].x << " " << arr[0].y << endl;



    






    
   

    


















    return 0;
}