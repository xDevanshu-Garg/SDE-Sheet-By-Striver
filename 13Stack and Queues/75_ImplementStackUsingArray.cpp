#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Implement stack using array LINK: https://www.geeksforgeeks.org/problems/implement-stack-using-array/1

class myStack {
  public:
    vector<int> arr;
    int i;
    
    myStack(int n) {
        // Define Data Structures
        arr.resize(n);
        i = 0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return i == 0;
    }

    bool isFull() {
        // check if the stack is full
        return i == arr.size();
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(isFull()) return;
        arr[i] = x;
        i++;
    }

    void pop() {
        // removes an element from the top of the stack
        if(isEmpty()) return;
        i--;
        arr[i] = -1;
    }

    int peek() {
        // Returns the top element of the stack
        if(isEmpty()) return -1;
        return arr[i-1];
    }
};

// TC: O(1) for all operations
// SC: O(n) where n is the size of the stack