#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 229. Majority Element II LINK: https://leetcode.com/problems/majority-element-ii/submissions/2023978519/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int cand1 = INT_MIN, cand2 = INT_MIN;

        for(int x: nums) {
            if(count1 == 0 && cand2 != x) cand1 = x;
            else if(count2 == 0 && cand1 != x) cand2 = x;

            if(cand1 == x) count1++;
            else if(cand2 == x) count2++;
            else count1--, count2--;
        }

        // Check for real 
        count1 = 0, count2 = 0;
        for(int x: nums) {
            if(cand1 == x) count1++;
            else if(cand2 == x) count2++;
        }

        vector<int> ans;
        if(cand1 != INT_MIN && count1 > nums.size()/3) ans.push_back(cand1);
        if(cand2 != INT_MIN && count2 > nums.size()/3) ans.push_back(cand2);
        return ans;
    }
};

// Intuition: Maintain two counts for two candidates. If the current element is equal to one of the candidates, we increment the corresponding count. If the current element is not equal to either candidate, we decrement both counts. If any count becomes zero, we replace the corresponding candidate with the current element and reset the count to 1. After processing all elements, we need to check if the candidates are actually majority elements by counting their occurrences in the array. Finally, we return the candidates that appear more than n/3 times.