#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 15. 3Sum LINK: https://leetcode.com/problems/3sum/submissions/2026279550/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n-2; i++) {
            if(i != 0 && nums[i-1] == nums[i]) continue; // Skip dup for i

            int x = i + 1, y = n-1;
            while(x < y) {
                int sum = nums[i] + nums[x] + nums[y];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[x], nums[y]});
                    x++, y--;

                    // IMP skip duplicated for a and b too
                    while(x < y && nums[x] == nums[x-1]) x++;
                    while(x < y && nums[y] == nums[y+1]) y--;
                }
                else if(sum < 0) {
                    x++;
                }
                else y--;
            }
        }

        return ans;
    }
};