// 118. Pascal's Triangle (Easy)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;

        if (numRows == 0)
            return ans;
        ans.push_back({1});

        for (int i = 1; i < numRows; ++i){

            vector<int> temp(i+1, 0);
            temp[0] = 1;
            temp[i] = 1;
			
			int index = 0;
            for (size_t j = 1; j < i; ++j){
                temp[j] = ans[i-1][index] + ans[i-1][index+1];
				++index;
            }

			ans.push_back(temp);

        }

		return ans;
    }
};