// 46. Permutations (Meidum)

#include <iostream>
#include <vector>
using namespace std;

void print2D(vector<vector<int>>& ans){
    for (int i = 0; i < int(ans.size()); ++i){
        for (int j = 0; j < int(ans[i].size()); ++j){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}

void print1D(vector<int>& ans){
    for (int j = 0; j < int(ans.size()); ++j){
        cout << ans[j] << ' ';
    }
    cout << endl;
}

class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& cur, vector<bool>& visited, int size){
        if (size == cur.size()){
            ans.push_back(cur);
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
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ans;
        vector<bool> visited(size, false);
        vector<int> cur;
        helper(ans, nums, cur, visited, size);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = sol.permute(nums);
    cout << "The size of ans is " << ans.size() << endl;
    print2D(ans);
    return 0;
    
}