#ifndef Q_Circular_h
#define Q_Circular_h

#include <iostream>

class Queue {
    public:
        int *data;
        int size;
        int front;
        int rear;

    // Constructor
    Queue(){};
    Queue(int size);
    
    // Method
    void enqueue(int x);
    int dequeue();
    bool is_full();
    bool is_empty();
    void display();
};

Queue::Queue(int size) {
    this->data = new int[size + 1]{0};
    this->size = size + 1;
    this->front = 1;
    this->rear = 1;
}

bool Queue::is_full() {
    return this->rear % this->size + 1 == this->front;
}

bool Queue::is_empty() {
    return this->front == this->rear;
}

void Queue::enqueue(int x) {
    if(this->is_full()) {
        std::cout << "error, queue is full" << std::endl;
    } else {
        this->data[this->rear] = x;
        this->rear = this->rear % this->size + 1;
    }
}

int Queue::dequeue() {
    int x = -1;
    if(this->is_empty()) {
        std::cout << "error, queue is empty" << std::endl;
    } else {
        x = this->data[this->front];
        this->data[this->front] = 0;
        this->front = this->front % this->size + 1;
    }
    return x;
}

void Queue::display() {
    for(int i=0; i<this->size; i++) {
        std::cout << this->data[i] << " " << std::flush;
    }
    std::cout << std::endl;
}

#endif