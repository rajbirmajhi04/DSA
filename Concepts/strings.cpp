#include <iostream>
using namespace std;
int main()
{
    //C-strings are arrays of type char terminated with a null character, that is, \0 (ASCII value of null character is 0).
    char str[] = "c++";
    char str[4] = "c++";
    char str[] = {'c', '+', '+', '\0'};
    char str[4] = {'c', '+', '+', '\0'};

    // working 
    char string[100];

    cout << "Enter string: ";
    cin >> string;
    cout << "Entered: " << string << endl;

    // if you enter space between strings then strings after whitespaces will be excluded
    cout << "Enter another string: ";
    cin >> string;
    cout << "Entered: " << string << endl;

    // to include everything 
    cout << "Enter a new string: ";
    cin.get(string, 100);
    cout << "You entered: " << string << endl;

    //string object: unlike char arrays string objects have no fixed lenght and can be
    //extended as per requirement.

    



    return 0;
}