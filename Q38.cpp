// 38. Count and Say (Easy)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    void clearVec(vector<int>& vec){
        for (size_t i = 0; i < vec.size(); ++i){
            vec[i] = 0;
        }
    }

    string countAndSay(int n) {

        vector<int> count (31, 0);
        string base = "1";

        if (n == 1)
            return base;
        
        string ans = "";
        char target;
        for (int i = 2; i <= n; ++i){
            ans = "";
            target = base.at(0);
            count[target-'0'] += 1;
            for (size_t j = 1; j < base.size(); ++j){
                if (base.at(j) == target)
                    count[target-'0'] += 1;
                else{
                    ans += (count[target-'0']+'0');
                    ans += target;
                    target = base.at(j);
                    clearVec(count);
                    count[target-'0'] += 1;
                }
            }

            if (count[target-'0'] != 0){
                ans += (count[target-'0']+'0');
                ans += target;
                clearVec(count);
            }
            base = ans;

        }
        return ans;
    }
};

int main(){
    Solution sol;
    cout << sol.countAndSay(9) << endl;
}