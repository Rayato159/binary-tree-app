#ifndef Stack_h
#define Stack_h

#include <iostream>
#include "../trees/node.h"
using namespace std;

class Stack {
    private:
        int size;
        Node **s;
        int top;

    public:
        Stack(int size);

        void push(Node *x);
        Node *pop();
        Node *peek();
        bool stackoverflow();
        bool is_empty();

        void display();
};

Stack::Stack(int size) {
    this->size = size;
    this->s = new Node*[size];
    this->top = -1;
}

void Stack::push(Node *x) {
    if(this->stackoverflow()) {
        cout << "stackoverflow" << endl;
    } else {
        this->top++;
        this->s[this->top] = x;
    }
}

Node *Stack::pop() {
    Node *x = NULL;
    if(this->is_empty()) {
        cout << "empty" << endl;
    } else {
        x = this->s[this->top];
        this->s[this->top] = 0;
        this->top--;
    }
    return x;
}

Node *Stack::peek() {
    Node *x = NULL;
    if(this->is_empty()) {
        cout << "empty" << endl;
    } else {
        x = this->s[this->top];
    }
    return x;
}

bool Stack::stackoverflow() {
    return this->top == this->size - 1;
}

bool Stack::is_empty() {
    return this->top == -1;
}

void Stack::display() {
    for(int i=0; i<this->size && this->s[i]; i++) {
        cout << this->s[i]->data << " " << flush;
    }
    cout << endl;
}

#endif