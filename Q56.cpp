// 56. Merge Intervals (Medium)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Input: intervals = [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

class Solution {
public:
    vector<int> merge(vector<vector<int>>& intervals, vector<int>& left, vector<int>& right){
        vector<int> ans;
        ans.push_back(min(left[0], right[0]));
        ans.push_back(max(left[1], right[1]));
        return ans;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals.size() == 1)
            return intervals;
        vector<vector<int>> ref(intervals.begin(), intervals.end());
        sort(ref.begin(), ref.end());
        vector<vector<int>> ans;
        int size = ref.size();
        
        vector<int> tmp(ref[0].begin(), ref[0].end());
        for (int i = 1; i < ref.size(); ++i){
            if (tmp[1] >= ref[i][0])
                tmp = merge(ref, tmp, ref[i]);
            else{
                ans.push_back(tmp);
                tmp = ref[i];
            }
        }
        ans.push_back(tmp);
        return ans;
    }
};