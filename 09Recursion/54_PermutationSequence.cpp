#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 60 Permutation Sequence LINK: https://leetcode.com/problems/permutation-sequence/submissions/2037058943/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
            nums.push_back(i);
        }
        
        // Compute (n-1)!
        fact = fact / n;

        string ans = "";
        k--;  // convert to 0-based

        while (!nums.empty()) {
            int index = k / fact;
            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);

            if (nums.empty()) break;

            k %= fact;            // update k within current block
            fact /= nums.size();  // next block size
        }

        return ans;
    }
};