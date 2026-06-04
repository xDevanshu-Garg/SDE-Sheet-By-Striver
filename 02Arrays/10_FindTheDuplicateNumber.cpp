#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 287. Find the Duplicate Number LINK: https://leetcode.com/problems/find-the-duplicate-number/submissions/2021994651/

// Use LL approach
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;

        // Detect cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        // Place fast or slow at start and move them one by one
        fast = 0;
        while(fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};