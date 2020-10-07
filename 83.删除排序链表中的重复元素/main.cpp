#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *nhead = head;

        if (nhead == NULL)
            return NULL;

        ListNode *p = nhead;
        ListNode *q = p->next;

        while (q != NULL){
            if (q->val == p->val){
                p->next = q->next;
            } else{
                p = p->next;
            }

            q = q->next;
        }

        return nhead;
    }
};

//class Solution {
//public:
//    ListNode* deleteDuplicates(ListNode* head) {
//        ListNode *nhead = head;
//
//        while (head){
//            while (head->next && head->next->val == head->val){
//                head->next = head->next->next;
//            }
//            head = head->next;
//        }
//        return nhead;
//    }
//};

int main() {
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(1);
    ListNode *n3 = new ListNode(2);
    ListNode *n4 = new ListNode(3);
    ListNode *n5 = new ListNode(3);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Solution s;
    ListNode *nh = s.deleteDuplicates(n1);
    ListNode * r = nh;
    while (r != NULL){
        cout << r->val << endl;
        r = r->next;
    }

    return 0;
}
