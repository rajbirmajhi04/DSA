#include <iostream>
using namespace std;


struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data){
    struct Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertAtBeginning(struct Node **head, int data){
    // create a new node
    struct Node *newNode = createNode(data);

    // check if the circular linked list is empty
    if(*head == nullptr){
        // if empty then set newNode.next to newNode
        newNode->next = newNode;
        // then ehad is updated to point to this new node
        *head = newNode;
    }
    else {
        // initialize a temp pointer pointing to head
        struct Node *temp = *head;
        //traverse the list until it reaches the last node
        while (temp->next != *head){
            // update temp's next poiinter
            temp = temp->next;
        }
        // next pointer of the new node is set to the current head node
        newNode->next = *head;
        // next pointer of the last node is updated to point to the new node
        temp->next = newNode;
        // finally head is updated to point to the new node
        *head = newNode;
    }
}

void insertAtEnd(struct Node **head, int data){
    struct Node *newNode = createNode(data);
    if(*head == nullptr){
        newNode->next = newNode;
        *head = newNode;
    }
    else {
        struct Node *temp = *head;
        while (temp->next != *head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertBetween(struct Node *head, int data, int pos){
    // check if the list is empty
    if(head == nullptr){
        cout << "Circular Linked List is Empty!" << endl;
        return;
    }
    // create a new node
    Node *newNode = createNode(data);
    // initialize a temp pointer to point to the head of the list
    Node *temp = head;
    // for loop to traverse the list to reach the node just before the 
    // desired position. the loop stops if the next node is the head, 
    // indicating we have looped through the entire list
    for(int i = 1; i < pos - 1 && temp->next != head; i++){
        temp = temp->next;
    } 
    // check if the position is valid
    if(temp->next == head && pos > 1){
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }
    // insert the new node
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(struct Node *head, int key){
    if(head == nullptr){
        cout << "List is empty!" << endl;
        return;
    }
 Node* temp = head;
    Node* prev = nullptr;

    // If head needs to be removed
    if (temp != nullptr && temp->data == key) {
        if (temp->next == head) {
            head = nullptr; // Only one node in the list
            delete temp;
            return;
        }

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = head->next;
        delete head;
        head = temp->next;
        return;
    }

    // Search for the node to be deleted
    while (temp->next != head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Node not found
    if (temp->data != key) {
        cout << "Node not found." << endl;
        return;
    }

    // Node found, unlink it
    prev->next = temp->next;
    delete temp;
}













int main()
{
    return 0;
}