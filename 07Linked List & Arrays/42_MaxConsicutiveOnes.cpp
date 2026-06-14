#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 485. Max Consecutive Ones LINK: https://leetcode.com/problems/max-consecutive-ones/submissions/2032595883/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0, count = 0;
        for(int x: nums) {
            if(x) count++;
            else count = 0;
            maxi = max(maxi, count);
        }

        return maxi;
    }
};