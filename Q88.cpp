// 88. Merge Sorted Array

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> nums(m+n, 0);
        int index = 0, i = 0, j = 0;
        while (i < m && j < n){
            if (nums1[i] < nums2[j]){
                nums[index] = nums1[i];
                ++i;
            }
                
            else{
                nums[index] = nums2[j];
                ++j;
            }

            ++index;   
        }

        while (i < m){
            nums[index] = nums1[i++];
            ++index;
        }
        while (j < n){
            nums[index] = nums2[j++];
            ++index;
        }

        index = 0;
        while (index < m+n){
            nums1[index] = nums[index];
            ++index;
        }
    }
};