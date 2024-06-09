#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // Initialization
    vector <int> v1; // Empty vector
    vector <int> v2(10, 0); // Vector of integers 10 initialized to 0
    vector <int> v3(10, 5); // Vector of integers 10 initialized to 5
    vector <int> v4 = {1, 2, 3, 4, 5}; // Vector initialized with a list

    // Adding elements
    v1.push_back(10); // add element to the end of the vector
    v1.push_back(20); // add element to the end of the vector
    v1.push_back(30); // add element to the end of the vector
    v1.emplace_back(40); // add element to the end of the vector using in place construction

    // Accessing elements
    int first = v4[0]; // access the first element (no bound checking)
    int second = v4.at(1); // access the second element (bound checking)
    int last = v4.back(); // access the last element
    int front = v4.front(); // access the front element

    // Iterating
    // using index based loop
    cout << "Printing vector 4: "; 
    for(size_t i = 0; i < v4.size(); i++){
        cout << v4[i] << " ";
    }
    cout << endl;

    // using ranged based loop
    cout << "Printing vector 3: ";
    for(const int &i: v3){
        cout << i << " ";
    }
    cout << endl;

    // using iterators
     vector <int>::iterator iter;
    vector <int>::iterator it;
    for(auto it = v1.begin(); it != v1.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    iter = v4.begin() + 1;
    iter = v4.end() - 1;


    // Modifying Elements
    v1[0] = 100;
    v1.at(1) = 200;

    // removind elements
    v1.pop_back(); // removes the last element
    v1.erase(v1.begin()); // removes the first element
    v1.erase(v1.begin(), v1.begin() + 2); // removes the first two elements
    v1.clear(); // removes all elements

    // capacity and size
    size_t size = v1.size(); // Number of elements
    size_t capacity = v1.capacity(); // capacity of the vector
    bool isEmpty = v1.empty(); // check if the vector is empty
    v1.resize(2); // resize the vector to contain two elements
    v1.shrink_to_fit(); // reduce capacity to fit all the size

    // Inserting element
    v1.insert(v1.begin(), 56); // insert 56 at startng index
    v1.insert(v1.end(), 27); // insert 27 at the end of index
    v1.insert(v1.begin() + 1, 10);
    v1.insert(v1.begin() + 2, 100);

    // Sorting and Reversing
    sort(v1.begin(), v1.end()); // sort in ascending order
    reverse(v1.begin(), v1.end()); // reverse the order








    return 0;
}