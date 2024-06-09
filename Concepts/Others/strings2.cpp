#include <iostream>
using namespace std;

int main()
{

    string str = "Hello World, wonderful world";
    cout << "String: " << str << endl;

    // find the first occurence 
    size_t first_occurence = str.find("World");

    // find the last occurence
    size_t last_occurence = str.rfind("World");

    if (first_occurence != string::npos){
        cout << "First occurrence: 'world' found at position: " << first_occurence << endl;
        cout << "Last occurrence: 'world' found at position: " << last_occurence << endl;
    }
    else {
        cout << "'world' not found" << endl;
    }

    return 0;
}