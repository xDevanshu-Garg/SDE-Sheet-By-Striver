#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 19. Remove Nth Node From End of List LINK: https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/2028097673/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create dummy, move fast n ahead, move slow and fast until LL ends, now slow is at the node which we wanna delete, so stop 1 before or like in our code move fast extra 1 ahead and then slow->next is the node we wanna delete, so delete it.
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del;

        return dummy->next;
    }
};