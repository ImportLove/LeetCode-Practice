// 57. Insert Interval (Medium)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int size = intervals.size();
        if (size == 0){
            ans.push_back(newInterval);
            return ans;
        }

        if (newInterval[1] < intervals[0][0]){
            ans.push_back(newInterval);
            for (auto& x : intervals){
                ans.push_back(x);
            }
            return ans;
        }

        else if (newInterval[0] > intervals.back()[1]){
            for (auto& x : intervals){
                ans.push_back(x);
            }
            ans.push_back(newInterval);
            return ans;
        }
        int first, second;
        int begin = 0, end = intervals.size()-1;

        for (int i = 0; i < size*2-1; ++i){ 
            first = intervals[i/2][i%2];
            second = intervals[(i+1)/2][(i+1)%2];
            if (newInterval[0] == first)
                begin = i/2;
            if (newInterval[0] > first && newInterval[0] <= second)
                begin = (i+1)/2;
            if (newInterval[1] == second)
                end = (i+1)/2;
            if (newInterval[1] >= first && newInterval[1] < second)
                end = i/2;
        }

        for(int i = 0; i < begin; ++i){
            ans.push_back(intervals[i]);
        }

        vector<int> tmp;
        tmp.push_back(min(newInterval[0], intervals[begin][0]));
        tmp.push_back(max(newInterval[1], intervals[end][1]));
        ans.push_back(tmp);

        for (int i = end + 1; i < size; ++i){
            ans.push_back(intervals[i]);
        }

        return ans;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> intervals;
    intervals.push_back({4,4});
    intervals.push_back({5,7});
    intervals.push_back({8,10});
    vector<int> newInterval = {10,18};
    vector<vector<int>> ans = sol.insert(intervals, newInterval);
    for (auto& x : ans){
        for (auto y : x){
            cout << y << ' ';
        }
        cout << endl;
    }
    return 0;
}