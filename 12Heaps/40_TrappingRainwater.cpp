#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 42. Trapping Rain Water LINK: https://leetcode.com/problems/trapping-rain-water/submissions/2042161816/

class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = 0, rightMax = 0, l = 0, r = height.size() - 1, ans = 0;

        while(l <= r) {
            if(height[l] <= height[r]) {
                leftMax = max(leftMax, height[l]);
                ans += leftMax - height[l];
                l++;
            } else {
                rightMax = max(rightMax, height[r]);
                ans += rightMax - height[r];
                r--;
            }
        }

        return ans;
    }
};

// Intuition : Whichever side is shorter becomes the bottleneck. Since the other side is already taller, we don't need to know its exact maximum height. We can safely calculate water using only the maximum seen so far on the shorter side. 

// This is reason we have our 2nd ptr at end because of rightMax






// 🌊 Intuition

// Water above any building depends on the tallest wall on its left
// and the tallest wall on its right.
//
// water[i] = min(leftTallest, rightTallest) - height[i]
//
// A building can only hold water up to the height of the shorter wall
// among the two sides.

// -------------------------------------------------------------

// ⚡ Why Two Pointers Work

// We keep two pointers: left and right.
// Also maintain:
//
// leftMax  = tallest building seen from the left
// rightMax = tallest building seen from the right
//
// At every step, we move the pointer that is currently at the
// smaller height.

// Suppose:
// height[left] <= height[right]
//
// Since the right boundary is already at least as tall as the left one,
// we know there is definitely a wall on the right side that can support
// water for the current left position.
//
// So the amount of water at 'left' no longer depends on the exact
// rightMax value. The limiting factor is only leftMax.
//
// Therefore:
//
// water at left = leftMax - height[left]   (if leftMax > height[left])
//
// After processing it, we move left++.

// Similarly, if:
//
// height[right] < height[left]
//
// then we are guaranteed that a sufficient wall exists on the left side,
// so the water at 'right' depends only on rightMax.
//
// water at right = rightMax - height[right]
//
// After processing it, we move right--.

// -------------------------------------------------------------

// 🔑 Key Insight
//
// We always process the side with the smaller height because
// the opposite side is guaranteed to be tall enough.
//
// In other words:
//
// Smaller side decides the water level.
// Larger side is already "safe" and doesn't need to be known exactly.
//
// That's why we can calculate trapped water in one pass
// without storing leftMax[] and rightMax[] arrays.