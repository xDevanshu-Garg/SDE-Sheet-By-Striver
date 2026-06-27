#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 155. Min Stack LINK: https://leetcode.com/problems/min-stack/submissions/2050085806/

// ********************************BRUTE FORCE************************ 
// Idea: Maintain a second stack for minimum values
class MinStack {
public:
    stack<int> st; // stack to perform normal steps
    stack<int> mini; // stack to find mini in constant time
    MinStack() {}
    
    void push(int value) {
        st.push(value);

        if(mini.empty() || value <= mini.top()) {
            mini.push(value);
        }
    }
    
    void pop() {
        if(mini.top() == st.top()) mini.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
    }
};


// ************************optimised approch***********************
// By modifying the values pushed into the stack when a new minimum is encountered, so that we can retrieve the previous minimum without using an auxiliary(helper) stack.
class MinStack {
public:

    long long mini = INT_MAX;
    stack<long long>st;

    MinStack() {
    }
    
    void push(int value) {
        long long newVal = value;

        // For first element update mini
        if(st.empty()) {
            mini = value;
        }
        else if(value < mini) { // value is less than mini then update value and mini
            newVal = 2LL * value - mini;
            mini = value;
        } 

        st.push(newVal);
    }
    
    void pop() {
        // if curr element is less then mini, then recover mini first
        if(st.top() < mini) {
            mini = 2LL * mini - st.top();
        }
        st.pop();
    }
    
    int top() {
        // if top is less then min then ans is min otherwise directly ans
        if(st.top() < mini) {
            return mini;
        }

        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};