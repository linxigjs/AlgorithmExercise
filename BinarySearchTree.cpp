//
// Created by gjs on 18-12-28.
//

#include <iostream>

using namespace std;

typedef int KEY;
typedef int RANK;
typedef string VALUE;

class Node {
public:
    Node() : key_(-1), value_(""), left_(nullptr), right_(nullptr), N_(-1) {}
    Node(KEY k, VALUE v, int n) : key_(k), value_(v), left_(nullptr), right_(nullptr), N_(n) {}
    Node(KEY k, VALUE v, Node *l, Node *r, int n) : key_(k), value_(v), left_(l), right_(r), N_(n) {}
    KEY key_;
    VALUE value_;
    Node *left_, *right_;
    int N_;
};

class BinarySearchTree {
public:
    int Size() {
        return Size(root_);
    }
    VALUE Get(KEY k) {
        return Get(root_, k);
    }
    void Put(KEY k, VALUE v) {
        root_ = Put(root_, k, v);
    }
    KEY Min() {
        if(IsRootNull())
            return -1;
        return Min(root_)->key_;
    }
    KEY Max() {
        if(IsRootNull())
            return -1;
        return Max(root_)->key_;
    }
    KEY Floor(KEY k) {
        if(IsRootNull())
            return -1;
        Node* node = Floor(root_, k);
        if(!node)
            return -1;
        return node->key_;
    }
    KEY Select(RANK k) {
        if(IsRootNull() || k >= root_->N_)
            return -1;
        return Select(root_, k)->key_;
    }
    RANK Rank(KEY k) {
        if(IsRootNull())
            return 0;
        return Rank(root_, k);
    }

private:
    RANK Rank(Node* node, KEY k) {
        if(!node)
            return 0;
        if(k < node->key_) {
            return Rank(node->left_, k);
        } else if(k > node->key_) {
            return 1 + Size(node->left_) + Rank(node->right_, k);
        } else {
            return Size(node->left_);
        }
    }
    Node* Max(Node* node) {
        if(!node->right_)
            return node;
        else
            return Max(node->right_);
    }
    bool IsRootNull() {
        if(!root_) {
            cout << "Tree is empty!!!" << endl;
            return true;
        }
        return false;
    }
    int Size(Node *ro) {
        if(!ro)
            return 0;
        return ro->N_;
    }
    VALUE Get(Node *node, KEY k) {
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
    Node* Put(Node *node, KEY k, VALUE v) {
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
        //无论有没有插入新节点，下一句都可以正确执行
        node->N_ = Size(node->left_) + Size(node->right_) + 1;
        return node;
    }
    Node* Min(Node* node) {
        if(!node->left_) {
            return node;
        }
        return Min(node->left_);
    }
    Node* Floor(Node* node, KEY k) {
        if(!node)
            return nullptr;
        if(node->key_ == k) {
            return node;
        } else if(node->key_ > k) {
            return Floor(node->left_, k);
        } else {
            auto temp = Floor(node->right_, k);
            if(!temp)
                return node;
            else
                return temp;
        }
    }
    Node* Select(Node* node, RANK k) {
        if(!node)
            return nullptr;
        int temp = Size(node->left_);
        if(k > temp) {
            return Select(node->right_, k-temp-1);
        } else if(k < temp) {
            return Select(node->left_, k);
        } else {
            return node;
        }
    }
private:
    Node *root_;
};



int main() {
    return 0;
}