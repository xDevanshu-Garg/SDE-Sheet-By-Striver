#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! N Meetings in One Room LINK: https://takeuforward.org/plus/dsa/problems/n-meetings-in-one-room?source=strivers-sde-sheet
class Solution{
    public:
    int maxMeetings(vector<int>& start, vector<int>& end){
        vector<pair<int, int>> arr(start.size());
        for(int i = 0; i < start.size(); i++) {
            arr[i] = {end[i], start[i]};
        }

        sort(arr.begin(), arr.end());

        int finishTime = -1, cnt = 0;
        for(auto& [e, s]: arr) {
            if(finishTime < s) {
                cnt++;
                finishTime = e;
            }
        }
        
        return cnt;
    }
};