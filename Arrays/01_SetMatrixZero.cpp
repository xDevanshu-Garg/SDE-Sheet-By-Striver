#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Set Matrix Zero Link: https://leetcode.com/problems/set-matrix-zeroes/submissions/2019087441/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        int col0 = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!matrix[i][j]) {
                    matrix[i][0] = 0;
                    if(j == 0) col0 = 0;
                    else matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(!matrix[i][0] || !matrix[0][j]) 
                    matrix[i][j] = 0;
            }
        }

        // Check if row0 is 0 then whole row is 0
        if(matrix[0][0] == 0){
            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }

        // Check if col0 is 0 then whole col is 0
        // We were able to perform this without loosing info is because above operation didn't modified the variable col0
        if(col0 == 0){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
    }
};