#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 146. LRU Cache LINK: https://leetcode.com/problems/lru-cache/submissions/2047356870/

class Node {
public: 
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) {
        this->key = key; 
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    Node* head;
    Node* tail;
    int size;
    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
    }

    void shiftAtEnd(Node* node) {
        if(node == tail) return;

        // Delete the node
        if(node == head) {
            head = head->next;
            head->prev = NULL;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        // Put at end
        tail->next = node;
        node->next = NULL;
        node->prev = tail;
        tail = node;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        shiftAtEnd(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) { // Update the value
            shiftAtEnd(mp[key]);
            mp[key]->val = value;

            
        } else {
            // if size is full
            if(size == cap) { 
                Node* temp = head;
                if(size == 1) {
                    head = tail = NULL;
                } else {
                    head = head->next;
                    head->prev = NULL; 
                }

                mp.erase(temp->key);
                delete temp;
                size--;
            }
             
            // Create key
            Node* temp = new Node(key, value);
            if(size == 0){
                head = temp; 
                tail = temp;
            } else {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }

            mp[key] = temp;
            size++;
        }         
    }
};