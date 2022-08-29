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

    public:
        // Constructure
        LinkedLists(int data);
        
        // Methods
        Node* get_head();
        Node* add_node(Node *n, int data);
        void display();
};

LinkedLists::LinkedLists(int data) {
    this->head = new Node;
    this->head->data = data;
    this->head->next = NULL;
}

Node *LinkedLists::get_head() {
    return this->head;
}

Node *LinkedLists::add_node(Node *last, int data) {
    Node *t = new Node;
    t->data = data;
    t->next = NULL;
    last->next = t;
    return t;
}

void LinkedLists::display() {
    Node* p = this->head;
    while(p) {
        cout << p->data << " " << flush;
        p = p->next;
    }
    cout << endl;
}

int main() {
    LinkedLists l(10);
    Node* head = l.get_head();
    Node* last = head;

    last = l.add_node(last, 20);
    last = l.add_node(last, 30);
    last = l.add_node(last, 40);
    last = l.add_node(last, 50);

    l.display();

    return 0;
}