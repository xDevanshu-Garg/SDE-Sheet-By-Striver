#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Flattening a Linked List LINK: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

struct Node {
    int data;
    Node *next;
    Node *bottom;
    
    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
  public:
    Node* merge(Node* down, Node* right) {
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        while(down && right) {
            if(down->data < right->data) {
                temp->bottom = down;
                down = down->bottom;
            }
            else {
                temp->bottom = right;
                right = right->bottom;
            }
            temp = temp->bottom;
        }
        
        if(down) temp->bottom = down;
        if(right) temp->bottom = right;
        
        return dummy->bottom;
    }
    
    Node *flatten(Node *head) {
        // Base Case
        if(!head || !head->next) return head;
        
        Node* down = head;
        Node* right = flatten(head->next);
        
        head->next = NULL; // IMP
        
        return merge(down, right);
    }
};