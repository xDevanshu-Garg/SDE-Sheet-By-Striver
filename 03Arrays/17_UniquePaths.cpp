#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 62. Unique Paths LINK: https://leetcode.com/problems/unique-paths/submissions/2024050697/

// f(i, j) = number of ways to reach cell (i, j) from (0, 0)
//If I found out the ans coming from up and left side then I can add them and I'll have the ans for that state(i,j) i.e. f(i,j) = f(up) + f(left)

// ******************************Recursion + Memoization********************************
class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &dp) {

        //Base Cases
        if(m == 0 && n == 0) return 1; 
        if(m < 0 || n < 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        //Up
        int up = solve(m-1, n, dp);
        
        //left
        int left = solve(m, n-1, dp);

        return dp[m][n] = up + left;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, dp); 
    }
};

//****************************************Tabulation*************************************
// I initialized the grid with 1 because first row and column always have one path, so base cases are implicitly handled then in both for loops we started with value 1, so both left and upper corners are not overridden.
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int row = 1; row < m; row++) {
            for(int col = 1; col < n; col++) {
                dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }
        return dp[m-1][n-1];
    }
};

//*********************************Space Optimized*************************************
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1); //for upper row
        vector<int> curr(n, 1); //for curr row

        for(int row = 1; row < m; row++) {
            for(int col = 1; col < n; col++) {
                curr[col] = prev[col] + curr[col-1];
            }
            prev = curr;
        }
        return curr[n-1];
    }
};

//******************Mathematical Approach (Combinatorics)**********************
// Intuition: We have to move right n-1 times and down m-1 times, so total moves are m+n-2.
// Let's say m = 6, n = 4, so total moves are N = 6 + 4 - 2 = 8 and we have to choose 3 moves from right and 5 moves from down, so we can say that we have to choose 3 moves from total 8 moves, so the answer is 8C3 = 8! / 3! * 5! = (8 * 7 * 6) / (3 * 2 * 1) = 56. So the answer is 56 or we can say that we have to choose 5 moves from total 8 moves, so the answer is 8C5 = 8! / 5! * 3! = (8 * 7 * 6) / (3 * 2 * 1) = 56. So the answer is 56. So we can say that nCr == nCn-r, so we can compute smaller one to avoid overflow and reduce time complexity. 
class Solution {
public:
    int uniquePaths(int m, int n) {
        int left = m - 1;
        int right = n - 1;

        int N = left + right;; // m + n - 2;

        int r = min(left, right); // nCr == nCn-r , so why not compute smaller once

        // 8C3 = 8! / 3! * 5! so remaining is 8 * 7 * 6 / 3 * 2 * 1
        // This loop simulates above expression 
        long long ans = 1;
        for(int i = 1; i <= r; i++) {
            ans = ans * (N - r + i) / i;
        }

        return ans;
    }
};


// Template
/*
int N = n + m - 2;
int r = min(n-1, m-1);

long long ans = 1;

for(int i = 1; i <= r; i++) {
    ans = ans * (N - r + i) / i;
}

return ans;
*/