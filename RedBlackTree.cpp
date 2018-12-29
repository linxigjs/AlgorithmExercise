//
// Created by gjs on 18-12-29.
//

#include <iostream>

using namespace std;

typedef int KEY;
typedef string VALUE;

bool RED = true;
bool BLACK = false;

class Node {
public:
    Node() : key_(-1), value_(""), left_(nullptr), right_(nullptr), N_(-1), color_(BLACK) {}
    Node(KEY k, VALUE v, int n) :
            key_(k), value_(v), left_(nullptr), right_(nullptr), N_(n), color_(BLACK) {}
    Node(KEY k, VALUE v, int n, bool col) :
            key_(k), value_(v), left_(nullptr), right_(nullptr), N_(n), color_(col) {}
    Node(KEY k, VALUE v, Node *l, Node *r, int n, bool col) :
            key_(k), value_(v), left_(l), right_(r), N_(n), color_(BLACK) {}
    bool IsRed() {
        return color_ == RED;
    }
    KEY key_;
    VALUE value_;
    Node *left_, *right_;
    int N_;
    bool color_;
};

class RedBlackTree {
public:
    RedBlackTree() : root_(nullptr) {}

    void Put(KEY k, VALUE v) {
        root_ = Put(root_, k, v);
        root_->color_ = BLACK;
    }

private:
    Node* Put(Node* h, KEY k, VALUE v) {
        if(!h)
            return new Node(k,v,1,RED);
        if(k > h->key_)
            h->right_ = Put(h->right_, k, v);
        else if(k < h->key_)
            h->left_ = Put(h->left_, k, v);
        else
            h->value_ = v;

        if(IsRed(h->right_) && !IsRed(h->left_))
            h = RotateLeft(h);
        if(IsRed(h->left_) && IsRed(h->left_->left_))
            h = RotateRight(h);
        if(IsRed(h->left_) && IsRed(h->right_))
            FlipColors(h);

        h->N_ = Size(h->left_) + Size(h->right_) + 1;
        return h;
    }

    Node* RotateLeft(Node* h) {
        auto temp = h->right_;
        h->right_ = temp->left_;
        temp->left_ = h;
        temp->color_ = h->color_;
        h->color_ = RED;
        temp->N_ = h->N_;
        h->N_ = Size(h->left_) + Size(h->right_) + 1;
        return temp;
    }

    Node* RotateRight(Node* h) {
        auto temp = h->left_;
        h->left_ = temp->right_;
        temp->right_ = h;
        temp->color_ = h->color_;
        h->color_ = RED;
        temp->N_ = h->N_;
        h->N_ = Size(h->left_) + Size(h->right_)  +1;
        return temp;
    }

    void FlipColors(Node* h) {
        h->color_ = RED;
        h->left_->color_ = BLACK;
        h->right_->color_ = BLACK;
    }

    int Size(Node* node) {
        if(!node)
            return 0;
        return node->N_;
//        return Size(node->left_) + Size(node->right_) + 1;
    }

    bool IsRed(Node* h) {
        if(!h)
            return false;
        return h->color_ == RED;
    }

private:
    Node* root_ = nullptr;
};


int main() {
    RedBlackTree mytree;
    mytree.Put(1,"A");
    mytree.Put(3,"C");
    mytree.Put(5,"E");
    mytree.Put(8,"H");
    mytree.Put(12,"L");
    mytree.Put(13,"M");
//    mytree.Put(16,"P");

    return 0;
}