#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 2. Add Two Numbers LINK: https://leetcode.com/problems/add-two-numbers/submissions/2028104456/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int carry = 0;
        while(l1 && l2) {
            int val = l1->val + l2->val + carry;
            int digit = val % 10;

            temp->next = new ListNode(digit);

            carry = val / 10;

            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }

        while(l1) {
            int val = l1->val + carry;
            int digit = val % 10;

            temp->next = new ListNode(digit);

            carry = val / 10;

            l1 = l1->next;
            temp = temp->next;
        }

        while(l2) {
            int val = l2->val + carry;
            int digit = val % 10;

            temp->next = new ListNode(digit);

            carry = val / 10;

            l2 = l2->next;
            temp = temp->next;
        }

        if(carry) temp->next = new ListNode(carry);

        return dummy->next;
    }
};

//********************* CLEANER CODE **********************


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int carry = 0;
        while(l1 || l2 || carry) {
            int x = (l1) ? l1->val : 0;
            int y = (l2) ? l2->val : 0;

            int sum = x + y + carry;
            carry = sum / 10;

            int digit = sum % 10;
            temp->next = new ListNode(digit);

            l1 = (l1) ? l1->next : NULL;
            l2 = (l2) ? l2->next : NULL;
            temp = temp->next;
        }

        return dummy->next;
    }
};