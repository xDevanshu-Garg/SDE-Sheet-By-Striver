#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Sort Colors LINK: https://leetcode.com/problems/sort-colors/submissions/2019992778/

// Dutch National Flag Algo
/*
i = where the next 0 should go
j = the ball we're currently looking at
k = where the next 2 should go

If j sees 1:
    Just move forward.
    1 belongs in the middle, so it's already fine.

If j sees 2:
    Swap with k and move k left.
    2 belongs at the end.

    BUTTTT Don't move j yet.
    The element that came from k could be 0, 1, or 2.
    We must check it before moving on.

If j sees 0:
    Swap with i and move both i and j forward.
    0 belongs at the front.

    Why move j too?
    Because everything before j has already been processed.
    The value coming from i can only be:
    - 0 (already correct), or
    - 1 (also fine to skip)
    It can never be 2 because any 2 found earlier would already have been sent to the end.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = nums.size() - 1;

        while(j <= k) {
            if(nums[j] == 2) swap(nums[j], nums[k--]);
            else if(nums[j] == 0) swap(nums[j++], nums[i++]);
            else j++;
        }
    }
};


// Quick memory:
// 0 -> send left  -> i++, j++
// 1 -> leave it   -> j++
// 2 -> send right -> k--