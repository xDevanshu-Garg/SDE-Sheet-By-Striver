#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//! Pascal's Traingle Link: https://leetcode.com/problems/pascals-triangle/submissions/2019088315/

// Main observation: See this triangle as right angle triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        // Row no. = row length
        for(int i = 0; i < numRows; i++) {
            ans[i].resize(i+1, 1); // i+1, because 0th row(0 index based) have size 1

            for(int j = 1; j < i; j++) { // Start from 1 and end 1 early
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j]; // curr = up-1 + up
            }
        }

        return ans;
    }
};