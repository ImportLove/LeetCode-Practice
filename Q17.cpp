// 17. Letter Combinations of a Phone Number (Medium)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void init(){
        map['2'] = {'a', 'b', 'c'};
        map['3'] = {'d', 'e', 'f'};
        map['4'] = {'g', 'h', 'i'};
        map['5'] = {'j', 'k', 'l'};
        map['6'] = {'m', 'n', 'o'};
        map['7'] = {'p', 'q', 'r', 's'};
        map['8'] = {'t', 'u', 'v'};
        map['9'] = {'w', 'x', 'y', 'z'};
    }

    void helper(const vector< vector<char> >& source, vector<string>& ans, int size, string cur){
        if (size == int(cur.size())){
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < int(source[cur.size()].size()); ++i){
            helper(source, ans, size, cur + source[cur.size()].at(i));
        }
    }

    vector<string> letterCombinations(string digits) {
        init();
        vector<string> ans;
        if (digits.size() == 0)
            return ans;
        vector< vector<char> > source;
        for (int i = 0; i < int(digits.size()); ++i){
            source.push_back(map[digits.at(i)]);
        }

        int size = int(digits.size());
        string cur;
        helper(source, ans, size, cur);

        return ans;
    }

private:
    unordered_map<char, vector<char> > map;
};