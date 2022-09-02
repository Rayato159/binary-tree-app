#ifndef Queue_h
#define Queue_h

#include <iostream>

class Node {
    public:
        int data;
        Node *next;
        Node *prev;
};

class Queue {
    private:
        Node *data;
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
    this->data = new Node[size + 1];
    this->size = size + 1;
    this->front = 1;
    this->rear = 1;

    Node *t = new Node;
    t->data = 0;
    t->next = NULL;
    t->prev = NULL;
    this->data[0] = *t;
}

void Queue::enqueue(Node *data) {
    if(!this->is_full()) {
        this->data[this->rear] = *data;
        this->rear % this->size + 1;
    }
}

Node *Queue::dequeue() {
    Node *t = new Node;
    t->data = 0;
    t->next = NULL;
    t->prev = NULL;
    if(!this->is_empty()) {
        *t = this->data[this->front];
        this->data[this->front] = *t;
        this->front % this->size + 1;
    }
    return t;
}

bool Queue::is_empty() {
    if(this->front == this->rear) {
        std::cout << "error, queue is empty" << std::endl;
        return true;
    }
    return false;
}

bool Queue::is_full() {
    if(this->rear % this->size + 1 == this->front) {
        std::cout << "error, queue is full" << std::endl;
        return true;
    }
    return false;
}

void Queue::display() {
    for(int i=0; i<this->size; i++) {
        std::cout << this->data[i].data << " " << std::endl;
    }
    std::cout << std::endl;
}

#endif