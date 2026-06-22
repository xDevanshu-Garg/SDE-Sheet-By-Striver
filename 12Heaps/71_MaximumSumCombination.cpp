#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Maximum Sum Combination LINK: https://www.geeksforgeeks.org/problems/maximum-sum-combination/1

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        
        // {sum, i, m} tuple<int, int, int> 
        priority_queue<tuple<int, int, int>> pq;
        pq.push({a[0] + b[0], 0, 0});
        
        set<pair<int, int>> vis;
        vis.insert({0, 0});
        
        vector<int> ans;
        
        while(ans.size() < k) {
            auto [sum, i, j] = pq.top(); pq.pop();
            ans.push_back(sum);
            
            if (j + 1 < n && !vis.count({i, j + 1})) {
                pq.push({a[i] + b[j + 1], i, j + 1});
                vis.insert({i, j + 1});
            }

            if (i + 1 < n && !vis.count({i + 1, j})) {
                pq.push({a[i + 1] + b[j], i + 1, j});
                vis.insert({i + 1, j});
            }
        }
        
        return ans;
    }
};