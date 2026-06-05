#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 74. Search a 2D Matrix LINK: https://leetcode.com/problems/search-a-2d-matrix/submissions/2023276130/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int l = 0, h = (m * n) - 1;

        while(l <= h) {
            int mid = l + (h - l) / 2;

            int row = mid / m;
            int col = mid % m;

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) l = mid + 1;
            else h = mid - 1;
        }

        return false;
    }
};