#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <list>
using namespace std;
int main()
{
    /*
        ? Declaring and Initialising 
    */ 

    // Arrays
    array <int, 5> array1 = {1, 2, 3, 4, 5};      // direct initialization
    array <int, 5> array2 = {1, 2, 3};           // direct initialization but incomplete fillings
    array <int, 5> array4(array2);              // copying from another array
    array <int, 5> array3 = {};                // empty initialization with default elements as zeros
    
    // Vectors
    vector <int> v1 = {1, 2, 3, 4, 5};    // direct initialization
    vector <int> v2(5, 9);               // a vector with defined size and default value
    vector <int> v6(v1);                // copy constructor
    vector <int> v3(5);                // vector with defined size
    vector <int> v4;                  // default (empty) initialization

    // Lists
    list <int> list1 = {1, 2, 3, 4, 5};  
    list <int> list2(list1);
    list <int> list3(5, 0);
    list <int> list4(5);
    list <int> list5;

    /*
        ? Iterating 
    */

    // Ranged based iteration
    for(const int &i: array1){
        cout << i << " ";
    }
    cout << endl;

    // Using iterator
    array <int, 5>::iterator it;
    for(auto it = array1.begin(); it != array1.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    // Using const iterator
    for(auto it = array1.cbegin(); it != array1.cend(); it++){
        cout << *it << " ";
    }
    cout << endl;

    // Using reverse iterator
    for(auto it = array1.rbegin(); it != array1.rend(); it++){
        cout << *it << " ";
    }
    cout << endl;

    // Using const reverse iterator
    for(auto it = array1.crbegin(); it != array1.crend(); it++){
        cout << *it << " ";
    }
    cout << endl;

    /*
        ? Basic Operations: 
    */

    // Adding elements
    v4.push_back(5);
    v4.emplace_back(4);
    v4.insert(v4.begin(), 1);
    v4.insert(v4.begin() + 1, 2);
    v4.insert(v4.begin() + 2, 3);
    list5.push_back(500);
    list5.push_front(100);
    list5.insert(list5.begin(), 200);

    // Removing elements
    v4.clear();
    v4.pop_back();
    v4.erase(v4.begin());
    v4.erase(v4.begin(), v4.begin() + 1);
    list5.pop_back();
    list5.pop_front();
    list5.erase(list5.end());
    list5.erase(list5.begin());
    list5.remove(3);

    // Accessing and Modifying elements
    // []: dont give out bound error
    // at: gives out of bound error
    array1[0] = 99;
    array1.at(1) = 56;
    v1[0] = 23;
    v1.at(1) = 54;
    list1.front();
    list1.back();

    return 0;
}