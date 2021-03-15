// 71. Simplify Path (Medium)

#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string tmp(path);
        stack<string> s;
        for (int i = int(tmp.size()-1); i >= 1; --i){
            if (tmp.at(i) == '/' && tmp.at(i-1) == '/')
                tmp.erase(i, 1);
        }

        int size = tmp.size();
        for (int i = 1; i < size; ++i){
            if (tmp.at(i) == '/')
                continue;
            
            int index = i;
            while (index < size && tmp.at(index) != '/'){
                ++index;
            }
            
            int length = index-i;

            if (length > 2 || (tmp.at(i) != '/' && tmp.at(i) != '.')){
                string dir;
                while (i < size && tmp.at(i) != '/'){
                    dir += tmp.at(i);
                    ++i;
                }
                s.push(dir);
            } 
            else if (tmp.at(i) == '.'){
                if (i+1 < size && tmp.at(i+1) == '.' && !s.empty()){
                    s.pop();
                    ++i;
                }
            }
        }

        
        if (s.empty())
            return "/";
        
        string ans;
        while (!s.empty()){
            ans = '/' + s.top() + ans;
            s.pop();
        }

        return ans;

    }
};

int main(){
    Solution sol;
    string path = "/a//b////c/d//././/..";
    cout << sol.simplifyPath(path) << endl;
    return 0;
}