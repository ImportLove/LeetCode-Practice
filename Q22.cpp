// 22. Generate Parentheses (Medium)

#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]
*/

class Solution {
public:
    void helper(set<string>& res, int left, int right, string tmp){
        if (right < left || left < 0 || right < 0)
            return;
        if (left == 0 && right == 0){
            res.insert(tmp);
            return;
        }

        helper(res, left-1, right, tmp+'(');
        helper(res, left, right-1, tmp+')');

    }

    vector<string> generateParenthesis(int n) {
        set<string> res;
        vector<string> ans;

        int left = n;
        int right = n;

        helper(res, left, right, "");
        for (auto x : res){
            ans.push_back(x);
        }


        return ans;
    }
};

int main(){
    Solution sol;
    vector<string> vec = sol.generateParenthesis(4);
    for (int i = 0; i < int(vec.size()); ++i){
        cout << vec[i] << ' ';
    }
    cout << endl;
    return 0;
}