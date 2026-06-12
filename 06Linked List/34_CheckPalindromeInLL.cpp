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

        // Step 2: Rev LL before slow
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != slow) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head->next = slow; // Connect both LL together 
        head = prev; // New head is prev now

        // Step 3: If LL is odd move slow 1 ahead eg: 1 2 3 2 1, move slow from 3 to 2
        if(fast) {
            slow = slow->next;
        }

        // Step 4: Now check for palindrome
        while(slow) {
            if(head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }

        return true;
    }
};