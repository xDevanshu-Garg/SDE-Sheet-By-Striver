#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 50. Pow(x, n) LINK: https://leetcode.com/problems/powx-n/submissions/2023265920/

class Solution {
public:
    double myPow(double x, int n) {
        bool neg = n < 0;
        long pow = labs(n);

        double ans = 1.00;
        while(pow) {
            if(pow & 1) ans *= x;
            x = x * x; 
            pow >>= 1;
        }

        return (neg) ? 1 / ans : ans;
    }

    // Template
    long long fastPow(long long base, long long exp) {
        long long ans = 1;
        while(exp) {
            if(exp & 1) ans *= base;
            base = base * base; 
            exp >>= 1;
        }
        return ans;
    }
};