#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Sort a Stack LINK: https://www.geeksforgeeks.org/problems/sort-a-stack/1

//******************************** BRUTE FORCE ***********************************

// BRUTE FORCE
// Extract all elements into a vector, sort using STL sort, then push back into the stack. 
// O(n log n) time, O(n) extra space.

class Solution {
  public:
    void sortStack(stack<int> &st) {
        vector<int> arr;
        while(!st.empty()) {
            arr.push_back(st.top());
            st.pop();
        }
        
        sort(arr.begin(), arr.end());
        
        for(int x: arr) {
            st.push(x);
        }
    }
};

//******************************** SELECTION SORT ***********************************
// STACK-ONLY (Selection Sort Idea)
// Repeatedly find the minimum element in the unsorted portion, place it in its final position, and restore the remaining elements.
// O(n²) time, O(n) extra space (temporary stack).
class Solution {
  public:
    void sortStack(stack<int> &st) {
        int n = st.size();
        
        for(int i = 0; i < n; i++) {
            int mini = INT_MAX;
            int sz = n - i;
            stack<int> temp;
            
            while(sz--) {
                mini = min(mini, st.top());
                temp.push(st.top());
                st.pop();
            }
            
            st.push(mini);
            bool skip = false;
            while(!temp.empty()) {
                if(!skip && temp.top() == mini) {
                    temp.pop();
                    skip = true;
                    continue;
                } 
                st.push(temp.top());
                temp.pop();
            }
            
        }
        
    }
};

//******************************** RECURSIVE INSERTION SORT ***********************************

// RECURSIVE INSERTION SORT
// Recursively pop all elements from the stack, sort the remaining stack, and then insert the popped element back into the sorted stack in its correct position.
class Solution {
  public:
  
    void mergeStack(int x, stack<int>& st) {
       // Base Case
       if(st.empty() || st.top() <= x) {
           st.push(x);
           return;
       }
       
       int val = st.top();
       st.pop();
       mergeStack(x, st);
       st.push(val);
    }
    
    void sortStack(stack<int> &st) {
        if(st.empty()) return;
        
        int x = st.top(); st.pop();
        
        sortStack(st);
        
        mergeStack(x, st);
    }
};



/*
| Approach                          | Time         | Extra Space | Notes                      |
| --------------------------------- | ------------ | ----------- | -------------------------- |
| Vector + sort                     | `O(n log n)` | `O(n)`      | Fastest, simplest          |
| Your selection-style stack method | `O(n²)`      | `O(n)`      | Uses stacks only           |
| Recursive insertion sort on stack | `O(n²)`      | `O(n)`      | Classic interview solution |
*/