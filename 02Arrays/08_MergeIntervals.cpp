#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode: 56. Merge Intervals LINK: https://leetcode.com/problems/merge-intervals/submissions/2021132594/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        for(auto& interval: intervals) {
           // if ans is empty or no merge possible then append curr 
            if(ans.empty() || ans.back()[1] < interval[0])
                ans.push_back(interval);
            // before merging check if curr end time is greater or new ones
            else 
                ans.back()[1] = max(ans.back()[1], interval[1]);
        }

        return ans;
    }
};