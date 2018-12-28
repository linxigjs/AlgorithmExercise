//
// Created by gjs on 18-12-28.
//

#include <iostream>

using namespace std;

class Node {
public:
    Node() : key_(-1), value_(""), left_(nullptr), right_(nullptr), N_(-1) {}
    Node(int k, string v, int n) : key_(k), value_(v), left_(nullptr), right_(nullptr), N_(n) {}
    Node(int k, string v, Node *l, Node *r, int n) : key_(k), value_(v), left_(l), right_(r), N_(n) {}
    int key_;
    string value_;
    Node *left_, *right_;
    int N_;
};

class BinarySearchTree {
public:
    int Size() {
        return Size(root_);
    }
    string Get(int k) {
        return Get(root_, k);
    }
    void Put(int k, string v) {
        root_ = Put(root_, k, v);
    }

private:
    int Size(Node *ro) {
        if(!ro)
            return 0;
        return ro->N_;
    }
    string Get(Node *node, int k) {
        if(!node)
            return nullptr;
        if(node->key_ < k) {
            return Get(node->right_, k);
        } else if(node->key_ > k) {
            return Get(node->left_, k);
        } else {
            return node->value_;
        }
    }
    Node* Put(Node *node, int k, string v) {
        if(!node) {
            return new Node(k, v, 1);
        }
        if(node->key_ < k) {
            node->right_ = Put(node->right_, k, v);
        } else if(node->key_ > k) {
            node->left_ = Put(node->left_, k, v);
        } else {
            node->value_ = v;
        }
        return node;
    }
private:
    Node *root_;
};



int main() {
    return 0;
}