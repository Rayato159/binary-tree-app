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
        Node **data;
        int size;
        int front;
        int rear;

    public:
        // Constructor
        Queue(){};
        Queue(int size);

        // Methods
        void enqueue(Node *data);
        Node *dequeue();
        bool is_empty();
        bool is_full();
        void display();
};

Queue::Queue(int size) {
    this->data = new Node*[size + 1];
    this->size = size + 1;
    this->front = 1;
    this->rear = 1;

    Node *t = new Node;
    t->data = 0;
    t->left = t->right = NULL;
    this->data[0] = t;
}

void Queue::enqueue(Node *data) {
    if(!this->is_full()) {
        this->data[this->rear] = data;
        this->rear = this->rear % this->size + 1;
    }
}

Node *Queue::dequeue() {
    Node *t;
    if(!this->is_empty()) {
        t = this->data[this->front];
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