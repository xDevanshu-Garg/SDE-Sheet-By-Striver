#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// this is 2 pass soln, TC = 2 * O(2N) = O(4N) 
//***************************BRUTE FORCE SOLN***************************
// here stored indices, also for nse last index is n not -1
class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();

        vector<int> nse(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();
            }

            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();

            st.push(i);
        }

        vector<int> pse(n);
        st = {};
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();
            }

            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();

            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, (nse[i] - pse[i] - 1) * nums[i]);
        }

        return ans;
    }
};

//***************************OPTIMIZED SOLN***************************
class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[i] <= nums[st.top()]) {
                int val = nums[st.top()];
                st.pop();

                int nse = i;
                int pse = -1;
                if(!st.empty()) pse = st.top();

                ans = max(ans, (nse - pse - 1) * val);
            }

            st.push(i);
        }

        while(!st.empty()) {
            int val = nums[st.top()];
            st.pop();

            int nse = n;
            int pse = -1;
            if(!st.empty()) pse = st.top();

            ans = max(ans, (nse - pse -1) * val);
        }
        
        return ans;
    }
};
