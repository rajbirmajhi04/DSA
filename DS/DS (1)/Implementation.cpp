#include <iostream>
using namespace std;

// stack structure
struct Stack
{   
    int *stack_Array;
    int size;
    int top;

    Stack(int size) {
        this -> size = size;
        stack_Array = new int[size];
        top = -1;
    }

    bool isFull(){
        return (top == size - 1);
    }
    bool isEmpty(){
        return (top == -1);
    }

    void push(int value){
        if(isFull()){
            cout << "Stack Overflow!" << endl;
            return;
        }
        else {
            stack_Array[++top] = value;
        }
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack Underflow!" << endl;
            return;
        }
        else {
            stack_Array[top--];
        }
    }

    void display(){
        if(isEmpty()){
            cout << "Stack Underflow!" << endl;
            return;
        }
        else {
            for(int i = 0; i <= top; i++){
                cout << stack_Array[i] << " ";
            }
            cout << endl;
        }
    }

    ~Stack(){
        delete[] stack_Array;
    }
};

// Queue Structure
struct Queue 
{
    int *queue_Array;
    int size;
    int front;
    int rear;

    Queue(int size){
        this -> size = size;
        queue_Array = new int[size];
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return (rear = size - 1);
    }
    bool isEmpty(){
        return (front = -1);
    }

    void Enqueue(int value){
        if(isFull()){
            cout << "Queue Overflow!" << endl;
            return;
        }
        if(front = -1){
            front = 0;
        }
        queue_Array[rear++] = value;
    }
    int dequeue(){
        if(isEmpty()){
            cout << "Queue Underflow!" << endl;
            return;
        }
        int pop = queue_Array[front++];
        if(front > rear){
            front = -1;
            rear = -1;
        }
        return pop;
    }

    void display(){
        if(isEmpty()){
            cout << "Queue Undeflow!" << endl;
            return;
        }
        else {
            for(int i = 0; i <= size; i++){
                cout << queue_Array[i] << " ";
            }
            cout << endl;
        }
    }

    ~Queue(){
        delete[] queue_Array;
    }
};

// Circular Queue Structure
struct CircularQueue
{
    int *circularqueue_Array;
    int size;
    int front;
    int rear;

    CircularQueue(int size){
        this -> size = size;
        circularqueue_Array = new int[size];
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return (front = (rear + 1) % size);
    }
    bool isEmpty(){
        return (front == -1);
    }

    void enqueue(int value){
        if(isFull()){
            cout << "Circular Queue Overflow!" << endl;
            return;
        }
        if(isEmpty()){
            cout << "Circular Queue Underflow! " << endl;
        }
        rear = ((rear + 1) % size);
        circularqueue_Array[rear] = value;
    }

    int dequeue(){
        if(isEmpty()){
            cout << "Circular Queue Overflow!" << endl;
            return -1;
        }
        int val = circularqueue_Array[front];
        if(front == rear){
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
        return val;
    }

    void display(){
        if(isEmpty()){
            cout << "Circular Queue Underflow!" << endl;
            return;
        }
        else {
            cout << "Displaying Circular Queue: " << endl;
            for(int i = front; i <= rear; i++){
                cout << circularqueue_Array[i] << " ";
            }
            cout << endl;
        }
    }

    ~CircularQueue(){
        delete[] circularqueue_Array;
    }
};

struct Deque 
{
    int *deque_Array;
    int size;
    int front;
    int rear;

    Deque(){
        this -> size = size;
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return front == -1;
    }
    bool isFull(){
        return ((front == 0 && rear == size - 1) || front == rear + 1);
    }

    void insertFront(int value){
        if(isFull()){
            cout << "Deque Overflow!" << endl;
            return;
        }
        if(isEmpty()){
            front = 0;
            rear = 0;
        }
        else if(front == 0){
            front = size - 1;
        }
        else {
            front = front - 1;
        }
        deque_Array[front] = value;
    }

    void insertRear(int value){
        if(isFull()){
            cout << "Deque Overflow!" << endl;
            return;
        }
        if(isEmpty()){
            front = 0;
            rear = 0;
        }
        if(rear == size - 1){
            rear = 0;
        }
        else {
            rear = rear + 1;
        }
        deque_Array[rear] = value;
        
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
        return deque_Array[front];
    }

    int getRear(){
        if(isEmpty() || rear < 0){
            cout << "Already Empty!" << endl;
            return -1;
        }
        return deque_Array[rear];
    }
};

int main()
{
    return 0;
}