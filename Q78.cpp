// 78. Subsets (Medium)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});

        for (int i = 0; i < int(nums.size()); ++i){
            int size = ans.size();
            for(int j = 0; j < size; ++j){
                vector<int> tmp(ans[j].begin(), ans[j].end());
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }
        
        return ans;
    }
};