#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Count Intervals LINK: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution {
  public:
    void merge(vector<int>& arr, int l, int h, int& ans) {
        int mid = l + (h - l) / 2;
        
        vector<int> left(arr.begin() + l, arr.begin() + mid + 1);
        vector<int> right(arr.begin() + mid + 1, arr.begin() + h + 1);
        
        int n = left.size(), m = right.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(left[i] > right[j]) {
                ans += n - i;
                arr[l++] = right[j++];
            }
            else {
                arr[l++] = left[i++];
            }
        }
        
        while(i < n) {
            arr[l++] = left[i++];
        }
        while(j < m) {
            arr[l++] = right[j++];
        }
    }
    
    void mergeSort(vector<int>& arr, int l, int h, int& ans) {
        // Base Case
        if(l >= h == 1) return;
        
        int mid = l + (h - l) / 2;
        mergeSort(arr, l, mid, ans);
        mergeSort(arr, mid+1, h, ans);
        
        merge(arr, l, h, ans);
    }
    
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        int ans = 0;
        mergeSort(arr, 0, n-1, ans);
        
        return ans;
    }
};