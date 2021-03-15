// 74. Search a 2D Matrix (Medium)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool binaryS(vector<int>& nums, int target){
        
        int begin = 0;
        int end = nums.size();
        while (begin < end){
            int mid = begin + (end-begin)/2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] > target)
                end = mid;
            else 
                begin = mid+1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        vector<int> index;
        for (int i = 0; i < int(matrix.size()); ++i){
            index.push_back(matrix[i][0]);
        }

        int begin = 0;
        int end = int(matrix.size());
        int row = 0;
        while (begin < end){
            int mid = begin + (end-begin)/2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] > target){
                end = mid;
            }
            else{
                row = mid;
                begin = mid+1;
            }
        }

        return binaryS(matrix[row], target);
    }
};