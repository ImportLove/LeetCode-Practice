// 5. Longest Palindromic Substring (medium)

#include <iostream>
using namespace std;

/*
// version 1
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) 
            return s;
        
        int maxLen = 0, begin=0;
        for (int i = 0; i < int(s.size())-1; ++i){
            search(s, i, i, maxLen, begin);
            search(s, i, i+1, maxLen, begin);
        }

        return s.substr(begin, maxLen);
    }

    void search(string& s, int left, int right, int& maxLen, int& begin){
        while (left >= 0 && right < s.size() && s.at(left) == s.at(right)){
            --left;
            ++right;
        }
        if (maxLen < right-left-1){
            begin = left+1;
            maxLen = right-left-1;
        }
    }
};
*/

// version 2 (dynamic programming) (slow in leetcode)
class Solution {
public:
    string longestPalindrome(string s){
        int size = int(s.size());
        int dp[size][size];
        for (int i = 0; i < size;++i){
            for (int j = 0; j < size; ++j){
                dp[i][j] = 0;
            }
        }

        int begin = 0, maxLen = 1;
        for (int j = 0; j < size; ++j){
            for (int i = 0; i <= j; ++i){
                if (i == j)
                    dp[i][j] = 1;
                if (j-i == 1 && s.at(i) == s.at(j))
                    dp[i][j] = 1;
                if (j-i > 1 && s.at(i) == s.at(j) && dp[i+1][j-1])
                    dp[i][j] = 1;
                
                if (dp[i][j] && j-i+1 > maxLen){
                    begin = i;
                    maxLen = j-i+1;
                }
            }
        }

        return s.substr(begin, maxLen);
    }
};