// circular_queue.h.h
#ifndef circular_queue
#define circular_queue

#include <iostream>
#include <cstdio>
#include <string>

class Queue {
    public:
        int *data;
        int size;
        int front;
        int rear;

    // Constructor
    Queue(int size);
    
    // Method
    void enqueue(int x);
    int dequeue();
    bool is_full();
    bool is_empty();
    void display();
};

Queue::Queue(int size) {
    this->data = new int[size+1]{0};
    this->size = size + 1;
    this->front = 0;
    this->rear = 0;
}

bool Queue::is_full() {
    if(this->rear % this->size + 1 == this->front) {
        return true;
    }
    return false;
}

bool Queue::is_empty() {
    if(this->front == this->rear) {
        return true;
    }
    return false;
}

void Queue::enqueue(int x) {
    if(this->is_full()) {
        std::cout << "error, queue is full" << std::endl;
    } else {
        this->rear = this->rear % this->size + 1;
        this->data[this->rear] = x;
    }
}

int Queue::dequeue() {
    int x = -1;
    if(this->is_empty()) {
        std::cout << "error, queue is empty" << std::endl;
    } else {
        x = this->data[this->front];
        this->data[this->front] = 0;
        this->front%this->size + 1;
    }
    return x;
}

void Queue::display() {
    for(int i=0; i<this->size; i++) {
        std::cout << this->data[i] << " " << std::flush;
    }
    std::cout << std::endl;
}

int receive_queue_size(char **argv) {
    int size = std::stoi(argv[2]);
    if((std::string)argv[1] == "-size") {
        return size;
    }
    return -1;
}

#endif