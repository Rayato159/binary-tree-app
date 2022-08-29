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
        int node_count();
        int sum_node();
        int max_node();
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

// O(1)
Node *LinkedLists::add_node(Node *last, int data) {
    Node *t = new Node;
    t->data = data;
    t->next = NULL;
    last->next = t;
    return t;
}

// O(n)
int LinkedLists::node_count() {
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

int LinkedLists::max_node() {
    Node *p = this->head;
    int max = p->data;
    p = p->next;
    while(p) {
        if(max < p->data) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
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
    last = l.add_node(last, 50);
    last = l.add_node(last, 30);
    last = l.add_node(last, 40);

    l.display();
    cout << "count:\t" << l.node_count() << endl;
    cout << "sum:\t" << l.sum_node() << endl;
    cout << "max:\t" << l.max_node() << endl;

    return 0;
}