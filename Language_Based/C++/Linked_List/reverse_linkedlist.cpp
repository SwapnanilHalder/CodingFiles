#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int val;
    node* next;
    node (int n) {
        val = n;
        next = nullptr;
    }

};

void print_ll(node* head) {
    cout << "Printing  LL: ";
    node* tail = head;
    while(tail != nullptr) {
        cout << tail->val << " ";
        tail = tail->next;
    }
    cout<<"\n";
}

node* reverse_ll(node* head) {
    node* rev = new node(0);
    node* temp;
    node* tail = head;
    // cout << head->val << "\n";
    while(tail != nullptr) {
        // cout << temp->val << "\n";
        // cout << tail->val << "\n";

        temp->val = tail->val;
        temp->next = rev;
        cout << temp->val << "\n";
        rev = temp;
        tail = tail->next;
        // cout << rev->val << "\n";

        // print_ll(rev);
    }
    return rev;
}

int main() {
    node* head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    print_ll(head);
    node* rev = reverse_ll(head);
    // print_ll(rev);
}