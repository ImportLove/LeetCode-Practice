// 773. Sliding Puzzle (Hard)

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string.h>
using namespace std;

class Solution {
public:
    string getStatus(vector<vector<int>>& board){
        string ans;
        for (int i = 0; i < 2; ++i){
            for (int j = 0; j < 3; ++j){
                ans += (board[i][j]+'0');
            }
        }
        return ans;
    }

    bool isValid(int row, int col){
        return row >= 0 && row < 2 && col >= 0 && col < 3;
    }

    void addAll(string& cur, queue<string>& q, set<string>& dead){
        cout << "cur is " << cur << endl;
        for (int i = 0; i < 6; ++i){
            if (cur.at(i) == '0'){
                char tmp[7];
                strcpy(tmp, cur.c_str());
                int row = i/3;
                int col = i%3;
                
                if (isValid(row-1, col)){
                    int index = (row-1)*3 + col;
                    swap(tmp[index], tmp[i]);
                    if (!dead.count(string(tmp))){
                        dead.insert(string(tmp));
                        q.push(string(tmp));
                    }
                    swap(tmp[index], tmp[i]);
                }

                if (isValid(row+1, col)){
                    int index = (row+1)*3 + col;
                    swap(tmp[index], tmp[i]);
                    if (!dead.count(string(tmp))){
                        dead.insert(string(tmp));
                        q.push(string(tmp));
                    }
                    swap(tmp[index], tmp[i]);
                }

                if (isValid(row, col-1)){
                    int index = (row)*3 + col-1;
                    swap(tmp[index], tmp[i]);
                    if (!dead.count(string(tmp))){
                        dead.insert(string(tmp));
                        q.push(string(tmp));
                    }
                    swap(tmp[index], tmp[i]);
                }

                if (isValid(row, col+1)){
                    int index = (row)*3 + col+1;
                    swap(tmp[index], tmp[i]);
                    if (!dead.count(string(tmp))){
                        dead.insert(string(tmp));
                        q.push(string(tmp));
                    }
                    swap(tmp[index], tmp[i]);
                }
                break;
            }
        }
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        string init = getStatus(board);
        queue<string> q;
        set<string> dead;
        dead.insert(init);
        q.push(init);

        int min_step = 0;

        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; ++i){
                string cur = q.front();
                q.pop();
                if (cur == "123450")
                    return min_step;
                addAll(cur, q, dead);
            }
            ++min_step;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> vec1 = {1,2,3};
    vector<int> vec2 = {4,0,5};
    vector<vector<int>> board;
    board.push_back(vec1);
    board.push_back(vec2);
    cout << sol.slidingPuzzle(board) << endl;
}