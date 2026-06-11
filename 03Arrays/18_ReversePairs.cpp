#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 493. Reverse Pairs LINK: https://leetcode.com/problems/reverse-pairs/submissions/2029492414/

class Solution {
public:
    void merge(int l, int h, vector<int>& nums, int& ans) { 
        int mid = l + (h - l) / 2;
        
        vector<int> left(nums.begin() + l, nums.begin() + mid + 1);
        vector<int> right(nums.begin() + mid + 1, nums.begin() + h + 1);

        int n = left.size(), m = right.size();
        // First count then perform merge 
        int j = 0;
        for(int i = 0; i < n; i++) {
            while(j < m && left[i] > 2LL * right[j]) j++;

            ans += j;
        }

        // Merge
        int i = 0;
        j = 0;
        while(i < n && j < m) {
            if(left[i] < right[j]) nums[l++] = left[i++];
            else nums[l++] = right[j++];
        }

        while(i < n) {
            nums[l++] = left[i++];
        }

        while(j < m) {
            nums[l++] = right[j++];
        }
    }

    void mergeSort(int l, int h, vector<int>& nums, int& ans) {
        // Base Case
        if(l >= h) return;

        int mid = l + (h - l) / 2;

        mergeSort(l, mid, nums, ans);
        mergeSort(mid+1, h, nums, ans);

        merge(l, h, nums, ans);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        mergeSort(0, n-1, nums, ans);

        return ans;
    }
};