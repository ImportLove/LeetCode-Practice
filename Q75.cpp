// 75. Sort Colors (Medium)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int getPivot(vector<int>& nums, int begin, int end){

        int small = begin-1;
        for (int i = begin; i < end; ++i){
            if (nums[i] < nums[end]){
                ++small;
                swap(nums[small], nums[i]);
            }
        }

        ++small;
        swap(nums[small], nums[end]);
        return small;
    }

    void sortColors(vector<int>& nums, int begin, int end){
        if (begin >= end)
            return;
        int pivot = getPivot(nums, begin, end);
        sortColors(nums, begin, pivot-1);
        sortColors(nums, pivot+1, end);
    }

    void sortColors(vector<int>& nums) {
        if (nums.size() == 0)
            return;
        sortColors(nums, 0, nums.size()-1);
    }
};