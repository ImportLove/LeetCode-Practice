// 60. Permutation Sequence (Hard)

#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    string helper(set<string>& s, int n, int begin, int end, int k){
        if (s.size() == 1)
            return *s.begin();

        cout << "begin is " << begin << endl;
        cout << "end is " << end << endl;
        
        int interval = (end-begin)/n;
        int index = (k-begin)/interval;

        auto it = s.begin();
        for (int i = 0; i < index; ++i){
            ++it;
        }
        string cur = *it;
        cout << "it is " << cur << " and its index is " << index << endl;
        s.erase(it);
        return cur + helper(s, n-1, begin + index*interval, min(begin + (index+1)*interval, end), k);
    }

    string getPermutation(int n, int k) {
        set<string> s;
        int begin = 0, end = 1;
        for (int i = 1; i <= n; ++i){
            s.insert(to_string(i));
            end *= i;
        }
        return helper(s, n, begin, end, k-1);
    }
};

int main(){
    Solution sol;
    string ans = sol.getPermutation(3, 3);
    cout << ans << endl;
    return 0;
}