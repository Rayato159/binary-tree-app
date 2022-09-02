#include <iostream>

#include "../linkedlists/double.h"

using namespace std;

class BinaryTree {
    private:
        Node *root;

    // Constructor
    BinaryTree(){};

    // Methods
    void plant();
};

BinaryTree::BinaryTree() {}

void BinaryTree::plant() {
    Node *p, *t;
    int x;
    cin >> x;
    this->root = new Node;
    this->root->data = x;
    this->root->next = this->root->prev = NULL;
}

int main() {
    return 0;
}