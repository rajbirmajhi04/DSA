#include <iostream>
using namespace std;

/*
? Self refferential structures are those structures that have one or more pointers which point to the same type 
? of structure as their member
*/
struct Node{
    int data1;
    int data2;
    struct Node *link;
};

struct node{
    int x;
    struct node *prev_link;
    struct node *next_link;
};

int main()
{
    struct Node object1;
    object1.link = NULL;
    object1.data1 = 10;
    object1.data2 = 20;

    struct Node object2;
    object2.link = NULL;
    object2.data1 = 30;
    object2.data2 = 40;

    // linking object 1 and object 2
    object1.link = &object2;

    // accessing data memebers using object 1
    cout << object1.link -> data1 << endl;
    cout << object1.link -> data2 << endl;

    struct node n1;
    n1.next_link = NULL;
    n1.prev_link = NULL;
    n1.x = 197;

    struct node n2;
    n2.next_link = NULL;
    n2.prev_link = NULL;
    n2.x = 678;

    struct node n3;
    n3.next_link = NULL;
    n3.prev_link = NULL;
    n3.x = 500;

    // forward links
    n1.next_link = &n2;
    n2.next_link = &n3;

    // backward links
    n2.prev_link = &n1;
    n3.prev_link = &n2;

    // access data of n1, n2 and n3 using n1
    cout << n1.x << endl;
    cout << n1.next_link -> x << endl;
    cout << n1.next_link->next_link -> x << endl;

    // access the data of n1, n2 and n3 using n2
    cout << n2.x << endl;
    cout << n2.prev_link -> x << endl;
    cout << n2.next_link -> x << endl;

    






    return 0;
}