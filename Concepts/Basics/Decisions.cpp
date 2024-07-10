#include <iostream>
using namespace std;
int main()
{
    label1:
        cout << "Even" << endl;
        return 0;
    
    label2: 
        cout << "Odd" << endl;
        return 0;

    int n = 4;
    if(n % 2 == 0){
        goto label1;
    }
    else {
        goto label2;
    }

    for (int i = 1; i < 10; i++) {
        if (i == 5)
            continue;
        cout << i << " ";
    }

    for (int i = 1; i < 10; i++) {
        // Breaking Condition
        if (i == 5)
            break;
        cout << i << " ";
    }

    cout << "Begin ";
    for (int i = 0; i < 10; i++) {
        // Termination condition
        if (i == 5)
            return 0;
        cout << i << " ";
    }
    cout << "end";

    // switch variable
    char x = 'A';

    // switch statements
    switch (x) {
    case 'A':
        cout << "Choice is A";
        break;
    case 'B':
        cout << "Choice is B";
        break;
    case 'C':
        cout << "Choice is C";
        break;
    default:
        cout << "Choice other than A, B and C";
        break;
    }


    return 0;
}