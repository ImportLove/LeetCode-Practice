// 62. Unique Paths (Medium)

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:

    string getKey(int m, int n){
        string ans = "";
        char mc = m + '0';
        ans += mc;
        ans += ' ';
        char nc = n + '0';
        ans += nc;
        return ans;
    }

    int helper(int m, int n, unordered_map< string,int >& map){
        if (m <= 0 || n <= 0)
            return 0;
        if (map.count(getKey(m,n))){
            return map[getKey(m,n)];
        }
        string key = getKey(m,n);
        map[key] = helper(m-1, n, map) + helper(m, n-1, map);
        return map[key];
    }

    int uniquePaths(int m, int n) {
        unordered_map< string, int > map;
        string key = getKey(1,1);
        map[key] = 1;
        return helper(m, n, map);
    }
};