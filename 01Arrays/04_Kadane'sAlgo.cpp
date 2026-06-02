#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Maximum Subarray Sum using Kadane's Algorithm LINK: https://leetcode.com/problems/maximum-subarray/submissions/2019940972/

// Kadane's Algo: If curr contri is neg discard it becuase it'll only bring total sum down.
// Lesson: Avoid Negative people. 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;

        for(int x: nums) {
            currSum += x;
            maxSum = max(currSum, maxSum);
            if(currSum < 0) currSum = 0;
        }

        return maxSum;
    }
};
