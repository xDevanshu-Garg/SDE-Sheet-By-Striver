#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Implement queue using stack LINK: https://leetcode.com/problems/implement-queue-using-stacks/submissions/2045266046/

// Queue implemented using two stacks.
//
// input  -> receives all new elements
// output -> serves dequeue/front operations
//
// push:  O(1)
// empty: O(1)
// pop:   O(1) amortized, O(n) worst case
// peek:  O(1) amortized, O(n) worst case
//
// Each element is transferred from input to output at most once, so the total cost of transfers is spread across operations.

// Alternative approach includes making push O(n), but that is not considered optimal. 

class MyQueue {
public:
    stack<int> input;
    stack<int> output;

    MyQueue() {
    }

    void pushIntoOutput(){
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        //underflow
        if(empty()) return -1;
        
        if(output.empty()) pushIntoOutput();

        int val = output.top();
        output.pop();
        return val;
    }
    
    int peek(){
        //underflow
        if(empty()) return -1;

        if(output.empty()) pushIntoOutput();
        return output.top();
    }
    
    bool empty() {
        return (input.empty() && output.empty());
    }
};
