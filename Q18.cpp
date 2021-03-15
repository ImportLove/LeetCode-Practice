// 18. 4Sum (Medium)

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> res;
        for (int i = 0; i < int(nums.size()); ++i){
            for (int j = i+1; j < int(nums.size()); ++j){
                int left = j + 1;
                int right = int(nums.size()-1);
                while (left < right){
                    int tmp_sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if ( tmp_sum == target){
                        vector<int> tmp = {nums[i], nums[j], nums[left], nums[right]};
                        res.insert(tmp);
                        ++left;
                        --right;
                    }
                    else if (tmp_sum > target)
                        --right;
                    else
                        ++left;
                }
            }
        }

        for (auto key : res){
            ans.push_back(key);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-3,-2,-1,0,0,1,2,3};
    int target = 0;

    auto ans = sol.fourSum(nums, target);
    cout << "Answer" << endl;
    for (int i = 0; i < int(ans.size()); ++i){
        cout << "[ ";
        for (int j = 0; j < int(ans[i].size()); ++j){
            cout << ans[i][j] << ' ';
        }
        cout << ']' << endl;
    }

    return 0;
}