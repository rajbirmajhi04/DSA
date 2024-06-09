#include <iostream>
using namespace std;

// function prototype
void display(char *);
void display(string);

int main()
{
    /*//C-strings are arrays of type char terminated with a null character, that is, \0 (ASCII value of null character is 0).
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
    //extended as per requirement. getline()
    string string_object;
    cout << "Enter a string object: ";
    getline(cin, string_object);
    cout << "Entered data: "<< endl;
    cout << string_object;*/
    
    string str1;
    char str[100];

    cout << "Enter a string: ";
    getline(cin, str1);

    cout << "Enter another string: ";
    cin.get(str, 100, '\n');

    display(str1);
    display(str);
    return 0;
    
}

void display(char s[])
{
    cout << "Entered char array is: " << s << endl;
}

void display(string s)
{
    cout << "Entered string is: " << s << endl;
}

