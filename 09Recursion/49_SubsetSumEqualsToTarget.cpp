#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Subset Sum Equals to Target LINK: https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution {
  public:
    bool solve(int i, int curr, vector<int>& arr, int sum) {
        // Base Case
        if (curr > sum) return false;
        if(curr == sum) return true;
        if(i >= arr.size()) return false;
        
        // Take and not take
        return solve(i + 1, curr + arr[i], arr, sum) ||
                solve(i + 1, curr, arr, sum);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        return solve(0, 0, arr, sum);
    }
};