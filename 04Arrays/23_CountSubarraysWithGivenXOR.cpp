#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! For better Understanding first refer to Leetcode 560. Subarray Sum Equals K LINK: https://leetcode.com/problems/subarray-sum-equals-k/submissions/1878909928/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int prefixSum = 0, count = 0;
        mp[0] = 1; // if we need sum = 0, there is 1 ans in starting atleas, because not taking anything is 0, after that if we find more 0's in nums it can increase.

        for(int x: nums) {
            prefixSum += x;
            count += mp[prefixSum - k];
            mp[prefixSum]++;
        }
        return count;
    }
};

//! Count Subarrays with given XOR LINK: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        int prefXor = 0, ans = 0;
        for(int x: arr) {
            prefXor ^= x;
            ans += mp[prefXor ^ k];
            mp[prefXor]++;
        }
        
        return ans;
    }
};