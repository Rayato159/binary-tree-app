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
        int count(Node *t);
        int height(Node *t);
        void preorder(Node *p);
        void preorder_stack();
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

int BinaryTree::count(Node *t) {
    int l, r;
    if(t) {
        l = this->count(t->left);
        r = this->count(t->right);
        return l + r + 1;
    } else {
        return 0;
    }
}

int BinaryTree::height(Node *t) {
    int l, r;
    if(t) {
        l = this->height(t->left);
        r = this->height(t->right);
        if (l > r) {
            return l + 1;
        } else {
            return r + 1;
        }
    }
    return -1;
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

// Stack
void BinaryTree::preorder_stack() {
    Stack s(100);
    Node *t = this->root;

    while(!s.is_empty() || t) {
        if(t) {
            cout << t->data << " " << flush;
            s.push(t);
            t = t->left;
        } else {
            t = s.pop();
            t = t->right;
        }

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

    cout << bt.height(p) << endl;

    return 0;
}