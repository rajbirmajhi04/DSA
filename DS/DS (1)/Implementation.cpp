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
    int *CircularQueue_Array;
    int size;
    int front;
    int rear;

    CircularQueue(int size){
        
    }
};

struct Deque 
{
    int *deque_Array;
    int size;
    int front;
    int rear;
};

int main()
{

    
    return 0;
}