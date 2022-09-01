#ifndef double
#define double

#include <iostream>
#include <cstdlib>

class Node {
    public:
        Node *next;
        int data;
        Node *prev;
};

class LinkedLists {
    private:
        Node *head;
        Node *last;

    public:
        LinkedLists(){this->head = NULL;};

        void insert_last(int data);
        void display_forward();
        void display_reverse();
};

void LinkedLists::insert_last(int data) {
    Node *t = new Node;
    t->data = data;
    t->next = NULL;
    t->prev = NULL;
    
    if(!this->head) {
        this->head = t;
        this->last = this->head;
    } else {
        t->prev = this->last;
        this->last->next = t;
        this->last = t;
    }
}

void LinkedLists::display_forward() {
    Node *p = this->head;
    while(p) {
        std::cout << p->data << " " << std::flush;
        p = p->next;
    }
    std::cout << std::endl;
}

void LinkedLists::display_reverse() {
    Node *p = this->last;
    while(p) {
        std::cout << p->data << " " << std::flush;
        p = p->prev;
    }
    std::cout << std::endl;
}

int main() {
    LinkedLists l;
    l.insert_last(10);
    l.insert_last(20);
    l.insert_last(30);
    l.insert_last(40);
    l.insert_last(50);
    l.display_forward();
    l.display_reverse();
    return 0;
}

#endif