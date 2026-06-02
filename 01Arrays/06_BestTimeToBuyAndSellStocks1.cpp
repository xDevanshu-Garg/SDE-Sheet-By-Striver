#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Best Time to Buy and Sell Stocks 1 LINK: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/2019969036/

// Profit = buy at low price and sell at high
// For each day, pretend today is the selling day.
// The best buying day is simply the cheapest price seen before today.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cheapest = INT_MAX; // Current cheapest stock
        int ans = 0;

        for(int price: prices) {
            cheapest = min(cheapest, price);

            ans = max(ans, price - cheapest);
        }

        return ans;
    }
};