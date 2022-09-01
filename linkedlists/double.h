#ifndef L_Double_h
#define L_Double_h

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

#endif