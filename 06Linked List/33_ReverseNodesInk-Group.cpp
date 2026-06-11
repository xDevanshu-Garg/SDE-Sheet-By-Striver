#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 25. Reverse Nodes in k-Group LINK: https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/2029386300/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rev(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        for(int i = 0; i < k; i++) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // Check if k nodes exist
        ListNode* temp = head;
        for(int i = 0; i < k; i++) {
            if(!temp) return head;
            temp = temp->next;
        }

        ListNode* newHead = rev(head, k);

        head->next = reverseKGroup(temp, k);

        return newHead;
    }
};