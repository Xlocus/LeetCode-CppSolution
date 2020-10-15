#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return nullptr;

        while (head){
            if (head->val == val)
                head = head->next;
            else
                break;
        }

        ListNode *p = head;

        if (!p)
            return nullptr;
        else{
            while (p->next){
                if (p->next->val == val)
                    p->next = p->next->next;
                else
                    p = p->next;
            }
        }

        return head;
    }
};

int main() {
    int x = 6;
    auto *n0 = new ListNode(1);
    auto *n1 = new ListNode(2);
    auto *n2 = new ListNode(6);
    auto *n3 = new ListNode(3);
    auto *n4 = new ListNode(4);
    auto *n5 = new ListNode(5);
    auto *n6 = new ListNode(6);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    Solution s;

    auto r = s.removeElements(n0, x);
    auto p = r;

    while (p){
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}
