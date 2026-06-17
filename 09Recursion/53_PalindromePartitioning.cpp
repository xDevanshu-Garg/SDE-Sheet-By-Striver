#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 191. Palindrome Partitioning LINK: https://leetcode.com/problems/palindrome-partitioning/submissions/2036978887/

class Solution {
public:
    bool checkPalindrome(int st, int e, string& s) {
        while(st < e) {
            if(s[st++] != s[e--]) return false;
        }

        return true;
    }

    void solve(int ind, vector<string>& output, vector<vector<string>>& ans, string& s) {
        // Base Case
        if(ind >= s.size()) {
            ans.push_back(output);
            return;
        }

        for(int i = ind; i < s.size(); i++) {
            if(checkPalindrome(ind, i, s)) {
                output.push_back(s.substr(ind, i - ind + 1));
                solve(i+1, output, ans, s);
                output.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> output;
        vector<vector<string>> ans;
        solve(0, output, ans, s); 

        return ans;
    }
};