#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 901. Online Stock Span LINK: https://leetcode.com/problems/online-stock-span/submissions/2049799909/
class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};
// Very easy monotonic stack ques, idea is that keep {price, span}, pop if older days price is <= curr price, and incremenet with there span, because if you are greater than them, then elements lesser than them is also lesser than you. 

// TC: O(2n) atmost one time push and pop for all elements.