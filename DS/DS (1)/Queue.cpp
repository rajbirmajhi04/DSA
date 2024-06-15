#include <iostream>
using namespace std;

const int size = 5;

struct Queue {
    int front, rear;
    int items[size];
};

void initialize(struct Queue &q){
    q.front = -1;
    q.rear = -1;
}

bool isFull(struct Queue &q){
    return q.rear == size - 1 && q.front == 0;
}

bool isEmpty(struct Queue &q){
    return q.front > q.rear || q.front == -1;
}

void enqueue(struct Queue &q, int newData){
    if(isFull(q)){
        cout << "Queue Overflow" << endl;
        return;
    }
    if (q.front == -1) {
        q.front = 0;
    }
    q.rear++;
    q.items[q.rear] = newData;
    cout << "Enqueued: " << newData << endl;
}

int dequeue(struct Queue &q){
    if(isEmpty(q)){
        cout << "Queue Underflow" << endl;
        return -1;
    }
    int pop = q.items[q.front];
    q.front++;
    // If the queue becomes empty, reset it
    if (q.front > q.rear) {
        q.front = q.rear = -1;
    }
    return pop;
}

void displayQueue(struct Queue &q){
    if(isEmpty(q)){
        cout << "Empty queue!" << endl;
        return;
    }
    cout << "Queue: ";
    for(int i = q.front; i <= q.rear; i++){
        cout << q.items[i] << " ";
    }
    cout << endl;
}

int main()
{
    struct Queue q;
    initialize(q);

    enqueue(q, 10);
    enqueue(q, 11);
    enqueue(q, 12);
    enqueue(q, 13);
    enqueue(q, 14);

    displayQueue(q);

    cout << "Dequeue Element: " << dequeue(q) << endl;

    enqueue(q, 20);
    displayQueue(q);

    return 0;
}
