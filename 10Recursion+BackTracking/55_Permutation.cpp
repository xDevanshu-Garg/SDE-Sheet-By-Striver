#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 46. Permutations LINK: https://leetcode.com/problems/permutations/submissions/2037478630/

class Solution {
public:
    void solve(int ind, vector<int>& nums, vector<vector<int>>& res) {
        // Base Case
        if(ind >= nums.size()) {
            res.push_back(nums);
            return;
        }

        for(int i = ind; i < nums.size(); i++) {
            swap(nums[ind], nums[i]);
            solve(ind + 1, nums, res);
            swap(nums[i], nums[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        solve(0, nums, res);

        return res;
    }
};