#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 18. 4Sum LINK: https://leetcode.com/problems/4sum/submissions/2026289404/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, long long tar, int start) {
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = start+1; i < n-2; i++) {
            if(i != start + 1 && nums[i-1] == nums[i]) continue; // Skip dip for i

            int x = i + 1, y = n-1;
            while(x < y) {
                long long sum = (long long) nums[i] + nums[x] + nums[y];
                if(sum == tar) {
                    ans.push_back({nums[start], nums[i], nums[x], nums[y]});
                    x++, y--;

                    // IMP skip duplicated for a and b too
                    while(x < y && nums[x] == nums[x-1]) x++;
                    while(x < y && nums[y] == nums[y+1]) y--;
                }
                else if(sum < tar) {
                    x++;
                }
                else y--;
            }
        }

        return ans;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            if(i != 0 && nums[i] == nums[i-1]) continue;
            vector<vector<int>> temp = threeSum(nums, (long long) target - nums[i], i);
            
            for(auto& v: temp) ans.push_back(v);
        }

        return ans;
    }
};