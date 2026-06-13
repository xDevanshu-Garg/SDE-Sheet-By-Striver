#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 138. Copy List with Random Pointer LINK: https://leetcode.com/problems/copy-list-with-random-pointer/submissions/2041671521/


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


// Deep copy means, create new nodes, point next of new nodes to new nodes itself not to old nodes. A`->next = B` not B. 

//**************************Map way*****************************
// TC & SC both: O(n) 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;

        Node* temp = head;
        while(temp) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp) {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];

            temp = temp->next;
        }

        return mp[head];
    }
};

//***********************Space Optmized************************
// TC: O(n) & SC: O(1)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // Step 1: Create copied nodes and insert copied nodes bw orignal nodes
        // A -> A' -> B -> B' -> C -> C'
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // Step 2: Set random pointers
        curr = head;
        while (curr) {
            Node* copy = curr->next;

            copy->random =
                curr->random ? curr->random->next : NULL;

            curr = copy->next;
        }

        // Step 3: Separate the lists
        curr = head;
        Node* copyHead = head->next;
        while (curr) {
            Node* copy = curr->next;

            curr->next = copy->next;

            if (copy->next)
                copy->next = copy->next->next;

            curr = curr->next;
        }

        return copyHead;
    }
};