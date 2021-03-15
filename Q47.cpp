// 47. Permutations II (Medium)

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void helper(set<vector<int>>& ans, vector<int>& nums, vector<int>& cur, vector<bool>& visited, int size){
        if (size == cur.size()){
            ans.insert(cur);
        }
            
        for (int i = 0; i < int(nums.size()); ++i){
            if (!visited[i]){
                visited[i] = true;
                cur.push_back(nums[i]);
                helper(ans, nums, cur, visited, size);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size();
        set<vector<int>> ans;
        vector<bool> visited(size, false);
        vector<int> cur;
        helper(ans, nums, cur, visited, size);

        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};