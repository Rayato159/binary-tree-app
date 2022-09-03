#include <iostream>

#include "../queue/queue.h"

using namespace std;

class BinaryTree {
    private:
        Node *root;
        Queue q;

    public:
        // Constructor
        BinaryTree();

        // Methods
        Node *get_root();
        int node_count(Node *p);
        int height(Node *p);
        int leaf_node(Node *p);
        void preorder(Node *p);
        void inorder(Node *p);
        void postorder(Node *p);
        void levelorder();
};

BinaryTree::BinaryTree() {
    Node *p, *t;
    this->root = new Node;
    this->root->left = this->root->right = NULL;

    int x;
    cout << "root: " << flush;
    cin >> x;

    this->root->data = x;
    this->q.enqueue(this->root);

    while(!this->q.is_empty()) {
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

void BinaryTree::levelorder() {
    Node *p = this->root;

    cout << p->data << " " << flush;
    this->q.enqueue(p);

    while(!this->q.is_empty()) {
        p = this->q.dequeue();

        if(p->left) {
            cout << p->left->data << " " << flush;
            q.enqueue(p->left);
        }

        if(p->right) {
            cout << p->right->data << " " << flush;
            q.enqueue(p->right);
        }
    }
    cout << endl;
}

int BinaryTree::node_count(Node *p) {
    while(p) {
        return this->node_count(p->left) + this->node_count(p->right) + 1;
    }
    return 0;
}

int BinaryTree::height(Node *p) {
    int x, y = 0;

    if(!p) {
        return 0;
    }
    x = this->height(p->left);
    y = this->height(p->right);

    if(x > y) {
        return x + 1;
    } else {
        return y + 1;
    }
}

int BinaryTree::leaf_node(Node *p) {
    if(!p) {
        return 0;
    }

    if(!p->left && !p->right) {
        return this->leaf_node(p->left) + this->leaf_node(p->right) + 1;
    } else {
        return this->leaf_node(p->left) + this->leaf_node(p->right);
    }
}

int main() {
    BinaryTree bt;
    Node *t = bt.get_root();

    cout << "numbers of node: " << bt.node_count(t) << endl;
    cout << "number of leaf nodes: " << bt.leaf_node(t) << endl;
    cout << "height of tree: " << bt.height(t) << endl;
    cout << endl;

    cout << "preorder:" << endl;
    bt.preorder(t);
    cout << endl;

    cout << "inorder:" << endl;
    bt.inorder(t);
    cout << endl;

    cout << "postorder:" << endl;
    bt.postorder(t);
    cout << endl;

    cout << "levelorder:" << endl;
    bt.levelorder();
    cout << endl;

    return 0;
}