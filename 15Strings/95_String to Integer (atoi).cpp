#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 8. String to Integer (atoi) LINK: https://leetcode.com/problems/string-to-integer-atoi/submissions/2050835272/

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();

        // 1. Skip leading spaces
        int i = 0;
        while(i < n && s[i] == ' ') i++;

        if(i == n) return 0;    

        // 2. Handle sign
        bool positive = (s[i] == '-') ? false : true;
        if(s[i] == '+' || s[i] == '-') i++;

        // 3. Process digits
        long long ans = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            ans = (ans * 10) + (s[i] - '0');

            // 4. Check Overflow
            if(positive && ans > INT_MAX) return INT_MAX; 
            if(!positive && -ans < INT_MIN) return INT_MIN; 
            i++;
        }

        // 5. Apply sign
        ans = (positive) ? ans : -ans;

        return (int) ans;
    }
};