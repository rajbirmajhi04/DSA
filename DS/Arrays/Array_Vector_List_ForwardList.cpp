#include <forward_list>
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

     // Initialization
    forward_list <int> flist1 = {1, 2, 3, 4, 5};
    forward_list <int> flist6 = {5, 3, 4, 2, 1};
    forward_list <int> flist2(flist1);
    forward_list <int> flist3(5, 0);
    forward_list <int> flist4(5);
    forward_list <int> flist5;

    // Assign elements
    flist1.assign({50, 60, 70, 80, 90}); // Assign new contents to the list by replacing the current contents

    // Insert elements
    flist1.push_front(10);
    flist1.push_front(20);
    flist1.emplace_front(30);

    // Insert after a given position
    auto it = flist1.begin();
    // flist1.insert_after(it, 40);
    // flist1.insert_after(it, 45);

    // Removing elements
    flist1.pop_front();
    flist1.remove(20); // removes element with value 20
    flist1.remove_if([](int x){return x > 45;}); // remove element based on condition
    flist1.erase_after(flist1.begin()); // remove element after the first element

    // Resizing
    flist1.resize(3); // resize to contain 3 elements
    flist1.resize(5, 100); // resize to fit 5 elements, new elements initialized to 100;

    // Operations
    flist1.reverse();
    flist1.unique();
    flist1.sort();

    flist1.merge(flist6);
    flist1.splice_after(flist1.begin(), flist6); // transfer elements

    // Size and Capacity
    // size and capacity measured manually
    size_t count = distance(flist1.begin(), flist1.end());

    return 0;
}