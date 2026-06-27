#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 994. Rotting Oranges LINK: https://leetcode.com/problems/rotting-oranges/submissions/2049776930/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // Multi source BFS, marking all rotten oranges
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        // Now BFS
        int min = 0;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while (!q.empty()) {
            int sz = q.size();

            bool ok = false;
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                        grid[nx][ny] == 1) {
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                        ok = true;
                    }
                }
            }
            if(ok) min++;
        }

        // If fresh orange still exist -> -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return min;
    }
};

//  Also we didn't use any vis here!!