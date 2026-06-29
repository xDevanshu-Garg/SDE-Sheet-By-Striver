#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 13. Roman to Integer LINK: https://leetcode.com/problems/roman-to-integer/submissions/2049663812/

// Trick: If the current value is less than the next value, then we subtract the current value from the next value and add it to the answer. Otherwise, we add the current value to the answer.
class Solution {
public:
    int romanToInt(string s) {
        // Creating mapping
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(i < n-1 && mp[s[i]] < mp[s[i+1]]) {
                ans += mp[s[i+1]] - mp[s[i]];
                i++;
            } else {
                ans += mp[s[i]];
            }
        }

        return ans;
    }
};

// TC: O(n) and SC: O(1) 