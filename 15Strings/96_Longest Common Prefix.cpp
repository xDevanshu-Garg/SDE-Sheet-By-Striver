#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Leetcode 14. Longest Common Prefix LINK: https://leetcode.com/problems/longest-common-prefix/submissions/2050890422/?__cf_chl_f_tk=F.3noxJsZ1gTntHyXis9KiL_qOujSVRFNG765pc5uYA-1782800813-1.0.1.1-07S.zPv9Ig4Ks.AAJ5d3wZvy9CMvoKGrw_pBaTXoVhw

// ************INTENDED SOLN*************** TC: O(N*M) SC: O(1)
// First loop for jth char, Second loop compares that jth char for every string wrt to 1st string
// Early return if ith string is shorter or doesn't match with first one
// Only increased len if jth char matches with every string.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = 0;
        for (int j = 0; j < strs[0].size(); j++) {
            for (int i = 1; i < strs.size(); i++) {
                if (j >= strs[i].size() || strs[i][j] != strs[0][j]) {
                    return strs[0].substr(0, len);
                }
            }
            len++;
        }

        return strs[0].substr(0, len);
    }
};


// ***************USING TRIE(just for practice)***************** TC & SC: O(NM)
class TrieNode{
  public:
    char data;
    TrieNode* children[26];
    bool isEndOfWord;
    int childCount = 0; //Added this to count how many childs are there

    TrieNode(char data){
        this->data = data;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr; // Initialize all children to nullptr
        
        isEndOfWord = false;
    }
};

class Trie{
  public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');  // root with null character
    }

    void insertUtil(TrieNode* node, const string& word, int i){
        //Base Case
        if(i == word.length()){
            node->isEndOfWord = true;
            return;
        }

        int index = word[i] - 'a';
        TrieNode* child;
        //Present
        if(node->children[index]){
            child = node->children[index];
        }
        //Absent
        else{
            child = new TrieNode(word[i]);
            node->children[index] = child;
            node->childCount++;
        }
        insertUtil(child, word, i+1);
    }

    void insert(string word){
        insertUtil(root, word, 0);
    }

    void LCP(const string& word, string &ans) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr->childCount == 1 && !curr->isEndOfWord) {
                int index = word[i] - 'a';
                ans += word[i];
                curr = curr->children[index];
            } else {
                break;
            }
        }
    }
    
    
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie t;
        //Insert all strings into Trie
        for(auto &str: strs){
            t.insert(str);
        }
        
        //if a node has more then 1 children then break otherwise add to ans;
        string ans;
        t.LCP(strs[0], ans);
        return ans;
    }
};