#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Job Sequencing Problem LINK: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int maxDl = *max_element(deadline.begin(), deadline.end());
        
        // Decleare an array with size = max deadline to track which jobs are done
        vector<int> jobs(maxDl + 1, -1);
        
        // Make a  array to store profit, deadline in decreasing order
        int n = deadline.size();
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++) {
            arr[i] = {profit[i], deadline[i]};
        }
        sort(arr.rbegin(), arr.rend());
        
        // Fill the jobs array
        int cnt = 0, totalProfit = 0;
        for(auto& [p, d]: arr) {
            for(int i = d; i > 0; i--) { // This loop can be eliminated using DSU
                if(jobs[i] == -1) {
                    jobs[i] = p;
                    cnt++;
                    totalProfit += p;
                    break;
                }
            }
        }
        
        return {cnt, totalProfit};
    }
};
// Can be optimized to nlogn using DSU 