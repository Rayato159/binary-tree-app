#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* leftChild;
        Node* rightChild;
};

class BinarySearchTree {
    private:
        Node* root;

    public:
        BinarySearchTree() { this->root = NULL; };
        void insert(int value);
        void insert(int value, Node* node);
        void printTree();
        void printTree(Node* node);
        bool search(int key);
        bool search(int key, Node* node);
};

void BinarySearchTree::insert(int value) {
    if (!this->root) {
        this->root = new Node;
        this->root->value = value;
        this->root->leftChild = NULL;
        this->root->rightChild = NULL;
    } else {
        this->insert(value, this->root);
    }
}

void BinarySearchTree::insert(int value, Node* node) {
    if (value < node->value) {
        if (!node->leftChild) {
            node->leftChild = new Node;
            node->leftChild->value = value;
            node->leftChild->leftChild = NULL;
            node->leftChild->rightChild = NULL;
        } else {
            this->insert(value, node->leftChild);
        }
    } else if (value > node->value) {
        if (!node->rightChild) {
            node->rightChild = new Node;
            node->rightChild->value = value;
            node->rightChild->leftChild = NULL;
            node->rightChild->rightChild = NULL;
        } else {
            this->insert(value, node->rightChild);
        }
    } else {
        cout << "Value already exists in the tree." << endl;
    }
}

void BinarySearchTree::printTree() {
    this->printTree(this->root);
}

void BinarySearchTree::printTree(Node* node) {
    if (node) {
        this->printTree(node->leftChild);
        cout << node->value << " ";
        this->printTree(node->rightChild);
    }
}

bool BinarySearchTree::search(int key) {
    return search(key, this->root);
}

bool BinarySearchTree::search(int key, Node* node) {
    if (!node) {
        return false;
    } else if (node->value == key) {
        return true;
    } else if (key < node->value) {
        return search(key, node->leftChild);
    } else {
        return search(key, node->rightChild);
    }
}

int main() {
    BinarySearchTree t;

    int a[] = {10, 20, 4, 50, 7};
    int size = sizeof(a)/sizeof(a[0]);

    for(int i=0; i < size; i++) {
        t.insert(a[i]);
    }
    t.printTree();
    cout << endl;

    cout << t.search(50) << endl;

    return 0;
}