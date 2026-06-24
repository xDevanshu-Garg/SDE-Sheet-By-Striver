#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Implement Stack using Queue LINK: https://leetcode.com/problems/implement-stack-using-queues/submissions/2045261595/
class MyStack {
public:
    queue<int> q;
    MyStack() {}
    
    void push(int x) {
        q.push(x);

        int sz = q.size();
        for(int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(q.empty()) return -1;
        int val = q.front(); q.pop();
        return val;
    }
    
    int top() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};