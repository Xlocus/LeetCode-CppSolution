#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head)
            return true;

        ListNode *firstHalfEnd = endOfFirstHalf(head);
        ListNode *secondHalfStart = reverseList(firstHalfEnd->next);

        auto result = true;
        ListNode *p = head;
        ListNode *q = secondHalfStart;

        while (result && q){
            if (p->val != q->val)
                result = false;

            p = p->next;
            q = q->next;
        }

        firstHalfEnd->next = reverseList(secondHalfStart);

        return result;
    }

    ListNode* reverseList(ListNode *head){
        ListNode *prev = nullptr;
        ListNode * curr = head;

        while (curr){
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        return prev;
    }

    ListNode* endOfFirstHalf(ListNode* head){
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};

int main() {
    auto *h = new ListNode(1);
    auto *h1 = new ListNode(2);
    auto *h2 = new ListNode(2);
    auto *h3 = new ListNode(1);

    h->next = h1;
    h1->next = h2;
    h2->next = h3;

    Solution s;

    auto r = s.isPalindrome(h);
    cout << r << endl;

    return 0;
}

