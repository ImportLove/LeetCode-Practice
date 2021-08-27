// Longest Common Prefix (Easy)

#include <iostream>
#include <String>
#include <vector>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t count = 0;
        for (size_t i = 0; i < strs[0].size(); ++i){
            for (size_t j = 1; j < strs.size(); ++j){
                if (strs[j][i] != strs[0][i] || count >= strs[j].size())
                    return strs[0].substr(0, count);
            }
            ++count;
        }
        return strs[0];
    }
};
