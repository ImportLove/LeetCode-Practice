// 77. Combinations (Medium)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& single, int n , int k, int index){
        if (single.size() == k){
            ans.push_back(single);
            return;
        }

        for (int i = index+1; i <= n; ++i){
            single.push_back(i);
            helper(ans, single, n, k, i);
            single.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> single;
        for (int i = 1; i <= n; ++i){
            single.push_back(i);
            helper(ans, single, n, k, i);
            single.pop_back();
        }
        
        return ans;
    }
};