// 49. Group Anagrams (Medium)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
	Input: strs = ["eat","tea","tan","ate","nat","bat"]
	Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
		unordered_map<string, int> map;
        if (strs.size()){
			for (size_t i = 0; i < strs.size(); ++i){
				string tmp = strs[i];
				sort(tmp.begin(), tmp.end());

				if (!map.count(tmp)){
					map[tmp] = ans.size();
					ans.push_back({});
				}

				ans[map[tmp]].push_back(strs[i]);
			}
        }

        return ans;
    }
};