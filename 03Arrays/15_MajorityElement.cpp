#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 169. Majority Element LINK: https://leetcode.com/problems/majority-element/submissions/2023252737/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = -1;

        for(int x: nums) {
            if(count == 0)  candidate = x;

            if(x == candidate) count++;
            else count--;
        }

        return candidate;
    }
};