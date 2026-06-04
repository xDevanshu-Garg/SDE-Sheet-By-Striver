#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 645. Set Mismatch LINK: https://leetcode.com/problems/set-mismatch/submissions/2022335853/

// *******************NAIVE APPROACH USING HASH MAP******************
// TC: O(N), SC: O(N)
/*
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> freq(nums.size()+1, 0);

        for (int x : nums) freq[x]++;

        int dup = -1, missing = -1;
         for (int i = 1; i <= nums.size(); i++) {
            if(freq[i] == 2) dup = i;
            else if (freq[i] == 0) missing = i;
        }
        return {dup, missing};
    }
};
*/

// *************************USING MATHS**********************************
// TC: O(N), SC: O(1)
/*
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();

        long long sn = n * (n + 1) / 2;
        long long s2n = n * (n + 1) * (2 * n + 1) / 6;

        long long s = 0, s2 = 0;

        for (int x : nums) {
            s += x;
            s2 += 1LL * x * x;
        }

        long long val1 = sn - s;      // missing - duplicate
        long long val2 = s2n - s2;    // missing² - duplicate²

        val2 /= val1;                 // missing + duplicate

        long long missing = (val1 + val2) / 2;
        long long duplicate = missing - val1;

        return {(int)duplicate, (int)missing};
    }
};
*/

// *************************XOR APPROACH****************************
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();

        int xr = 0;
        for(int i = 0; i < n; i++) {
            xr ^= nums[i];
            xr ^= (i + 1);
        }

        int rmsb = xr & -xr;

        int zero = 0;
        int one = 0;

        for(int i = 0; i < n; i++) {
            if(rmsb & nums[i]) one ^= nums[i];
            else zero ^= nums[i];

            if(rmsb & i+1) one ^= (i+1);
            else zero ^= (i+1);
        }

        int cnt = 0;
        for(int x: nums) {
            if(one == x) cnt++;
        }
        int miss = 0, dup = 0;
        if(cnt) miss = zero, dup = one;
        else miss = one, dup = zero;
        return {dup, miss};
    }
};