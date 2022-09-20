#ifndef Queue_h
#define Queue_h

#include <iostream>
#include "../trees/node.h"
using namespace std;

class Queue {
    private:
        Node **q;
        int size;
        int front;
        int rear;

    public:
        Queue(){};
        Queue(int size);

        void enqueue(Node *q);
        Node *dequeue();
        bool is_full();
        bool is_empty();
        void display();
};

Queue::Queue(int size) {
    this->q = new Node*[size + 1];
    this->size = size + 1;
    this->front = 1;
    this->rear = 1;
}

void Queue::enqueue(Node *q) {
    if(this->is_full()) {
        cout << "queue is full" << endl;
    } else {
        this->q[this->rear] = q;
        this->rear = this->rear % this->size + 1;
    }
}

Node *Queue::dequeue() {
    Node *x = NULL;
    if(this->is_empty()) {
        cout << "queue is already empty" << endl;
    } else {
        x = this->q[this->front];
        this->q[this->front] = 0;
        this->front = this->front % this->size + 1;
    }
    return x;
}

bool Queue::is_empty() {
    return this->front == this->rear;
}

bool Queue::is_full() {
    return this->rear % this->size + 1 == this->front;
}

void Queue::display() {
    for(int i=0; i<this->size; i++) {
        cout << this->q[i] << " " << flush;
    }
    cout << endl;
}

#endif