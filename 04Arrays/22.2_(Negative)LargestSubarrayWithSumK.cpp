#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// This code is for negative numbers. 

// ***************** count how many subarrays have sum k ******************
//! LINK: https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1

class Solution {
public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;  // Empty prefix

        int pref = 0;
        int cnt = 0;

        for (int x : arr) {
            pref += x;

            if (mp.find(pref - k) != mp.end()) {
                cnt += mp[pref - k];
            }

            mp[pref]++;
        }

        return cnt;
    }
};

//! LINK: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

// ***************** longest subarray with sum k ******************
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> mp; // prefix sum -> first index
        mp[0] = -1;

        int pref = 0;
        int ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            pref += arr[i];

            if (mp.find(pref - k) != mp.end()) {
                ans = max(ans, i - mp[pref - k]);
            }

            // Check for earliest pref
            if (mp.find(pref) == mp.end()) {
                mp[pref] = i;
            }
        }

        return ans;
    }
};