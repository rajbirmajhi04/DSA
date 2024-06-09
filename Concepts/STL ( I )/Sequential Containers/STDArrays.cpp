#include <iostream>
#include <array>
using namespace std;

int main()
{
    // Initializer list
    array<int, 5> numbers = {1, 2, 3, 4, 5};
    array<int, 5> sameVal;

    // Access and Modify
    numbers[1] = 20;
    cout << "Modified Value: " << numbers.at(1) << endl; // out of bound error 
    cout << "Modified value: " << numbers[1] << endl; // Without out of bound error

    // Iterate
    for(const int &i: numbers){
        cout << i << " ";
    }
    cout << endl;

    // Size and Capacity
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.max_size() << endl;

    // Front and Back elements
    cout << "Front: " << numbers.front() << endl;
    cout << "Back: " << numbers.back() << endl;

    // Fill 
    sameVal.fill(7);
    cout << "Array after filling: " << endl;
    for(const int &i: sameVal){
        cout << i << " ";
    }
    cout << endl;

    // Swap
    numbers.swap(sameVal);
    cout << "Array after swapping: " << endl;
    for(const int &i: numbers){
        cout << i << " ";
    }
    cout << endl;

    


}