#include <iostream>
using namespace std;

const int size = 5;

struct Stack {
    int top;
    int items[size];
};

void initialize(struct Stack *st){
    st -> top = -1;
}

int isFull(struct Stack *st){
    if (st -> top == size - 1){
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty(struct Stack *st){
    if(st -> top == -1){
        return 1;
    }
    else {
        return 0;
    }
}

bool push(struct Stack *st, int newItem){
    if (isFull(st)){
        cout << "Stack Overflow!" << endl;
        return false;
    }
    else {
        st -> items[++(st -> top)] = newItem;
        cout << newItem << " pushed to stack!" << endl;
        return true;
    }
}

int pop(struct Stack *st){
    if(isEmpty(st)){
        cout << "Stack Undeflow!" << endl;
        return -1;
    }
    else {
        cout << endl;
        int poppedItem = st -> items[st -> top--];
        cout << "Item Popped: " << poppedItem << endl;
        return poppedItem;
    }
    cout << endl;
}

int peek(struct Stack *st){
    if(isEmpty(st)){
        cout << "Stack is empty!" << endl;
    }
    else {
        int topItem = st -> items[st -> top];
        cout << "Peeking Item: " << topItem<< endl;
        return topItem;
    }
}

void displayStack(struct Stack *st){
    cout << "Stack: ";
    for(int i = 0; i < size; i++){
        cout << st -> items[i] << " ";
    }
    cout << endl;
}

int main()
{

    struct Stack st;
    initialize(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    displayStack(&st);

    pop(&st);
    peek(&st);



    

    
    return 0;
}