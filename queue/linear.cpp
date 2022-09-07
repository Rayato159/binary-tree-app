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
        bool is_empty();
        bool is_full();
        void display();
        void swap(int *x, int *y);
};

Queue::Queue(int size) {
    this->q = new int[size]{0};
    this->size = size;
    this->front = -1;
    this->rear = 0;
}

void Queue::enqueue(int q) {
    if(this->is_full()) {
        cout << "queue is full" << endl;
    } else {
        this->q[this->rear] = q;
        this->rear++;
    }
}

int Queue::dequeue() {
    int x = -1;
    if(this->is_empty()) {
        cout << "queue is empty" << endl;
    } else {
        x = this->q[0]; // FIFO
        for(int i=0; i<this->rear; i++) {
            this->swap(&this->q[i+1], &this->q[i]);
            this->q[i+1] = 0;
        }
        this->rear--;
    }
    return x;
}

bool Queue::is_full() {
    return this->rear == this->size;
}

bool Queue::is_empty() {
    return this->rear == 0;
}

void Queue::swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
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
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.display();
    return 0;
}