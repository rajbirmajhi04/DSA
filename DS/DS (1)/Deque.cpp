#include <iostream>
using namespace std;

const int size = 5;
int item[size];
int front = -1;
int rear = -1;

bool isEmpty(){return front == -1;}
bool isFull(){return ((front == 0 && rear == size - 1) || (front = rear + 1));}


void insertFront(int value){
    if(isFull()){
        cout << "Already Full" << endl;
        return;
    }
    if(isEmpty()){front = 0, rear = 0;}
    else if (front == 0){front = size - 1;}
    else {front = front - 1;}
    item[front] = value;
}

void insertRear(int value){
    if(isFull()){
        cout << "Already Full!" << endl;
        return;
    }
    else if (rear == size - 1){
        rear = 0;
    }
    else {
        rear = rear + 1;
    }
    item[rear] = value;
}

void deleteFront(){
    if(isEmpty()){
        cout << "Already Empty!" << endl;
        return;
    }
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else if(front == size - 1) {
        front = 0;
    }
    else {
        front = front - 1;
    }
}

void deleteRear(){
    if(isEmpty()){
        cout << "Already Empty!" << endl;
        return;
    }
    if (front == rear){
        front = -1;
        rear = -1;
    }
    else if (rear == 0){
        rear = size - 1;
    }
    else {
        rear = rear - 1;
    }
}

int getFront(){
    if(isEmpty()){
        cout << "Already Empty!" << endl;
        return -1;
    }
    return item[front];
}

int getRear(){
    if(isEmpty() || rear < 0){
        cout << "Already Empty!" << endl;
        return -1;
    }
    return item[rear];
}

int main()
{
    insertRear(5);
    insertRear(10);
    cout << "Rear Elment: " << getRear() << endl;

    insertFront(100);
    insertFront(150);
    cout << "Front Element: " << getFront() << endl;

    deleteFront();
    cout << "After front deletion: " << getFront() << endl;
    deleteRear();
    cout << "After rear deletion: " << getRear() << endl;
    return 0;
}