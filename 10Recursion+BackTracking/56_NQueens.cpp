#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 51. N-Queens LINK: https://leetcode.com/problems/n-queens/submissions/2037547778/

class Solution {
public:
    vector<bool> leftRow;
    vector<bool> upperDiagonal;
    vector<bool> lowerDiagonal;

    void solve(int col, vector<vector<string>>& ans, vector<string>& board) {
        // Base Case
        if(col >= board.size()) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < board.size(); row++) {
            int lower = row + col, upper = board.size() - 1 + row - col;

            if(!leftRow[row] && !upperDiagonal[upper] && !lowerDiagonal[lower]) {

                // Place Queen
                board[row][col] = 'Q';
                leftRow[row] = true;
                upperDiagonal[upper] = true;
                lowerDiagonal[lower] = true;


                // RR
                solve(col+1, ans, board);

                // Backtrack
                board[row][col] = '.';
                leftRow[row] = false;
                upperDiagonal[upper] = false;
                lowerDiagonal[lower] = false;
            }
        }
    }
        
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        leftRow.assign(n, false);
        upperDiagonal.assign(2*n - 1, false);
        lowerDiagonal.assign(2*n - 1, false);

        solve(0, ans, board);

        return ans;
    }
};