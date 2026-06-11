#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 3. Longest Substring Without Repeating Characters LINK: https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/2025941780/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, n = s.length();
        unordered_map<char, bool> mp;
        int maxi = 0;

        for(int j = 0; j < n; j++) {
            if(mp[s[j]] == false) {
                mp[s[j]] = true;
            }
            else {
                while(s[i] != s[j]) {
                    mp[s[i]] = false;
                    i++;
                }
                // here we are at i == j, so don't mark it as false, because it is taken by j
                // i++ must
                i++;
            }
            maxi = max(maxi, j - i + 1);
        }

        return maxi;
    }
};