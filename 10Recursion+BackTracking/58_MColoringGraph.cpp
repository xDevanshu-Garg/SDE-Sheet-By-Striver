#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! M-Coloring Problem LINK: https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

class Solution {
  public:
    bool solve(int node, vector<vector<int>> &adj, vector<int> &color, int v, int m) {
        //Base Case: When nodes are over
        if(node == v) return true;
        
        for(int i = 0; i < m; i++) {
            
            bool isSafe = true;
            for(auto nei: adj[node]) {
                if(color[nei] == i) {
                    isSafe = false;
                    break;
                }
            }
            if(isSafe) {
                color[node] = i;
                if(solve(node+1, adj, color, v, m)) return true;
                color[node] = -1;
            }
            
        }
        return false;
    }
    
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        //Making an adj list
        vector<vector<int>> adj(v);
        for(auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> color(v, -1);
        return solve(0, adj, color, v, m);
    }
};