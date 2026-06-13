#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        // Find len
        int n = 0;
        ListNode* temp = head;
        while(temp) {
            temp = temp->next;
            n++;
        }

        k = k % n;
        if(k == 0) return head;

        // Point at k
        ListNode* fast = head;
        for(int i = 0; i < k; i++) {
            fast = fast->next;
        }

        ListNode* slow = head;
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = head; // Make LL circular
        head = slow->next; // New head
        slow->next = NULL; // Break Circular LL 

        return head;
    }
};