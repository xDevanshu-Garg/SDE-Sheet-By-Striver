#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 141. Linked List Cycle LINK: https://leetcode.com/problems/linked-list-cycle/submissions/2029338731/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast) return true;
        }

        return false;
    }
};

// if fast and slow overlapped then there is a cycle otherwise fast would have just reached end and slow and fast would have never met.