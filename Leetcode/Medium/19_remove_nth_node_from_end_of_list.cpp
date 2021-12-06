#include <iostream>
#include <vector>
#include <string>
#define For(i, a, b) for(int i=a; i<b; i++)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* tail = head;
        while(tail != nullptr) {
            len++;
            tail = tail->next;
        }
        int target = len - n +1;
        For(i, 0, target-1) {

        }
        cout << "LEN : " << len << endl;
        return head;
    }
};

int main() {
    ListNode* one = new ListNode(1);
    one->next = new ListNode(2);
    one->next->next = new ListNode(3);
    one->next->next->next = new ListNode(4);
    one->next->next->next->next = new ListNode(5);
    one->print_List(one);

    Solution sol;
    ListNode* answer = sol.removeNthFromEnd(one, 2);
    answer->print_List(answer);
}