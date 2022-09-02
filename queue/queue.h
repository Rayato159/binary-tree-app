#ifndef Queue_h
#define Queue_h

#include <iostream>

class Node {
    public:
        int data;
        Node *left;
        Node *right;
};

class Queue {
    private:
        Node **Q;
        int size;
        int front;
        int rear;

    public:
        // Constructor
        Queue();

        // Methods
        void enqueue(Node *data);
        Node *dequeue();
        bool is_empty();
        bool is_full();
        void display();
};

Queue::Queue() {
    this->Q = new Node*[1001];
    this->size = 1001;
    this->front = 1;
    this->rear = 1;

    Node *t = new Node;
    t->data = 0;
    t->left = t->right = NULL;
    this->Q[0] = t;
}

void Queue::enqueue(Node *data) {
    if(!this->is_full()) {
        this->Q[this->rear] = data;
        this->rear = this->rear % this->size + 1;
    }
}

Node *Queue::dequeue() {
    Node *t;
    if(!this->is_empty()) {
        t = this->Q[this->front];
        this->front = this->front % this->size + 1;
    }
    return t;
}

bool Queue::is_empty() {
    if(this->front == this->rear) {
        printf("queue is empty\n\n");
        return true;
    }
    return false;
}

bool Queue::is_full() {
    if(this->rear % this->size + 1 == this->front) {
        printf("queue is full\n\n");
        return true;
    }
    return false;
}

#endif