#include <iostream>
using namespace std;

struct Node {
    int data; // data item
    struct Node *next; //address of next node
};

int main()
{
    // initialize node
    struct Node *head;
    struct Node *one = NULL;
    struct Node *two = NULL;
    struct Node *three = NULL;
    struct Node *four = NULL;

    // allocate 3 nodes in the heap
    one = new Node();
    two = new Node();
    three = new Node();
    four = new Node();

    // assign values
    one -> data = 1;
    two -> data = 2;
    three -> data = 3;
    four -> data = 4;

    // connect nodes
    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = NULL;

    // traversal
    head = one;
    while(head != NULL){
        cout << head -> data << " ---> ";
        head = head -> next;
    }
    return 0;
}