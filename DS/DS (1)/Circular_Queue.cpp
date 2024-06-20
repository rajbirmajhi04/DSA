#include <iostream>
using namespace std;

typedef struct CircularQueue {
    int *array, front, rear, size;
}cq;

void initialize(CircularQueue &cq, int size){
    cq.size = size;
    cq.array = new int[size];
    cq.front = -1;
    cq.rear = -1;
}

bool isFull(const CircularQueue &cq){
    return cq.front == ((cq.rear + 1) % cq.size);
}

bool isEmpty(const CircularQueue &cq){
    return (cq.front == -1);
}   

void enqueue(CircularQueue &cq, int value){
    if(isFull(cq)){
        cout << "Already Full!" << endl;
        return;
    }
    if(isEmpty(cq)){
        cq.front = 0;
    }
    cq.rear = ((cq.rear + 1) % cq.size);
    cq.array[cq.rear] = value;
}

int dequeue(CircularQueue &cq){
    if(isEmpty(cq)){
        cout << "Already Empty!" << endl;
        return -1;
    }
    int value = cq.array[cq.front];
    if(cq.front == cq.rear){
        cq.front = cq.rear = -1; // queue is now empty
    }
    else {
        cq.front = ((cq.front + 1) % cq.size);
    }
    return value;
}

void displayQueue(const CircularQueue &cq){
    if(isEmpty(cq)){
        cout << "Already Empty!" << endl;
        return;
    }
    else {
        cout << "Displaying Circular Queue: ";
        for(int i = cq.front; i < cq.rear; i++){
            cout << cq.array[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    
    int size = 5;
    
    CircularQueue cq;
    initialize(cq, size);

    enqueue(cq, 10);
    enqueue(cq, 20);
    enqueue(cq, 30);
    enqueue(cq, 40);
    enqueue(cq, 50);

    displayQueue(cq);

    cout << "Dequeued: " << dequeue(cq) << endl;
    cout << "Dequeued: " << dequeue(cq) << endl;

    displayQueue(cq);
    return 0;
}