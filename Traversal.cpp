//
// Created by gjs on 19-1-27.
//

#include <iostream>
#include <vector>
#include <algorithm>

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

void PreOrder2(Node* head) {
    if (!head) {
        return;
    }
    vector<Node *> vec;
    vec.emplace_back(head);
    while(!vec.empty()) {
        Node* cur = vec.back();
        vec.pop_back();
        cout << cur->val << " ";
        if(cur->right) {
            vec.emplace_back(cur->right);
        }
        if(cur->left) {
            vec.emplace_back(cur->left);
        }
    }
}

void PreOrder3(Node* head) {
    vector<Node *> vec;
    Node *p = head;
    while(p || !vec.empty()) {
        if(p) {
            vec.emplace_back(p);
            cout << p->val << " ";
            p = p->left;
        } else {
            p = vec.back();
            vec.pop_back();
            p = p->right;
        }
    }
}

void InOrder(Node* head) {
    if(!head) {
        return;
    }
    InOrder(head->left);
    cout << head->val << " ";
    InOrder(head->right);
}

void InOrder2(Node* head) {
    vector<Node *> vec;
    Node *p = head;
    while(p || !vec.empty()) {
        if(p) {
            vec.emplace_back(p);
            p = p->left;
        } else {
            p = vec.back();
            vec.pop_back();
            cout << p->val << " ";
            p = p->right;
        }
    }

}

void PostOrder(Node* head) {
    if(!head) {
        return;
    }
    PostOrder(head->left);
    PostOrder(head->right);
    cout << head->val << " ";
}

void PostOrder2(Node* head) {
    vector<double> res;
    vector<Node *> vec;
    Node *p = head;
    while(p || !vec.empty()) {
        if(p) {
            res.emplace_back(p->val);
            vec.emplace_back(p);
            p = p->right;
        } else {
            p = vec.back();
            vec.pop_back();
            p = p->left;
        }
    }
    reverse(res.begin(), res.end());
    for(auto e : res) {
        cout << e << " ";
    }
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

    cout << "PreOrder2: ";
    PreOrder2(&head);
    cout << endl;

    cout << "PreOrder3: ";
    PreOrder3(&head);
    cout << endl;

    cout << "InOrder: ";
    InOrder(&head);
    cout << endl;

    cout << "InOrder2: ";
    InOrder2(&head);
    cout << endl;

    cout << "PostOrder: ";
    PostOrder(&head);
    cout << endl;

    cout << "PostOrder2: ";
    PostOrder2(&head);
    cout << endl;

    return 0;
}