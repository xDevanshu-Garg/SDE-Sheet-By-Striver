#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 26. Remove Duplicates from Sorted Array LINK: https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/2032605647/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;

        for(int j = 1; j < nums.size(); j++) {
            if(nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
        }

        return i+1;
    }
};