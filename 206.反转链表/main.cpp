#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        if (!head)
//            return nullptr;
//
//        auto *p = head;
//        ListNode *temp, *q = head;
//
//        while (p->next){
//            temp = p->next;
//            p->next = p->next->next;
//
//            temp->next = q;
//            q = temp;
//        }
//
//        return q;
//    }
//};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;

        auto *p = head;
        ListNode *q = nullptr;

        while (p){
            auto *k = p->next;
            p->next = q;

            q = p;
            p = k;
        }

        return q;
    }
};

int main() {
    auto *t0 = new ListNode(1);
    auto *t1 = new ListNode(2);
    auto *t2 = new ListNode(3);
    auto *t3 = new ListNode(4);
    auto *t4 = new ListNode(5);

    t0->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;

    Solution s;
    auto *r = s.reverseList(t0);

    auto *ptr = r;
    while (ptr){
        cout << ptr->val << endl;
        ptr = ptr->next;
    }

    return 0;
}
