#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 455. Assign Cookies LINK: https://leetcode.com/problems/assign-cookies/submissions/2034870492/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int a = 0, b = 0;

        while(a < g.size() && b < s.size()) {
            if(g[a] <= s[b]) {
                count++;
                a++, b++;
            }
            else b++;
        }

        return count;
    }
};