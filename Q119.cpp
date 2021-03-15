// 119. Pascal's Triangle II (Easy)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<long> ans(rowIndex+1, 1);
        for (int i = 1; i < rowIndex; ++i){
            ans[i] = ((rowIndex-i+1)*ans[i-1])/i;
        }

        vector<int> res;
        for (int i = 0; i < int(ans.size()); ++i){
            res.push_back(int(ans[i]));
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> ans = sol.getRow(3);
    cout << ans.size() << endl;
    for (int i = 0; i < int(ans.size()); ++i){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}