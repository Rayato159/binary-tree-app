#include <iostream>
using namespace std;

class Queue {
    private:
        int *Q;
        int size;
        int front;
        int rear;
    public:
        //Constructor
        Queue(){};
        Queue(int size);

        //Methods
        void enqueue(int q);
        int dequeue();
        bool is_empty();
        bool is_full();
        void swap(int *x, int *y);
        void display();
};

Queue::Queue(int size) {
    this->Q = new int[size]{0};
    this->size = size;
    this->front = -1;
    this->rear = 0;
}

void Queue::enqueue(int q) {
    if(this->is_full()) {
        cout << "queue is full" << endl;
    } else {
        this->Q[this->rear] = q;
        this->rear++;
    }
}

int Queue::dequeue() {
    int x = -1;
    if(this->is_empty()) {
        cout << "queue is empty" << endl;
    } else {
        x = this->Q[0];
        for(int i=0; i<this->rear; i++) {
            swap(&this->Q[i+1], &this->Q[i]);
            this->Q[i+1] = 0;
        }
        this->rear--;
    }
    return x;
}

void Queue::swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
} 

bool Queue::is_empty() {
    return this->front == this->rear - 1;
}

bool Queue::is_full() {
    return this->front == this->rear;
}

void Queue::display() {
    for(int i=0; i<this->size; i++) {
        cout << Q[i] << " " << flush; 
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
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.display();
    return 0;
}