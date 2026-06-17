#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 39. Combination Sum LINK: https://leetcode.com/problems/combination-sum/submissions/2036660982/

class Solution {
public:
    void solve(int i, vector<int>& temp, vector<vector<int>>& ans, vector<int>& candidates, int tar) {
        // Base Case
        if(tar < 0) return;

        if(tar == 0) {
            ans.push_back(temp);
            return;
        }

        if(i >= candidates.size()) return;

        // Not pick
        solve(i+1, temp, ans, candidates, tar);

        // Pick
        temp.push_back(candidates[i]);
        solve(i, temp, ans, candidates, tar - candidates[i]);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int> temp;
       vector<vector<int>> ans;
       solve(0, temp, ans, candidates, target); 

       return ans;
    }
};