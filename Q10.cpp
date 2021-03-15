// 10. Regular Expression Matching (Hard)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();
        if (p.size() == 1){
            if (s.size() == 1 && (p.at(0) == s.at(0) || p.at(0) == '.'))
                return true;
            return false;
        }

        if (p.at(1) != '*'){
            if (s.empty())
                return false;
            return ( (p.at(0) == s.at(0) || p.at(0) == '.') && isMatch(s.substr(1), p.substr(1)) );
        }

        while (!s.empty() && (s.at(0) == p.at(0) || p.at(0) == '.' )){
            if (isMatch(s, p.substr(2)))
                return true;
            s = s.substr(1);
        }

        return isMatch(s, p.substr(2));
    }
};

int main(){
    Solution sol;
    string s = "aaa";
    string p = "a*a";
    cout << ((sol.isMatch(s, p) == 1) ? "true" : "false") << endl;
}