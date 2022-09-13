#include <iostream>
using namespace std;

class Stack {
    private:
        int size;
        char *data;
        int top;

    public:
        Stack(int size);

        void push(char x);
        char pop();
        char peek();
        bool stackoverflow();
        bool is_empty();

        void display();
};

Stack::Stack(int size) {
    this->size = size;
    this->data = new char[size];
    this->top = -1;
}

void Stack::push(char x) {
    if(this->stackoverflow()) {
        cout << "stackoverflow" << endl;
    } else {
        this->top++;
        this->data[this->top] = x;
    }
}

char Stack::pop() {
    char x = ' ';
    if(this->is_empty()) {
        cout << "empty" << endl;
    } else {
        x = this->data[this->top];
        this->data[this->top] = 0;
        this->top--;
    }
    return x;
}

char Stack::peek() {
    char x = ' ';
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

char check(string str) {
    Stack s(100);
    for(int i=0; i<str.length(); i++) {
        if(str[i] == '(') {
            s.push(str[i]);
        } else if(str[i] == ')') {
            if(s.is_empty()) {
                return '(';
            }
            s.pop();
        }
    }
    return (s.is_empty())? ' ':')';
}

int main() {
    string str = "(cos(A)sin(B))";
    cout << check(str) << endl;
    return 0;
}