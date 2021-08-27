// 152. Maximum Product Subarray

#include <iostream>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int res = -10;
        for (int i = 0; i < size; ++i)
            res = max(res, nums[i]);

        int curMax = 1, curMin = 1;

        for (int i = 0; i < size; ++i){
            int tmp = curMax;
            curMax = max(nums[i], max(curMax*nums[i], curMin*nums[i]));
            curMin = min(nums[i], min(curMin*nums[i], tmp*nums[i]));
            res = max(res, curMax);
        }
        return res;
    }
};
