#include <iostream>
using namespace std;

// node structre
struct Node {
    int data;
    struct Node *next;
    struct Node *previous;
};

// function to create a new node
struct Node *createNode(int data){
    struct Node *newNode;
    newNode = new Node();
    newNode -> data = data;
    newNode -> next = nullptr;
    newNode -> previous = nullptr;
    return newNode;
}

void insertAtBeginning(struct Node **head, int data){
    struct Node *newNode = createNode(data);
    if(*head == nullptr){
        *head = newNode;
        return;
    }
    // link new node with current head
    newNode->next = *head;
    // update the current head's previous pointer
    (*head)->previous = newNode;
    // update the head pointer
    *head = newNode;
}

void insertAtEnd(struct Node **head, int data){
    struct Node *newNode = createNode(data);
    if(*head == nullptr){
        *head = newNode;
        return;
    }
    // create a temp pointer and set it to head
    struct Node *temp = *head;
    // traverse
    while(temp -> next != nullptr){
        temp = temp -> next;
    }
    // link the new node to the last node
    temp -> next = newNode;
    newNode -> previous = temp;
}

void insertAfter(struct Node **head, int key, int data){
    struct Node *temp = *head;

    // find the node with the given key
    while(temp != nullptr && temp -> data != key){
        temp = temp -> next;
    }
    
    // if the key is not found return
    if(temp == nullptr){
        cout << "Key not found!" << endl;
        return;
    }

    // create a new node
    struct Node *newNode = createNode(data);

    // set the new node's next to the temp's next
    newNode->next = temp->next;

    // set the new node's prev to temp
    newNode->previous = temp;

    // if the temp's next is not null then set the temp's next's prev to newnode
    if(temp->next != nullptr){
        temp->next->previous = newNode;
    }

    // set the temp's next to new node
    temp->next = newNode;
}

void deleteNode(Node** head, int data) {
    // if the head is null then deletion is not possible
    if (*head == nullptr) return;
    
    // create a temp pointer
    Node* temp = *head;

    // traverse through each node using temp pointer
    while (temp != nullptr && temp->data != data) {
        temp = temp->next;
    }

    // if temp becomes null
    if (temp == nullptr) return;

    // if node to be deleted is not in the first node, set the next pointer 
    // of the previous node to the node following
    if (temp->previous != nullptr) {
        temp->previous->next = temp->next;
    } else {
        *head = temp->next;
    }

    // update the next node's previous pointer
    if (temp->next != nullptr) {
        temp->next->previous = temp->previous;
    }

    // free up memory
    delete temp;
}

void displayList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " <--> ";
        head = head->next;
    }
    cout << std::endl;
}

int main()
{
    Node *head = nullptr;
    insertAtBeginning(&head, 50);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 60);
    insertAtEnd(&head, 70);
    insertAtEnd(&head, 80);
    insertAtEnd(&head, 90);
    insertAtEnd(&head, 100);

    cout << "Displaying Doubly Linked List: " << endl;
    displayList(head);
    

    return 0;
}