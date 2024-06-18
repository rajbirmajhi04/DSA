#include <iostream>
using namespace std;

// define node structure
struct Node {
    int data;
    struct Node *next;
};

// functon to create a new node
struct Node *createNode(int data){
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

// function to insert a node at the beginnning of a linked list
void insertAtHead(struct Node **head, int data){
    struct Node *newNode = createNode(data);
    newNode -> next = *head;
    *head = newNode;
}

// function to insert a node at the end of the linked list
void insertAtEnd(struct Node **head, int data){
    struct Node *newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

// function to insert at the middle
void insertAtMiddle(struct Node **head, int data){
    struct Node *newNode = createNode(data);

    // if list is empty, the new node is the head
    if(*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *slow = *head;
    struct Node *fast = *head;
    struct Node *previous = NULL;

    // use two pointer technique to find the middle
    while (fast != NULL && fast->next != NULL){
        fast = fast -> next -> next;
        previous = slow;
        slow = slow -> next;
    }

    // insert the new node
    newNode->next = slow;
    if(previous != NULL){
        previous -> next = newNode;
    }
    else {
        *head = newNode; // this case handles if there's only one element in the list
    }
}
// delete a node
void deleteNode(struct Node **head, int key){
    struct Node *temp = *head;
    struct Node *previous = NULL;

    // if the head node itself holds the key
    if(temp != NULL && temp -> data == key){
        *head = temp -> next;
        free(temp);
        return;
    }    

    // search for the key to be deleted
    while (temp != NULL && temp -> data != key){
        previous = temp;
        temp = temp -> next;
    }

    // if key is not present in the list
    if(temp == NULL){
        cout << "Key not found!" << endl;
        return;
    }

    // unlink the node from the linked list
    previous -> next = temp -> next;
    free(temp);
}

// display linked list
void display(struct Node *head){
    struct Node *temp = head;
    while (temp != NULL){
        cout << temp -> data << " --> ";
        temp = temp -> next;
    }
    cout << endl;
}

// function to free the entire list
void freeList(struct Node *head){
    struct Node *temp;
    while(head != NULL){
        temp = head;
        head = head -> next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 10);
    insertAtHead(&head, 50);
    insertAtHead(&head, 60);
    insertAtHead(&head, 70);
    insertAtHead(&head, 80);

    cout << "Displaying Linked List: " << endl;
    display(head);

    cout << "Deleting node with data 20" << endl;
    deleteNode(&head, 20);

    cout << "Displaying Linked List after deletion: " << endl;
    display(head);

    cout << "Inserting 250 at middle of list: " << endl;
    insertAtMiddle(&head, 250);

    cout << "Displaying Linked List: " << endl;
    display(head);

    freeList(head);
    return 0;
}