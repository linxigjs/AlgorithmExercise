//
// Created by gjs on 19-1-27.
//

#include <iostream>

using namespace std;

class Node {
public:
    Node() : val(0.0), left(nullptr), right(nullptr) {}
    Node(double v) : val(v), left(nullptr), right(nullptr) {}
    double val = 0.0;
    Node* left = nullptr;
    Node* right = nullptr;
};

void PreOrder(Node* head) {
    if(!head) {
        return;
    }
    cout << head->val << " ";
    PreOrder(head->left);
    PreOrder(head->right);
}

void InOrder(Node* head) {
    if(!head) {
        return;
    }
    InOrder(head->left);
    cout << head->val << " ";
    InOrder(head->right);
}

void PostOrder(Node* head) {
    if(!head) {
        return;
    }
    PostOrder(head->left);
    PostOrder(head->right);
    cout << head->val << " ";
}

int main() {
    Node head(0), l(1), r(2), ll(3), lr(4), rr(5), llr(6), lrl(7), lrr(8), rrl(9), lrlr(10);
    head.left = &l;
    head.right = &r;
    l.left = &ll;
    l.right = &lr;
    r.right = &rr;
    ll.right = &llr;
    lr.left = &lrl;
    lr.right = &lrr;
    rr.left = &rrl;
    lrl.right = &lrlr;

    cout << "PreOrder: ";
    PreOrder(&head);
    cout << endl;

    cout << "InOrder: ";
    InOrder(&head);
    cout << endl;

    cout << "PostOrder: ";
    PostOrder(&head);
    cout << endl;

    return 0;
}