#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<b;i++)
#define END cout << "\n" 
#define ENDstd printf("\n")
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define pl(x) cout << x << endl

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
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
        ListNode* answer = new ListNode();
        ListNode* tail = answer;
        ListNode* prev;
        int num, hand = 0, sum;
        while(l1 != nullptr and l2 != nullptr) {
            sum = l1->val + l2->val + hand;
            num = sum%10;
            hand = sum/10;
            // deb(num);
            // pl("4");
            tail->val = num;
            // pl("0");
            tail->next = new ListNode();
            // pl("Created Tail");
            // deb(tail->val);
            prev = tail;
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
            // pl("1");
        }
        while(l2 != nullptr) {
            sum = l2->val + hand;
            num = sum%10;
            hand = sum/10;
            tail->val = num;
            tail->next = new ListNode();
            // pl("Created Tail");            
            // deb(tail->val);     
            prev = tail;       
            tail = tail->next;
            l2 = l2->next;
            // pl("2");
        }
        while(l1 != nullptr) {
            sum = l1->val + hand;
            num = sum%10;
            hand = sum/10;
            tail->val = num;
            tail->next = new ListNode();
            // pl("Created Tail");
            // deb(tail->val);
            prev = tail;
            tail = tail->next;
            l1 = l1->next;
            // pl("3");
        }
        tail->val = hand;
        if(hand == 0) {
            prev->next = nullptr;
        }
        return answer;
    }
};

int main() {
    ListNode* one = new ListNode(2);
    one->next = new ListNode(4);
    one->next->next = new ListNode(3);
    one->print_List(one);

    ListNode* two = new ListNode(5);
    two->next = new ListNode(6);
    two->next->next = new ListNode(4);
    two->print_List(two);
    Solution sol;
    ListNode* answer = sol.addTwoNumbers(one, two);
    answer->print_List(answer);
}