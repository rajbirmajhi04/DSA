#include <iostream>
#include <forward_list>
using namespace std;
int main()
{

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
    flist1.insert_after(it, 40);
    flist1.insert_after(it, 45);

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