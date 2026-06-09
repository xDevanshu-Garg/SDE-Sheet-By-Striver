#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 1. Two Sum LINK: https://leetcode.com/problems/two-sum/submissions/1748386627/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // ******************BRUTE FORCE************************
        /*
        for(int i =0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {0};
        */

        // *******************BETTER APPROACH*******************
        //Best in this case!!
        //Using hash map TC = O(n) mostly but due to collision it can go to O(n^2) or if you take simple map then O(nlogn)
        // SC = O(n)
        /*
        unordered_map<int, int> isPresent;
        for(int i = 0; i < n; i++) {
            int newTar = target - nums[i];
            if(isPresent.find(newTar) != isPresent.end())
                return {i, isPresent[newTar]};
            //If we're here means we didn't found our ans so let's make a new entry.
            isPresent[nums[i]] = i; // Add nums of i
        }
        return {};
        */

        // **********************BEST APPROACH************************
        // (only if we've to return yes or no)
        //otherwise make a DS so that we can store indexes of orignal array too but then this approach is bas because TC: O(nlogn) SC: O(n)
        sort(nums.begin(), nums.end());
        int i = 0, j = n-1;
        while(i < j) {
            int sum = nums[i] + nums[j];
            if(sum == target) return {i, j};
            if(sum < target) i++;
            else j--;
        }
        return {};
    }
};