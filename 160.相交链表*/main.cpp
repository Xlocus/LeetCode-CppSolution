#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 双栈法
//class Solution {
//public:
//    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//        if (!headA || !headB)
//            return nullptr;
//
//        auto st1 = stack<ListNode*>();
//        auto st2 = stack<ListNode*>();
//
//        auto *p = headA;
//        auto *q = headB;
//
//        while (p){
//            st1.push(p);
//            p = p->next;
//        }
//
//        while (q){
//            st2.push(q);
//            q = q->next;
//        }
//
//        ListNode *i = nullptr;
//        ListNode *j = nullptr;
//        while (!st1.empty() && !st2.empty()){
//            i = st1.top();
//            j = st2.top();
//
//            st1.pop();
//            st2.pop();
//
//            if (i != j)
//                return i->next;
//        }
//
//        if (st1.empty() && !st2.empty())
//            return i;
//
//        if (st2.empty() && !st1.empty())
//            return j;
//
//        if (st1.empty() && st2.empty())
//            return i;
//
//        return nullptr;
//    }
//};

// 双指针法
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return nullptr;

        auto *p = headA;
        auto *q = headB;

        while (p != q){
            p = p == nullptr ? headB : p->next;
            q = q == nullptr ? headA : q->next;
        }

        return p;
    }
};

int main() {
    auto *a1 = new ListNode(4);
    auto *a2 = new ListNode(1);

    auto *b1 = new ListNode(5);
    auto *b2 = new ListNode(0);
    auto *b3 = new ListNode(1);

    auto *c1 = new ListNode(8);
    auto *c2 = new ListNode(4);
    auto *c3 = new ListNode(5);

    a1->next = a2;
    a2->next = c1;

    b1->next = b2;
    b2->next = b3;
    b3->next = c1;

    c1->next = c2;
    c2->next = c3;

    Solution s;
    auto *r = s.getIntersectionNode(a1, b1);
    cout << r->val << endl;

//    auto *a = new ListNode(4);
//    auto *b = new ListNode(3);
//    auto *c = new ListNode(1);
//    a->next = c;
//    b->next = c;
//
//    if (a->next == b->next)
//        cout << true <<endl;

    return 0;
}
