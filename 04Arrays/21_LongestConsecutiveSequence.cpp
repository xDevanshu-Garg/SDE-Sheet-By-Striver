#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 128. Longest Consecutive Sequence LINK: https://leetcode.com/problems/longest-consecutive-sequence/submissions/2025901683/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int maxi = 0, count = 0;
        for(int x: s) {
            if(s.find(x-1) == s.end()) {
                int curr = x;
                count = 1;
                while(s.find(curr + 1) != s.end()) {
                    count++;
                    curr++;
                }

                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};