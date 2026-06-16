#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 90. Subsets II LINK: https://leetcode.com/problems/subsets-ii/submissions/2034813225/

class Solution {
public:
    void solve(vector<int> &nums, int index, vector<int> &output, vector<vector <int>> &ans) {
        ans.push_back(output); //Push everytime

        for(int i = index; i < nums.size(); i++) {
            if(i != index && nums[i] == nums[i-1]) continue; //Ignore dups but consider 1st element

            output.push_back(nums[i]);
            solve(nums, i+1, output, ans);
            output.pop_back(); //Backtrack
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;

        sort(nums.begin(), nums.end()); //Sort the array so duplicates are together

        solve(nums, 0, output, ans);
        return ans;
    }
};