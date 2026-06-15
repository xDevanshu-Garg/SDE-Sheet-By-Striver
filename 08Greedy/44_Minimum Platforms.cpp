#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Minimum Platforms LINK: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution {
public:
    int minPlatform(vector<int>& Arrival, vector<int>& Departure) {
        int n = Arrival.size();

        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());

        int i = 0, j = 0;
        int platforms = 0, ans = 0;

        while (i < n && j < n) {
            if (Arrival[i] <= Departure[j]) {
                platforms++;
                ans = max(ans, platforms);
                i++;
            } else {
                platforms--;
                j++;
            }
        }

        return ans;
    }
};