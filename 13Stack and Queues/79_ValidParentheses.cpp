#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 20: Valid Parentheses LINK: https://leetcode.com/problems/valid-parentheses/submissions/2045278761/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) return false;

                if ((ch == ')' && st.top() != '(') ||
                    (ch == ']' && st.top() != '[') ||
                    (ch == '}' && st.top() != '{'))
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};