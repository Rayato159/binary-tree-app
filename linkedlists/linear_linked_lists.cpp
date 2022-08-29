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
        // Constructor
        LinkedLists(int data);

        // Deconstructor
        ~LinkedLists();
        
        // Methods
        Node* get_head();
        Node* add_node(Node *n, int data);
        int node_count();
        int sum_node();
        int max_node();
        int min_node();
        int search(int key);
        void display();
};

LinkedLists::LinkedLists(int data) {
    this->head = new Node;
    this->head->data = data;
    this->head->next = NULL;
}

LinkedLists::~LinkedLists() {
    Node *p = this->head;
    while(this->head) {
        this->head = this->head->next;
        delete p;
        p = this->head;
    }
    cout << "All nodes are deleted" << endl;
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

int LinkedLists::min_node() {
    Node *p = this->head;
    int min = p->data;
    p = p->next;
    while(p) {
        if(min > p->data) {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

int LinkedLists::search(int key) {
    Node *p = this->head;
    Node *q = NULL;
    int result = -1;
    while(p) {
        if(key == p->data) {
            // Move to head
            q->next = p->next;
            p->next = this->head;
            this->head = p;
            return p->data;
        }
        q = p;
        p = p->next;
    }
    return result;
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
    cout << "min:\t" << l.min_node() << endl;
    cout << "search:\t" << l.search(30) << endl;
    l.display();

    return 0;
}