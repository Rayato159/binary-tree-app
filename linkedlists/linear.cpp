#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class LinkedLists {
    private:
        Node *head;
        Node *last;

    public:
        LinkedLists(){this->head = NULL;};

        void insert_last(int data);
        int length();
        int sum_node();
        int search(int key);
        void display();
};

void LinkedLists::insert_last(int data) {
    Node *n = new Node;
    n->data = data;
    n->next = NULL;

    if(!this->head) {
        this->head = n;
        this->last = head;
    } else {
        this->last->next = n;
        this->last = n;
    }
}

int LinkedLists::length() {
    Node *p = this->head;
    int count = 0;
    while(p) {
        count++;
        p = p->next;
    }
    return count;
}

int LinkedLists::sum_node() {
    Node *p = this->head;
    int sum = 0;
    while(p) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int LinkedLists::search(int key) {
    Node *p = this->head;
    Node *q = NULL;
    while(p) {
        if(p->data == key) {
            if(p == this->last) {
                q->next = NULL;
                this->last = q;
                p->next = head;
                head = p;
                return this->head->data;
            } else {
                q->next = p->next;
                p->next = head;
                head = p;
                return this->head->data;
            }
        }
        q = p;
        p = p->next;
    }
    return -1;
}

void LinkedLists::display() {
    Node *p = this->head;
    while(p) {
        cout << p->data << " " << flush;
        p = p->next;
    }
    cout << endl;
}

int main() {
    LinkedLists l;
    l.insert_last(10);
    l.insert_last(20);
    l.insert_last(30);
    l.insert_last(40);
    l.insert_last(50);
    l.display();
    cout << l.length() << endl;
    cout << l.sum_node() << endl;
    cout << "key " << l.search(5) << endl;
    l.display();
    return 0;
}