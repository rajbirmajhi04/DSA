#include <iostream>
using namespace std;

/*
* A class declared inside a function becomes local to that function
? A local class name can only be used locally
? The methods of a local class must be defined inside it only
? A local class can have static functions but not static data members
*/

/*
! A local class type name can only be used in the enclosing function
*/
void fun(){
    // Local Class
    class Test {};

    // Fine
    Test t;
    Test *tp;
}

/*
! All the methods of the local classes must be defined inside the class only.
*/
void fun1(){
    class Test {
        public:
            void method(){
                cout << "Local class method" << endl;
            }
            void method2();
    };

    // Error
    // void Test::method2(){}

    Test t;
    t.method();
}

/*
!  A Local class cannot contain static data members. It may contain static functions though.
*/
void fun2(){
    class Test {
        // Error
        // static int x;

        public:
            static void method(){
                cout << "Local class method" << endl;
            }
    };
    Test t;
    t.method();
}

/*
!  Member methods of the local class can only access static and enum variables of the enclosing function. Non-static variables of the enclosing function are not accessible inside local classes.
*/
void fun3(){
    
    static int x;
    enum {i = 1,j = 2};

    class Test {
        public:
            void method(){
                cout << x << endl;
                cout << i << endl;
                cout << j << endl;
            }
    };
    Test t;
    t.method();
}

/*
! Local classes can access global types, variables, and functions
*/
// Glocal variable 
int x;

void fun4(){    
    // First local class
    class Test1 {
        public:
            Test1(){
                cout << "Test1::Test1()" << endl;
            }
    };

    // Second local class
    class Test2 {
        public:
            // Fine! A local class can use other local class
            Test1 t1;
            void method(){
                // Local class member methods can access global variables
                cout << x << endl;
            }
    };
    Test2 t2;
    t2.method();

}



int main()
{
    // Error
    // Test t;
    // Test *tp;

    fun1();
    fun2();
    fun3();
    return 0;
}