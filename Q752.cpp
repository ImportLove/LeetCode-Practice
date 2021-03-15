// 752. Open the Lock (Medium)

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
    void addAll(queue<string>& q, set<string>& dead, const string& cur){
        int size = cur.size() + 1;
        char char_array[size];
        strcpy(char_array, cur.c_str());
        for (int i = 0; i < 4; ++i){
            char origin = char_array[i];
            char_array[i] = (((char_array[i]-'0') + 1)%10 + '0');
            if (!dead.count(string(char_array))){
                q.push(string(char_array));
                dead.insert(string(char_array));
            }
            char_array[i] = origin;

            char_array[i] = (((char_array[i]-'0') + 9)%10 + '0');
            if (!dead.count(string(char_array))){
                q.push(string(char_array));
                dead.insert(string(char_array));
            }
            char_array[i] = origin;
        }
    }

    int openLock(vector<string>& deadends, string target) {
        set<string> dead;
        int size = deadends.size();
        for (int i = 0; i < size; ++i){
            dead.insert(deadends[i]);
        }
        if (dead.count("0000") || dead.count(target))
            return -1;
        if (target == "0000")
            return 0;

        queue<string> q;
        q.push("0000");
        dead.insert("0000");
        int min_step = 0;
        while (!q.empty()){
            
            int level = q.size();
            for(int i = 0; i < level; ++i){
                string cur = q.front();
                q.pop();
                if (cur == target)
                    return min_step;
                addAll(q, dead, cur);
            }
            ++min_step;
        }

        return -1;
    }
};