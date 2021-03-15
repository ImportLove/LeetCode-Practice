// 912. Sort an Array (Medium)

// solution: quick sort

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	int pivot(vector<int>& ans, int begin, int end){

		int index = begin-1;
		for (int i = begin; i <= end-1; ++i){
			if (ans[i] < ans[end]){
				++index;
				swap(ans[index], ans[i]);
			}
		}

		++index;
		swap(ans[index], ans[end]);
		return index;

	}

	void quicksort(vector<int>& ans, int begin, int end){
		if (begin >= end)
			return;
		int index = pivot(ans, begin, end);
		quicksort(ans, begin, index-1);
		quicksort(ans, index+1, end);
	}

    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans(nums);
        quicksort(ans, 0, ans.size()-1);
        return ans;
    }
};

void printVec(vector<int>& vec){
	for (size_t i = 0; i < vec.size(); ++i){
		cout << vec[i] << ' ';
	}
	cout << endl;
}

int main(){
	Solution sol;
	vector<int> vec = {5,2,3,1};
	
	vector<int> ans = sol.sortArray(vec);
	printVec(ans);
	
}