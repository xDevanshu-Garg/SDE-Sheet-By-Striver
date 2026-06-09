#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 21. Merge Two Sorted Lists LINK: https://leetcode.com/problems/merge-two-sorted-lists/submissions/2027061458/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        // don't use while loop this is a LL 
        if(list1) 
            temp->next = list1;
        if(list2) 
            temp->next = list2;
            
        return dummy->next;
    }
};