#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 239. Sliding Window Maximum LINK: https://leetcode.com/problems/sliding-window-maximum/submissions/2049161787/

// *************************BRUTE FORCE**************************
// TC: O(nlogn)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        for (int i = 0; i < k; i++)
            pq.push({nums[i], i});

        ans.push_back(pq.top().first);

        for (int i = k; i < nums.size(); i++) {
            pq.push({nums[i], i});

            while (pq.top().second <= i - k)
                pq.pop();

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};

//*************************OPTIMIZED APPROACH*******************
// TC: O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq; // Stores indices
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            // Maintaining monotonic nature so if front goes out ele is next biggest
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);

            // Remove out of window element
            if(i - k == dq.front()) dq.pop_front();

            // ignore staring window
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};