#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Fractional Knapsack LINK: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector<pair<double, int>> ratio(n);
        for(int i = 0; i < n; i++) {
            ratio[i] = {(double)val[i] / wt[i], i};
        }
        sort(ratio.rbegin(), ratio.rend());
        
        double ans = 0;
        for(int i = 0; i < n && capacity; i++) {
            auto& [r, ind] = ratio[i];
            
            if(capacity >= wt[ind]) {
                capacity -= wt[ind];
                ans += val[ind];
            } else {
                ans += capacity * r; 
                break;
            }
        }
        
        return ans;
    }
};