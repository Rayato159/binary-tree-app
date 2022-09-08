#include <iostream>
using namespace std;

class Queue {
    private:
        int *q;
        int size;
        int front;
        int rear;

    public:
        Queue(){};
        Queue(int size);

        void enqueue(int q);
        int dequeue();
        bool is_full();
        bool is_empty();
        void display();
};

Queue::Queue(int size) {
    this->q = new int[size + 1]{0};
    this->size = size + 1;
    this->front = 1;
    this->rear = 1;
}

void Queue::enqueue(int q) {
    if(this->is_full()) {
        cout << "queue is full" << endl;
    } else {
        this->q[this->rear] = q;
        this->rear = this->rear % this->size + 1;
    }
}

int Queue::dequeue() {
    int x = -1;
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

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.display();
    return 0;
}