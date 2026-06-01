#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Next Permutation Link: https://leetcode.com/problems/next-permutation/submissions/2018927021/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Finding first no. that is less then curr number,  i will be at one before.
        int i = n-1;
        while(i > 0 && nums[i-1] >= nums[i]) {
            i--;
        }

        // if i at 0, means whole array is sorted in descending order
        if(i == 0) {
            sort(nums.begin(), nums.end());
            return;
        } 

        // Finding first number that is greater then i-1
        int j = n-1;
        while(j >= i && nums[i-1] >= nums[j]) {
            j--;
        }

        // Swap that number with i-1 and then sort from i+1 to end
        swap(nums[i-1], nums[j]);
        sort(nums.begin() + i, nums.end());
    }
};