#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<b;i++)
#define END cout << "\n" 
#define ENDstd printf("\n")
#define deb(x) cout << '\t'<<#x << " = " << x << endl

using namespace std;

class ListNode {
 public:   
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void print_List(ListNode* head) {
        while(head != nullptr) {
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << "/\n";
    }

};



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer;

    }
};

int main() {
    ListNode* one = new ListNode(2);
    one->next = new ListNode(4);
    one->next->next = new ListNode(3);

    ListNode* two = new ListNode(5);
    two->next = new ListNode(6);
    two->next->next = new ListNode(4);
    two->print_List(two);
    // Solution sol;
    // ListNode* answer = sol.addTwoNumbers(one, two);
    // answer->print_List(answer);
}