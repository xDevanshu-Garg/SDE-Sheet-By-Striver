#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 5. Longest Palindromic Substring LINK: https://leetcode.com/problems/longest-palindromic-substring/submissions/2049627836/

class Solution {
public:
    string longestPalindrome(string s) {
        // Idea: Grow from len 1 to bigger lengths

        int n = s.size();
        int maxi = 0;
        string ans = "";

        for(int i = 0; i < n; i++) {
            int st = i, e = i;

            // First find the center like "a" "aa" "cccc" 
            while(st > 0 && s[st] == s[st-1]) st--;
            while(e < n-1 && s[e] == s[e+1]) e++;

            // Now I can extend in both dirn
            while(st > 0 && e < n-1 && s[st-1] == s[e+1]) st--, e++;
            
            int size = e - st + 1;
            if(maxi < size) {
                ans = s.substr(st, size);
                maxi = size;
            }
        }
        return ans;
    }
};

// TC: O(n^2) SC: O(1) 