// 207. Course Schedule

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	
	void printVec1(vector<int>& vec){
		for (int i = 0; i < vec.size(); ++i)
			cout << vec[i] << ' ';
		cout << endl;
	}

	void printVec2(vector<vector<int>>& vec){
		for (int i = 0; i < vec.size(); ++i){
			cout << i << ": ";
			for (int j = 0; j < vec[i].size(); ++j){
				cout << vec[i][j] << ' ';
			}
			cout << endl;
		}
	}

    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

		// construct the in_table and the graph
        vector<int> in_table(numCourses, 0);
		vector<vector<int>> graph(numCourses, vector<int>());

        for (int i = 0; i < prerequisites.size();++i){
            ++in_table[prerequisites[i][0]];
			graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

		queue<int> schedule;
		for (int i = 0; i < in_table.size(); ++i){
			if (in_table[i] == 0)
				schedule.push(i);
		}

		if (schedule.empty())
			return false;

		while (!schedule.empty()){
			int tmp = schedule.front();
			schedule.pop();

			int num_neigh = graph[tmp].size();
			for (int i = 0; i < num_neigh; ++i){
				--in_table[graph[tmp][i]];
				if (in_table[graph[tmp][i]] == 0)
					schedule.push(graph[tmp][i]);
			}
				
		}

		for (int i = 0; i < in_table.size(); ++i){
			if (in_table[i] != 0)
				return false;
		}
		return true;
    }
};

int main(){
	Solution sol;
	int numCourse = 3;
	vector<vector<int>> preq = {{1,0}, {2,1}};
	cout << ((sol.canFinish(numCourse, preq) == 0 )? "false" : "true") << endl;
	return 0;
}