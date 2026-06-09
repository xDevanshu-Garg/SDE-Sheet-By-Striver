#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 240. Search a 2D Matrix II LINK: https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/2027564925/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int r = 0, c = m-1;
        while(r < n && c >= 0) {
            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] < target) r++;
            else c--;
        }

        return false;
    }
};

// Tc: O(m+n)
// Intuition: We can start from the top right corner of the matrix. If the current element is equal to the target, we return true. If the current element is less than the target, we can move down to the next row because all elements in the current column are less than the target. If the current element is greater than the target, we can move left to the previous column because all elements in the current row are greater than the target. We continue this process until we find the target or exhaust all possibilities.