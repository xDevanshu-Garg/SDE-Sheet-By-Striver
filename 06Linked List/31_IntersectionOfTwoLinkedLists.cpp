#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 160. Intersection of Two Linked Lists LINK: https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/2029327665/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while(a && b) {
            a = a->next;
            b = b->next;
        }

        if(!a) a = headB;
        else b = headA;

        while(a && b) {
            a = a->next;
            b = b->next;
        }

        if(!a) a = headB;
        else b = headA;

        while(a && b) {
            if(a == b) return a;
            a = a->next;
            b = b->next;
        }

        return NULL;
    }
};