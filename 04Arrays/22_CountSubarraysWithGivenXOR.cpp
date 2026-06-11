#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Count Subarrays with given XOR LINK: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        int Xor = 0, ans = 0;
        for(int x: arr) {
            Xor ^= x;
            ans += mp[Xor ^ k];
            mp[Xor]++;
        }
        
        return ans;
    }
};