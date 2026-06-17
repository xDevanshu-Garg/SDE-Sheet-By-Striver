#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Leetcode 40. Combination Sum II LINK: https://leetcode.com/problems/combination-sum-ii/submissions/2036970044/

class Solution {
public:
    void solve(int ind, vector<int>& temp, vector<vector<int>>& ans, vector<int>& candidates, int tar) {
        // Base Case
        if(tar < 0) return;

        if(tar == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i < candidates.size(); i++) {
            if(i != ind && candidates[i] == candidates[i-1]) continue;

            temp.push_back(candidates[i]);
            solve(i+1, temp, ans, candidates, tar - candidates[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        vector<vector<int>> ans;
        solve(0, temp, ans, candidates, target); 

       return ans;
    }
};