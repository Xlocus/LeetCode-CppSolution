#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        auto *p = node;
        ListNode *q;

        while (p->next){
            p->val = p->next->val;
            q = p;
            p = p->next;
        }
        q->next = nullptr;
    }
};

int main() {
    return 0;
}
