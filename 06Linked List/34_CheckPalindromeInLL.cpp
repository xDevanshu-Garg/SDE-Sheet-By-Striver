#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 334. Palindrome Linked List LINK: https://leetcode.com/problems/palindrome-linked-list/submissions/2030373259/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        
        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: If LL is odd move slow 1 ahead eg: 1 2 3 2 1, move slow from 3 to 2
        if(fast) {
            slow = slow->next;
        }

        // Step 3: Rev LL from slow
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while(curr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        // Step 4: Now check for palindrome
        while(prev) {
            if(head->val != prev->val) return false;
            head = head->next;
            prev = prev->next;
        }

        return true;
    }
};