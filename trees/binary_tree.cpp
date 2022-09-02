#include <iostream>

#include "../queue/queue.h"

using namespace std;

class BinaryTree {
    private:
        Node *root;
        Queue q;

    public:
        BinaryTree();

        void create_tree();
        Node *get_root();
        void preorder(Node *p);
        void inorder(Node *p);
        void postorder(Node *p);
};

BinaryTree::BinaryTree() {
    Queue t(100);
    this->q = t;
}

void BinaryTree::create_tree() {
    Node *p, *t;
    this->root = new Node;
    this->root->left = this->root->right = NULL;

    int x;
    cout << "root: " << flush;
    cin >> x;

    this->root->data = x;
    this->q.enqueue(this->root);

    while(!q.is_empty()) {
        p = this->q.dequeue();
        printf("p: %p\n", p);
        printf("left child of %d: ", p->data);
        cin >> x;

        if(x != -1) {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            printf("t: %p\n", t);
            this->q.enqueue(t);
        }

        printf("right child of %d: ", p->data);
        cin >> x;

        if(x != -1) {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            printf("t: %p\n", t);
            this->q.enqueue(t);
        }
        cout << endl;
    }
}

Node *BinaryTree::get_root() {
    return this->root;
}

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
    BinaryTree bt;
    bt.create_tree();
    Node *t = bt.get_root();

    cout << "preorder:" << endl;
    bt.preorder(t);
    cout << endl;

    cout << "inorder:" << endl;
    bt.inorder(t);
    cout << endl;

    cout << "postorder:" << endl;
    bt.postorder(t);
    cout << endl;
    return 0;
}