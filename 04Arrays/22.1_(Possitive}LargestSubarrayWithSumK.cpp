#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 325. Maximum Size Subarray Sum Equals K LINK: https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

// For positive numbers we can use sliding window, but for negative numbers we can't use sliding window, because it can increase or decrease the sum, so we will use prefix sum and hashmap to store the prefix sum and its count or index depending on the problem, if we find the same prefix sum again then we can calculate the count or length of the subarray and update the maximum count or length.

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n = nums.size();
        int i = 0;
        int maxi = 0;
        int sum = 0;

        for(int j = 0; j < n; j++) {
            
            sum += nums[j]; // Increase without chinta
            

            while(sum > k) { // yaha shi ho jayega 
                sum -= nums[i]; //shrink
                i++;
            }

            if(sum == k) maxi = max(maxi, j - i + 1);
        }

        return maxi;
    }
};