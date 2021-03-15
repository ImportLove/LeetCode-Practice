// 494. Target Sum (Medium)

// the vector only contains non-negative integers

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countWay(vector<int>& nums, int S, int cur_sum, int used){
        if (used == nums.size()){
            if (cur_sum == S)
                return 1;
            return 0;
        }

        return countWay(nums, S, cur_sum+nums[used], used+1) + 
            countWay(nums, S, cur_sum-nums[used], used+1);
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.size() == 0)
            return 0;
        return countWay(nums, S, 0, 0);
    }
};