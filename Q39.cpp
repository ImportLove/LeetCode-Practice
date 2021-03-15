// 39. Combination Sum (Medium)

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    void helper(vector<int>& candidates, set<vector<int>>& res, vector<int>& cur_vec, int cur_sum, 
        int cur_index, int target){
        
        if (cur_sum == target){
            res.insert(cur_vec);
            return;
        }

        if (cur_sum > target){
            return;
        }

        for (int i = cur_index; i < int(candidates.size()); ++i){
            cur_vec.push_back(candidates[i]);
            helper(candidates, res, cur_vec, cur_sum + candidates[i], i, target);
            cur_vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> cur_vec;
        int cur_sum = 0;
        helper(candidates, res, cur_vec, cur_sum, 0, target);

        vector<vector<int>> ans;
        for (auto x : res){
            ans.push_back(x);
        }
        return ans;
    }
};