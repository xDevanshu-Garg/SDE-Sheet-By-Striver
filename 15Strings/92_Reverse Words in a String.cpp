#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 151. Reverse Words in a String LINK: https://leetcode.com/problems/reverse-words-in-a-string/submissions/2049573714/

class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        string ans = "";
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] != ' ') {
                word = word + s[i];
            } else {
                if(!word.empty()) {
                    reverse(word.begin(), word.end());
                    ans = ans + word;
                    ans = ans + ' ';
                    word = "";
                }
            }
        }
        reverse(word.begin(), word.end());
        ans = ans + word; 
        if(ans.back() == ' ') ans.pop_back();

        return ans;
    }
};