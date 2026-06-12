#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 142. Linked List Cycle II LINK: https://leetcode.com/problems/linked-list-cycle-ii/submissions/2030380652/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Using hare tortoise 
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                // Move either pointer at start and traverse till they meet again
                slow = head;
                
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return NULL;
    }
};