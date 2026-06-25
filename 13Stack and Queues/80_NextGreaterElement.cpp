#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Next Greater Element LINK: https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        
        stack<int> st;
        vector<int> ans(n);
        
        for(int i = n - 1; i >= 0; i--) {
            
            while(!st.empty() && arr[i] >= st.top()) st.pop();
            
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            
            st.push(arr[i]);
        }
        
        return ans;
    }
};