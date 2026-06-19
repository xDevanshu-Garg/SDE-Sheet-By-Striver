#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Rat in a Maze LINK: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution {
  public:
    int n, m;
    void dfs(int x, int y, string& output, vector<string>& ans, vector<vector<bool>>& vis, vector<vector<int>>& maze) {
        // Base Case
        if(x == n-1 && y == m-1) {
            ans.push_back(output);
            return;
        }
         
        vector<int> dx = {1, 0, 0, -1};
        vector<int> dy = {0, -1, 1, 0};
        string dir = "DLRU";
        
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || !maze[nx][ny] || vis[nx][ny]) continue;
            
            output.push_back(dir[i]);
            dfs(nx, ny, output, ans, vis, maze);
            output.pop_back();
        }
        
        vis[x][y] = 0;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        n = maze.size(), m = maze[0].size();
        
        // Base Case: If start or exit is blocked
        if(!maze[0][0] || !maze[n-1][m-1]) return {};
        
        vector<string> ans;
        string output = "";
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        dfs(0, 0, output, ans, vis, maze);
        
        return ans;
    }
};