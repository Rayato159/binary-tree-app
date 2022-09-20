#include <iostream>

#include "../queue/queue.h"
#include "../stack/stack.h"
#include "./node.h"

using namespace std;

class BinaryTree {
    private:
        Node *root;
        Queue q;

    public:
        BinaryTree(Queue q);

        Node *get_root();

        // Traversal
        void preorder(Node *p);
        void inorder(Node *p);
        void postorder(Node *p);
};

BinaryTree::BinaryTree(Queue q) {
    // Step 1
    this->q = q;

    Node *t, *p;
    this->root = new Node;
    this->root->left = this->root->right = NULL;

    int x;
    cout << "root: " << flush;
    cin >> x;

    this->root->data = x;

    // Step 2
    this->q.enqueue(this->root);

    while(!this->q.is_empty()) {
        p = this->q.dequeue();

        // Left
        printf("left child: %d\n", p->data);
        cin >> x;

        if(x != -1) {
            // Step 3
            t = new Node;
            t->left = t->right = NULL;
            t->data = x;
            p->left = t;
            
            // Step 4
            this->q.enqueue(t);
        }

        // Right
        printf("right child: %d\n", p->data);
        cin >> x;

        if(x != -1) {
            // Step 3
            t = new Node;
            t->left = t->right = NULL;
            t->data = x;
            p->right = t;
            
            // Step 4
            this->q.enqueue(t);
        }
        cout << endl;
    }
}

Node *BinaryTree::get_root() {
    return this->root;
}

// Traversal
void BinaryTree::preorder(Node *p) {
    if(p) {
        cout << p->data << " " << flush;
        this->preorder(p->left);
        this->preorder(p->right);
    }
}

void BinaryTree::inorder(Node *p) {
    if(p) {
        this->inorder(p->left);
        cout << p->data << " " << flush;
        this->inorder(p->right);
    }
}

void BinaryTree::postorder(Node *p) {
    if(p) {
        this->postorder(p->left);
        this->postorder(p->right);
        cout << p->data << " " << flush;
    }
}

int main() {
    Queue q(100);
    BinaryTree bt(q);

    Node *p = bt.get_root();

    bt.preorder(p);
    cout << endl;
    bt.inorder(p);
    cout << endl;
    bt.postorder(p);
    cout << endl;

    return 0;
}