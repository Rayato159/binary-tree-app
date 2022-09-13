#include <iostream>
using namespace std;

class Stack {
    private:
        int size;
        int *data;
        int top;

    public:
        Stack(int size);

        void push(int x);
        int pop();
        int peek();
        bool stackoverflow();
        bool is_empty();

        void display();
};

Stack::Stack(int size) {
    this->size = size;
    this->data = new int[size]{0};
    this->top = -1;
}

void Stack::push(int x) {
    if(this->stackoverflow()) {
        cout << "stackoverflow" << endl;
    } else {
        this->top++;
        this->data[this->top] = x;
    }
}

int Stack::pop() {
    int x = -1;
    if(this->is_empty()) {
        cout << "empty" << endl;
    } else {
        x = this->data[this->top];
        this->data[this->top] = 0;
        this->top--;
    }
    return x;
}

int Stack::peek() {
    int x = -1;
    if(this->is_empty()) {
        cout << "empty" << endl;
    } else {
        x = this->data[this->top];
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
    for(int i=0; i<this->size; i++) {
        cout << this->data[i] << " " << flush;
    }
    cout << endl;
}

int main() {
    Stack s(5);
    s.display();
    cout << s.peek() << endl;
    return 0;
}